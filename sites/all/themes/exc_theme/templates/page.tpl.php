<?php
/**
 * @file
 */
?>
<div class="space30"></div>
<div class="content">
  <div class="container site">
    <div class="row">
      <div class="span12">
        <header>
          <div class="row">
            <?php if (!empty($logo)): ?>
              <div class="span4">
                <?php print l($logo, '', array('html' => TRUE)); ?>
              </div>
            <?php endif; ?>

            <?php if (!empty($search_form)): ?>
              <div class="span3">
                <?php print render($search_form); ?>
              </div>
            <?php endif; ?>

            <?php if (!empty($language_switcher)): ?>
              <div class="span2">
                <?php print render($language_switcher); ?>
              </div>
            <?php endif; ?>

            <?php if (!empty($currency_switcher)): ?>
              <div class="span3">
                <?php print render($currency_switcher); ?>
              </div>
            <?php endif; ?>
          </div>
          <?php if (!empty($main_menu)): ?>
            <div class="row">
              <div class="span12">
                <nav class="navbar">
                  <?php if (!empty($user_links)): ?>
                    <?php print $user_links; ?>
                  <?php endif; ?>
                </nav>
              </div>
            </div>
          <?php endif; ?>
        </header>


        <?php if (!empty($messages)): ?>
          <div class="space10"></div>
          <?php print $messages; ?>
        <?php endif; ?>

        <?php if (!empty($breadcrumb)): ?>
          <div class="space10"></div>
          <?php print $breadcrumb; ?>
        <?php endif; ?>

        <div id="content">
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?>
            <div class="tabs">
              <?php print render($tabs); ?>
            </div>
          <?php endif; ?>
          <?php if (!empty($action_links)): ?>
            <ul class="action-links">
              <?php print render($action_links); ?>
            </ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
        </div>
      </div>
    </div>
  </div>

  <div id="footer" class="container">
    <div id="footer-menu">
      <?php print render($footer_menu); ?>
    </div>
  </div>
  <div class="space30"></div>
</div>
