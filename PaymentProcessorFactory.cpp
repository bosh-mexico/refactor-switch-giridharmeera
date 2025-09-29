#include "PaymentProcessorFactory.h"
#include <memory>

PaymentProcessorFactory::PaymentProcessorFactory() {
    registry["PayPal"]     = [] { return make_unique<PayPalProcessor>(); };
    registry["GooglePay"]  = [] { return make_unique<GooglePayProcessor>(); };
    registry["CreditCard"] = [] { return make_unique<CreditCardProcessor>(); };
}

unique_ptr<IPaymentProcessor> PaymentProcessorFactory::create(const string& mode) const {
    auto it = registry.find(mode);
    if (it != registry.end()) {
        return it->second();
    }
    throw invalid_argument("Invalid payment mode selected: " + mode);
}
