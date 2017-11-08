<?php

namespace Checkout;

/**
 * Class Payment
 *
 * @package CheckoutFinland
 */
class Payment
{
    /**
     * @var string Merchant id (AN 20)
     */
    protected $merchantId;

    /**
     * @var string Secret merchant key
     */
    protected $merchantSecret;

    /**
     * @var string Payment version, currently always '0001' (AN 4)
     */
    protected $version;

    /**
     * @var string Unique identifier for the payment (AN 20)
     */
    protected $stamp;

    /**
     * @var string Amount of payment in cents (10€ == 1000) (N 8)
     */
    protected $amount;

    /**
     * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
     */
    protected $reference;

    /**
     * @var string Message/Description for the buyer (Nuts and bolts, Furniture, Cuckoo clocks) (AN 1000)
     */
    protected $message;

    /**
     * @var string Language of the payment selection page/bank interface if supported. Currently supported languages include Finnish FI, Swedish SE and English EN (AN  2)
     */
    protected $language;

    /**
     * @var string Url called when returning successfully (AN 300)
     */
    protected $returnUrl;

    /**
     * @var string Url called when user cancelled payment (AN 300)
     */
    protected $cancelUrl;

    /**
     * @var string Url called when payment was rejected (No credit on credit card etc) (AN 300)
     */
    protected $rejectUrl;

    /**
     * @var string Url called when payment is initially successful but not yet confirmed (AN 300)
     */
    protected $delayedUrl;

    /**
     * @var string Country of the buyer, affects available payment methods (AN 3)
     */
    protected $country;

    /**
     * @var string Currency used in payment. Currently only EUR is supported (AN 3)
     */
    protected $currency;

    /**
     * @var string device or method used when creating new transaction. Affects how Checkout servers respond to posting the new payment 1 = HTML 10 = XML (N 2)
     */
    protected $device;

    /**
     * @var string Payment type or content of purchase. Used to differentiate between adult entertainment and everything else. 1 = normal, 2 = adult entertainment (N 2)
     */
    protected $content;

    /**
     * @var string Type, currently always 0 (N 1)
     */
    protected $type;

    /**
     * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
     */
    protected $algorithm;

    /**
     * @var \DateTime Expected delivery date (N 8) (Ymd)
     */
    protected $deliveryDate;

    /**
     * @var string First name of customer (AN 40)
     */
    protected $firstName;

    /**
     * @var string Last name of customer (AN 40)
     */
    protected $familyName;

    /**
     * @var string Street address of customer (AN 40)
     */
    protected $address;

    /**
     * @var string Postcode of customer (AN 14)
     */
    protected $postcode;

    /**
     * @var string Post office of customer (AN 18)
     */
    protected $postOffice;

    /**
     * @var bool If true overrides the minimum allowed amount check (by default 1€ is smallest allowed amount). Do not set to true unless you have a contract with Checkout Finland that allows smaller purchases then 1€.
     */
    protected $allowSmallPurchases;


    /**
     * @param mixed $merchantId
     * @param mixed $merchantSecret
     * @param mixed $allowSmallPurchases
     * @param $allowSmallPurchases
     */
    public function __construct($merchantId, $merchantSecret, $allowSmallPurchases = false) {}

    /**
     * @return $this
     */
    protected function setDefaultValues() {}

    /**
     * Sets payment/order information
     *
     * @throws \CheckoutFinland\Exceptions\AmountUnderMinimumException
     * @throws \CheckoutFinland\Exceptions\AmountTooLargeException
     * @throws \CheckoutFinland\Exceptions\VariableTooLongException
     * @param mixed $stamp
     * @param mixed $amount
     * @param mixed $reference
     * @param mixed $message
     * @param DateTime $deliveryDate
     * @param $message
     * @param \DateTime $$deliveryDate
     * @return $this
     */
    public function setOrderData($stamp, $amount, $reference, $message, DateTime $deliveryDate) {}

    /**
     * Sets customer information
     *
     * @param mixed $firstName
     * @param mixed $familyName
     * @param mixed $address
     * @param mixed $postcode
     * @param mixed $postOffice
     * @param mixed $country
     * @param mixed $language
     * @param $language
     * @return $this
     */
    public function setCustomerData($firstName, $familyName, $address, $postcode, $postOffice, $country, $language) {}

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
     * @param array $$params
     * @return $this
     */
    public function setData(array $params) {}

    /**
     * Set all response urls as the same return url.
     *
     * @throws UrlTooLongException
     * @param string $returnUrl
     * @param string $$returnUrl
     * @return $this
     */
    public function setUrls($returnUrl) {}

    /**
     *   Calculates MAC string from all variables in the class
     *
     * @return string|null
     */
    public function calculateMac() {}

    /**
     * @return string|null
     */
    public function getAddress() {}

    /**
     * @param string $address
     * @param string $$address
     * @return $this
     */
    public function setAddress($address) {}

    /**
     * @return string|null
     */
    public function getAlgorithm() {}

