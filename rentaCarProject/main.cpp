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

struct account{
    char name[30];
    char password[30];
};

struct car{
    char brand[20];
    char model[20];
    string id;
    int price;
};

struct car cars[10]{
    {"Mercedes","C220", "01", 2000},
    {"Mercedes", "E350", "02", 2000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},
    {"Mazda", "Demio", "02", 1000},

};

void accountSelection(){
    int selection;


}

int main() {
    int balance;
    char askName[30];
    char askEmail[30];
    char askPhone[30];
    char askPassword[30];
    int selection;
    int carSelection;
    int number;
    int i;

    welcomeFunction();
    
    return 0;
}
