#include <iostream>
#include "PaymentProcessorFactory.h"

using namespace std;

// Checkout Function
void checkout(const string& mode, double amount, const PaymentProcessorFactory& factory) {
    try {
        auto processor = factory.create(mode);
        processor->process(amount);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
}

int main() {
    PaymentProcessorFactory factory;
    double amount = 150.75;

    checkout("PayPal", amount, factory);
    checkout("GooglePay", amount, factory);
    checkout("CreditCard", amount, factory);
    checkout("Bitcoin", amount, factory); // Unsupported mode

    return 0;
}
