# Islandora Saved Searches

## Introduction

Adds the ability to save searches on the Islandora SOLR index provided by the
Islandora SOLR module.  

## Requirements

- [Islandora](https://github.com/islandora/islandora)
- [Islandora SOLR Search](https://github.com/Islandora/islandora_solr_search)

## Installation

Enable the module and place the "Islandora save search" block in any region on
the active theme.  This block will only appear on results screens and allows
users to save searches which will then appear at 
`user/[uid]/islandora-saved-searches`.

## Configuration

There are two permissions associated with this, the "save islandora searches" 
permission allows users to see the "Islandora save search" block, view their 
saved searches in the "Islandora current users saved searches" block and access
their saved searches at `user/[uid]/islandora-saved-searches`.  The "administer 
islandora saved searches" permission allows access to any users saved searches.

## Alternatives

The [cwrc_workflow](https://github.com/discoverygarden/cwrc_workflow) module
provides a reports interface that has somewhat similar capabilities, in that it
can create canned reports that are essentially saved searches, however, the
interface for this is a little intimidating and not end-user friendly.  This
module is designed to be simple and end-user friendly.

The drupal [sarnia](https://www.drupal.org/project/sarnia) and
[search_api](https://www.drupal.org/project/search_api) modules provide a
powerful alternative to the core islandora solr module, which can then be 
combined with [search_api_saved_searches](https://www.drupal.org/project/search_api_saved_searches)
for a saved search solution, however, this would require not using the islandora
solr modules at all.

## Maintainers/Sponsors

Current maintainer:

- [Luke Bainbridge](https://github.com/midnightluke)

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
