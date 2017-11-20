# Islandora BagIt Extension 

## Introduction

[Extenstion to Islandora BagIt](https://github.com/Islandora/islandora_bagit) allowing the storage of a Bag in a custom directory, instantiation from a Drush script, and providing a PID/timestamp for auditing


## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [Scholars' Lab BagItPHP library](https://github.com/scholarslab/BagItPHP)
* [Archive_Tar](http://pear.php.net/package/Archive_Tar)
* [Libraries](https://drupal.org/project/libraries)
* [Bagit Islandora](https://github.com/Islandora/islandora_bagit)

## Installation

To install the Islandora BagIt module:

1. Unzip this module into your site's modules directory as you would any other contrib module.


## Configuration

See [Bagit Islandora](https://github.com/Islandora/islandora_bagit)


### Permissions and security

This module is intended for users who have a fairly high level of permissions on a Drupal site. Because the goal is to package up all or some of the datastreams in an Islandora object, users who can create and download Bags should have access to those datastreams. However, the module does check the current users' access to a datastream before adding it to the Bag.

## Documentation

See [Bagit Islandora](https://github.com/Islandora/islandora_bagit)

### Usage

* Audit trail for all objects current user has view access (note some object may require admin access to view)
  * `services/bagit_extension/audit`
    * e.g., `services/bagit_extension/audit`
 
* Audit trail for all objects modified/created since a specified date/time; current user has view access (note some object may require admin access to view)
  * `services/bagit_extension/audit_by_date/YYYY-MM-DDTHH:MM:SS.xxxZ`
    * e.g., `services/bagit_extension/audit_by_date/2017-01-01T15:29:21.374Z`

* Download the Bag for the specified Fedora PID
  * `islandora/object/%islandora_object/manage/bagit_extension`
  * includes custom header elements:
    * CWRC-MODIFIED_DATE: modification timestamp of the Fedora Object - date/time with timezone
      * e.g., CWRC-MODIFIED_DATE: "2016-12-21T20:14:23.888Z"
    * CWRC-CHECKSUM: checksum of the zip file included in the above response (also in the ETag) 
      * e.g., CWRC-CHECKSUM: "2e30758521f2ad9147d14df8463dd2cc"
    * CWRC-PID: persistent identifier from Fedora (UUID)
      * e.g., CWRC-PID: "cwrc:UUID"


* Drush script to create a bag for a given object


## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
