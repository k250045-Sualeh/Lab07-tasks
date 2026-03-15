#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;  

public:
    Currency(double amt, string code, string symbol, double rate = 1.0) {
        amount = amt;
        currencyCode = code;
        currencySymbol = symbol;
        exchangeRate = rate;
    }

    
    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    double convertTo(Currency &targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount; 
    }

    void displayCurrency() override {
        cout << "US Dollar: $" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "Euro: €" << amount << endl;
    }
};


class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs ", 0.0036) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "Pakistani Rupee: Rs " << amount << endl;
    }
};


int main() {

    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(10000);

    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:\n";

    cout << "50 EUR in USD: " << eur.convertTo(usd) << endl;
    cout << "100 USD in EUR: " << usd.convertTo(eur) << endl;
    cout << "10000 PKR in USD: " << pkr.convertTo(usd) << endl;

    return 0;
}