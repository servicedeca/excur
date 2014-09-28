(function ($) {

  Drupal.behaviors.excurSlider = {
    attach: function(context, settings) {
      $slider = $('.slider1');
      if ($slider[0] != undefined) {
        $slider.flexslider();
      }
    }
  };

  Drupal.behaviors.excurTextOnSlider = {
    attach: function(context, settings) {
      // Titles
      var $title = $('.title-wrapper');
      var $clSpan = $title.closest('[class^="span"]');
      var left = $title.width() * 100 / $clSpan.width() / 2;
      $title.css('left', 50 - left + '%');

      // Search form.
      var $form = $('#slider-search-form');
      var $closestSpan = $form.closest('[class^="span"]');
      left = $form.width() * 100 / $closestSpan.width() / 2;
      $form.css('left', 50 - left + '%');
    }
  };

  Drupal.behaviors.excurSearchIcon = {
    attach: function(context, settings) {
      $('.search-box a.search-icon').click(function(e) {
        e.preventDefault();

        $(this).closest('form').find('input[type="submit"]').click();
      });
    }
  };

  Drupal.behaviors.excurScrollTo = {
    attach: function(context, settings) {
      excurScrollTo('.do-offer button', '#reservation', 1000);
      excurScrollTo('.ask-guide button', '#message-guide', 1000);
    }
  };

  Drupal.behaviors.excurUserLinks = {
    attach: function(context, settings) {
      $('.navbar .nav.nav-right').once('user-links', function() {
        $('li a.active', this).parent().addClass('active');
      });
    }
  };

  Drupal.behaviors.excurServiceCategories = {
    attach: function(context, settings) {
      $('ul.list-a.categories').once('categories', function() {
        $('li', this).click(function() {
          var $this = $(this)
          var tid = $this.attr('id').split('-')[1];
          tid = tid == 0 ? 'All' : tid;
          $('ul.list-a.categories li.active').removeClass('active');
          $this.addClass('active');
          $('#views-exposed-form-content-city-service #edit-tid').val(tid);
          $('#views-exposed-form-content-city-service #edit-submit-content').click();
        })
      });
    }
  };

  Drupal.behaviors.excurSelect = {
    attach: function(context, settings) {
      var currency = $('#edit-currency');
      var language = $('#edit-languages');
      var city = $('.view-display-id-city_service select');
      var guide = $('.view-display-id-guide_service select');

      if(/Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
        currency.selectpicker('mobile');
        language.selectpicker('mobile');
        city.selectpicker('mobile');
        guide.selectpicker('mobile');
      }
      else {
        currency.selectpicker();
        language.selectpicker();
        city.selectpicker();
        guide.selectpicker();
      }

      currency.change(function() {
        $('#excur-currency-choice-form input[type="submit"]').click();
      });
      language.change(function() {
        location.href = $(this).val();
      });
    }
  };

  Drupal.behaviors.excurServiceOps = {
    attach: function(context, settings) {
      $('a.confirm-order').click(function(e) {
        e.preventDefault();

        var $this = $(this);
        var id = $this.data('id');
        $.get('/excur/offer/confirm/' + $this.data('id'), function(html) {
          $(".content_confirm" + id).html(html);
        });
      });

      $('a.confirm-reject').click(function(e) {
        e.preventDefault();

        var $this = $(this);
        var id = $this.data('id');

        $.get('/excur/offer/reject/' + $this.data('id'), function(html) {
            $('.content_confirm' + id).html(html);
        });
      });
    }
  };

  Drupal.behaviors.excurTravelPlanner = {
    attach: function(context, settings) {
      $('#external-events .fc-event').each(function() {
        var eventObject = {
          title: $.trim($(this).text())
        };

        $(this).data('eventObject', eventObject);
        $(this).draggable({
          zIndex: 999,
          revert: true,      // will cause the event to go back to its
          revertDuration: 0  //  original position after the drag
        });
      });

      $('#calendar').fullCalendar({
        header: {
          left: 'prev,next today',
          center: 'title',
          right: ''
        },
        editable: true,
        droppable: true,
        drop: function(date) {
          var originalEventObject = $(this).data('eventObject');
          var copiedEventObject = $.extend({}, originalEventObject);
          copiedEventObject.start = date;
          $('#calendar').fullCalendar('renderEvent', copiedEventObject, true);
          if ($('#drop-remove').is(':checked')) {
            $(this).remove();
          }
        }
      });
    }
  };

  function excurScrollTo(from, to, time) {
    $(from).click(function (){
      $('html, body').animate({
        scrollTop: $(to).offset().top
      }, time);
    });
  }

}(jQuery));
