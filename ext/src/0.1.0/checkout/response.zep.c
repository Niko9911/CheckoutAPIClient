
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * Class Response
 * @package CheckoutFinland
 */
ZEPHIR_INIT_CLASS(Checkout_Response) {

	ZEPHIR_REGISTER_CLASS(Checkout, Response, checkout, response, checkout_response_method_entry, 0);

	/**
	 * @var string Secret merchant key
	 */
	zend_declare_property_null(checkout_response_ce, SL("merchant_secret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Payment version, currently always '0001'
	 */
	zend_declare_property_null(checkout_response_ce, SL("version"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Unique identifier for the payment, set by merchant when creating new payment
	 */
	zend_declare_property_null(checkout_response_ce, SL("stamp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Reference number for the payment, set by merchant when creating new payment, recommended to be unique but not forced
	 */
	zend_declare_property_null(checkout_response_ce, SL("reference"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Archive id/Unique id for the payment, set by Checkout Finland
	 */
	zend_declare_property_null(checkout_response_ce, SL("payment"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(checkout_response_ce, SL("status"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(checkout_response_ce, SL("algorithm"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(checkout_response_ce, SL("mac"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $merchant_secret
 */
PHP_METHOD(Checkout_Response, __construct) {

	zval *merchant_secret, merchant_secret_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchant_secret_sub);

	zephir_fetch_params(0, 1, 0, &merchant_secret);



	zephir_update_property_zval(this_ptr, SL("merchant_secret"), merchant_secret);

}

/**
 * @return bool
 * @throws MacMismatchException
 * @throws UnsupportedAlgorithmException
 */
PHP_METHOD(Checkout_Response, validate) {

	zval expected_mac, _0, _5, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expected_mac);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&expected_mac);
	ZVAL_NULL(&expected_mac);
	zephir_read_property(&_0, this_ptr, SL("algorithm"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		zephir_read_property(&_1$$3, this_ptr, SL("merchant_secret"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "sha256");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "{this->version}&{this->stamp}&{this->reference}&{this->payment}&{this->status}&{this->algorithm}");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "hash_hmac", NULL, 13, &_2$$3, &_3$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&expected_mac);
		zephir_fast_strtoupper(&expected_mac, &_4$$3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_unsupportedalgorithmexception_ce, "UnsupportedAlgorithm", "checkout/Response.zep", 65);
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("mac"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&expected_mac, &_5)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_macmismatchexception_ce, "MacMismatch", "checkout/Response.zep", 70);
	return;

}

/**
 * @param $params
 * @return $this
 */
PHP_METHOD(Checkout_Response, setRequestParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);

	ZEPHIR_SEPARATE_PARAM(params);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&_1, "array_change_key_case", NULL, 14, params, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(params, &_1);
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_array_isset_string(params, SL("VERSION"))) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_string(&_2, params, SL("VERSION"), PH_NOISY, "checkout/Response.zep", 80 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_NULL(&_2);
	}
	zephir_update_property_zval(this_ptr, SL("version"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_array_isset_string(params, SL("STAMP"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, params, SL("STAMP"), PH_NOISY, "checkout/Response.zep", 81 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_NULL(&_3);
	}
	zephir_update_property_zval(this_ptr, SL("stamp"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_array_isset_string(params, SL("REFERENCE"))) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_array_fetch_string(&_4, params, SL("REFERENCE"), PH_NOISY, "checkout/Response.zep", 82 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_NULL(&_4);
	}
	zephir_update_property_zval(this_ptr, SL("reference"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_array_isset_string(params, SL("PAYMENT"))) {
		ZEPHIR_OBS_NVAR(&_5);
		zephir_array_fetch_string(&_5, params, SL("PAYMENT"), PH_NOISY, "checkout/Response.zep", 83 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_NULL(&_5);
	}
	zephir_update_property_zval(this_ptr, SL("payment"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	if (zephir_array_isset_string(params, SL("STATUS"))) {
		ZEPHIR_OBS_NVAR(&_6);
		zephir_array_fetch_string(&_6, params, SL("STATUS"), PH_NOISY, "checkout/Response.zep", 84 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_NULL(&_6);
	}
	zephir_update_property_zval(this_ptr, SL("status"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_array_isset_string(params, SL("ALGORITHM"))) {
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, params, SL("ALGORITHM"), PH_NOISY, "checkout/Response.zep", 85 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_NULL(&_7);
	}
	zephir_update_property_zval(this_ptr, SL("algorithm"), &_7);
	ZEPHIR_INIT_VAR(&_8);
	if (zephir_array_isset_string(params, SL("MAC"))) {
		ZEPHIR_OBS_NVAR(&_8);
		zephir_array_fetch_string(&_8, params, SL("MAC"), PH_NOISY, "checkout/Response.zep", 86 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_NULL(&_8);
	}
	zephir_update_property_zval(this_ptr, SL("mac"), &_8);
	RETURN_THIS();

}

/**
 * @return mixed
 */
PHP_METHOD(Checkout_Response, getAlgorithm) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "algorithm");

}

/**
 * @param mixed $algorithm
 * @return $this
 */
PHP_METHOD(Checkout_Response, setAlgorithm) {

	zval *algorithm, algorithm_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algorithm_sub);

	zephir_fetch_params(0, 1, 0, &algorithm);



	zephir_update_property_zval(this_ptr, SL("algorithm"), algorithm);
	RETURN_THISW();

}

/**
 * @return mixed
 */
PHP_METHOD(Checkout_Response, getMac) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mac");

}

/**
 * @param mixed $mac
 * @return $this
 */
PHP_METHOD(Checkout_Response, setMac) {

	zval *mac, mac_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mac_sub);

	zephir_fetch_params(0, 1, 0, &mac);



	zephir_update_property_zval(this_ptr, SL("mac"), mac);
	RETURN_THISW();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Response, getMerchantSecret) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "merchant_secret");

}

/**
 * @param string $merchant_secret
 * @return $this
 */
PHP_METHOD(Checkout_Response, setMerchantSecret) {

	zval *merchant_secret_param = NULL;
	zval merchant_secret;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchant_secret);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merchant_secret_param);

	zephir_get_strval(&merchant_secret, merchant_secret_param);


	zephir_update_property_zval(this_ptr, SL("merchant_secret"), &merchant_secret);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Response, getPayment) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "payment");

}

/**
 * @param string $payment
 * @return $this
 */
PHP_METHOD(Checkout_Response, setPayment) {

	zval *payment_param = NULL;
	zval payment;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payment);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &payment_param);

	zephir_get_strval(&payment, payment_param);


	zephir_update_property_zval(this_ptr, SL("payment"), &payment);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Response, getReference) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reference");

}

/**
 * @param string $reference
 * @return $this
 */
PHP_METHOD(Checkout_Response, setReference) {

	zval *reference_param = NULL;
	zval reference;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reference);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reference_param);

	zephir_get_strval(&reference, reference_param);


	zephir_update_property_zval(this_ptr, SL("reference"), &reference);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Response, getStamp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stamp");

}

/**
 * @param string $stamp
 * @return $this
 */
PHP_METHOD(Checkout_Response, setStamp) {

	zval *stamp_param = NULL;
	zval stamp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stamp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stamp_param);

	zephir_get_strval(&stamp, stamp_param);


	zephir_update_property_zval(this_ptr, SL("stamp"), &stamp);
	RETURN_THIS();

}

/**
 * @return int
 */
PHP_METHOD(Checkout_Response, getStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "status");

}

/**
 * @param int $status
 * @return $this
 */
PHP_METHOD(Checkout_Response, setStatus) {

	zval *status_param = NULL, _0;
	zend_long status;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &status_param);

	status = zephir_get_intval(status_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, status);
	zephir_update_property_zval(this_ptr, SL("status"), &_0);
	RETURN_THISW();

}

/**
 * @return int
 */
PHP_METHOD(Checkout_Response, getVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "version");

}

/**
 * @param string $version
 * @return $this
 */
PHP_METHOD(Checkout_Response, setVersion) {

	zval *version_param = NULL;
	zval version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(&version, version_param);


	zephir_update_property_zval(this_ptr, SL("version"), &version);
	RETURN_THIS();

}

