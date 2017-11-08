CheckoutAPIClient (PHP-Extension)
=================

[![Build Status](https://travis-ci.org/Niko9911/CheckoutAPIClient.svg?branch=master)](https://travis-ci.org/niko9911/CheckoutAPIClient) [![Latest Stable Version](https://poser.pugx.org/niko9911/checkout-api-client/v/stable.svg)](https://packagist.org/packages/niko9911/checkout-api-client) [![Latest Unstable Version](https://poser.pugx.org/niko9911/checkout-api-client/v/unstable.svg)](https://packagist.org/packages/niko9911/checkout-api-client) [![License](https://poser.pugx.org/niko9911/checkout-api-client/license.svg)](https://packagist.org/packages/niko9911/checkout-api-client)


API client for the finnish payment gateway Checkout Finland.


In this directory you can find source for PHP-extension version of this API client.
When client is provided via PHP extension, you don't need include any libraries.
Also extension version might be little bit faster than library based.

## Requirements

The following version of PHP are supported.
 - PHP 7.0 (Confirmed)
 - PHP 7.1 (Confirmed)
 - PHP 7.2 (Confirmed)
 
 Requires.
 - cURL extension.
 
 If you can confirm extension to working with unconfirmed version,
 please open issue and let me know.
 
 
 ## Installation on Linux

 - Make sure packages `php-dev` is installed.
 - Download or clone this repo.
 - Use following commands to install extension.
 <pre>
  #   cd CheckoutAPIClient-master/ext/src/{version}/
  #   phpize
  #   ./configure
  #   make && make install
 </pre>
 - Add `extension=checkout.so` into your `php.ini`.
 - Restart your webserver.
 
 
 ## Installation on Windows.
 - Compile your extension using [this guide](https://wiki.php.net/internals/windows/stepbystepbuild).
  - Add `extension=checkout.dll` into your `php.ini`.
  - Restart your webserver.
  
  
  ## Usage

Take a look at the example folder for a full working example.

Creating payment
```php

use Checkout\Payment;
use Checkout\Client;

$demo_merchant_id       = "375917";
$demo_merchant_secret   = "SAIPPUAKAUPPIAS";
$return_url             = "http://yourservice.com/your_return_handling_script.php";

$payment = new  Payment($demo_merchant_id, $demo_merchant_secret);

$payment->setUrls($return_url);

$stamp          = time(); // unique id for the payment  
$amount         = '1000'; // amount is in cents
$reference      = '12344';
$message        = 'Nuts and bolts';
$delivery_date  = new \DateTime('2014-12-31');

$first_name     = 'John';
$family_name    = 'Doe';
$address        = 'Some Street 13 B 2';
$postcode       = '33100';
$post_office    = 'Some city';
$country        = 'FIN';
$language       = 'EN';

$payment->setOrderData($stamp, $amount, $reference, $message, $delivery_date);
$payment->setCustomerData($first_name, $family_name, $address, $postcode, $post_office, $country, $language);

$client = new Client();

$response = $client->sendPayment($payment);

$response_xml = @simplexml_load_string($response);
// redirect to payment page
header('Location: '.$response_xml->paymentURL);

// or show the payment buttons on your webpage, you will find all the data you need in the response xml
```

Handling return
```php
use Checkout\Response;

$demo_merchant_secret   = "SAIPPUAKAUPPIAS";

$response = new Response($demo_merchant_secret);

$response->setRequestParams($_GET);

if($response->validate()) 
{
    // now check the status parameter if the payment was paid and do whatever you do in your shop when you get money
}
```