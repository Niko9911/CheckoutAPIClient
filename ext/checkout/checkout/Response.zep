namespace Checkout;

use Checkout\Exceptions\MacMismatchException;
use Checkout\Exceptions\UnsupportedAlgorithmException;
/**
 * Class Response
 * @package CheckoutFinland
 */
class Response
{
    /**
     * @var string Secret merchant key
     */
    protected merchant_secret;
    /**
     * @var string Payment version, currently always '0001'
     */
    protected version;
    /**
     * @var string Unique identifier for the payment, set by merchant when creating new payment
     */
    protected stamp;
    /**
     * @var string Reference number for the payment, set by merchant when creating new payment, recommended to be unique but not forced
     */
    protected reference;
    /**
     * @var string Archive id/Unique id for the payment, set by Checkout Finland
     */
    protected payment;
    /**
     * @var integer
     */
    protected status;
    /**
     * @var integer
     */
    protected algorithm;
    /**
     * @var string
     */
    protected mac;
    /**
     * @param $merchant_secret
     */
    public function __construct(merchant_secret) -> void
    {
        let this->merchant_secret = merchant_secret;
    }

    /**
     * @return bool
     * @throws MacMismatchException
     * @throws UnsupportedAlgorithmException
     */
    public function validate() -> bool
    {
        var expected_mac;

        let expected_mac =  null;
        /** @noinspection TypeUnsafeComparisonInspection */
        if this->algorithm == 3 {
            let expected_mac =  strtoupper(hash_hmac("sha256", "{this->version}&{this->stamp}&{this->reference}&{this->payment}&{this->status}&{this->algorithm}", this->merchant_secret));
        } else {
            throw new UnsupportedAlgorithmException("UnsupportedAlgorithm");
        }
        if expected_mac === this->mac {
            return true;
        }
        throw new MacMismatchException("MacMismatch");
    }

    /**
     * @param $params
     * @return $this
     */
    public function setRequestParams(params)
    {
        let params =  array_change_key_case(params, CASE_UPPER);
        let this->version =  isset params["VERSION"] ? params["VERSION"]  : null;
        let this->stamp =  isset params["STAMP"] ? params["STAMP"]  : null;
        let this->reference =  isset params["REFERENCE"] ? params["REFERENCE"]  : null;
        let this->payment =  isset params["PAYMENT"] ? params["PAYMENT"]  : null;
        let this->status =  isset params["STATUS"] ? params["STATUS"]  : null;
        let this->algorithm =  isset params["ALGORITHM"] ? params["ALGORITHM"]  : null;
        let this->mac =  isset params["MAC"] ? params["MAC"]  : null;
        return this;
    }

    /**
     * @return mixed
     */
    public function getAlgorithm()
    {
        return this->algorithm;
    }

    /**
     * @param mixed $algorithm
     * @return $this
     */
    public function setAlgorithm(algorithm)
    {
        let this->algorithm = algorithm;
        return this;
    }

    /**
     * @return mixed
     */
    public function getMac()
    {
        return this->mac;
    }

    /**
     * @param mixed $mac
     * @return $this
     */
    public function setMac(mac)
    {
        let this->mac = mac;
        return this;
    }

    /**
     * @return string
     */
    public function getMerchantSecret() -> string
    {
        return this->merchant_secret;
    }

    /**
     * @param string $merchant_secret
     * @return $this
     */
    public function setMerchantSecret(string merchant_secret)
    {
        let this->merchant_secret = merchant_secret;
        return this;
    }

    /**
     * @return string
     */
    public function getPayment() -> string
    {
        return this->payment;
    }

    /**
     * @param string $payment
     * @return $this
     */
    public function setPayment(string payment)
    {
        let this->payment = payment;
        return this;
    }

    /**
     * @return string
     */
    public function getReference() -> string
    {
        return this->reference;
    }

    /**
     * @param string $reference
     * @return $this
     */
    public function setReference(string reference)
    {
        let this->reference = reference;
        return this;
    }

    /**
     * @return string
     */
    public function getStamp() -> string
    {
        return this->stamp;
    }

    /**
     * @param string $stamp
     * @return $this
     */
    public function setStamp(string stamp)
    {
        let this->stamp = stamp;
        return this;
    }

    /**
     * @return int
     */
    public function getStatus() -> int
    {
        return this->status;
    }

    /**
     * @param int $status
     * @return $this
     */
    public function setStatus(int status)
    {
        let this->status = status;
        return this;
    }

    /**
     * @return int
     */
    public function getVersion() -> int
    {
        return this->version;
    }

    /**
     * @param string $version
     * @return $this
     */
    public function setVersion(string version)
    {
        let this->version = version;
        return this;
    }

}