
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "checkout.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *checkout_client_ce;
zend_class_entry *checkout_exceptions_amounttoolargeexception_ce;
zend_class_entry *checkout_exceptions_amountunderminimumexception_ce;
zend_class_entry *checkout_exceptions_currencynotsupportedexception_ce;
zend_class_entry *checkout_exceptions_macmismatchexception_ce;
zend_class_entry *checkout_exceptions_unsupportedalgorithmexception_ce;
zend_class_entry *checkout_exceptions_urltoolongexception_ce;
zend_class_entry *checkout_exceptions_variabletoolongexception_ce;
zend_class_entry *checkout_payment_ce;
zend_class_entry *checkout_poll_ce;
zend_class_entry *checkout_response_ce;

ZEND_DECLARE_MODULE_GLOBALS(checkout)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(checkout)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Checkout_Client);
	ZEPHIR_INIT(Checkout_Exceptions_AmountTooLargeException);
	ZEPHIR_INIT(Checkout_Exceptions_AmountUnderMinimumException);
	ZEPHIR_INIT(Checkout_Exceptions_CurrencyNotSupportedException);
	ZEPHIR_INIT(Checkout_Exceptions_MacMismatchException);
	ZEPHIR_INIT(Checkout_Exceptions_UnsupportedAlgorithmException);
	ZEPHIR_INIT(Checkout_Exceptions_UrlTooLongException);
	ZEPHIR_INIT(Checkout_Exceptions_VariableTooLongException);
	ZEPHIR_INIT(Checkout_Payment);
	ZEPHIR_INIT(Checkout_Poll);
	ZEPHIR_INIT(Checkout_Response);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(checkout)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_checkout_globals *checkout_globals TSRMLS_DC)
{
	checkout_globals->initialized = 0;

	/* Memory options */
	checkout_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	checkout_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	checkout_globals->cache_enabled = 1;

	/* Recursive Lock */
	checkout_globals->recursive_lock = 0;

	/* Static cache */
	memset(checkout_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_checkout_globals *checkout_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(checkout)
{

	zend_checkout_globals *checkout_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	checkout_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(checkout_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(checkout_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(checkout)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(checkout)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_CHECKOUT_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_CHECKOUT_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_CHECKOUT_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_CHECKOUT_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_CHECKOUT_ZEPVERSION);
	php_info_print_table_end();
	php_info_print_table_start();
	php_info_print_table_header(1, "Credits");
	php_info_print_table_end();
	php_info_print_table_start();
	php_info_print_table_header(2, "Tittle", "Author");
	php_info_print_table_row(2, "Translation to PHP-Extension", "Niko Grano =niko.grano@ironlions.fi=");
	php_info_print_table_row(2, "Original Library", "Matti Särkikoski =matti@checkout.fi=");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(checkout)
{
	php_zephir_init_globals(checkout_globals TSRMLS_CC);
	php_zephir_init_module_globals(checkout_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(checkout)
{

}


zend_function_entry php_checkout_functions[] = {
ZEND_FE_END

};

zend_module_entry checkout_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_CHECKOUT_EXTNAME,
	php_checkout_functions,
	PHP_MINIT(checkout),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(checkout),
#else
	NULL,
#endif
	PHP_RINIT(checkout),
	PHP_RSHUTDOWN(checkout),
	PHP_MINFO(checkout),
	PHP_CHECKOUT_VERSION,
	ZEND_MODULE_GLOBALS(checkout),
	PHP_GINIT(checkout),
	PHP_GSHUTDOWN(checkout),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_CHECKOUT
ZEND_GET_MODULE(checkout)
#endif
