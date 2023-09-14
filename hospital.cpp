#include <iostream>
#include <string>
using namespace std;

const int maxPatients = 10;

struct Patient {
    int patientID;
    string name;
    string phoneNumber;
    string address;
    int age;
    string diagnosis;
};

void admit_patient(Patient patients[], int &patientCount, int &patientIDCounter) {
    if (patientCount >= maxPatients) {
        cout << "Maximum patient limit reached." << endl;
    } else {
        Patient newPatient;
        newPatient.patientID = patientIDCounter++;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, newPatient.name);

        cout << "Enter Phone Number: ";
        cin >> newPatient.phoneNumber;

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, newPatient.address);

        cout << "Enter Age: ";
        cin >> newPatient.age;

        cout << "Enter Diagnosis: ";
        cin.ignore();
        getline(cin, newPatient.diagnosis);

        patients[patientCount++] = newPatient;
        cout << "Patient admitted with ID: " << newPatient.patientID << endl;
    }
}

void view_patient_list(Patient patients[], int patientCount) {
    cout << "List of Patients:" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < patientCount; ++i) {
        cout << "Patient ID: " << patients[i].patientID << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Phone Number: " << patients[i].phoneNumber << endl;
        cout << "Address: " << patients[i].address << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
        cout << "---------------------" << endl;
    }
}

void delete_patient(Patient patients[], int &patientCount) {
    int patientID;
    cout << "Enter the Patient ID to delete: ";
    cin >> patientID;

    bool found = false;
    for (int i = 0; i < patientCount; ++i) {
        if (patients[i].patientID == patientID) {
            found = true;
            for (int j = i; j < patientCount - 1; ++j) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            cout << "Patient with ID " << patientID << " has been deleted." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Patient with ID " << patientID << " not found." << endl;
    }
}

float calculate_patient_bill(const Patient &patient) {
    // You can implement your billing logic here based on the diagnosis.
    // For simplicity, let's assume a fixed bill amount of $500 for all patients.
    return 500.0;
}

int main() {
    Patient patients[maxPatients];
    int patientIDCounter = 1001;
    int patientCount = 0;

    int choice = -1;
    while (choice != 0) {
        cout << "Hospital Management System" << endl;
        cout << "1. Admit New Patient" << endl;
        cout << "2. View Patient List" << endl;
        cout << "3. Delete Patient" << endl;
        cout << "4. Calculate Patient Bill" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            admit_patient(patients, patientCount, patientIDCounter);
        } else if (choice == 2) {
            view_patient_list(patients, patientCount);
        } else if (choice == 3) {
            delete_patient(patients, patientCount);
        } else if (choice == 4) {
            cout << "Enter the Patient ID to calculate the bill: ";
            int patientID;
            cin >> patientID;
            bool found = false;
            for (int i = 0; i < patientCount; ++i) {
                if (patients[i].patientID == patientID) {
                    found = true;
                    float bill = calculate_patient_bill(patients[i]);
                    cout << "Patient ID: " << patients[i].patientID << endl;
                    cout << "Patient Name: " << patients[i].name << endl;
                    cout << "Patient Bill: $" << bill << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Patient with ID " << patientID << " not found." << endl;
            }
        } else if (choice == 5) {
            cout << "Exiting the program." << endl;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
