#ifndef PARKINGMANAGER_H
#define PARKINGMANAGER_H
#include <iostream>
#include "FileUtil.h"
#include <list>
class ParkingManager
{
    public:
        ParkingManager();
        void updateList(std::string filePath,std::list<Vehicle> vehicles);
        std::list<Vehicle>  getUnresolvedVehicleList(std::list<Vehicle> vehicles);
};

#endif // PARKINGMANAGER_H
