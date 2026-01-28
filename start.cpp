#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Vehicle {
public:
    string regNumber, ownerName, vehicleType;
    void getData() {
        cout << "Enter Registration Number: ";
        cin >> regNumber;
        cout << "Enter Owner Name: ";
        cin.ignore();
        getline(cin, ownerName);
        cout << "Enter Vehicle Type (Car/Bike/Truck): ";
        cin >> vehicleType;
    }
    void displayData() {
        cout << "Reg No: " << regNumber << ", Owner: " << ownerName << ", Type: " << vehicleType << endl;
    }
};

class Challan {
public:
    string regNumber;
    double fineAmount;
    string reason;

    void issueChallan() {
        cout << "Enter Vehicle Registration Number: ";
        cin >> regNumber;
        cout << "Enter Fine Amount: ";
        cin >> fineAmount;
        cout << "Enter Reason: ";
        cin.ignore();
        getline(cin, reason);
    }
    void displayChallan() {
        cout << "Reg No: " << regNumber << ", Fine: Rs. " << fineAmount << ", Reason: " << reason << endl;
    }
};

void saveVehicle(Vehicle v) {
    ofstream file("vehicles.txt", ios::app);
    file << v.regNumber << "," << v.ownerName << "," << v.vehicleType << endl;
    file.close();
}

void saveChallan(Challan c) {
    ofstream file("challans.txt", ios::app);
    file << c.regNumber << "," << c.fineAmount << "," << c.reason << endl;
    file.close();
}

void displayVehicles() {
    ifstream file("vehicles.txt");
    string line;
    cout << "\nStored Vehicle Records:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void displayChallans() {
    ifstream file("challans.txt");
    string line;
    cout << "\nIssued Challans:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\nTraffic Management System";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Issue Challan";
        cout << "\n3. View Vehicles";
        cout << "\n4. View Challans";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Vehicle v;
            v.getData();
            saveVehicle(v);
        } else if (choice == 2) {
            Challan c;
            c.issueChallan();
            saveChallan(c);
        } else if (choice == 3) {
            displayVehicles();
        } else if (choice == 4) {
            displayChallans();
        }
    } while (choice != 5);
    return 0;
}
