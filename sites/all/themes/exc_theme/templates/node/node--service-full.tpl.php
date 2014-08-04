<?php

/**
 * @file
 */
?>
<article id="node-<?php print $node->nid; ?>" class="contextual-links-region">
  <?php print render($title_prefix); ?>
  <h1>
    <?php print $title; ?>
  </h1>
  <?php print render($title_suffix); ?>
  <?php if (!empty($images)): ?>
    <div class="fotorama" data-nav="thumbs" data-autoplay="true" data-keyboard="true" data-loop="true" data-swipe="true">
      <?php foreach($images as $image): ?>
        <?php print $image; ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <h2 class="node-description">
    <?php print t('Description'); ?>
  </h2>
  <?php hide($content['comments']); ?>
  <?php hide($content['links']); ?>
  <?php print render($content['body']); ?>
  <div class="row">
    <?php if (!empty($venue)): ?>
      <div class="span4">
        <h2 class="meeting"><?php print t('Venue') . ': '; ?></h2>
        <?php print $venue; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($meeting_time)): ?>
      <div class="span4">
        <h2 class="meeting"><?php print t('Time of meeting') . ': '; ?></h2>
        <?php print $meeting_time; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['field_included'])): ?>
      <div class="span4">
        <h2 class="included"><?php print t('Входит в стоимость') . ': '; ?></h2>
        <?php print render($content['field_included']); ?>
       </div>
    <?php endif; ?>
    <?php if (!empty($content['field_excluded'])): ?>
      <div class="span4">
        <h2 class="excluded"><?php print t('Не входит в стоимость') . ': '; ?></h2>
        <?php print render($content['field_excluded']).'<br>' ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['field_reservation_rules'])): ?>
      <div class="span4">
        <h2 class="meeting"><?php print t('Правила бронирования') . ': '; ?></h2>
        <p class="meeting"><?php print t('Билет на экскурсию можно забронировать:');?><p>
        <?php print render($content['field_reservation_rules'][0]['entity']['field_collection_item']).'<br>'; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['field_cancellation'])): ?>
      <div class="span4">
        <h2 class="meeting"><?php print t('Правила отмены бронирования') . ': '; ?></h2>
          <?php print render($content['field_cancellation']).'<br>'; ?>
      </div>
    <?php endif; ?>
  </div>
  <h2 id="reservation" class="node-description">
    <?php print t('Reservation'); ?>
  </h2>
</article>
