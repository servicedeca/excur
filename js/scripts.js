/***************** Waypoints ******************/

jQuery(document).ready(function() {

  jQuery('.wp5').waypoint(function() {
      jQuery('.wp5').addClass('animated fadeInUp');
    },
    {
      offset: '75%',
      triggerOnce: true
    });

});
