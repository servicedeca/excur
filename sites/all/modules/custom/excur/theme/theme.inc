<?php

/**
 * @file.
 */


/**
 * Preprocess for excur-profile-form.tpl.php.
 */
function excur_preprocess_excur_profile_form(&$vars) {
  $vars['form']['account']['name']['#title'] = t('login');
}