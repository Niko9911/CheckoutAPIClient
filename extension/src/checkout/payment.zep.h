
extern zend_class_entry *checkout_payment_ce;

ZEPHIR_INIT_CLASS(Checkout_Payment);

PHP_METHOD(Checkout_Payment, __construct);
PHP_METHOD(Checkout_Payment, setDefaultValues);
PHP_METHOD(Checkout_Payment, setOrderData);
PHP_METHOD(Checkout_Payment, setCustomerData);
PHP_METHOD(Checkout_Payment, setData);
PHP_METHOD(Checkout_Payment, setUrls);
PHP_METHOD(Checkout_Payment, calculateMac);
PHP_METHOD(Checkout_Payment, getAddress);
PHP_METHOD(Checkout_Payment, setAddress);
PHP_METHOD(Checkout_Payment, getAlgorithm);
PHP_METHOD(Checkout_Payment, setAlgorithm);
PHP_METHOD(Checkout_Payment, getAmount);
PHP_METHOD(Checkout_Payment, setAmount);
PHP_METHOD(Checkout_Payment, getCancelUrl);
PHP_METHOD(Checkout_Payment, setCancelUrl);
PHP_METHOD(Checkout_Payment, getContent);
PHP_METHOD(Checkout_Payment, setContent);
PHP_METHOD(Checkout_Payment, getCountry);
PHP_METHOD(Checkout_Payment, setCountry);
PHP_METHOD(Checkout_Payment, getCurrency);
PHP_METHOD(Checkout_Payment, setCurrency);
PHP_METHOD(Checkout_Payment, getDelayedUrl);
PHP_METHOD(Checkout_Payment, setDelayedUrl);
PHP_METHOD(Checkout_Payment, getDeliveryDate);
PHP_METHOD(Checkout_Payment, setDeliveryDate);
PHP_METHOD(Checkout_Payment, getDevice);
PHP_METHOD(Checkout_Payment, setDevice);
PHP_METHOD(Checkout_Payment, getFamilyName);
PHP_METHOD(Checkout_Payment, setFamilyName);
PHP_METHOD(Checkout_Payment, getFirstName);
PHP_METHOD(Checkout_Payment, setFirstName);
PHP_METHOD(Checkout_Payment, getLanguage);
PHP_METHOD(Checkout_Payment, setLanguage);
PHP_METHOD(Checkout_Payment, getMerchantId);
PHP_METHOD(Checkout_Payment, setMerchantId);
PHP_METHOD(Checkout_Payment, getMerchantSecret);
PHP_METHOD(Checkout_Payment, setMerchantSecret);
PHP_METHOD(Checkout_Payment, getMessage);
PHP_METHOD(Checkout_Payment, setMessage);
PHP_METHOD(Checkout_Payment, getPostOffice);
PHP_METHOD(Checkout_Payment, setPostOffice);
PHP_METHOD(Checkout_Payment, getPostcode);
PHP_METHOD(Checkout_Payment, setPostcode);
PHP_METHOD(Checkout_Payment, getReference);
PHP_METHOD(Checkout_Payment, setReference);
PHP_METHOD(Checkout_Payment, getRejectUrl);
PHP_METHOD(Checkout_Payment, setRejectUrl);
PHP_METHOD(Checkout_Payment, getReturnUrl);
PHP_METHOD(Checkout_Payment, setReturnUrl);
PHP_METHOD(Checkout_Payment, getStamp);
PHP_METHOD(Checkout_Payment, setStamp);
PHP_METHOD(Checkout_Payment, getType);
PHP_METHOD(Checkout_Payment, setType);
PHP_METHOD(Checkout_Payment, getVersion);
PHP_METHOD(Checkout_Payment, setVersion);

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, merchantId)
	ZEND_ARG_INFO(0, merchantSecret)
	ZEND_ARG_INFO(0, allowSmallPurchases)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setorderdata, 0, 0, 5)
	ZEND_ARG_INFO(0, stamp)
	ZEND_ARG_INFO(0, amount)
	ZEND_ARG_INFO(0, reference)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_OBJ_INFO(0, deliveryDate, Checkout\\DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setcustomerdata, 0, 0, 7)
	ZEND_ARG_INFO(0, firstName)
	ZEND_ARG_INFO(0, familyName)
	ZEND_ARG_INFO(0, address)
	ZEND_ARG_INFO(0, postcode)
	ZEND_ARG_INFO(0, postOffice)
	ZEND_ARG_INFO(0, country)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_seturls, 0, 0, 1)
	ZEND_ARG_INFO(0, returnUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setaddress, 0, 0, 1)
	ZEND_ARG_INFO(0, address)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setamount, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setcancelurl, 0, 0, 1)
	ZEND_ARG_INFO(0, cancelUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setcountry, 0, 0, 1)
	ZEND_ARG_INFO(0, country)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setcurrency, 0, 0, 1)
	ZEND_ARG_INFO(0, currency)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setdelayedurl, 0, 0, 1)
	ZEND_ARG_INFO(0, delayedUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_getdeliverydate, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setdeliverydate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, deliveryDate, Checkout\\DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setdevice, 0, 0, 1)
	ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setfamilyname, 0, 0, 1)
	ZEND_ARG_INFO(0, familyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setfirstname, 0, 0, 1)
	ZEND_ARG_INFO(0, firstName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setlanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setmerchantid, 0, 0, 1)
	ZEND_ARG_INFO(0, merchantId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setmerchantsecret, 0, 0, 1)
	ZEND_ARG_INFO(0, merchantSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setpostoffice, 0, 0, 1)
	ZEND_ARG_INFO(0, postOffice)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setpostcode, 0, 0, 1)
	ZEND_ARG_INFO(0, postcode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setreference, 0, 0, 1)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setrejecturl, 0, 0, 1)
	ZEND_ARG_INFO(0, rejectUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setreturnurl, 0, 0, 1)
	ZEND_ARG_INFO(0, returnUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setstamp, 0, 0, 1)
	ZEND_ARG_INFO(0, stamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_checkout_payment_setversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(checkout_payment_method_entry) {
	PHP_ME(Checkout_Payment, __construct, arginfo_checkout_payment___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Checkout_Payment, setDefaultValues, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Checkout_Payment, setOrderData, arginfo_checkout_payment_setorderdata, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setCustomerData, arginfo_checkout_payment_setcustomerdata, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setData, arginfo_checkout_payment_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setUrls, arginfo_checkout_payment_seturls, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, calculateMac, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getAddress, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setAddress, arginfo_checkout_payment_setaddress, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getAlgorithm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setAlgorithm, arginfo_checkout_payment_setalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getAmount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setAmount, arginfo_checkout_payment_setamount, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getCancelUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setCancelUrl, arginfo_checkout_payment_setcancelurl, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setContent, arginfo_checkout_payment_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getCountry, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setCountry, arginfo_checkout_payment_setcountry, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getCurrency, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setCurrency, arginfo_checkout_payment_setcurrency, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getDelayedUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setDelayedUrl, arginfo_checkout_payment_setdelayedurl, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getDeliveryDate, arginfo_checkout_payment_getdeliverydate, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setDeliveryDate, arginfo_checkout_payment_setdeliverydate, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getDevice, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setDevice, arginfo_checkout_payment_setdevice, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getFamilyName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setFamilyName, arginfo_checkout_payment_setfamilyname, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getFirstName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setFirstName, arginfo_checkout_payment_setfirstname, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getLanguage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setLanguage, arginfo_checkout_payment_setlanguage, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getMerchantId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setMerchantId, arginfo_checkout_payment_setmerchantid, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getMerchantSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setMerchantSecret, arginfo_checkout_payment_setmerchantsecret, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setMessage, arginfo_checkout_payment_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getPostOffice, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setPostOffice, arginfo_checkout_payment_setpostoffice, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getPostcode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setPostcode, arginfo_checkout_payment_setpostcode, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getReference, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setReference, arginfo_checkout_payment_setreference, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getRejectUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setRejectUrl, arginfo_checkout_payment_setrejecturl, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getReturnUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setReturnUrl, arginfo_checkout_payment_setreturnurl, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getStamp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setStamp, arginfo_checkout_payment_setstamp, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setType, arginfo_checkout_payment_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Checkout_Payment, setVersion, arginfo_checkout_payment_setversion, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
