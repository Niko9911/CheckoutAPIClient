<?php

namespace Checkout;

/**
 * Class Response
 *
 * @package CheckoutFinland
 */
class Response
{
    /**
     * @var string Secret merchant key
     */
    protected $merchant_secret;

    /**
     * @var string Payment version, currently always '0001'
     */
    protected $version;

    /**
     * @var string Unique identifier for the payment, set by merchant when creating new payment
     */
    protected $stamp;

    /**
     * @var string Reference number for the payment, set by merchant when creating new payment, recommended to be unique but not forced
     */
    protected $reference;

    /**
     * @var string Archive id/Unique id for the payment, set by Checkout Finland
     */
    protected $payment;

    /**
     * @var integer
     */
    protected $status;

    /**
     * @var integer
     */
    protected $algorithm;

    /**
     * @var string
     */
    protected $mac;


    /**
     * @param mixed $merchant_secret
     * @param $merchant_secret
     */
    public function __construct($merchant_secret) {}

    /**
     * @throws MacMismatchException
     * @throws UnsupportedAlgorithmException
     * @return bool
     */
    public function validate() {}

    /**
     * @param mixed $params
     * @param $params
     * @return $this
     */
    public function setRequestParams($params) {}

    /**
     * @return mixed
     */
    public function getAlgorithm() {}

    /**
     * @param mixed $algorithm
     * @param mixed $$algorithm
     * @return $this
     */
    public function setAlgorithm($algorithm) {}

    /**
     * @return mixed
     */
    public function getMac() {}

    /**
     * @param mixed $mac
     * @param mixed $$mac
     * @return $this
     */
    public function setMac($mac) {}

    /**
     * @return string
     */
    public function getMerchantSecret() {}

    /**
     * @param string $merchant_secret
     * @param string $$merchant_secret
     * @return $this
     */
    public function setMerchantSecret($merchant_secret) {}

    /**
     * @return string
     */
    public function getPayment() {}

    /**
     * @param string $payment
     * @param string $$payment
     * @return $this
     */
    public function setPayment($payment) {}

    /**
     * @return string
     */
    public function getReference() {}

    /**
     * @param string $reference
     * @param string $$reference
     * @return $this
     */
    public function setReference($reference) {}

    /**
     * @return string
     */
    public function getStamp() {}

    /**
     * @param string $stamp
     * @param string $$stamp
     * @return $this
     */
    public function setStamp($stamp) {}

    /**
     * @return int
     */
    public function getStatus() {}

    /**
     * @param int $status
     * @param int $$status
     * @return $this
     */
    public function setStatus($status) {}

    /**
     * @return int
     */
    public function getVersion() {}

    /**
     * @param string $version
     * @param string $$version
     * @return $this
     */
    public function setVersion($version) {}

}
