<?php

namespace Checkout;


class Poll
{
    /**
     * @var string Payment version, currently always '0001' (AN 4)
     */
    protected $version;

    /**
     * @var string Unique identifier for the payment (AN 20)
     */
    protected $stamp;

    /**
     * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
     */
    protected $reference;

    /**
     * @var string Merchant id (AN 20)
     */
    protected $merchantId;

    /**
     * @var string Secret merchant key
     */
    protected $merchantSecret;

    /**
     * @var string Amount of payment in cents (10€ == 1000) (N 8)
     */
    protected $amount;

    /**
     * @var string Currency used in payment. Currently only EUR is supported (AN 3)
     */
    protected $currency;

    /**
     * @var string format Currently only 1
     */
    protected $format;

    /**
     * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
     */
    protected $algorithm;


    /**
     * @param $merchantSecret
     *
     * @param mixed $merchantId
     * @param mixed $merchantSecret
     * @param $merchantId
     */
    public function __construct($merchantId, $merchantSecret) {}

    /**
     * @return $this
     */
    protected function setDefaultValues() {}

    /**
     * Set the Payment info
     *
     * @param mixed $stamp
     * @param mixed $reference
     * @param mixed $amount
     * @param $amount
     * @return $this
     */
    public function setPaymentData($stamp, $reference, $amount) {}

    /**
     *   Calculates MAC string from all variables in the class
     *
     * @return string
     */
    public function calculateMac() {}

    /**
     * @return string
     */
    public function getVersion() {}

    /**
     * @param string $version
     * @param string $$version
     */
    public function setVersion($version) {}

    /**
     * @return string
     */
    public function getStamp() {}

    /**
     * @param string $stamp
     * @param string $$stamp
     */
    public function setStamp($stamp) {}

    /**
     * @return string
     */
    public function getReference() {}

    /**
     * @param string $reference
     * @param string $$reference
     */
    public function setReference($reference) {}

    /**
     * @return string
     */
    public function getMerchantId() {}

    /**
     * @param string $merchantId
     * @param string $$merchantId
     */
    public function setMerchantId($merchantId) {}

    /**
     * @return string
     */
    public function getMerchantSecret() {}

    /**
     * @param string $merchantSecret
     * @param string $$merchantSecret
     */
    public function setMerchantSecret($merchantSecret) {}

    /**
     * @return string
     */
    public function getAmount() {}

    /**
     * @param string $amount
     * @param string $$amount
     */
    public function setAmount($amount) {}

    /**
     * @return string
     */
    public function getCurrency() {}

    /**
     * @param string $currency
     * @param string $$currency
     */
    public function setCurrency($currency) {}

    /**
     * @return string
     */
    public function getFormat() {}

    /**
     * @param string $format
     * @param string $$format
     */
    public function setFormat($format) {}

    /**
     * @return string
     */
    public function getAlgorithm() {}

    /**
     * @param string $algorithm
     * @param string $$algorithm
     */
    public function setAlgorithm($algorithm) {}

}
