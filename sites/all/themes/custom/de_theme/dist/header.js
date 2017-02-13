jQuery(function($) {
  $("a.dropdown-toggle").click(function(e) {
    var thisMenu = $(this).parent();
    var status = thisMenu.hasClass("open");

    setMenu(thisMenu, !status);

    // Don't bother with hover-only menus
    if ($(this).hasClass("hover-menu") && !$(this).parent().parent().parent().hasClass("hamburger")) return;

    // close all open dropdowns
    $("a.dropdown-toggle").each(function(e) {
      $(this).parent().removeClass("open");
    });

    // It was closed, we want it open
    if (!status) thisMenu.addClass("open");

    // Stop it from propagating back to the document and getting closed again
    e.stopPropagation();
    return false;
  });
  $("ul.dropdown-menu").click(function(e) {
    // This prevents the next click event from being fired if the click happens within our container
    e.stopPropagation();
  });
  $(document).click(function(e) {
    // Close all open dropdown menus in the navbar
    closeMenus();
  });

  var closeHoverTimeout = 0;

  $("div#tabs a.dropdown-toggle").hover(function(e) {
    if ($(this).parent().parent().parent().hasClass("hamburger")) return;

    if (closeHoverTimeout != 0) clearTimeout(closeHoverTimeout);
    setMenu($(this).parent(), true);
  }).mouseleave(function(e) {
    if ($(this).parent().parent().parent().hasClass("hamburger")) return;

    closeHoverTimeout = setTimeout(closeMenus, 500);
  });
  $("div#tabs ul.dropdown-menu").mouseenter(function(e) {
    if (closeHoverTimeout != 0) clearTimeout(closeHoverTimeout);
  }).mouseleave(function(e) {
    if ($(this).parent().parent().parent().hasClass("hamburger")) return;

    closeHoverTimeout = setTimeout(closeMenus, 500);
  });

  function setMenu(thisMenu, open) {
    closeMenus();
    if (open) thisMenu.addClass("open");
  }

  function closeMenus() {
    if (closeHoverTimeout != 0) clearTimeout(closeHoverTimeout);
    $(".open").removeClass("open");
  }

});
