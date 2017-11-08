
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Checkout_Poll) {

	ZEPHIR_REGISTER_CLASS(Checkout, Poll, checkout, poll, checkout_poll_method_entry, 0);

	/**
	 * @var string Payment version, currently always '0001' (AN 4)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("version"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Unique identifier for the payment (AN 20)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("stamp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("reference"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Merchant id (AN 20)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("merchantId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Secret merchant key
	 */
	zend_declare_property_null(checkout_poll_ce, SL("merchantSecret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Amount of payment in cents (10€ == 1000) (N 8)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("amount"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Currency used in payment. Currently only EUR is supported (AN 3)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("currency"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string format Currently only 1
	 */
	zend_declare_property_null(checkout_poll_ce, SL("format"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
	 */
	zend_declare_property_null(checkout_poll_ce, SL("algorithm"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 *	@param $merchantId
 *	@param $merchantSecret
 *
 */
PHP_METHOD(Checkout_Poll, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *merchantId, merchantId_sub, *merchantSecret, merchantSecret_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantId_sub);
	ZVAL_UNDEF(&merchantSecret_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &merchantId, &merchantSecret);



	zephir_update_property_zval(this_ptr, SL("merchantId"), merchantId);
	zephir_update_property_zval(this_ptr, SL("merchantSecret"), merchantSecret);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultvalues", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return $this
 */
PHP_METHOD(Checkout_Poll, setDefaultValues) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "0001");
	zephir_update_property_zval(this_ptr, SL("version"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 3);
	zephir_update_property_zval(this_ptr, SL("algorithm"), &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "EUR");
	zephir_update_property_zval(this_ptr, SL("currency"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_zval(this_ptr, SL("format"), &_1);
	RETURN_THIS();

}

/**
 * Set the Payment info
 *
 * @param $stamp
 * @param $reference
 * @param $amount
 * @return $this
 */
PHP_METHOD(Checkout_Poll, setPaymentData) {

	zval *stamp, stamp_sub, *reference, reference_sub, *amount, amount_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stamp_sub);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&amount_sub);

	zephir_fetch_params(0, 3, 0, &stamp, &reference, &amount);



	zephir_update_property_zval(this_ptr, SL("stamp"), stamp);
	zephir_update_property_zval(this_ptr, SL("reference"), reference);
	zephir_update_property_zval(this_ptr, SL("amount"), amount);
	RETURN_THISW();

}

/**
 *   Calculates MAC string from all variables in the class
 *
 *   @return string
 */
PHP_METHOD(Checkout_Poll, calculateMac) {

	zval mac_string, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mac_string);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&mac_string, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstamp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "+", &_0);
	zephir_concat_self(&mac_string, &_1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getreference", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "+", &_2);
	zephir_concat_self(&mac_string, &_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getmerchantid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "+", &_4);
	zephir_concat_self(&mac_string, &_5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getamount", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SV(&_7, "+", &_6);
	zephir_concat_self(&mac_string, &_7 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcurrency", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SV(&_9, "+", &_8);
	zephir_concat_self(&mac_string, &_9 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_SV(&_11, "+", &_10);
	zephir_concat_self(&mac_string, &_11 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SV(&_13, "+", &_12);
	zephir_concat_self(&mac_string, &_13 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getmerchantsecret", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_VSV(&_15, &mac_string, "+", &_14);
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "sha256");
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 12, &_16, &_15);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "version");

}

/**
 * @param string $version
 */
PHP_METHOD(Checkout_Poll, setVersion) {

	zval *version_param = NULL;
	zval version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(&version, version_param);


	zephir_update_property_zval(this_ptr, SL("version"), &version);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getStamp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stamp");

}

/**
 * @param string $stamp
 */
PHP_METHOD(Checkout_Poll, setStamp) {

	zval *stamp_param = NULL;
	zval stamp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stamp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stamp_param);

	zephir_get_strval(&stamp, stamp_param);


	zephir_update_property_zval(this_ptr, SL("stamp"), &stamp);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getReference) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reference");

}

/**
 * @param string $reference
 */
PHP_METHOD(Checkout_Poll, setReference) {

	zval *reference_param = NULL;
	zval reference;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reference);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reference_param);

	zephir_get_strval(&reference, reference_param);


	zephir_update_property_zval(this_ptr, SL("reference"), &reference);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getMerchantId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "merchantId");

}

/**
 * @param string $merchantId
 */
PHP_METHOD(Checkout_Poll, setMerchantId) {

	zval *merchantId_param = NULL;
	zval merchantId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merchantId_param);

	zephir_get_strval(&merchantId, merchantId_param);


	zephir_update_property_zval(this_ptr, SL("merchantId"), &merchantId);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getMerchantSecret) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "merchantSecret");

}

/**
 * @param string $merchantSecret
 */
PHP_METHOD(Checkout_Poll, setMerchantSecret) {

	zval *merchantSecret_param = NULL;
	zval merchantSecret;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantSecret);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merchantSecret_param);

	zephir_get_strval(&merchantSecret, merchantSecret_param);


	zephir_update_property_zval(this_ptr, SL("merchantSecret"), &merchantSecret);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getAmount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "amount");

}

/**
 * @param string $amount
 */
PHP_METHOD(Checkout_Poll, setAmount) {

	zval *amount_param = NULL;
	zval amount;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&amount);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	zephir_get_strval(&amount, amount_param);


	zephir_update_property_zval(this_ptr, SL("amount"), &amount);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getCurrency) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "currency");

}

/**
 * @param string $currency
 */
PHP_METHOD(Checkout_Poll, setCurrency) {

	zval *currency_param = NULL;
	zval currency;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&currency);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &currency_param);

	zephir_get_strval(&currency, currency_param);


	zephir_update_property_zval(this_ptr, SL("currency"), &currency);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "format");

}

/**
 * @param string $format
 */
PHP_METHOD(Checkout_Poll, setFormat) {

	zval *format_param = NULL;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &format_param);

	zephir_get_strval(&format, format_param);


	zephir_update_property_zval(this_ptr, SL("format"), &format);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Poll, getAlgorithm) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "algorithm");

}

/**
 * @param string $algorithm
 */
PHP_METHOD(Checkout_Poll, setAlgorithm) {

	zval *algorithm_param = NULL;
	zval algorithm;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algorithm);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &algorithm_param);

	zephir_get_strval(&algorithm, algorithm_param);


	zephir_update_property_zval(this_ptr, SL("algorithm"), &algorithm);
	ZEPHIR_MM_RESTORE();

}

