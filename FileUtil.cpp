#include "FileUtil.h"
#include <sstream>
#include <iostream>
#include "Vehicle.h"
#include <list>
#include <fstream>
#include <vector>
FileUtil::FileUtil()
{
}

std::string FileUtil::readFile(std::string msg)
{
    return msg;
}

std::list<Vehicle> FileUtil::getListOfVehicle(std::string filePath)
{
    FileUtil f;
    std::string text;
    std::ifstream MyReadFile(filePath);
    std::list<Vehicle> vehicleList;
    while (getline (MyReadFile, text))
    {

        Vehicle vehicle;
        std::vector<std::string> token=f.getStringToken(text);
        vehicle.Setnumber(token[0]);
        vehicle.SetentryTime(token[1]);
        vehicle.SetexitTime(token[2]);
        vehicleList.push_back(vehicle);
    }
    //std::cout<<vehicleList.size()<<std::endl;
    MyReadFile.close();
    return vehicleList;
}

std::vector<std::string> FileUtil::getStringToken(std::string myText)
{
    std::vector <std::string> tokens;
    std::stringstream check1(myText);
    std::string intermediate;
    while(getline(check1, intermediate, '|'))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}

int FileUtil::getTotalTime(std::string myText)
{
    std::vector <std::string> tokens;
    std::stringstream check1(myText);
    std::string intermediate;
    while(getline(check1, intermediate, ':'))
    {
        tokens.push_back(intermediate);
    }
    int totalTime= (stoi(tokens[0])*60+stoi(tokens[1]))*60+stoi(tokens[2]);

    return totalTime;
}
double FileUtil::getPartkingCost(double parkingDuration)
{
    double parkingCost=0;
    if(parkingDuration>0.5 && parkingDuration<=1)
    {
        return  parkingCost=1.5;
    }
    else if(  parkingDuration>1 && parkingDuration<=2)
    {
        return  parkingCost=3;
    }
    else if(  parkingDuration>2 && parkingDuration<=4 )
    {
        return  parkingCost=5;
    }
    else if(  parkingDuration>4 && parkingDuration<=8)
    {
        return  parkingCost=15;
    }
    else if( parkingDuration>8)
    {
        return  parkingCost=30;
    }
    return parkingCost;
}
