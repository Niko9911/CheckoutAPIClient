
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Class Client
 * @package CheckoutFinland
 */
ZEPHIR_INIT_CLASS(Checkout_Client) {

	ZEPHIR_REGISTER_CLASS(Checkout, Client, checkout, client, checkout_client_method_entry, 0);

	return SUCCESS;

}

/**
 * Builds an array that can be passed to Checkout Finland as POST parameters. Sends the data. Returns the response body
 * that contains payment options xml or error message.
 *
 * @param Payment $payment
 * @throws \Exception
 * @return string
 */
PHP_METHOD(Checkout_Client, sendPayment) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payment, payment_sub, postData, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payment_sub);
	ZVAL_UNDEF(&postData);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &payment);



	ZEPHIR_INIT_VAR(&postData);
	zephir_create_array(&postData, 24, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, payment, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_0);
	zephir_array_update_string(&postData, SL("VERSION"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, payment, "getstamp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_2);
	zephir_array_update_string(&postData, SL("STAMP"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, payment, "getamount", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_3);
	zephir_array_update_string(&postData, SL("AMOUNT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_4, payment, "getreference", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_4);
	zephir_array_update_string(&postData, SL("REFERENCE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_5, payment, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_5);
	zephir_array_update_string(&postData, SL("MESSAGE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, payment, "getlanguage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_6);
	zephir_array_update_string(&postData, SL("LANGUAGE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, payment, "getmerchantid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_7);
	zephir_array_update_string(&postData, SL("MERCHANT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_8, payment, "getreturnurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_8);
	zephir_array_update_string(&postData, SL("RETURN"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, payment, "getcancelurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_9);
	zephir_array_update_string(&postData, SL("CANCEL"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_10, payment, "getrejecturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_10);
	zephir_array_update_string(&postData, SL("REJECT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_11, payment, "getdelayedurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_11);
	zephir_array_update_string(&postData, SL("DELAYED"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_12, payment, "getcountry", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_12);
	zephir_array_update_string(&postData, SL("COUNTRY"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_13, payment, "getcurrency", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_13);
	zephir_array_update_string(&postData, SL("CURRENCY"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_14, payment, "getdevice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_14);
	zephir_array_update_string(&postData, SL("DEVICE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_15, payment, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_15);
	zephir_array_update_string(&postData, SL("CONTENT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_16, payment, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_16);
	zephir_array_update_string(&postData, SL("TYPE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_17, payment, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_17);
	zephir_array_update_string(&postData, SL("ALGORITHM"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "Ymd");
	ZEPHIR_CALL_METHOD(&_18, payment, "getdeliverydate", NULL, 0, &_19);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_18);
	zephir_array_update_string(&postData, SL("DELIVERY_DATE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_20, payment, "getfirstname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_20);
	zephir_array_update_string(&postData, SL("FIRSTNAME"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_21, payment, "getfamilyname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_21);
	zephir_array_update_string(&postData, SL("FAMILYNAME"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_22, payment, "getaddress", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_22);
	zephir_array_update_string(&postData, SL("ADDRESS"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_23, payment, "getpostcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_23);
	zephir_array_update_string(&postData, SL("POSTCODE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_24, payment, "getpostoffice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_24);
	zephir_array_update_string(&postData, SL("POSTOFFICE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_25, payment, "calculatemac", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "", &_25);
	zephir_array_update_string(&postData, SL("MAC"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_19);
	ZVAL_STRING(&_19, "https://payment.checkout.fi");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "postdata", NULL, 0, &_19, &postData);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Poll payment, returns with xml containing payment info or error message
 *
 * @param Poll $poll
 * @return string
 * @throws \Exception
 */
PHP_METHOD(Checkout_Client, poll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poll, poll_sub, postData, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poll_sub);
	ZVAL_UNDEF(&postData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &poll);



	ZEPHIR_INIT_VAR(&postData);
	zephir_create_array(&postData, 9, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, poll, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("VERSION"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getstamp", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("STAMP"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getreference", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("REFERENCE"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getmerchantid", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("MERCHANT"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getamount", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("AMOUNT"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getcurrency", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("CURRENCY"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getformat", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("FORMAT"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "getalgorithm", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("ALGORITHM"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, poll, "calculatemac", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&postData, SL("MAC"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "https://rpcapi.checkout.fi/poll2");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "postdata", NULL, 0, &_1, &postData);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Posts data, tries to use stream context if allow_url_fopen is on in php.ini or CURL if not. If neither option is available throws exception.
 *
 * @param $url
 * @param $postData
 * @throws \Exception
 * @return string
 */
PHP_METHOD(Checkout_Client, postData) {

	zval _2$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *postData, postData_sub, __$false, __$true, context, tmpArray, options, ch, result, _0, _1, _5, _6, _3$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&postData_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&tmpArray);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &postData);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "allow_url_fopen");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 1, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&tmpArray);
		zephir_create_array(&tmpArray, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_2$$3, SL("method"), SL("POST"));
		add_assoc_stringl_ex(&_2$$3, SL("header"), SL("Content-Type: application/x-www-form-urlencoded"));
		ZEPHIR_CALL_FUNCTION(&_3$$3, "http_build_query", &_4, 2, postData);
		zephir_check_call_status();
		zephir_array_update_string(&_2$$3, SL("content"), &_3$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&tmpArray, SL("http"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&context, "stream_context_create", NULL, 3, &tmpArray);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 4, url, &__$false, &context);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_5, "get_loaded_extensions", NULL, 5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "curl");
	ZEPHIR_CALL_FUNCTION(&_6, "in_array", NULL, 6, &_0, &_5, &__$true);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_INIT_VAR(&options);
		zephir_create_array(&options, 8, 0 TSRMLS_CC);
		add_index_long(&options, 47, 1);
		add_index_long(&options, 42, 0);
		zephir_array_update_long(&options, 10002, url, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		add_index_long(&options, 74, 1);
		add_index_long(&options, 19913, 1);
		add_index_long(&options, 75, 1);
		add_index_long(&options, 13, 4);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "http_build_query", &_4, 2, postData);
		zephir_check_call_status();
		zephir_array_update_long(&options, 10015, &_7$$4, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 7);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt_array", NULL, 8, &ch, &options);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 9, &ch);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 10, &ch);
		zephir_check_call_status();
		RETURN_CCTOR(&result);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No valid method to post data. Set allow_url_fopen setting to On in php.ini file or install curl extension.", "checkout/Client.zep", 118);
	return;

}

