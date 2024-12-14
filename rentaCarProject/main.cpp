//
//  main.cpp
//  rentaCarProject
//
//  Created by Oğuz Gürkan Altunok on 10.12.2024.
//

#include <iostream>
using namespace std;

void welcomeFunction(){
    cout<<"*** Welcome to Altunok Rent a Car ***"<<endl;
}

class Car {
protected:
    string brand;
    string model;
    string id;
    int price;

public:
    Car(const string& brand, const string& model, const string& id, int price)
        : brand(brand), model(model), id(id), price(price) {}

    virtual void display() const {
        cout << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }

    virtual ~Car() {}
};

class PremiumCar : public Car {
public:
    PremiumCar(const string& brand, const string& model, const string& id, int price)
        : Car(brand, model, id, price) {}

    void display() const override {
        cout << "[Premium] " << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }
};

class EconomyCar : public Car {
public:
    EconomyCar(const string& brand, const string& model, const string& id, int price)
        : Car(brand, model, id, price) {}

    void display() const override {
        cout << "[Economy] " << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }
};

int main() {
    welcomeFunction();

    vector<Car*> cars = {
        new PremiumCar("Mercedes", "C220", "01", 2000),
        new PremiumCar("Mercedes", "E350", "02", 2000),
        new PremiumCar("BMW", "4.20d", "06", 1800),
        new PremiumCar("Audi", "A5", "07", 1800),
        new PremiumCar("Audi", "A3", "08", 1600),
        new EconomyCar("Mazda", "Demio", "03", 1200),
        new EconomyCar("Hyundai", "i20", "04", 600),
        new EconomyCar("Suzuki", "Swift", "05", 800),
        new EconomyCar("Volkswagen", "Golf", "09", 1200),
        new EconomyCar("Nissan", "March", "10", 600)
        };

    for (const auto& car : cars) {
        car->display();
    }
    return 0;
}
