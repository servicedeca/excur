<?php

abstract class Redis_AbstractBackend
{
    /**
     * Key components name separator
     */
    const KEY_SEPARATOR = ':';

    /**
     * @var string
     */
    static protected $globalPrefix;

    /**
     * Get site default global prefix
     *
     * @return string
     */
    static public function getGlobalPrefix()
    {
        // Provide a fallback for multisite. This is on purpose not inside the
        // getPrefixForBin() function in order to decouple the unified prefix
        // variable logic and custom module related security logic, that is not
        // necessary for all backends. We can't just use HTTP_HOST, as multiple
        // hosts might be using the same database. Or, more commonly, a site
        // might not be a multisite at all, but might be using Drush leading to
        // a separate HTTP_HOST of 'default'. Likewise, we can't rely on
        // conf_path(), as settings.php might be modifying what database to
        // connect to. To mirror what core does with database caching we use
        // the DB credentials to inform our cache key.
      if (null === self::$globalPrefix) {
            $dbInfo = Database::getConnectionInfo();
            $active = $dbInfo['default'];
            self::$globalPrefix = md5($active['host'] . $active['database'] . $active['prefix']['default']);
        }

        return self::$globalPrefix;
    }

    /**
     * Get global default prefix
     *
     * @param string $suffix
     *
     * @return string
     */
    static public function getDefaultPrefix($suffix = null)
    {
        $ret = null;

        if (isset($GLOBALS['drupal_test_info']) && !empty($test_info['test_run_id'])) {
            $ret = $test_info['test_run_id'];
        } else {
            $prefixes = variable_get('cache_prefix', null);

            if (is_string($prefixes)) {
                // Variable can be a string which then considered as a default
                // behavior.
                $ret = $prefixes;
            } else if (null !== $suffix && isset($prefixes[$suffix])) {
                if (false !== $prefixes[$suffix]) {
                    // If entry is set and not false an explicit prefix is set
                    // for the bin.
                    $ret = $prefixes[$suffix];
                } else {
                    // If we have an explicit false it means no prefix whatever
                    // is the default configuration.
                    $ret = '';
                }
            } else {
                // Key is not set, we can safely rely on default behavior.
                if (isset($prefixes['default']) && false !== $prefixes['default']) {
                    $ret = $prefixes['default'];
                } else {
                    // When default is not set or an explicit false this means
                    // no prefix.
                    $ret = '';
                }
            }
        }

        if (empty($ret)) {
            $ret = self::getGlobalPrefix();
        }

        return $ret;
    }

    /**
     * @var string
     */
    private $prefix;

    /**
     * Default constructor
     */
    public function __construct($prefix = null)
    {
        if (null === $prefix) {
            $this->prefix = $prefix = self::getDefaultPrefix();
        } else {
            $this->prefix = $prefix;
        }
    }

    /**
     * Get redis client
     *
     * @return Redis|Predis\Client
     */
    public function getClient()
    {
        // Ugly stateless and static
        return Redis_Client::getClient();
    }

    /**
     * Set prefix
     *
     * @param string $prefix
     */
    final public function setPrefix($prefix)
    {
        $this->prefix = $prefix;
    }

    /**
     * Get prefix
     *
     * @return string
     */
    final public function getPrefix()
    {
        return $this->prefix;
    }

    /**
     * Get full key name using the set prefix
     *
     * @param string ...
     *   Any numer of strings to append to path using the separator
     *
     * @return string
     */
    public function getKey()
    {
        $args = array_filter(func_get_args());

        if (empty($args)) {
            return $this->prefix;
        } else if (is_array($args)) {
            array_unshift($args, $this->prefix);
            return implode(self::KEY_SEPARATOR, $args);
        } else {
            return $this->prefix . self::KEY_SEPARATOR . $args;
        }
    }
}
