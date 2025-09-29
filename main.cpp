#include "PaymentProcessorFactory.h"

int main() {
    PaymentProcessorFactory factory;
    auto processor = factory.create("PayPal");
    processor->processPayment(200.0);
}
