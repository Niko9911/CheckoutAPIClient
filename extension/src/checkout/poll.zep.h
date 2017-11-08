
extern zend_class_entry *checkout_poll_ce;

ZEPHIR_INIT_CLASS(Checkout_Poll);

PHP_METHOD(Checkout_Poll, __construct);
PHP_METHOD(Checkout_Poll, setDefaultValues);
PHP_METHOD(Checkout_Poll, setPaymentData);
PHP_METHOD(Checkout_Poll, calculateMac);
PHP_METHOD(Checkout_Poll, getVersion);
PHP_METHOD(Checkout_Poll, setVersion);
PHP_METHOD(Checkout_Poll, getStamp);
PHP_METHOD(Checkout_Poll, setStamp);
PHP_METHOD(Checkout_Poll, getReference);
PHP_METHOD(Checkout_Poll, setReference);
PHP_METHOD(Checkout_Poll, getMerchantId);
PHP_METHOD(Checkout_Poll, setMerchantId);
PHP_METHOD(Checkout_Poll, getMerchantSecret);
PHP_METHOD(Checkout_Poll, setMerchantSecret);
PHP_METHOD(Checkout_Poll, getAmount);
PHP_METHOD(Checkout_Poll, setAmount);
PHP_METHOD(Checkout_Poll, getCurrency);
PHP_METHOD(Checkout_Poll, setCurrency);
PHP_METHOD(Checkout_Poll, getFormat);
PHP_METHOD(Checkout_Poll, setFormat);
PHP_METHOD(Checkout_Poll, getAlgorithm);
PHP_METHOD(Checkout_Poll, setAlgorithm);

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, merchantId)
	ZEND_ARG_INFO(0, merchantSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setpaymentdata, 0, 0, 3)
	ZEND_ARG_INFO(0, stamp)
	ZEND_ARG_INFO(0, reference)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setstamp, 0, 0, 1)
	ZEND_ARG_INFO(0, stamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setreference, 0, 0, 1)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setmerchantid, 0, 0, 1)
	ZEND_ARG_INFO(0, merchantId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setmerchantsecret, 0, 0, 1)
	ZEND_ARG_INFO(0, merchantSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setamount, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setcurrency, 0, 0, 1)
	ZEND_ARG_INFO(0, currency)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_poll_setalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(checkout_poll_method_entry) {
	PHP_ME(Checkout_Poll, __construct, arginfo_checkout_poll___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Checkout_Poll, setDefaultValues, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Checkout_Poll, setPaymentData, arginfo_checkout_poll_setpaymentdata, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, calculateMac, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setVersion, arginfo_checkout_poll_setversion, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getStamp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setStamp, arginfo_checkout_poll_setstamp, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getReference, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setReference, arginfo_checkout_poll_setreference, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getMerchantId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setMerchantId, arginfo_checkout_poll_setmerchantid, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getMerchantSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setMerchantSecret, arginfo_checkout_poll_setmerchantsecret, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getAmount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setAmount, arginfo_checkout_poll_setamount, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getCurrency, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setCurrency, arginfo_checkout_poll_setcurrency, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setFormat, arginfo_checkout_poll_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, getAlgorithm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Poll, setAlgorithm, arginfo_checkout_poll_setalgorithm, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
