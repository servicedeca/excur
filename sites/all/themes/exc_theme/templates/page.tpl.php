<?php
/**
 * @file
 */
?>

<div class="menu">
  <div class="menu-wrapper">
    <?php if (!empty($logo)): ?>
      <?php print l($logo, '', array('html' => TRUE, 'attributes' => array('class' => array('navbar-brand')))); ?>
    <?php endif; ?>
    <div class="menu-content-center">
      <?php print render($search_form); ?>
    </div>
    <div class="menu-content-right">
      <div class="col-xs-2 head-border">
        <div class="curent1">
          <?php print render($language_switcher); ?>
        </div>
      </div>
      <div class="col-xs-2 head-border">
        <div class="curent">
          <?php print render($currency_switcher); ?>
        </div>
      </div>
      <div class="col-xs-4  phone-small-res">
        <a class="btn head-reg" data-toggle="modal" data-target=".bs-example-modal-md">
          <?php print t('Login or <br> Create account');?>
        </a>
      </div>
      <div class="col-xs-4 head-border-phone">
        <p class="head-phone">
          <i class="fa fa-phone span-phone"></i>
          <a href="tel:<?php print $contact_phone; ?>" title="<?php print t('Contact us'); ?>">
            <?php print $contact_phone; ?>
          </a>
        </p>
      </div>
    </div>
  </div>
</div>

<?php if (user_is_anonymous()): ?>
  <div class="modal fade bs-example-modal-md in" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="false">
    <div class="modal-dialog modal-md center-modal">
      <div class="modal-content modal-registration">
        <ul id="menureg">
          <li class="reg-item reg-active">
            <a href="#homes" data-toggle="tab">
              <?php print t('Register'); ?>
            </a>
          </li>
          <li class="reg-item">
            <a href="#profile" data-toggle="tab">
              <?php print t('Login'); ?>
            </a>
          </li>
        </ul>
        <div id="myTabContent" class="tab-content">
          <div class="tab-pane fade active in" id="homes">
            <?php print render($register_form); ?>
          </div>
          <div class="tab-pane fade" id="profile">
            <?php print render($login_form); ?>
          </div>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($messages)): ?>
  <?php print $messages; ?>
<?php endif; ?>
<?php print render($page['content']); ?>

<footer class="text-center z-index">
  <div class="part">
    <div class="container">
      <div class="row">
        <div class="col-lg-3">
          <p class="text_part"><?php print t('Partner'); ?></p>
        </div>
        <div class="col-lg-3">
          <p class="text_part"><?php print t('Partner'); ?></p>
        </div>
        <div class="col-lg-3">
          <p class="text_part"><?php print t('Partner'); ?></p>
        </div>
        <div class="col-lg-3">
          <p class="text_part"><?php print t('Partner'); ?></p>
        </div>
      </div>
    </div>
  </div>

  <div class="footer-above z-index">
    <div class="container">
      <div class="row">
        <?php foreach ($footer_menu as $key => $item): ?>
          <div class="footer-col col-md-4">
            <h3>
              <?php print $footer_menu_title[$key]; ?>
            </h3>
            <?php if ($key == 1): ?>
              <ul class="list-inline">
            <?php else: ?>
              <ul>
            <?php endif; ?>
            <?php foreach ($item as $link): ?>
              <li>
                <?php print $link; ?>
              </li>
            <?php endforeach;?>
            </ul>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
  <div class="footer-below">
    <div class="container">
      <div class="row">
        <div class="col-lg-12">
          Copyright © Excursionline 2014
        </div>
      </div>
    </div>
  </div>
</footer>
