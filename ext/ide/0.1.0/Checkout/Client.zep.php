<?php

namespace Checkout;

/**
 * Class Client
 *
 * @package CheckoutFinland
 */
class Client
{

    /**
     * Builds an array that can be passed to Checkout Finland as POST parameters. Sends the data. Returns the response body
     * that contains payment options xml or error message.
     *
     * @throws \Exception
     * @param \Checkout\Payment $payment
     * @param Payment $$payment
     * @return string
     */
    public function sendPayment(\Checkout\Payment $payment) {}

    /**
     * Poll payment, returns with xml containing payment info or error message
     *
     * @throws \Exception
     * @param Poll $poll
     * @param Poll $$poll
     * @return string
     */
    public function poll(Poll $poll) {}

    /**
     * Posts data, tries to use stream context if allow_url_fopen is on in php.ini or CURL if not. If neither option is available throws exception.
     *
     * @throws \Exception
     * @param mixed $url
     * @param mixed $postData
     * @param $postData
     * @return string|null
     */
    protected function postData($url, $postData) {}

}
