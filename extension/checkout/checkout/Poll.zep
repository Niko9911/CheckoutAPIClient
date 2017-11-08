namespace Checkout;

class Poll
{
    /**
     * @var string Payment version, currently always '0001' (AN 4)
     */
    protected version;
    /**
     * @var string Unique identifier for the payment (AN 20)
     */
    protected stamp;
    /**
     * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
     */
    protected reference;
    /**
     * @var string Merchant id (AN 20)
     */
    protected merchantId;
    /**
     * @var string Secret merchant key
     */
    protected merchantSecret;
    /**
     * @var string Amount of payment in cents (10€ == 1000) (N 8)
     */
    protected amount;
    /**
     * @var string Currency used in payment. Currently only EUR is supported (AN 3)
     */
    protected currency;
    /**
     * @var string format Currently only 1
     */
    protected format;
    /**
     * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
     */
    protected algorithm;
    /**
     *	@param $merchantId
     *	@param $merchantSecret
     *
     */
    public function __construct(merchantId, merchantSecret) -> void
    {
        let this->merchantId = merchantId;
        let this->merchantSecret = merchantSecret;
        this->setDefaultValues();
    }

    /**
     * @return $this
     */
    protected function setDefaultValues()
    {
        let this->version = "0001";
        let this->algorithm = "3";
        let this->currency = "EUR";
        let this->format = "1";
        return this;
    }

    /**
     * Set the Payment info
     *
     * @param $stamp
     * @param $reference
     * @param $amount
     * @return $this
     */
    public function setPaymentData(stamp, reference, amount)
    {
        let this->stamp = stamp;
        let this->reference = reference;
        let this->amount = amount;
        return this;
    }

    /**
     *   Calculates MAC string from all variables in the class
     *
     *   @return string
     */
    public function calculateMac()
    {
        var mac_string;

        let mac_string =  this->getVersion();
        let mac_string .= "+" . this->getStamp();
        let mac_string .= "+" . this->getReference();
        let mac_string .= "+" . this->getMerchantId();
        let mac_string .= "+" . this->getAmount();
        let mac_string .= "+" . this->getCurrency();
        let mac_string .= "+" . this->getFormat();
        let mac_string .= "+" . this->getAlgorithm();
        return hash("sha256", mac_string . "+" . this->getMerchantSecret());
    }

    /**
     * @return string
     */
    public function getVersion() -> string
    {
        return this->version;
    }

    /**
     * @param string $version
     */
    public function setVersion(string version) -> void
    {
        let this->version = version;
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
     */
    public function setStamp(string stamp) -> void
    {
        let this->stamp = stamp;
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
     */
    public function setReference(string reference) -> void
    {
        let this->reference = reference;
    }

    /**
     * @return string
     */
    public function getMerchantId() -> string
    {
        return this->merchantId;
    }

    /**
     * @param string $merchantId
     */
    public function setMerchantId(string merchantId) -> void
    {
        let this->merchantId = merchantId;
    }

    /**
     * @return string
     */
    public function getMerchantSecret() -> string
    {
        return this->merchantSecret;
    }

    /**
     * @param string $merchantSecret
     */
    public function setMerchantSecret(string merchantSecret) -> void
    {
        let this->merchantSecret = merchantSecret;
    }

    /**
     * @return string
     */
    public function getAmount() -> string
    {
        return this->amount;
    }

    /**
     * @param string $amount
     */
    public function setAmount(string amount) -> void
    {
        let this->amount = amount;
    }

    /**
     * @return string
     */
    public function getCurrency() -> string
    {
        return this->currency;
    }

    /**
     * @param string $currency
     */
    public function setCurrency(string currency) -> void
    {
        let this->currency = currency;
    }

    /**
     * @return string
     */
    public function getFormat() -> string
    {
        return this->format;
    }

    /**
     * @param string $format
     */
    public function setFormat(string format) -> void
    {
        let this->format = format;
    }

    /**
     * @return string
     */
    public function getAlgorithm() -> string
    {
        return this->algorithm;
    }

    /**
     * @param string $algorithm
     */
    public function setAlgorithm(string algorithm) -> void
    {
        let this->algorithm = algorithm;
    }

}