namespace Checkout;

use Checkout\Exceptions\AmountTooLargeException;
use Checkout\Exceptions\AmountUnderMinimumException;
use Checkout\Exceptions\CurrencyNotSupportedException;
use Checkout\Exceptions\UrlTooLongException;
use Checkout\Exceptions\VariableTooLongException;
/**
 * Class Payment
 * @package CheckoutFinland
 */
class Payment
{
    /**
     * @var string Merchant id (AN 20)
     */
    protected merchantId;
    /**
     * @var string Secret merchant key
     */
    protected merchantSecret;
    /**
     * @var string Payment version, currently always '0001' (AN 4)
     */
    protected version;
    /**
     * @var string Unique identifier for the payment (AN 20)
     */
    protected stamp;
    /**
     * @var string Amount of payment in cents (10€ == 1000) (N 8)
     */
    protected amount;
    /**
     * @var string Reference number for the payment, recommended to be unique but not forced (AN 20)
     */
    protected reference;
    /**
     * @var string Message/Description for the buyer (Nuts and bolts, Furniture, Cuckoo clocks) (AN 1000)
     */
    protected message;
    /**
     * @var string Language of the payment selection page/bank interface if supported. Currently supported languages include Finnish FI, Swedish SE and English EN (AN  2)
     */
    protected language;
    /**
     * @var string Url called when returning successfully (AN 300)
     */
    protected returnUrl;
    /**
     * @var string Url called when user cancelled payment (AN 300)
     */
    protected cancelUrl;
    /**
     * @var string Url called when payment was rejected (No credit on credit card etc) (AN 300)
     */
    protected rejectUrl;
    /**
     * @var string Url called when payment is initially successful but not yet confirmed (AN 300)
     */
    protected delayedUrl;
    /**
     * @var string Country of the buyer, affects available payment methods (AN 3)
     */
    protected country;
    /**
     * @var string Currency used in payment. Currently only EUR is supported (AN 3)
     */
    protected currency;
    /**
     * @var string device or method used when creating new transaction. Affects how Checkout servers respond to posting the new payment 1 = HTML 10 = XML (N 2)
     */
    protected device;
    /**
     * @var string Payment type or content of purchase. Used to differentiate between adult entertainment and everything else. 1 = normal, 2 = adult entertainment (N 2)
     */
    protected content;
    /**
     * @var string Type, currently always 0 (N 1)
     */
    protected type;
    /**
     * @var string Algorithm used when calculating mac, currently = 3. 1 and 2 are still available but deprecated (N 1)
     */
    protected algorithm;
    /**
     * @var \DateTime Expected delivery date (N 8) (Ymd)
     */
    protected deliveryDate;
    /**
     * @var string First name of customer (AN 40)
     */
    protected firstName;
    /**
     * @var string Last name of customer (AN 40)
     */
    protected familyName;
    /**
     * @var string Street address of customer (AN 40)
     */
    protected address;
    /**
     * @var string Postcode of customer (AN 14)
     */
    protected postcode;
    /**
     * @var string Post office of customer (AN 18)
     */
    protected postOffice;
    /**
     * @var bool If true overrides the minimum allowed amount check (by default 1€ is smallest allowed amount). Do not set to true unless you have a contract with Checkout Finland that allows smaller purchases then 1€.
     */
    protected allowSmallPurchases;
    /**
     * @param $merchantId
     * @param $merchantSecret
     * @param $allowSmallPurchases
     */
    public function __construct(merchantId, merchantSecret, allowSmallPurchases = false) -> void
    {
        let this->merchantId = merchantId;
        let this->merchantSecret = merchantSecret;
        let this->allowSmallPurchases = allowSmallPurchases;
        this->setDefaultValues();
    }

