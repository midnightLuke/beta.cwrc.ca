# Islandora CWRC Document [![Build Status](https://travis-ci.org/discoverygarden/islandora_cwrc_document.png?branch=7.x)](https://travis-ci.org/discoverygarden/islandora_cwrc_document)

## Introduction

Defines required objects needed to house the CWRC Writer's agnostic content.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora CWRC Writer](https://github.com/discoverygarden/islandora_cwrc_writer)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

The Islandora CWRC Document module defines three permissions that allow users to view, annotate and edit CWRC datastreams. These allow access to tabs on CWRC Document objects that load the CWRC-Writer into modes appropriate for each task.

It's important to note that because viewing and editing datastreams in the CWRC-Writer is done through the lens of Islandora REST, REST-related permissions will also have to be given to users with the above three permissions. Specifically:

- Users with the 'view' permission should also be given the Islandora REST 'View objects' and 'View datastreams' permissions.
- Users with the 'annotate' and/or 'edit' permissions should also be given the Islandora REST 'Modify datastreams' permission.

## Troubleshooting/Issues

Having problems or solved a problem? Contact [discoverygarden](http://support.discoverygarden.ca).

## Maintainers/Sponsors

Current maintainers:

* [discoverygarden](http://www.discoverygarden.ca)

## Development

If you would like to contribute to this module, please check out our helpful
[Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers)
info, [Developers](http://islandora.ca/developers) section on Islandora.ca and
contact [discoverygarden](http://support.discoverygarden.ca).

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
