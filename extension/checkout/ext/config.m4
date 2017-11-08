PHP_ARG_ENABLE(checkout, whether to enable checkout, [ --enable-checkout   Enable Checkout])

if test "$PHP_CHECKOUT" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, CHECKOUT_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_CHECKOUT, 1, [Whether you have Checkout])
	checkout_sources="checkout.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c checkout/client.zep.c
	checkout/exceptions/amounttoolargeexception.zep.c
	checkout/exceptions/amountunderminimumexception.zep.c
	checkout/exceptions/currencynotsupportedexception.zep.c
	checkout/exceptions/macmismatchexception.zep.c
	checkout/exceptions/unsupportedalgorithmexception.zep.c
	checkout/exceptions/urltoolongexception.zep.c
	checkout/exceptions/variabletoolongexception.zep.c
	checkout/payment.zep.c
	checkout/poll.zep.c
	checkout/response.zep.c "
	PHP_NEW_EXTENSION(checkout, $checkout_sources, $ext_shared,, )
	PHP_SUBST(CHECKOUT_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([checkout], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([checkout], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/checkout], [php_CHECKOUT.h])

fi
