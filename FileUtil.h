#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <iostream>
#include "Vehicle.h"
#include <list>
#include <vector>
class FileUtil
{
    public:
        FileUtil();
        std::string readFile(std::string msg);
        std::list<Vehicle> getListOfVehicle(std::string filePath);
        std::vector<std::string> getStringToken(std::string myText);
        int getTotalTime(std::string myText);
        double getPartkingCost(double time);

       // double getParkingCostBytime()
};

#endif // FILEUTIL_H
