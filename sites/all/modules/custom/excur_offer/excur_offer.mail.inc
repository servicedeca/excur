<?php

class ExcurOfferMailSystem extends DefaultMailSystem {
  public function format(array $message) {
    $message['body'] = implode("\n\n", $message['body']);
    $message['body'] = drupal_wrap_mail($message['body']);
    return $message;
  }
}
