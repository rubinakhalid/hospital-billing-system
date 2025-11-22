// main.cpp
// Project 3: Hospital Charges

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double calculateCharges(int daysSpent, double dailyRate,
                        double medCharges, double serviceCharges);
double calculateCharges(double medCharges, double serviceCharges);

int main() {
    char patientType;

    cout << "Was the patient an in-patient (I) or an out-patient (O)? ";
    cin >> patientType;

    // Validate patient type
    while (patientType != 'I' && patientType != 'O' &&
           patientType != 'i' && patientType != 'o') {
        cout << "Invalid input. Please enter 'I' for in-patient or 'O' for out-patient: ";
        cin >> patientType;
    }

    cout << fixed << setprecision(2);

    if (patientType == 'I' || patientType == 'i') {
        // In-patient
        int daysSpent;
        double dailyRate, medCharges, serviceCharges;

        cout << "Enter the number of days spent in the hospital: ";
        cin >> daysSpent;
        while (daysSpent < 0) {
            cout << "Invalid input. Enter a non-negative number of days: ";
            cin >> daysSpent;
        }

        cout << "Enter the daily rate: ";
        cin >> dailyRate;
        while (dailyRate < 0) {
            cout << "Invalid input. Enter a non-negative daily rate: ";
            cin >> dailyRate;
        }

        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        while (medCharges < 0) {
            cout << "Invalid input. Enter non-negative medication charges: ";
            cin >> medCharges;
        }

        cout << "Enter charges for hospital services (lab tests, etc.): ";
        cin >> serviceCharges;
        while (serviceCharges < 0) {
            cout << "Invalid input. Enter non-negative service charges: ";
            cin >> serviceCharges;
        }

        double total = calculateCharges(daysSpent, dailyRate, medCharges, serviceCharges);
        cout << "Total hospital charges: $" << total << endl;

    } else {
        // Out-patient
        double medCharges, serviceCharges;

        cout << "Enter hospital medication charges: ";
        cin >> medCharges;
        while (medCharges < 0) {
            cout << "Invalid input. Enter non-negative medication charges: ";
            cin >> medCharges;
        }

        cout << "Enter charges for hospital services (lab tests, etc.): ";
        cin >> serviceCharges;
        while (serviceCharges < 0) {
            cout << "Invalid input. Enter non-negative service charges: ";
            cin >> serviceCharges;
        }

        double total = calculateCharges(medCharges, serviceCharges);
        cout << "Total hospital charges: $" << total << endl;
    }

    return 0;
}

// Overloaded function for in-patient charges
double calculateCharges(int daysSpent, double dailyRate,
                        double medCharges, double serviceCharges) {
    return (daysSpent * dailyRate) + medCharges + serviceCharges;
}

// Overloaded function for out-patient charges
double calculateCharges(double medCharges, double serviceCharges) {
    return medCharges + serviceCharges;
}
