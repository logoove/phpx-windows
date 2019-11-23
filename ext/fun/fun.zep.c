
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exit.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Fun_Fun) {

	ZEPHIR_REGISTER_CLASS(Fun, Fun, fun, fun, fun_fun_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Fun_Fun, dump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *t, t_sub, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&t_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &t);



	ZEPHIR_CALL_FUNCTION(&_0, "print_r", NULL, 1, t, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<pre>", &_0, "</pre>");
	zend_print_zval(&_1, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Fun_Fun, json) {

	zval message;
	zval *code_param = NULL, *message_param = NULL, *list = NULL, list_sub, *total = NULL, total_sub, json1, _0, _1;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&list_sub);
	ZVAL_UNDEF(&total_sub);
	ZVAL_UNDEF(&json1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&message);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &code_param, &message_param, &list, &total);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "请求成功");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!list) {
		list = &list_sub;
		ZEPHIR_INIT_VAR(list);
		array_init(list);
	}
	if (!total) {
		total = &total_sub;
		ZEPHIR_INIT_VAR(total);
		ZVAL_LONG(total, 0);
	}


	ZEPHIR_INIT_VAR(&json1);
	zephir_create_array(&json1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, code);
	zephir_array_update_string(&json1, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&json1, SL("message"), &message, PH_COPY | PH_SEPARATE);
	if (!(ZEPHIR_IS_EMPTY(list))) {
		zephir_array_update_string(&json1, SL("list"), list, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(total))) {
		zephir_array_update_string(&json1, SL("total"), total, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-type: application/json");
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(&_0, &json1, zephir_get_intval(&_1) );
	ZEPHIR_MM_RESTORE();
	zephir_exit(&_0);
	ZEPHIR_MM_RESTORE();

}

