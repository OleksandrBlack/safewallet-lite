#include "camount.h"
#include "settings.h"

#include "precompiled.h"

const int NUMPLACES = 8;
const qint64 COIN = 100000000;

double CAmount::toDecimalDouble() const {
    return static_cast<double>(this->amount) / COIN;
}

QString CAmount::toDecimalString() const {
    if (amount < 0) {
        CAmount negative(-1 * this->amount);
        return "-" + negative.toDecimalString();
    }

    int wholePart = amount / COIN;
    int decimalPart = amount % COIN;

    QString r = QString::number(wholePart);
    if (decimalPart > 0) {
        QString decimalPartStr = QString::number(decimalPart);
        r = r + "." + decimalPartStr.rightJustified(NUMPLACES, '0');

        // Trim tailing 0s
        while (r.right(1) == "0") {
            r = r.left(r.length() - 1);
        }
    }

    return r;
}

QString CAmount::toDecimalUSDString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getZECPrice();

    return "$ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}

QString CAmount::toDecimalEURString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getEURPrice();

    return QLocale(QLocale::German).toString(dblAmount*price, 'f', 2) + " €";
}
QString CAmount::toDecimalBTCString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getBTCPrice();

    return "BTC " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 9);
}
QString CAmount::toDecimalCNYString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getCNYPrice();

    return "¥ /元  " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalRUBString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getRUBPrice();

    return "₽ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalCADString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getCADPrice();

    return "$ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalSGDString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getSGDPrice();

    return "$ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalCHFString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getCHFPrice();

    return "CHF " + QLocale(QLocale::German).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalINRString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getINRPrice();

    return "₹ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalGBPString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getGBPPrice();

    return "£ " + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}
QString CAmount::toDecimalUAHString() const {
    double uahAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getUAHPrice();

    return "₴ " + QLocale(QLocale::English).toString(uahAmount*price, 'f', 2);
}
QString CAmount::toDecimalAUDString() const {
    double dblAmount = static_cast<double>(this->amount) / COIN;
    double price = Settings::getInstance()->getAUDPrice();

    return " $" + QLocale(QLocale::English).toString(dblAmount*price, 'f', 2);
}

QString CAmount::toDecimalsafecoinString() const {
    return this->toDecimalString() % " " % Settings::getTokenName();
}

QString CAmount::toDecimalsafecoinUSDString() const {
    auto usdString = this->toDecimalUSDString();
    if (!usdString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % usdString % ")";
    else
        return this->toDecimalsafecoinString();
}


QString CAmount::toDecimalsafecoinEURString() const {
    auto eurString = this->toDecimalEURString();
    if (!eurString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % eurString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinBTCString() const {
    auto btcString = this->toDecimalBTCString();
    if (!btcString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % btcString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinCNYString() const {
    auto cnyString = this->toDecimalCNYString();
    if (!cnyString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % cnyString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinRUBString() const {
    auto rubString = this->toDecimalRUBString();
    if (!rubString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % rubString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinCADString() const {
    auto cadString = this->toDecimalCADString();
    if (!cadString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % cadString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinSGDString() const {
    auto sgdString = this->toDecimalSGDString();
    if (!sgdString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % sgdString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinCHFString() const {
    auto chfString = this->toDecimalCHFString();
    if (!chfString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % chfString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinINRString() const {
    auto inrString = this->toDecimalINRString();
    if (!inrString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % inrString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinGBPString() const {
    auto gbpString = this->toDecimalGBPString();
    if (!gbpString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % gbpString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinUAHString() const {
    auto uahString = this->toDecimalUAHString();
    if (!uahString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % uahString % ")";
    else
        return this->toDecimalsafecoinString();
}

QString CAmount::toDecimalsafecoinAUDString() const {
    auto audString = this->toDecimalAUDString();
    if (!audString.isEmpty())
        return this->toDecimalsafecoinString() % " (" % audString % ")";
    else
        return this->toDecimalsafecoinString();
}


CAmount CAmount::fromDecimalString(QString decimalString) {
    auto amtParts = decimalString.split(".");
    qint64 r = amtParts[0].toULongLong() * COIN;
    if (amtParts.length() == 2) {
        auto trailingZeros = QString("0").repeated(NUMPLACES - amtParts[1].length());
        r += QString(amtParts[1] + trailingZeros).toULongLong();
    }

    return CAmount(r);
}