#include <iostream>

using namespace std;

int main()
{
    double total_cost,current_saving=0,anual_salary,portion_save,semi_annual_raise;//Definition of variables
    int month=0;

    // Enter the cost of a house, annual salary, and savings percentage
    cout << "Enter your annual salary: ";
    cin >> anual_salary;
    cout << "\nEnter the percent of your salary to save, as a decimal(30% == .3): ";
    cin >> portion_save;
    cout << "\nEnter the cost of your dream home: ";
    cin >> total_cost;
    cout << "\nEnter the semi­annual raise, as a decimal: (3% == .03): ";
    cin >> semi_annual_raise;



    // Calculate the number of months of savings
    while(true)
    {
        // Salary increase every 6 months
        if (month % 6 == 0 && month != 0)
        {
            anual_salary += (anual_salary * semi_annual_raise);
        }
        current_saving += ((anual_salary * portion_save) / 12.0) + ((current_saving * 0.04) / 12.0); // 0.04=r (r is the return on investment)
        month++;
        // A condition to exit the loop when the calculation is complete
        if (current_saving >= (total_cost * 0.25)) 
        {   // 0.25 = the portion of the cost needed for a down payment
            break;
        }
    }
    // Display the number of months for the user
    cout << "\nNumber of months: "<< month << endl;
    return 0;
}
