
extern zend_class_entry *fun_fun_ce;

ZEPHIR_INIT_CLASS(Fun_Fun);

PHP_METHOD(Fun_Fun, dump);
PHP_METHOD(Fun_Fun, json);

ZEND_BEGIN_ARG_INFO_EX(arginfo_fun_fun_dump, 0, 0, 1)
	ZEND_ARG_INFO(0, t)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fun_fun_json, 0, 0, 0)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, list)
	ZEND_ARG_INFO(0, total)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(fun_fun_method_entry) {
	PHP_ME(Fun_Fun, dump, arginfo_fun_fun_dump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Fun_Fun, json, arginfo_fun_fun_json, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
