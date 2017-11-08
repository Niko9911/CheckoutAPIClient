
extern zend_class_entry *checkout_client_ce;

ZEPHIR_INIT_CLASS(Checkout_Client);

PHP_METHOD(Checkout_Client, sendPayment);
PHP_METHOD(Checkout_Client, poll);
PHP_METHOD(Checkout_Client, postData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_client_sendpayment, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, payment, Checkout\\Payment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_client_poll, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, poll, Checkout\\Poll, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_client_postdata, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, postData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(checkout_client_method_entry) {
	PHP_ME(Checkout_Client, sendPayment, arginfo_checkout_client_sendpayment, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Client, poll, arginfo_checkout_client_poll, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Client, postData, arginfo_checkout_client_postdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
