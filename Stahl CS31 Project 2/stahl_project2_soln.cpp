// Project 2
// By Howard A. Stahl
#include <iostream>
#include <string>
#include <climits>
using namespace std;


void promptForInput( string& name, string& type, double& minutes, double& mileage );
bool isValid( string name, string type, double minutes, double mileage, string& errorMessage );
double calculateCost( string type, double minutes, double mileage );
void showOutput(  string name,  double amount );
void showError(  string errorMessage );


int main( )
{
    // driver code that uses the newly declared stubbed out functions
    string name(""), type("");
    double minutes(0.0), mileage(0.0), cost(0.0);
    string error("");

    promptForInput(name, type, minutes, mileage);
    if (isValid(name, type, minutes, mileage, error))
    {
        cost = calculateCost(type, minutes, mileage);
        showOutput( name, cost );
    }
    else
    {
        showError( error );
    }
}

void promptForInput( string& name, string& type, double& minutes, double& mileage )
{
    cout << "Customer Name: ";
    getline( cin, name );
    cout << "Miles to be driven: ";
    cin  >> mileage;
    cout << "Minutes to be driven: ";
    cin  >> minutes;
    cin.ignore( INT_MAX, '\n' );
    cout << "Ride Type: ";
    getline( cin, type );
}

bool isValid( string name, string type, double minutes, double mileage, string& errorMessage )
{
    bool result = true;
    const string BRUBERX_TYPE = "Br-UberX";
    const string BRUBERXL_TYPE = "Br-UberXL";
    
    if (name.length() == 0)
    {
        errorMessage = "You must enter a customer name.";
        result = false;
    }
    else if (minutes < 0)
    {
        errorMessage = "The time must be positive.";
        result = false;
    }
    else if (mileage < 0)
    {
        errorMessage = "The mileage must be positive.";
        result = false;
    }
    else if (type != BRUBERX_TYPE && type != BRUBERXL_TYPE )
    {
        errorMessage = "The ride type is not valid.";
        result = false;
    }
    return( result );
}

double calculateCost( string type, double minutes, double mileage )
{
    double cost(0.0);
    
    const string BRUBERX_TYPE = "Br-UberX";
    const string BRUBERXL_TYPE = "Br-UberXL";
    
    const double BOOKING_FEE = 1.65;
    const double BRUBERX_MINIMUM = 5.15;
    const double BRUBERXL_MINIMUM = 7.65;
    const double BRUBERX_COST_PER_MINUTE = 0.15;
    const double BRUBERXL_COST_PER_MINUTE = 0.30;
    const double BRUBERX_COST_PER_MILE = 0.90;
    const double BRUBERXL_COST_PER_MILE = 1.55;
    
    if (type == BRUBERX_TYPE)
    {
        cost = BOOKING_FEE + mileage * BRUBERX_COST_PER_MILE + minutes * BRUBERX_COST_PER_MINUTE;
        if (cost < BRUBERX_MINIMUM)
        {
            // ensure at least a minimum fare!
            cost = BRUBERX_MINIMUM;
        }
    }
    // BruberXL Cost Calculation
    else if (type == BRUBERXL_TYPE)
    {
        cost = BOOKING_FEE + mileage * BRUBERXL_COST_PER_MILE + minutes * BRUBERXL_COST_PER_MINUTE;
        if (cost < BRUBERXL_MINIMUM)
        {
            // ensure at least a minimum fare!
            cost = BRUBERXL_MINIMUM;
        }
    }
    
    return( cost );
}

void showOutput( string name,  double amount )
{
    cout.precision( 2 );
    cout.setf( ios::fixed );
    cout.setf( ios::showpoint );
    cout << "--- The fare for " << name << " is $" << amount << endl;

}

void showError(  string errorMessage )
{
    cout << "--- " << errorMessage << endl;
}
