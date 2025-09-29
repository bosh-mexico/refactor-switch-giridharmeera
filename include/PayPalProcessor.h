#pragma once
#include "IPaymentProcessor.h"

class PayPalProcessor : public IPaymentProcessor {
public:
    void processPayment(double amount) override;
};
