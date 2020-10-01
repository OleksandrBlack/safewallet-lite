#ifndef CAMOUNT_H
#define CAMOUNT_H

#include "precompiled.h"

class CAmount {
private:
    CAmount(qint64 amount) {
        this->amount = amount;
    }

    qint64 amount;

public:
    static CAmount fromDecimalString(QString decimalString);
    static CAmount fromqint64(qint64 a) {
        return CAmount(a);
    }
    static CAmount fromDouble(double d) {
        return CAmount::fromDecimalString(QString::number(d, 'f', 8));
    }

    CAmount() : amount(0) {};
    CAmount(const CAmount&) = default;
    ~CAmount() = default;

    double  toDecimalDouble() const;
    QString toDecimalString() const;
    QString toDecimalUSDString() const;
    QString toDecimalEURString() const;
    QString toDecimalBTCString() const;
    QString toDecimalCNYString() const;
    QString toDecimalRUBString() const;
    QString toDecimalCADString() const;
    QString toDecimalSGDString() const;
    QString toDecimalCHFString() const;
    QString toDecimalINRString() const;
    QString toDecimalGBPString() const;
    QString toDecimalUAHString() const;
    QString toDecimalAUDString() const;
    QString toDecimalsafecoinString() const;
    QString toDecimalsafecoinUSDString() const;
    QString toDecimalsafecoinEURString() const;
    QString toDecimalsafecoinBTCString() const;
    QString toDecimalsafecoinCNYString() const;
    QString toDecimalsafecoinRUBString() const;
    QString toDecimalsafecoinCADString() const;
    QString toDecimalsafecoinSGDString() const;
    QString toDecimalsafecoinCHFString() const;
    QString toDecimalsafecoinINRString() const;
    QString toDecimalsafecoinGBPString() const;
    QString toDecimalsafecoinUAHString() const;
    QString toDecimalsafecoinAUDString() const;
    
    qint64  toqint64() const { return amount; };

    CAmount operator+ (const CAmount& other) const {
        return CAmount(this->amount + other.amount);
    }  

    CAmount operator- (const CAmount& other) const {
        return CAmount(this->amount - other.amount);
    }

    bool operator< (const CAmount& other) const {
        return this->amount < other.amount;
    }

    bool operator< (const qint64& other) const {
        return this->amount < other;
    }

    bool operator> (const CAmount& other) const {
        return this->amount > other.amount;
    }
    bool operator== (const qint64 other) const {
        return this->amount == other;
    }
};

#endif // CAMOUNT_H
