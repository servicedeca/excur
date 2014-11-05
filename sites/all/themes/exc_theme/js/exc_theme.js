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
      $('#external-events .print-calendar').click(function() {
        window.print();
      });

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

  Drupal.behaviors.excurOrderOfferForm = {
    attach: function(context, settings) {
      $('#excur-offer-order').once(function() {
        $(this).click(function() {
          $('#excur-offer-order-form #edit-submit').click();
        });
      });
    }
  };

  Drupal.behaviors.excurOfferForm = {
    attach: function(context, settings) {
      $('.excur-offer-offer-form').once(function() {
        $('i.plus, i.minus', this).click(function() {
          var $this = $(this);
          var $input = $this.closest('div.form-item').find('input.form-text');
          var inputVal = $input.val();

          if ($this.hasClass('minus') && inputVal > 0) {
            $input.val(inputVal - 1);
          }
          else if ($this.hasClass('plus') && inputVal < 99) {
            $input.val(parseInt(inputVal) + 1);
          }
          $input.trigger('change');
        });

        $('input[id^=edit-tickets-]', this).change(function() {
          var $this = $(this);
          var $totalSum = $this.closest('div.tickets').find('span.total-price');
          var inputVal = $this.val();

          // Check if value isn't numeric
          if (!isFinite(String(inputVal)) || inputVal < 0 || inputVal > 99) {
            $this.val(0);
          }

          var totalSum = 0;
          $this.closest('form').find('div[class*=form-item-tickets-]').each(function(key, value) {
            var $div = $(value);
            totalSum += parseInt($div.find('input').val()) * $div.find('span.one-price').text();
          });
          $totalSum.html(Number(totalSum.toFixed(2)));
        });
      });
    }
  };

  Drupal.behaviors.excurProfileForm = {
    attach: function(context, settings) {
      $('#user-profile-form').once(function() {
        var $items = $('.user-guide-company');
        if ($(this).find(':radio[name=guide_company]:checked').val() == 2) {
          $items.show();
        }

        $('#edit-guide-company').change(function() {
          var value = $(this).find(':radio[name=guide_company]:checked').val();

          if (value == 2) {
            $items.show();
          }
          else {
            $items.hide();
          }
        });
      });
    }
  };

  Drupal.behaviors.excurComment = {
    attach: function(context, settings) {
      $('#excur-comment-rating-form').once().submit(function(e) {
        e.preventDefault();
        $.ajax({
          url: '/excur/comment_rating',
          type: 'POST',
          data: {
            number: $('#edit-number').val(),
            node: $('#number-node').val()
          },
          success: function(response) {
            if (response == false) {
              alert(Drupal.t('Wrong number!'));
            }
            else {
              var $comment_rating = $('#comment_rating');
              $comment_rating.html(response);
              Drupal.attachBehaviors($comment_rating, Drupal.settings);
            }
          },
          error: function(response) {
            alert('false');
          }
        });
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
