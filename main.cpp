#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    //constant
    const int numEmployees = 7;

    //arrays initialized with manual entries
    int empId[numEmployees] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489 };
    int hours[numEmployees];
    double payRate[numEmployees];
    double wages[numEmployees];

    //inputs for user entries
    cout << "Please enter the hours worked by " << numEmployees << " employees\n"
         << "and their hourly pay rates.\n";

    //loops for each employee
    for (int index = 0; index < numEmployees; index++)
    {
        do
        {
            cout << "Please enter the hours worked by Employee # " << (index + 1) << " (ID = " << empId[index] << ") : ";
            if (cin >> hours[index])
            {
                if (hours[index] > 0) //data validation
                    break;

                cout << "Enter in a positive number" << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.clear();
                cout << "Enter in a valid number" << endl;
            }
        }
        while (true);

        do
        {
            cout << "Please enter the pay rate for Employee # " << (index + 1) << " (ID = " << empId[index] << ") : ";
            if (cin >> payRate[index])
            {
                if (payRate[index] >= 15.0)
                    break;

                cout << "The pay rate must be >= 15" << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.clear();
                cout << "Enter in a valid monetary value" << endl;
            }
        }
        while (true);

        wages[index] = hours[index] * payRate[index];
    }

    //outputs for results

    cout << "This is the gross pay for each employee:\n";
    cout << fixed << showpoint << setprecision(2);

    for (int index = 0; index < numEmployees; index++)
    {
        cout << "Employee #" << (index + 1) << " (ID = " << empId[index] << ") : ";
        cout << "earned $" << wages[index] << endl << endl;
    }

    return 0;
}
