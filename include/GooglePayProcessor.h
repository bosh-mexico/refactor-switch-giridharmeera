#pragma once
#include "IPaymentProcessor.h"

class GooglePayProcessor : public IPaymentProcessor {
public:
    void processPayment(double amount) override;
};
