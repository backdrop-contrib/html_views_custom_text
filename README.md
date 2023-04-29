# HTML Custom Text Views Field

Provides a Views Global Custom Text field that can accept HTML tags as specified in the field configuration.

Unlike Drupal 7, Backdrop's Custom Text field only allows a limited number of HTML tags. The field provided by this module
allows users with the appropriate permission to specify allowed tags.

## Installation
- Install this module and its dependencies using the official [Backdrop CMS instructions](https://backdropcms.org/guide/modules)

## Instructions
The Views field provided by this module is available in the "Global" field group. By default, this field will accept the following HTML tags:
`<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>`

You can specify additional tags in the field configuration UI, under the text area "Allowed HTML tags". Only users with permission
"Administer HTML Custom Text Views field".

## Credits
- Created for Backdrop CMS by [argiepiano](https://github.com/argiepiano)

## Current maintainers
- [argiepiano](https://github.com/argiepiano)
- Seeking co-maintainers

## License
This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
