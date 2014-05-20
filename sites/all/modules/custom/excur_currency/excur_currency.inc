<?php

class excurCurrency {
  protected $list = array();
  protected $list_nom = array();

  public function load() {
    $xml = new DOMDocument();
    $url = 'http://www.cbr.ru/scripts/XML_daily.asp';
    if (@$xml->load($url)) {
      $this->list = array();
      $this->list_nom = array();
      $root = $xml->documentElement;
      $items = $root->getElementsByTagName('Valute');
      foreach ($items as $item) {
        $code = $item->getElementsByTagName('CharCode')->item(0)->nodeValue;
        $curs = $item->getElementsByTagName('Value')->item(0)->nodeValue;
        $nominal = $item->getElementsByTagName('Nominal')->item(0)->nodeValue;
        $this->list[$code] = floatval(str_replace(',', '.', $curs));
        $this->list_nom[$code] = floatval(str_replace(',', '.', $nominal));
      }
      return TRUE;
    }
    else
      return FALSE;
  }

  public function get($cur) {
    return isset($this->list[$cur]) ? $this->list[$cur] : 0;
  }

  public function get_nom($nom) {
    return isset($this->list_nom[$nom]) ? $this->list_nom[$nom] : 0;
  }

  public function converter($price, $existing_currency, $preferred_currency) {
    if ($this->load()) {
      $nominal_exis = $this->get_nom($existing_currency);
      $nominal_pref = $this->get_nom($preferred_currency);
      if($existing_currency == $preferred_currency) {
        return $price;
      }

      if ($existing_currency != 'RUB') {
        if ($preferred_currency != 'RUB') {
          $currency_exis = $this->get($existing_currency) / $nominal_exis;
          $currency_pref = $this->get($preferred_currency) / $nominal_pref;
          $currency = ($currency_exis/$currency_pref) * $price;
          $currency = round($currency, 2);
        }
        else {
          $currency_exis = $this->get($existing_currency) / $nominal_exis;
          $currency = $currency_exis * $price;
        }
      }
      else {
        $currency_pref = $this->get($preferred_currency) / $nominal_pref;
        $currency = $price / $currency_pref;
      }
    }

    return round($currency, 2);
  }
}