    /**
     * @param string $algorithm
     * @param string $$algorithm
     * @return $this
     */
    public function setAlgorithm($algorithm) {}

    /**
     * @return string|null
     */
    public function getAmount() {}

    /**
     * @throws AmountTooLargeException
     * @throws AmountUnderMinimumException
     * @param int $amount
     * @param string $$amount
     * @return $this
     */
    public function setAmount($amount) {}

    /**
     * @return string|null
     */
    public function getCancelUrl() {}

    /**
     * @throws UrlTooLongException
     * @param string $cancelUrl
     * @param string $$cancelUrl
     * @return $this
     */
    public function setCancelUrl($cancelUrl) {}

    /**
     * @return string|null
     */
    public function getContent() {}

    /**
     * @param string $content
     * @param string $$content
     * @return $this
     */
    public function setContent($content) {}

    /**
     * @return string|null
     */
    public function getCountry() {}

    /**
     * @param string $country
     * @param string $$country
     * @return $this
     */
    public function setCountry($country) {}

    /**
     * @return string|null
     */
    public function getCurrency() {}

    /**
     * @throws CurrencyNotSupportedException
     * @param string $currency
     * @param string $$currency
     * @return $this
     */
    public function setCurrency($currency) {}

    /**
     * @return string|null
     */
    public function getDelayedUrl() {}

    /**
     * @throws UrlTooLongException
     * @param string $delayedUrl
     * @param string $$delayedUrl
     * @return $this
     */
    public function setDelayedUrl($delayedUrl) {}

    /**
     * @param mixed $format
     * @param $format
     * @return mixed
     */
    public function getDeliveryDate($format = null) {}

    /**
     * @param DateTime $deliveryDate
     * @param \DateTime $$deliveryDate
     * @return $this
     */
    public function setDeliveryDate(DateTime $deliveryDate) {}

    /**
     * @return string|null
     */
    public function getDevice() {}

    /**
     * @param string $device
     * @param string $$device
     * @return $this
     */
    public function setDevice($device) {}

    /**
     * @return string|null
     */
    public function getFamilyName() {}

    /**
     * @param string $familyName
     * @param string $$familyName
     * @return $this
     */
    public function setFamilyName($familyName) {}

    /**
     * @return string|null
     */
    public function getFirstName() {}

    /**
     * @param string $firstName
     * @param string $$firstName
     * @return $this
     */
    public function setFirstName($firstName) {}

    /**
     * @return string|null
     */
    public function getLanguage() {}

    /**
     * @param string $language
     * @param string $$language
     * @return $this
     */
    public function setLanguage($language) {}

    /**
     * @return string|null
     */
    public function getMerchantId() {}

    /**
     * @throws VariableTooLongException
     * @param string $merchantId
     * @param string $$merchantId
     * @return $this
     */
    public function setMerchantId($merchantId) {}

    /**
     * @return string|null
     */
    public function getMerchantSecret() {}

    /**
     * @param string $merchantSecret
     * @param string $$merchantSecret
     * @return $this
     */
    public function setMerchantSecret($merchantSecret) {}

    /**
     * @return string|null
     */
    public function getMessage() {}

    /**
     * @param string $message
     * @param string $$message
     * @return $this
     */
    public function setMessage($message) {}

    /**
     * @return string|null
     */
    public function getPostOffice() {}

    /**
     * @param string $postOffice
     * @param string $$postOffice
     * @return $this
     */
    public function setPostOffice($postOffice) {}

    /**
     * @return string|null
     */
    public function getPostcode() {}

    /**
     * @param string $postcode
     * @param string $$postcode
     * @return $this
     */
    public function setPostcode($postcode) {}

    /**
     * @return string|null
     */
    public function getReference() {}

    /**
     * @throws VariableTooLongException
     * @param string $reference
     * @param string $$reference
     * @return $this
     */
    public function setReference($reference) {}

    /**
     * @return string|null
     */
    public function getRejectUrl() {}

    /**
     * @throws UrlTooLongException
     * @param string $rejectUrl
     * @param string $$rejectUrl
     * @return $this
     */
    public function setRejectUrl($rejectUrl) {}

    /**
     * @return string|null
     */
    public function getReturnUrl() {}

    /**
     * @throws UrlTooLongException
     * @param string $returnUrl
     * @param string $$returnUrl
     * @return $this
     */
    public function setReturnUrl($returnUrl) {}

    /**
     * @return string|null
     */
    public function getStamp() {}

    /**
     * @throws VariableTooLongException
     * @param string $stamp
     * @param string $$stamp
     * @return $this
     */
    public function setStamp($stamp) {}

    /**
     * @return string|null
     */
    public function getType() {}

    /**
     * @param string $type
     * @param string $$type
     * @return $this
     */
    public function setType($type) {}

    /**
     * @return string|null
     */
    public function getVersion() {}

    /**
     * @param string $version
     * @param string $$version
     * @return $this
     */
    public function setVersion($version) {}

}
