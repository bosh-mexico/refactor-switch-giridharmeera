#pragma once
#include <iostream>

class IPaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPaymentProcessor() = default;
};
