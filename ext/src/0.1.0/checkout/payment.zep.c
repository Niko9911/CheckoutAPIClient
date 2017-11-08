
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * Class Payment
 * @package CheckoutFinland
 */
ZEPHIR_INIT_CLASS(Checkout_Payment) {

	ZEPHIR_REGISTER_CLASS(Checkout, Payment, checkout, payment, checkout_payment_method_entry, 0);

	/**
	 * @var string Merchant id (AN 20)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("merchantId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Secret merchant key
	 */
	zend_declare_property_null(checkout_payment_ce, SL("merchantSecret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Payment version, currently always '0001' (AN 4)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("version"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Unique identifier for the payment (AN 20)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("stamp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Amount of payment in cents (10€ == 1000) (N 8)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("amount"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("reference"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Message/Description for the buyer (Nuts and bolts, Furniture, Cuckoo clocks) (AN 1000)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Language of the payment selection page/bank interface if supported. Currently supported languages include Finnish FI, Swedish SE and English EN (AN  2)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("language"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Url called when returning successfully (AN 300)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("returnUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Url called when user cancelled payment (AN 300)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("cancelUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Url called when payment was rejected (No credit on credit card etc) (AN 300)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("rejectUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Url called when payment is initially successful but not yet confirmed (AN 300)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("delayedUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Country of the buyer, affects available payment methods (AN 3)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("country"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Currency used in payment. Currently only EUR is supported (AN 3)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("currency"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string device or method used when creating new transaction. Affects how Checkout servers respond to posting the new payment 1 = HTML 10 = XML (N 2)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("device"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Payment type or content of purchase. Used to differentiate between adult entertainment and everything else. 1 = normal, 2 = adult entertainment (N 2)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Type, currently always 0 (N 1)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("algorithm"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \DateTime Expected delivery date (N 8) (Ymd)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("deliveryDate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string First name of customer (AN 40)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("firstName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Last name of customer (AN 40)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("familyName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Street address of customer (AN 40)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("address"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Postcode of customer (AN 14)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("postcode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Post office of customer (AN 18)
	 */
	zend_declare_property_null(checkout_payment_ce, SL("postOffice"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool If true overrides the minimum allowed amount check (by default 1€ is smallest allowed amount). Do not set to true unless you have a contract with Checkout Finland that allows smaller purchases then 1€.
	 */
	zend_declare_property_null(checkout_payment_ce, SL("allowSmallPurchases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $merchantId
 * @param $merchantSecret
 * @param $allowSmallPurchases
 */
PHP_METHOD(Checkout_Payment, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *merchantId, merchantId_sub, *merchantSecret, merchantSecret_sub, *allowSmallPurchases = NULL, allowSmallPurchases_sub, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantId_sub);
	ZVAL_UNDEF(&merchantSecret_sub);
	ZVAL_UNDEF(&allowSmallPurchases_sub);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &merchantId, &merchantSecret, &allowSmallPurchases);

	if (!allowSmallPurchases) {
		allowSmallPurchases = &allowSmallPurchases_sub;
		allowSmallPurchases = &__$false;
	}


	zephir_update_property_zval(this_ptr, SL("merchantId"), merchantId);
	zephir_update_property_zval(this_ptr, SL("merchantSecret"), merchantSecret);
	zephir_update_property_zval(this_ptr, SL("allowSmallPurchases"), allowSmallPurchases);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultvalues", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setDefaultValues) {

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
	ZVAL_LONG(&_1, 10);
	zephir_update_property_zval(this_ptr, SL("device"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 1);
	zephir_update_property_zval(this_ptr, SL("content"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(this_ptr, SL("type"), &_1);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 3);
	zephir_update_property_zval(this_ptr, SL("algorithm"), &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "EUR");
	zephir_update_property_zval(this_ptr, SL("currency"), &_0);
	RETURN_THIS();

}

/**
 * Sets payment/order information
 *
 * @param $stamp
 * @param $amount
 * @param $reference
 * @param $message
 * @param \DateTime $deliveryDate
 * @return $this
 * @throws \CheckoutFinland\Exceptions\AmountUnderMinimumException
 * @throws \CheckoutFinland\Exceptions\AmountTooLargeException
 * @throws \CheckoutFinland\Exceptions\VariableTooLongException
 */
PHP_METHOD(Checkout_Payment, setOrderData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stamp, stamp_sub, *amount, amount_sub, *reference, reference_sub, *message, message_sub, *deliveryDate, deliveryDate_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stamp_sub);
	ZVAL_UNDEF(&amount_sub);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&deliveryDate_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &stamp, &amount, &reference, &message, &deliveryDate);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstamp", NULL, 0, stamp);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setamount", NULL, 0, amount);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreference", NULL, 0, reference);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmessage", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdeliverydate", NULL, 0, deliveryDate);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets customer information
 *
 * @param $firstName
 * @param $familyName
 * @param $address
 * @param $postcode
 * @param $postOffice
 * @param $country
 * @param $language
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setCustomerData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *firstName, firstName_sub, *familyName, familyName_sub, *address, address_sub, *postcode, postcode_sub, *postOffice, postOffice_sub, *country, country_sub, *language, language_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&firstName_sub);
	ZVAL_UNDEF(&familyName_sub);
	ZVAL_UNDEF(&address_sub);
	ZVAL_UNDEF(&postcode_sub);
	ZVAL_UNDEF(&postOffice_sub);
	ZVAL_UNDEF(&country_sub);
	ZVAL_UNDEF(&language_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 0, &firstName, &familyName, &address, &postcode, &postOffice, &country, &language);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfirstname", NULL, 0, firstName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfamilyname", NULL, 0, familyName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setaddress", NULL, 0, address);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpostcode", NULL, 0, postcode);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpostoffice", NULL, 0, postOffice);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcountry", NULL, 0, country);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlanguage", NULL, 0, language);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets multiple variables at once
 *
 * $example_data =  [
 *   'stamp'            => '1245132',
 *   'amount'           => '1000',
 *   'reference'        => '12344',
 *   'message'          => 'Nuts and bolts',
 *   'deliveryDate'     => new \DateTime('2014-12-31'),
 *   'firstName'        => 'John',
 *   'familyName'       => 'Doe',
 *   'address'          => 'Some street 13 B 2',
 *   'postcode'         => '33100',
 *   'postOffice'       => 'Some city',
 *   'country'          => 'FIN',
 *   'language'         => 'EN'
 *   ];
 *
 * @param array $params
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setData) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, key, value, setter_name, *_0, _3$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&setter_name);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	zephir_is_iterable(&params, 0, "checkout/Payment.zep", 219);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_ucfirst(&_3$$3, &key);
		ZEPHIR_INIT_NVAR(&setter_name);
		ZEPHIR_CONCAT_SV(&setter_name, "set", &_3$$3);
		if ((zephir_method_exists(this_ptr, &setter_name TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &setter_name, NULL, 0, &value);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * Set all response urls as the same return url.
 *
 * @param string $returnUrl
 * @throws UrlTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setUrls) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *returnUrl_param = NULL;
	zval returnUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&returnUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &returnUrl_param);

	zephir_get_strval(&returnUrl, returnUrl_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setreturnurl", NULL, 0, &returnUrl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcancelurl", NULL, 0, &returnUrl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdelayedurl", NULL, 0, &returnUrl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrejecturl", NULL, 0, &returnUrl);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 *   Calculates MAC string from all variables in the class
 *
 *   @return string
 */
PHP_METHOD(Checkout_Payment, calculateMac) {

	zval mac_string, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&mac_string, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstamp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "+", &_0);
	zephir_concat_self(&mac_string, &_1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getamount", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "+", &_2);
	zephir_concat_self(&mac_string, &_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getreference", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "+", &_4);
	zephir_concat_self(&mac_string, &_5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SV(&_7, "+", &_6);
	zephir_concat_self(&mac_string, &_7 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getlanguage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SV(&_9, "+", &_8);
	zephir_concat_self(&mac_string, &_9 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getmerchantid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_SV(&_11, "+", &_10);
	zephir_concat_self(&mac_string, &_11 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getreturnurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SV(&_13, "+", &_12);
	zephir_concat_self(&mac_string, &_13 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getcancelurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SV(&_15, "+", &_14);
	zephir_concat_self(&mac_string, &_15 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getrejecturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SV(&_17, "+", &_16);
	zephir_concat_self(&mac_string, &_17 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "getdelayedurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SV(&_19, "+", &_18);
	zephir_concat_self(&mac_string, &_19 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "getcountry", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_CONCAT_SV(&_21, "+", &_20);
	zephir_concat_self(&mac_string, &_21 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_22, this_ptr, "getcurrency", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_23);
	ZEPHIR_CONCAT_SV(&_23, "+", &_22);
	zephir_concat_self(&mac_string, &_23 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "getdevice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_25);
	ZEPHIR_CONCAT_SV(&_25, "+", &_24);
	zephir_concat_self(&mac_string, &_25 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_SV(&_27, "+", &_26);
	zephir_concat_self(&mac_string, &_27 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_29);
	ZEPHIR_CONCAT_SV(&_29, "+", &_28);
	zephir_concat_self(&mac_string, &_29 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_30, this_ptr, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_CONCAT_SV(&_31, "+", &_30);
	zephir_concat_self(&mac_string, &_31 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "getdeliverydate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "Ymd");
	ZEPHIR_CALL_METHOD(&_33, &_32, "format", NULL, 0, &_34);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_CONCAT_SV(&_35, "+", &_33);
	zephir_concat_self(&mac_string, &_35 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "getfirstname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_CONCAT_SV(&_37, "+", &_36);
	zephir_concat_self(&mac_string, &_37 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_38, this_ptr, "getfamilyname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_39);
	ZEPHIR_CONCAT_SV(&_39, "+", &_38);
	zephir_concat_self(&mac_string, &_39 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_40, this_ptr, "getaddress", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_41);
	ZEPHIR_CONCAT_SV(&_41, "+", &_40);
	zephir_concat_self(&mac_string, &_41 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "getpostcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_43);
	ZEPHIR_CONCAT_SV(&_43, "+", &_42);
	zephir_concat_self(&mac_string, &_43 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_44, this_ptr, "getpostoffice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_45);
	ZEPHIR_CONCAT_SV(&_45, "+", &_44);
	zephir_concat_self(&mac_string, &_45 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_46, this_ptr, "getmerchantsecret", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_47);
	ZEPHIR_CONCAT_SV(&_47, "+", &_46);
	zephir_concat_self(&mac_string, &_47 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_34);
	zephir_md5(&_34, &mac_string);
	zephir_fast_strtoupper(return_value, &_34);
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getAddress) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "address");

}

/**
 * @param string $address
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setAddress) {

	zval *address_param = NULL, _0, _1, _2;
	zval address;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &address_param);

	zephir_get_strval(&address, address_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 40);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &address, 0 , 40 , 0);
	zephir_update_property_zval(this_ptr, SL("address"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getAlgorithm) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "algorithm");

}

/**
 * @param string $algorithm
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setAlgorithm) {

	unsigned char _0;
	zval *algorithm_param = NULL, _1;
	zval algorithm;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algorithm);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &algorithm_param);

	zephir_get_strval(&algorithm, algorithm_param);


	_0 = ZEPHIR_STRING_OFFSET(&algorithm, 0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, _0);
	zephir_update_property_zval(this_ptr, SL("algorithm"), &_1);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getAmount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "amount");

}

/**
 * @param string $amount
 * @throws AmountTooLargeException
 * @throws AmountUnderMinimumException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setAmount) {

	zval _3$$3;
	zend_bool _5;
	zval *amount_param = NULL, _0, _4, _6, _1$$3, _2$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZVAL_LONG(&_0, amount);
	if (zephir_fast_strlen_ev(&_0) > 8) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, checkout_exceptions_amounttoolargeexception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, amount);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VS(&_3$$3, &_2$$3, " is too large.");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 11, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "checkout/Payment.zep", 327 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("allowSmallPurchases"), PH_NOISY_CC | PH_READONLY);
	_5 = ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	if (_5) {
		_5 = amount < 100;
	}
	if (_5) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_amountunderminimumexception_ce, "1€ is the minimum allowed amount.", "checkout/Payment.zep", 330);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(&_6, amount);
	zephir_update_property_zval(this_ptr, SL("amount"), &_6);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getCancelUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cancelUrl");

}

/**
 * @param string $cancelUrl
 * @throws UrlTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setCancelUrl) {

	zval *cancelUrl_param = NULL;
	zval cancelUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cancelUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cancelUrl_param);

	zephir_get_strval(&cancelUrl, cancelUrl_param);


	if (zephir_fast_strlen_ev(&cancelUrl) > 300) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_urltoolongexception_ce, "Max url length is 300 characters", "checkout/Payment.zep", 352);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("cancelUrl"), &cancelUrl);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

/**
 * @param string $content
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setContent) {

	zval *content_param = NULL, _0, _1, _2;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &content, 0 , 2 , 0);
	zephir_update_property_zval(this_ptr, SL("content"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getCountry) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "country");

}

/**
 * @param string $country
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setCountry) {

	zval *country_param = NULL, _0, _1, _2;
	zval country;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&country);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &country_param);

	zephir_get_strval(&country, country_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &country, 0 , 3 , 0);
	zephir_update_property_zval(this_ptr, SL("country"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getCurrency) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "currency");

}

/**
 * @param string $currency
 * @throws CurrencyNotSupportedException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setCurrency) {

	zval *currency_param = NULL, _0;
	zval currency;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&currency);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &currency_param);

	zephir_get_strval(&currency, currency_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &currency);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_0, "EUR")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_currencynotsupportedexception_ce, "EUR is currently the only supported currency", "checkout/Payment.zep", 410);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("currency"), &currency);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getDelayedUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "delayedUrl");

}

/**
 * @param string $delayedUrl
 * @throws UrlTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setDelayedUrl) {

	zval *delayedUrl_param = NULL;
	zval delayedUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delayedUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &delayedUrl_param);

	zephir_get_strval(&delayedUrl, delayedUrl_param);


	if (zephir_fast_strlen_ev(&delayedUrl) > 300) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_urltoolongexception_ce, "Max url length is 300 characters", "checkout/Payment.zep", 432);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("delayedUrl"), &delayedUrl);
	RETURN_THIS();

}

/**
 * @param $format
 * @return mixed
 */
PHP_METHOD(Checkout_Payment, getDeliveryDate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *format = NULL, format_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &format);

	if (!format) {
		format = &format_sub;
		format = &__$null;
	}


	if (zephir_is_true(format)) {
		zephir_read_property(&_0$$3, this_ptr, SL("deliveryDate"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "format", NULL, 0, format);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "deliveryDate");

}

/**
 * @param \DateTime $deliveryDate
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setDeliveryDate) {

	zval *deliveryDate, deliveryDate_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&deliveryDate_sub);

	zephir_fetch_params(0, 1, 0, &deliveryDate);



	zephir_update_property_zval(this_ptr, SL("deliveryDate"), deliveryDate);
	RETURN_THISW();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getDevice) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "device");

}

/**
 * @param string $device
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setDevice) {

	zval *device_param = NULL, _0, _1, _2;
	zval device;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&device);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &device_param);

	zephir_get_strval(&device, device_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &device, 0 , 2 , 0);
	zephir_update_property_zval(this_ptr, SL("device"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getFamilyName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "familyName");

}

/**
 * @param string $familyName
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setFamilyName) {

	zval *familyName_param = NULL, _0, _1, _2;
	zval familyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&familyName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &familyName_param);

	zephir_get_strval(&familyName, familyName_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 40);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &familyName, 0 , 40 , 0);
	zephir_update_property_zval(this_ptr, SL("familyName"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getFirstName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "firstName");

}

/**
 * @param string $firstName
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setFirstName) {

	zval *firstName_param = NULL, _0, _1, _2;
	zval firstName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&firstName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &firstName_param);

	zephir_get_strval(&firstName, firstName_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 40);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &firstName, 0 , 40 , 0);
	zephir_update_property_zval(this_ptr, SL("firstName"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getLanguage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "language");

}

/**
 * @param string $language
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setLanguage) {

	zval *language_param = NULL, _0, _1, _2;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	zephir_get_strval(&language, language_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &language, 0 , 2 , 0);
	zephir_update_property_zval(this_ptr, SL("language"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getMerchantId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "merchantId");

}

/**
 * @param string $merchantId
 * @throws VariableTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setMerchantId) {

	zval *merchantId_param = NULL;
	zval merchantId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merchantId_param);

	zephir_get_strval(&merchantId, merchantId_param);


	if (zephir_fast_strlen_ev(&merchantId) > 20) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_variabletoolongexception_ce, "Merchant id: {merchantId} too long, max length is 20 characters", "checkout/Payment.zep", 548);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("merchantId"), &merchantId);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getMerchantSecret) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "merchantSecret");

}

/**
 * @param string $merchantSecret
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setMerchantSecret) {

	zval *merchantSecret_param = NULL;
	zval merchantSecret;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&merchantSecret);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merchantSecret_param);

	zephir_get_strval(&merchantSecret, merchantSecret_param);


	zephir_update_property_zval(this_ptr, SL("merchantSecret"), &merchantSecret);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getMessage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "message");

}

/**
 * @param string $message
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setMessage) {

	zval *message_param = NULL, _0, _1, _2;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1000);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &message, 0 , 1000 , 0);
	zephir_update_property_zval(this_ptr, SL("message"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getPostOffice) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "postOffice");

}

/**
 * @param string $postOffice
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setPostOffice) {

	zval *postOffice_param = NULL, _0, _1, _2;
	zval postOffice;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&postOffice);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &postOffice_param);

	zephir_get_strval(&postOffice, postOffice_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 18);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &postOffice, 0 , 18 , 0);
	zephir_update_property_zval(this_ptr, SL("postOffice"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getPostcode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "postcode");

}

/**
 * @param string $postcode
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setPostcode) {

	zval *postcode_param = NULL, _0, _1, _2;
	zval postcode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&postcode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &postcode_param);

	zephir_get_strval(&postcode, postcode_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 14);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &postcode, 0 , 14 , 0);
	zephir_update_property_zval(this_ptr, SL("postcode"), &_2);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getReference) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reference");

}

/**
 * @param string $reference
 * @throws VariableTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setReference) {

	zval *reference_param = NULL;
	zval reference;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reference);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reference_param);

	zephir_get_strval(&reference, reference_param);


	if (zephir_fast_strlen_ev(&reference) > 20) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_variabletoolongexception_ce, "Reference: {reference} too long, max length is 20 characters.", "checkout/Payment.zep", 642);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("reference"), &reference);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getRejectUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "rejectUrl");

}

/**
 * @param string $rejectUrl
 * @throws UrlTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setRejectUrl) {

	zval *rejectUrl_param = NULL;
	zval rejectUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rejectUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rejectUrl_param);

	zephir_get_strval(&rejectUrl, rejectUrl_param);


	if (zephir_fast_strlen_ev(&rejectUrl) > 300) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_urltoolongexception_ce, "Max url length is 300 characters", "checkout/Payment.zep", 664);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("rejectUrl"), &rejectUrl);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getReturnUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "returnUrl");

}

/**
 * @param string $returnUrl
 * @throws UrlTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setReturnUrl) {

	zval *returnUrl_param = NULL;
	zval returnUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&returnUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &returnUrl_param);

	zephir_get_strval(&returnUrl, returnUrl_param);


	if (zephir_fast_strlen_ev(&returnUrl) > 300) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_urltoolongexception_ce, "Max url length is 300 characters", "checkout/Payment.zep", 686);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("returnUrl"), &returnUrl);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getStamp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stamp");

}

/**
 * @param string $stamp
 * @throws VariableTooLongException
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setStamp) {

	zval *stamp_param = NULL;
	zval stamp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stamp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stamp_param);

	zephir_get_strval(&stamp, stamp_param);


	if (zephir_fast_strlen_ev(&stamp) > 20) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(checkout_exceptions_variabletoolongexception_ce, "Stamp: {stamp} too long, max length is 20 characters.", "checkout/Payment.zep", 708);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("stamp"), &stamp);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * @param string $type
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setType) {

	unsigned char _0;
	zval *type_param = NULL, _1;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	_0 = ZEPHIR_STRING_OFFSET(&type, 0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, _0);
	zephir_update_property_zval(this_ptr, SL("type"), &_1);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Checkout_Payment, getVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "version");

}

/**
 * @param string $version
 * @return $this
 */
PHP_METHOD(Checkout_Payment, setVersion) {

	zval *version_param = NULL, _0, _1, _2;
	zval version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(&version, version_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &version, 0 , 4 , 0);
	zephir_update_property_zval(this_ptr, SL("version"), &_2);
	RETURN_THIS();

}

