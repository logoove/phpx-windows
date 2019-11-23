
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "fun.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *fun_fun_ce;

ZEND_DECLARE_MODULE_GLOBALS(fun)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(fun)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Fun_Fun);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(fun)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_fun_globals *fun_globals TSRMLS_DC)
{
	fun_globals->initialized = 0;

	/* Memory options */
	fun_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	fun_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	fun_globals->cache_enabled = 1;

	/* Recursive Lock */
	fun_globals->recursive_lock = 0;

	/* Static cache */
	memset(fun_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_fun_globals *fun_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(fun)
{
	zend_fun_globals *fun_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	fun_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(fun_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(fun_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(fun)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(fun)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_FUN_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_FUN_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_FUN_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_FUN_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_FUN_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(fun)
{
	php_zephir_init_globals(fun_globals TSRMLS_CC);
	php_zephir_init_module_globals(fun_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(fun)
{
	
}


zend_function_entry php_fun_functions[] = {
	ZEND_FE_END

};

zend_module_entry fun_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_FUN_EXTNAME,
	php_fun_functions,
	PHP_MINIT(fun),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(fun),
#else
	NULL,
#endif
	PHP_RINIT(fun),
	PHP_RSHUTDOWN(fun),
	PHP_MINFO(fun),
	PHP_FUN_VERSION,
	ZEND_MODULE_GLOBALS(fun),
	PHP_GINIT(fun),
	PHP_GSHUTDOWN(fun),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(fun),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_FUN
ZEND_GET_MODULE(fun)
#endif
