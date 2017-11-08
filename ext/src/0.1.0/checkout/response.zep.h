
extern zend_class_entry *checkout_response_ce;

ZEPHIR_INIT_CLASS(Checkout_Response);

PHP_METHOD(Checkout_Response, __construct);
PHP_METHOD(Checkout_Response, validate);
PHP_METHOD(Checkout_Response, setRequestParams);
PHP_METHOD(Checkout_Response, getAlgorithm);
PHP_METHOD(Checkout_Response, setAlgorithm);
PHP_METHOD(Checkout_Response, getMac);
PHP_METHOD(Checkout_Response, setMac);
PHP_METHOD(Checkout_Response, getMerchantSecret);
PHP_METHOD(Checkout_Response, setMerchantSecret);
PHP_METHOD(Checkout_Response, getPayment);
PHP_METHOD(Checkout_Response, setPayment);
PHP_METHOD(Checkout_Response, getReference);
PHP_METHOD(Checkout_Response, setReference);
PHP_METHOD(Checkout_Response, getStamp);
PHP_METHOD(Checkout_Response, setStamp);
PHP_METHOD(Checkout_Response, getStatus);
PHP_METHOD(Checkout_Response, setStatus);
PHP_METHOD(Checkout_Response, getVersion);
PHP_METHOD(Checkout_Response, setVersion);

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, merchant_secret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setrequestparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setmac, 0, 0, 1)
	ZEND_ARG_INFO(0, mac)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setmerchantsecret, 0, 0, 1)
	ZEND_ARG_INFO(0, merchant_secret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setpayment, 0, 0, 1)
	ZEND_ARG_INFO(0, payment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setreference, 0, 0, 1)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setstamp, 0, 0, 1)
	ZEND_ARG_INFO(0, stamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_response_setversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(checkout_response_method_entry) {
	PHP_ME(Checkout_Response, __construct, arginfo_checkout_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Checkout_Response, validate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setRequestParams, arginfo_checkout_response_setrequestparams, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getAlgorithm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setAlgorithm, arginfo_checkout_response_setalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getMac, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setMac, arginfo_checkout_response_setmac, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getMerchantSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setMerchantSecret, arginfo_checkout_response_setmerchantsecret, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getPayment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setPayment, arginfo_checkout_response_setpayment, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getReference, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setReference, arginfo_checkout_response_setreference, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getStamp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setStamp, arginfo_checkout_response_setstamp, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getStatus, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setStatus, arginfo_checkout_response_setstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Response, setVersion, arginfo_checkout_response_setversion, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
