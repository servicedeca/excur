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
          <div class="tab-pane fade" id="homes">
            <?php print render($register_form); ?>
          </div>
          <div class="tab-pane fade active in" id="profile">
            <?php print render($login_form); ?>
          </div>
        </div>
      </div>
    </div>
  <div>
<?php endif; ?>

<!--<div class="content">-->
<!--  <div class="container site">-->
<!--    <div class="row">-->
<!--      <div class="span12">-->
<!--        <header>-->
<!--          <div class="row">-->
<!--            --><?php //if (!empty($logo)): ?>
<!--              <div class="span4">-->
<!--                --><?php //print l($logo, '', array('html' => TRUE)); ?>
<!--              </div>-->
<!--            --><?php //endif; ?>
<!---->
<!--            --><?php //if (!empty($search_form)): ?>
<!--              <div class="span3">-->
<!--                --><?php //print render($search_form); ?>
<!--              </div>-->
<!--            --><?php //endif; ?>
<!---->
<!--            --><?php //if (!empty($language_switcher)): ?>
<!--              <div class="span2">-->
<!--                --><?php //print render($language_switcher); ?>
<!--              </div>-->
<!--            --><?php //endif; ?>
<!---->
<!--            --><?php //if (!empty($currency_switcher)): ?>
<!--              <div class="span3">-->
<!--                --><?php //print render($currency_switcher); ?>
<!--              </div>-->
<!--            --><?php //endif; ?>
<!--          </div>-->
<!--          --><?php //if (!empty($main_menu)): ?>
<!--            <div class="row">-->
<!--              <div class="span12">-->
<!--                <nav class="navbar">-->
<!--                  --><?php //if (!empty($user_links)): ?>
<!--                    --><?php //print $user_links; ?>
<!--                  --><?php //endif; ?>
<!--                </nav>-->
<!--              </div>-->
<!--            </div>-->
<!--          --><?php //endif; ?>
<!--        </header>-->
<!---->
<!---->
<!--        --><?php //if (!empty($messages)): ?>
<!--          <div class="space10"></div>-->
<!--          --><?php //print $messages; ?>
<!--        --><?php //endif; ?>
<!---->
<!--        --><?php //if (!empty($breadcrumb)): ?>
<!--          <div class="space10"></div>-->
<!--          --><?php //print $breadcrumb; ?>
<!--        --><?php //endif; ?>
<!---->
<!--        <div id="content">-->
<!--          --><?php //print render($title_prefix); ?>
<!--          --><?php //print render($title_suffix); ?>
<!--          --><?php //if ($tabs): ?>
<!--            <div class="tabs">-->
<!--              --><?php //print render($tabs); ?>
<!--            </div>-->
<!--          --><?php //endif; ?>
<!--          --><?php //if (!empty($action_links)): ?>
<!--            <ul class="action-links">-->
<!--              --><?php //print render($action_links); ?>
<!--            </ul>-->
<!--          --><?php //endif; ?>
<!--          --><?php //print render($page['content']); ?>
<!--        </div>-->
<!--      </div>-->
<!--    </div>-->
<!--  </div>-->
<!---->
<!--  <div id="footer" class="container">-->
<!--    <div id="footer-menu">-->
<!--      --><?php //print render($footer_menu); ?>
<!--    </div>-->
<!--  </div>-->
<!--  <div class="space30"></div>-->
<!--</div>-->
