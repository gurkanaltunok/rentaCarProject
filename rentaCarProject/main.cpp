//
//  main.cpp
//  rentaCarProject
//
//  Created by Oğuz Gürkan Altunok on 10.12.2024.
//

#include <iostream>
#include <string>
using namespace std;

// Abstract base class for rental services
class RentalService {
public:
    // Function to display service information
    virtual void displayServiceInfo() const = 0;
    // Function to process car rental
    virtual void processRent() = 0;
    virtual ~RentalService() {}
};

// Base class for representing car
class Car {
protected:
    string brand;
    string model;
    string id;
    int price;

public:
    Car(const string& brand, const string& model, const string& id, int price)
        : brand(brand), model(model), id(id), price(price) {}

    // Function to display car details
    virtual void display() const {
        cout << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }

    // Fnction to get the type of car
    virtual string getType() const = 0;

    // Function to get the price of the car
    int getPrice() const {
        return price;
    }

    virtual ~Car() {}
};

// Class for PremiumCar, inherited from Car
class PremiumCar : public Car {
public:
    PremiumCar(const string& brand, const string& model, const string& id, int price)
        : Car(brand, model, id, price) {}

    // Override display function to include car type
    void display() const override {
        cout << "[Premium] " << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }

    // Override function to return the car type
    string getType() const override {
        return "Premium";
    }
};

// Class representing an EconomyCar, inherited from Car
class EconomyCar : public Car {
public:
    EconomyCar(const string& brand, const string& model, const string& id, int price)
        : Car(brand, model, id, price) {}

    // Override display function to include car type
    void display() const override {
        cout << "[Economy] " << "Brand: " << brand << ", Model: " << model << ", ID: " << id << ", Price: " << price << endl;
    }

    // Override function to return the car type
    string getType() const override {
        return "Economy";
    }
};

// Class representing the CarRentalService, inherited from RentalService
class CarRentalService : public RentalService {
private:
    Car** cars;  // Array of car pointers
    int carCount; // Total number of cars

public:
    CarRentalService(Car* cars[], int carCount)
        : cars(cars), carCount(carCount) {}

    // Display information about the service
    void displayServiceInfo() const override {
        cout << "*** Welcome to Altunok Rent a Car ***\n";
    }

    // Display available cars of a input type
    void displayCars(const string& type) const {
        cout << "\nAvailable " << type << " Cars:\n";
        for (int i = 0; i < carCount; ++i) {
            if (cars[i]->getType() == type) {
                cout << "[" << i + 1 << "] ";
                cars[i]->display();
            }
        }
    }

    // Select a car of a input type
    Car* selectCar(const string& type) {
        displayCars(type);

        int carChoice;
        cout << "\nEnter the number of the car you want to rent: ";
        cin >> carChoice;

        if (carChoice > 0 && carChoice <= carCount && cars[carChoice - 1]->getType() == type) {
            return cars[carChoice - 1];
        }
        cout << "Invalid car selection. Returning to main menu.\n";
        return nullptr;
    }

    // Process the rental of a car
    void processRent() override {
        int carType;
        cout << "\nSelect the type of car:\n";
        cout << "[1] Premium Cars\n";
        cout << "[2] Economy Cars\n";
        cout << "Enter your choice: ";
        cin >> carType;

        string type = (carType == 1) ? "Premium" : (carType == 2) ? "Economy" : "";
        if (type.empty()) {
            cout << "Invalid choice. Returning to main menu.\n";
            return;
        }

        Car* selectedCar = selectCar(type);
        if (!selectedCar) return;

        // Taking rental details from the user
        string name, phone, startDate;
        int days;

        cout << "\nEnter your full name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phone);
        cout << "Enter the rental start date (YYYY-MM-DD): ";
        getline(cin, startDate);
        cout << "Enter the number of days you want to rent the car: ";
        cin >> days;

        // Calculate total cost and display reservation details
        int totalCost = selectedCar->getPrice() * days;
        cout << "\nReservation Details:\n";
        cout << "Name: " << name << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "Start Date: " << startDate << "\n";
        cout << "Total Cost: " << totalCost << "\n";

        // Confirm the reservation
        int confirm;
        cout << "\nDo you confirm the reservation? (1 for Yes, 2 for No): ";
        cin >> confirm;
        if (confirm == 1) {
            cout << "\nYour reservation is confirmed. Thank you for choosing Altunok Rent a Car!\n";
        } else {
            cout << "\nReservation cancelled. Returning to main menu.\n";
        }
    }
};

// Function to display the options menu
void optionsMenu(RentalService& service) {
    int choice;
    do {
        cout << "\nOptions:\n";
        cout << "[1] Get information about renting a car\n";
        cout << "[2] Rent a car\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            service.displayServiceInfo();
            break;

        case 2:
            service.processRent();
            break;

        case 3:
            cout << "\nThank you for using our service! Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    // Writing a list of cars
    Car* cars[] = {
        new PremiumCar("Mercedes", "C220", "1", 2000),
        new PremiumCar("Mercedes", "E350", "2", 2000),
        new PremiumCar("BMW", "4.20d", "3", 1800),
        new PremiumCar("Audi", "A5", "4", 1800),
        new PremiumCar("Audi", "A3", "5", 1600),
        new EconomyCar("Mazda", "Demio", "6", 1200),
        new EconomyCar("Hyundai", "i20", "7", 600),
        new EconomyCar("Suzuki", "Swift", "8", 800),
        new EconomyCar("Volkswagen", "Golf", "9", 1200),
        new EconomyCar("Nissan", "March", "10", 600)
    };

    int carCount = sizeof(cars) / sizeof(cars[0]);

    CarRentalService carRental(cars, carCount);

    // Display the options menu
    optionsMenu(carRental);


    return 0;
}
