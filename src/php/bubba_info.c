#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "bubba_info.h"
#include <bubba_info.h>

ZEND_BEGIN_ARG_INFO(noargs, 0) 
ZEND_END_ARG_INFO()

static function_entry bubbainfo_functions[] = {
    PHP_FE(getHWType, noargs)
    PHP_FE(isB1, noargs)
    PHP_FE(isB2, noargs)
    PHP_FE(isB3, noargs)
    PHP_FE_END
};

zend_module_entry bubbainfo_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_BUBBAINFO_EXTNAME,
    bubbainfo_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_BUBBAINFO_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_BUBBAINFO
ZEND_GET_MODULE(bubbainfo)
#endif

PHP_FUNCTION(getHWType)
{
    RETURN_LONG(getHWType());
}

PHP_FUNCTION(isB1)
{
    RETURN_BOOL(isB1());
}

PHP_FUNCTION(isB2)
{
    RETURN_BOOL(isB2());
}

PHP_FUNCTION(isB3)
{
    RETURN_BOOL(isB3());
}
