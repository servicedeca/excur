<?php
/**
 * @file
 * Template for node Service in full view mode.
 */
?>
<?php if (!empty($images)): ?>
  <div class="col-xs-12 excur-slider">
    <div class="fotorama" data-autoplay="true" data-nav="none" data-width="720" data-ratio="720/479" data-max-width="100%">
      <?php foreach ($images as $image): ?>
        <?php print $image; ?>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif;?>
<div class="col-xs-12 excur-information">
  <div class="excur-information-text">
    <?php print render($content['body']); ?>
  </div>
</div>
<?php if (!empty($venue) || !empty($meeting_time)): ?>
  <div class="col-xs-12 excur-container">
    <?php if (!empty($venue)): ?>
      <div class="col-xs-6 excur-place-block">
        <div class="col-xs-6 excur-place-title">
          <?php print t('Starting place of the excursion');?>
        </div>
        <div class="col-xs-6 excur-place-place">
          <?php print $venue; ?>
        </div>
      </div>
    <?php endif; ?>
    <?php if (!empty($meeting_time)): ?>
      <div class="col-xs-6 excur-time-block">
        <div class="col-xs-6 excur-time-title">
          <?php print t('Time the excursion starts'); ?>
        </div>
        <div class="col-xs-6 excur-time-time">
          <?php print $meeting_time; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
<?php if (!empty($content['field_included']) || !empty($content['field_excluded'])): ?>
  <div class="col-xs-12 excur-container">
    <?php if (!empty($content['field_included'])): ?>
      <div class="col-xs-6 excur-place-block">
        <div class="col-xs-6 excur-place-title">
          <?php print t('Included in the price'); ?>
        </div>
        <div class="col-xs-6 excur-include">
          <?php print render($content['field_included']); ?>
        </div>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['field_excluded'])): ?>
      <div class="col-xs-6 excur-time-block">
        <div class="col-xs-6 excur-time-title">
          <?php print t('Not included'); ?>
        </div>
        <div class="col-xs-6 excur-include">
          <?php print render($content['field_excluded']); ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
