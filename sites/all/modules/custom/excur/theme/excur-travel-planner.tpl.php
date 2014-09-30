<div class="row">
  <div class="span3">
    <?php if (!empty($user_menu)): ?>
      <?php print $user_menu; ?>
    <?php endif ?>
  </div>
  <div class="span9">
    <?php if (!empty($services)): ?>
      <div id="external-events">
        <h4>
          <?php print t('Selected tours'); ?>
        </h4>
        <?php foreach ($services as $service): ?>
          <div class="fc-event ui-draggable ui-draggable-handle">
            <?php print $service; ?>
          </div>
        <?php endforeach; ?>
        <p>
          <input type="checkbox" id="drop-remove">
          <label for="drop-remove">
            <?php print t('remove after drop'); ?>
          </label>
        </p>
        <p class="print-calendar">
          <?php print t('Print calendar.'); ?>
        </p>
      </div>
      <div id='calendar'></div>
      <div style='clear:both'></div>
    <?php else: ?>
      <?php print t('Your Travel Planner is empty.'); ?>
    <?php endif; ?>
  </div>
</div>
