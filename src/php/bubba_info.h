#ifndef PHP_BUBBAINFO_H
#define PHP_BUBBAINFO_H 1

#define PHP_BUBBAINFO_VERSION "1.0"
#define PHP_BUBBAINFO_EXTNAME "bubba_info"

PHP_FUNCTION(getHWType);
PHP_FUNCTION(isB1);
PHP_FUNCTION(isB2);
PHP_FUNCTION(isB3);

extern zend_module_entry bubba_info_module_entry;
#define phpext_bubbainfo_ptr &bubbainfo_module_entry

#endif
