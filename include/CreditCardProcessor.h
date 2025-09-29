#pragma once
#include "IPaymentProcessor.h"

class CreditCardProcessor : public IPaymentProcessor {
public:
    void processPayment(double amount) override;
};