    /**
     * @return $this
     */
    protected function setDefaultValues()
    {
        let this->version = "0001";
        let this->device = "10";
        let this->content = "1";
        let this->type = "0";
        let this->algorithm = "3";
        let this->currency = "EUR";
        return this;
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
    public function setOrderData(stamp, amount, reference, message, <DateTime> deliveryDate)
    {
        this->setStamp(stamp);
        this->setAmount(amount);
        this->setReference(reference);
        this->setMessage(message);
        this->setDeliveryDate(deliveryDate);
        return this;
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
    public function setCustomerData(firstName, familyName, address, postcode, postOffice, country, language)
    {
        this->setFirstName(firstName);
        this->setFamilyName(familyName);
        this->setAddress(address);
        this->setPostcode(postcode);
        this->setPostOffice(postOffice);
        this->setCountry(country);
        this->setLanguage(language);
        return this;
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
    public function setData(array params)
    {
        var key, value, setter_name;

        for key, value in params {
            let setter_name =  "set" . ucfirst(key);
            if method_exists(this, setter_name) {
                this->{setter_name}(value);
            }
        }
        return this;
    }

    /**
     * Set all response urls as the same return url.
     *
     * @param string $returnUrl
     * @throws UrlTooLongException
     * @return $this
     */
    public function setUrls(string returnUrl)
    {
        this->setReturnUrl(returnUrl);
        this->setCancelUrl(returnUrl);
        this->setDelayedUrl(returnUrl);
        this->setRejectUrl(returnUrl);
        return this;
    }

    /**
     *   Calculates MAC string from all variables in the class
     *
     *   @return string
     */
    public function calculateMac() -> string | null
    {
        var mac_string;

        let mac_string =  this->getVersion();
        let mac_string .= "+" . this->getStamp();
        let mac_string .= "+" . this->getAmount();
        let mac_string .= "+" . this->getReference();
        let mac_string .= "+" . this->getMessage();
        let mac_string .= "+" . this->getLanguage();
        let mac_string .= "+" . this->getMerchantId();
        let mac_string .= "+" . this->getReturnUrl();
        let mac_string .= "+" . this->getCancelUrl();
        let mac_string .= "+" . this->getRejectUrl();
        let mac_string .= "+" . this->getDelayedUrl();
        let mac_string .= "+" . this->getCountry();
        let mac_string .= "+" . this->getCurrency();
        let mac_string .= "+" . this->getDevice();
        let mac_string .= "+" . this->getContent();
        let mac_string .= "+" . this->getType();
        let mac_string .= "+" . this->getAlgorithm();
        let mac_string .= "+" . this->getDeliveryDate()->format("Ymd");
        let mac_string .= "+" . this->getFirstName();
        let mac_string .= "+" . this->getFamilyName();
        let mac_string .= "+" . this->getAddress();
        let mac_string .= "+" . this->getPostcode();
        let mac_string .= "+" . this->getPostOffice();
        let mac_string .= "+" . this->getMerchantSecret();
        return strtoupper(md5(mac_string));
    }

    /**
     * @return string
     */
    public function getAddress() -> string | null
    {
        return this->address;
    }

    /**
     * @param string $address
     * @return $this
     */
    public function setAddress(string address)
    {
        let this->address =  substr(address, 0, 40);
        return this;
    }

    /**
     * @return string
     */
    public function getAlgorithm() -> string | null
    {
        return this->algorithm;
    }

    /**
     * @param string $algorithm
     * @return $this
     */
    public function setAlgorithm(string algorithm)
    {
        let this->algorithm = algorithm[0];
        return this;
    }

    /**
     * @return string
     */
    public function getAmount() -> string | null
    {
        return this->amount;
    }

    /**
     * @param string $amount
     * @throws AmountTooLargeException
     * @throws AmountUnderMinimumException
     * @return $this
     */
    public function setAmount(int amount)
    {
        if strlen(amount) > 8 {
            throw new AmountTooLargeException(amount . " is too large.");
        }
        if this->allowSmallPurchases === false && amount < 100 {
            throw new AmountUnderMinimumException("1€ is the minimum allowed amount.");
        }
        let this->amount = amount;
        return this;
    }

    /**
     * @return string
     */
    public function getCancelUrl() -> string | null
    {
        return this->cancelUrl;
    }

    /**
     * @param string $cancelUrl
     * @throws UrlTooLongException
     * @return $this
     */
    public function setCancelUrl(string cancelUrl)
    {
        if strlen(cancelUrl) > 300 {
            throw new UrlTooLongException("Max url length is 300 characters");
        }
        let this->cancelUrl = cancelUrl;
        return this;
    }

    /**
     * @return string
     */
    public function getContent() -> string | null
    {
        return this->content;
    }

    /**
     * @param string $content
     * @return $this
     */
    public function setContent(string content)
    {
        let this->content =  substr(content, 0, 2);
        return this;
    }

    /**
     * @return string
     */
    public function getCountry() -> string | null
    {
        return this->country;
    }

    /**
     * @param string $country
     * @return $this
     */
    public function setCountry(string country)
    {
        let this->country =  substr(country, 0, 3);
        return this;
    }

    /**
     * @return string
     */
    public function getCurrency() -> string | null
    {
        return this->currency;
    }

    /**
     * @param string $currency
     * @throws CurrencyNotSupportedException
     * @return $this
     */
    public function setCurrency(string currency)
    {
        if strtoupper(currency) !== "EUR" {
            throw new CurrencyNotSupportedException("EUR is currently the only supported currency");
        }
        let this->currency = currency;
        return this;
    }

    /**
     * @return string
     */
    public function getDelayedUrl() -> string | null
    {
        return this->delayedUrl;
    }

    /**
     * @param string $delayedUrl
     * @throws UrlTooLongException
     * @return $this
     */
    public function setDelayedUrl(string delayedUrl)
    {
        if strlen(delayedUrl) > 300 {
            throw new UrlTooLongException("Max url length is 300 characters");
        }
        let this->delayedUrl = delayedUrl;
        return this;
    }

    /**
     * @param $format
     * @return mixed
     */
    public function getDeliveryDate(format = null)
    {
        if format {
            return this->deliveryDate->format(format);
        }
        return this->deliveryDate;
    }

    /**
     * @param \DateTime $deliveryDate
     * @return $this
     */
    public function setDeliveryDate(<DateTime> deliveryDate)
    {
        let this->deliveryDate = deliveryDate;
        return this;
    }

    /**
     * @return string
     */
    public function getDevice() -> string | null
    {
        return this->device;
    }

    /**
     * @param string $device
     * @return $this
     */
    public function setDevice(string device)
    {
        let this->device =  substr(device, 0, 2);
        return this;
    }

    /**
     * @return string
     */
    public function getFamilyName() -> string | null
    {
        return this->familyName;
    }

    /**
     * @param string $familyName
     * @return $this
     */
    public function setFamilyName(string familyName)
    {
        let this->familyName =  substr(familyName, 0, 40);
        return this;
    }

    /**
     * @return string
     */
    public function getFirstName() -> string | null
    {
        return this->firstName;
    }

    /**
     * @param string $firstName
     * @return $this
     */
    public function setFirstName(string firstName)
    {
        let this->firstName =  substr(firstName, 0, 40);
        return this;
    }

    /**
     * @return string
     */
    public function getLanguage() -> string | null
    {
        return this->language;
    }

    /**
     * @param string $language
     * @return $this
     */
    public function setLanguage(string language)
    {
        let this->language =  substr(language, 0, 2);
        return this;
    }

    /**
     * @return string
     */
    public function getMerchantId() -> string | null
    {
        return this->merchantId;
    }

    /**
     * @param string $merchantId
     * @throws VariableTooLongException
     * @return $this
     */
    public function setMerchantId(string merchantId)
    {
        if strlen(merchantId) > 20 {
            throw new VariableTooLongException("Merchant id: {merchantId} too long, max length is 20 characters");
        }
        let this->merchantId = merchantId;
        return this;
    }

    /**
     * @return string
     */
    public function getMerchantSecret() -> string | null
    {
        return this->merchantSecret;
    }

    /**
     * @param string $merchantSecret
     * @return $this
     */
    public function setMerchantSecret(string merchantSecret)
    {
        let this->merchantSecret = merchantSecret;
        return this;
    }

    /**
     * @return string
     */
    public function getMessage() -> string | null
    {
        return this->message;
    }

    /**
     * @param string $message
     * @return $this
     */
    public function setMessage(string message)
    {
        let this->message =  substr(message, 0, 1000);
        return this;
    }

    /**
     * @return string
     */
    public function getPostOffice() -> string | null
    {
        return this->postOffice;
    }

    /**
     * @param string $postOffice
     * @return $this
     */
    public function setPostOffice(string postOffice)
    {
        let this->postOffice =  substr(postOffice, 0, 18);
        return this;
    }

    /**
     * @return string
     */
    public function getPostcode() -> string | null
    {
        return this->postcode;
    }

    /**
     * @param string $postcode
     * @return $this
     */
    public function setPostcode(string postcode)
    {
        let this->postcode =  substr(postcode, 0, 14);
        return this;
    }

    /**
     * @return string
     */
    public function getReference() -> string | null
    {
        return this->reference;
    }

    /**
     * @param string $reference
     * @throws VariableTooLongException
     * @return $this
     */
    public function setReference(string reference)
    {
        if strlen(reference) > 20 {
            throw new VariableTooLongException("Reference: {reference} too long, max length is 20 characters.");
        }
        let this->reference = reference;
        return this;
    }

    /**
     * @return string
     */
    public function getRejectUrl() -> string | null
    {
        return this->rejectUrl;
    }

    /**
     * @param string $rejectUrl
     * @throws UrlTooLongException
     * @return $this
     */
    public function setRejectUrl(string rejectUrl)
    {
        if strlen(rejectUrl) > 300 {
            throw new UrlTooLongException("Max url length is 300 characters");
        }
        let this->rejectUrl = rejectUrl;
        return this;
    }

    /**
     * @return string
     */
    public function getReturnUrl() -> string | null
    {
        return this->returnUrl;
    }

    /**
     * @param string $returnUrl
     * @throws UrlTooLongException
     * @return $this
     */
    public function setReturnUrl(string returnUrl)
    {
        if strlen(returnUrl) > 300 {
            throw new UrlTooLongException("Max url length is 300 characters");
        }
        let this->returnUrl = returnUrl;
        return this;
    }

    /**
     * @return string
     */
    public function getStamp() -> string | null
    {
        return this->stamp;
    }

    /**
     * @param string $stamp
     * @throws VariableTooLongException
     * @return $this
     */
    public function setStamp(string stamp)
    {
        if strlen(stamp) > 20 {
            throw new VariableTooLongException("Stamp: {stamp} too long, max length is 20 characters.");
        }
        let this->stamp = stamp;
        return this;
    }

    /**
     * @return string
     */
    public function getType() -> string | null
    {
        return this->type;
    }

    /**
     * @param string $type
     * @return $this
     */
    public function setType(string type)
    {
        let this->type = type[0];
        return this;
    }

    /**
     * @return string
     */
    public function getVersion() -> string | null
    {
        return this->version;
    }

    /**
     * @param string $version
     * @return $this
     */
    public function setVersion(string version)
    {
        let this->version =  substr(version, 0, 4);
        return this;
    }

}