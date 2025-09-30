#include <gtest/gtest.h>
#include "CreditCardProcessor.h"
#include "PayPalProcessor.h"
#include "GooglePayProcessor.h"
#include "PaymentProcessorFactory.h"

TEST(CreditCardProcessorTest, CanProcess) {
    CreditCardProcessor processor;
    EXPECT_NO_THROW(processor.processPayment(100.0));
}

TEST(PayPalProcessorTest, CanProcess) {
    PayPalProcessor processor;
    EXPECT_NO_THROW(processor.processPayment(200.5));
}

TEST(GooglePayProcessorTest, CanProcess) {
    GooglePayProcessor processor;
    EXPECT_NO_THROW(processor.processPayment(300.75));
}

TEST(PaymentProcessorFactoryTest, CreatesValidProcessor) {
    PaymentProcessorFactory factory;
    auto paypal = factory.create("PayPal");
    EXPECT_NO_THROW(paypal->processPayment(50));

    auto gpay = factory.create("GooglePay");
    EXPECT_NO_THROW(gpay->processPayment(75));

    auto credit = factory.create("CreditCard");
    EXPECT_NO_THROW(credit->processPayment(100));
}

TEST(PaymentProcessorFactoryTest, ThrowsOnInvalidProcessor) {
    PaymentProcessorFactory factory;
    EXPECT_THROW(factory.create("Bitcoin"), std::invalid_argument);
}
