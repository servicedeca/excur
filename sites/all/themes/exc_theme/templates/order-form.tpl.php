<div class="row-fluid">
  <div class="span10 order-template-content-bottom">
    <div class="row-fluid">
      <div class="span6 order-template-content-form1">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('Your contact details');?>
            </h1>
          </div>
          <div class="panel-body">
            <?php print render($form['name']);?>
            <?php print render($form['email']);?>
            <?php print render($form['phone']);?>
          </div>
        </div>
      </div>
      <div class="span6 order-template-content-form2">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('The contact details of the tourist'); ?>
            </h1>
          </div>
          <div class="panel-body">
            <?php print render($form['tourist_name']);?>
            <?php print render($form['tourist_email']);?>
            <?php print render($form['tourist_phone']);?>
          </div>
        </div>
      </div>
    </div>
    <div class="row-fluid">
      <div class="span6 order-template-content-form3">
        <div class="panel panel-default">
          <div class="panel-heading pay-h1">
            <h1>
              <?php print t('Parameters of your order'); ?>
            </h1>
          </div>
          <div class="panel-body">
            <?php print render($form['venue']); ?>
            <?php print render($form['language']); ?>
          </div>
        </div>
      </div>
      <div class="span5 order-template-content-forms">
        <?php print render($form['submit']); ?>
      </div>

    </div>
  </div>

  <?php print drupal_render_children($form); ?>
</div>