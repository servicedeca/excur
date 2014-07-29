<div class="space30"></div>
<div class="side-block guide-block">
  <?php print $guide_image; ?>
  <div class="name">
    <?php print $guide; ?>
  </div>
  <?php if(!empty($ask_guide)): ?>
    <div class="ask-guide">
      <?php print $ask_guide; ?>
    </div>
  <?php endif; ?>
  <div class="guide-rating">
    <?php print $rating; ?>
  </div>
  <?php if (!empty($certified)): ?>
    <p class="certified">
      <i class="fa fa-thumbs-up"></i>
      <?php print $certified; ?>
    </p>
  <?php endif; ?>
</div>
