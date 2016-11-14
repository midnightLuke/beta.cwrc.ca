CONTENTS OF THIS FILE
---------------------

* Introduction
* Features
* Requirements
* Installation
* Known problems
* Future plans
* Credits
* Recommended modules
* Similar projects

INTRODUCTION
------------

Sometimes you want a menu to be permanently visually-collapsed into a button,
which you must click on in order to see the items inside that menu.

FEATURES
--------

* Visually hide/show a menu when the end-user clicks on a glyph.
* Screenreaders see a fully-expanded menu and do not see the clickable glyph, to
  reduce confusion and save time by avoiding unnecessary interaction.
* Simple HTML, CSS, and JavaScript to make customization easier.

REQUIREMENTS
------------

Menu (in Drupal core)

INSTALLATION
------------

1. Download and install the menu_button project.

   See https://www.drupal.org/node/895232 for further information.

2. Go to the block administration page at Administration -> Structure -> Blocks.
   Look for blocks titled "Menu button: $menu_name". Move the menu button blocks
   that correspond with the menus you want to display as buttons into the
   appropriate regions.

   See https://www.drupal.org/node/1576530 for further information.

3. To change which character(s) the user has to click on to hide/show the menu,
   edit the block settings and change the "glyph" setting.

   See https://drupal.org/node/1576532 for further information.

KNOWN PROBLEMS
--------------

We don't know of any problems at this time, so if you find one, please let us
know by adding an issue!

FUTURE PLANS
------------

I'd like to make it so you could optionally upload an image to display as the
triggering element. If an image was used, then the glyph could be used as the
image's alternate text.

CREDITS
-------

Concept and coding by mparker17.

Sponsored by Digital Echidna (http://echidna.ca/).
