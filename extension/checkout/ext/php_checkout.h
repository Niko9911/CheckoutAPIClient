
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_CHECKOUT_H
#define PHP_CHECKOUT_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_CHECKOUT_NAME        "checkout"
#define PHP_CHECKOUT_VERSION     "0.1.0"
#define PHP_CHECKOUT_EXTNAME     "checkout"
#define PHP_CHECKOUT_AUTHOR      "Niko Grano <niko.grano@ironlions.fi>"
#define PHP_CHECKOUT_ZEPVERSION  "0.10.4"
#define PHP_CHECKOUT_DESCRIPTION "API client for the Finnish payment gateway Checkout Finland."



ZEND_BEGIN_MODULE_GLOBALS(checkout)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(checkout)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(checkout)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(checkout, v)
#else
	#define ZEPHIR_GLOBAL(v) (checkout_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_checkout_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(checkout_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(checkout_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def checkout_globals
#define zend_zephir_globals_def zend_checkout_globals

extern zend_module_entry checkout_module_entry;
#define phpext_checkout_ptr &checkout_module_entry

#endif
