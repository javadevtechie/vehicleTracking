#include <iostream>
#include "ParkingManager.h"
#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
ParkingManager parkingManager;


    cout << "|-" << setfill('*') << setw(24) << "-|" <<endl;
    cout << setfill(' ') << setw(12) << left << "|Fahrenheit|" <<  setfill(' ');
    cout << setw(14) << right << "|Celsius |" <<  endl;
    cout << "|-" <<  setfill('*') << setw(24) << "-|" << endl;
    //cout<< argv[1].length();
    if (&argv[1][0] == '\0')
    {
        std::string vehicleNumber,entryTime,exitTime;
        cout<< "Enter Vehicle Number:\n";
        cin>> vehicleNumber;
        cout<< "Enter Vehicle EntryTime:\n";
        cin>> entryTime;
        cout<< "Enter Vehicle ExitTime:\n";
        cin>> exitTime;
        Vehicle vehicle;
        vehicle.Setnumber(vehicleNumber);
        vehicle.SetentryTime(entryTime);
        vehicle.SetexitTime(exitTime);
        std::list<Vehicle> vehicleList;
        vehicleList.push_back(vehicle);
        parkingManager.updateList("",vehicleList);
    }
    else
    {
        std::ifstream infile(argv[1]);
        if (infile.good())
        {


        }
        else
        {
            cout<<"Given file does not exist";
        }
    }



    return 0;
}
