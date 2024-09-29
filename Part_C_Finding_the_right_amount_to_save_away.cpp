#include <iostream>
#include <cmath>

using namespace std;

int bisection_search(double annual_salary, double first_pay);

int main() 
{
    double annual_salary,  first_pay = 250000 ;
    // Enter the annual salary
    cout << "Enter the starting salary: ";
    cin >> annual_salary;
    // Call the Bisction function to find the appropriate savings rate
    bisection_search(annual_salary, first_pay);
    return 0;
}

int bisection_search(double annual_salary, double first_pay) 
{
    int low = 0, high = 10001, Steps_in_bisection = 0, savings_rate ;  // bisection Algorithmic settings
    float current_saving = 0, base_annual = annual_salary;
    while (low <= high) 
    {
        Steps_in_bisection++;  // Increment steps after each iteration
        savings_rate = (low + high) / 2; // bisection Algorithmic settings
        // Data needs to be returned to its value for each verification
        current_saving = 0;
        base_annual = annual_salary ;
        // Calculate a saving amount for every 36 months according to the savings percentage
        for (int i=1;i<=36;i++)
        {
           current_saving += ((base_annual * (savings_rate * 0.0001)) / 12.0) + ((current_saving * 0.04) / 12.0); // 0.04=r (r is the return on investment)

           if (i % 6 == 0)
           { // Fulfilling a condition means that the salary must be increased (the salary increase occurs every 6 months)
              base_annual += base_annual * 0.07; // 0.07 is semi­annual raise
           }
        }
        // bisection Algorithmic settings
        if (abs(current_saving - first_pay) < 100) 
        {
            cout << "Best savings rate: " << savings_rate*0.0001 << endl;
            cout << "Steps in bisection search: " << Steps_in_bisection << endl;
            return 0 ; // means he found the saving percentage

        } 
        else if (current_saving < first_pay) 
        {
            low = savings_rate;
        } 
        else 
        {
            high = savings_rate;
        }


        // If the program reaches 100% and does not find the savings percentage
        if (savings_rate * 0.0001 >= 1)
        {
            cout << "It is not possible to pay the down payment in three years.\n";
            return 0;

        }
    } 
    return 0;
}
