#pragma once
#include <memory>
#include <string>
#include <map>
#include <functional>
#include <stdexcept>

#include "IPaymentProcessor.h"
#include "PayPalProcessor.h"
#include "GooglePayProcessor.h"
#include "CreditCardProcessor.h"

using namespace std;

class PaymentProcessorFactory {
private:
    map<string, function<unique_ptr<IPaymentProcessor>()>> registry;

public:
    PaymentProcessorFactory();
    unique_ptr<IPaymentProcessor> create(const string& mode) const;
};
