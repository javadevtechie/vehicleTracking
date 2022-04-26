#include <iostream>
#include "ParkingManager.h"
#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;

//
//int main(){
//    cout << "|-" << setfill('*') << setw(100) << "-|" <<endl;
//    cout  << setw(50)<< setfill(' ')  << left << "|Parking Management System|" <<  setfill(' ');
//return 0;
//
//}
int main(int argc, char *argv[])
{
ParkingManager parkingManager;



    std::list<Vehicle> vehicleList;
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

        vehicleList.push_back(vehicle);
        parkingManager.updateList("",vehicleList);
    }
    else
    {
        std::ifstream infile(argv[1]);
        if (infile.good())
        {

        parkingManager.updateList(argv[1],vehicleList);
        }
        else
        {
            cout<<"Given file does not exist";
        }
    }



    return 0;
}
