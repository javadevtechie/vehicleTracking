#include "ParkingManager.h"
#include "FileUtil.h"
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <fstream>
#include <string>
FileUtil file;

std::list<Vehicle> costCalculatedVeh;
ParkingManager parking;
ParkingManager::ParkingManager()
{

}

std::list<Vehicle> ParkingManager::getUnresolvedVehicleList(std::list<Vehicle> vlist)
{
    std::list<Vehicle> remv;
    for (Vehicle inputVehicle : vlist)
    {
        if(inputVehicle.GetexitTime().compare("-")!=0  && inputVehicle.GetentryTime().compare("-")!=0)
        {
            Vehicle veh;
            double parkingTime = (file.getTotalTime(inputVehicle.GetexitTime())-file.getTotalTime(inputVehicle.GetentryTime()))/3600;
            if(parkingTime>-1)
            {
                double cost = file.getPartkingCost(parkingTime);
                veh=inputVehicle;
                veh.SetexitTime(inputVehicle.GetexitTime());
                veh.SetentryTime(inputVehicle.GetentryTime());
                veh.Setcost(cost);
                costCalculatedVeh.push_front(veh);

            }
        }
        else
        {
            remv.push_back(inputVehicle);
            //std::cout<<inputVehicle.Getnumber()<<std::endl;

        }
    }
    return remv;
}
void ParkingManager::updateList(std::string filePath)
{
    std::list<Vehicle> vehicleList=file.getListOfVehicle("vehicle.txt");
    std::list<Vehicle> inputVehicleList= file.getListOfVehicle(filePath);
    std::list<Vehicle> resolveInputVehicleList=  parking.getUnresolvedVehicleList(inputVehicleList);
    std::list<Vehicle> temp=vehicleList;
    temp.insert(temp.end(), resolveInputVehicleList.begin(), resolveInputVehicleList.end());

    std::map<std::string, Vehicle> vMap;
    //std::cout<<vMap.size()<<std::endl;
    for (Vehicle iv : temp)
    {
        vMap[iv.Getnumber()] = iv;
    }
    if(resolveInputVehicleList.size()>0)
    {
        for (Vehicle inputVehicle : resolveInputVehicleList)
        {
            for (Vehicle dbVehicle :vehicleList )
            {
                if(inputVehicle.Getnumber().compare(dbVehicle.Getnumber())==0)
                {
                    if(inputVehicle.GetexitTime().compare("-")!=0  && dbVehicle.GetentryTime().compare("-")!=0)
                    {
                        Vehicle veh;
                        double parkingTime = (file.getTotalTime(inputVehicle.GetexitTime())-file.getTotalTime(dbVehicle.GetentryTime()))/3600;
                        if(parkingTime>-1)
                        {
                            double cost = file.getPartkingCost(parkingTime);
                            veh=inputVehicle;
                            veh.SetexitTime(inputVehicle.GetexitTime());
                            veh.SetentryTime(dbVehicle.GetentryTime());
                            veh.Setcost(cost);
                            costCalculatedVeh.push_front(veh);
                            vMap.erase(dbVehicle.Getnumber());
                        }
                    }
                }
            }

        }
    }

    std::ofstream dbFile,inputFile;
    dbFile.open ("vehicle.txt");


    std::ofstream inputfile;
    inputfile.open(filePath, std::ofstream::out | std::ofstream::trunc);
    inputfile.close();

   std::ofstream fout;

     fout.open ("archive.txt",std::ios::app);

    for (auto& x: vMap)
    {
        std::cout << x.second.Getnumber()+"|"+x.second.GetentryTime()+"|"+x.second.GetexitTime()<<std::endl;
        dbFile << x.second.Getnumber()+"|"+x.second.GetentryTime()+"|"+x.second.GetexitTime()+"\n";
       // fout<<" tutorials point";
    }
    dbFile.close();
    for (Vehicle dbVehicle :costCalculatedVeh )
    {
        std::cout<<dbVehicle.Getnumber()<<"\t";
        std::cout<<dbVehicle.GetentryTime()<<"\t";
        std::cout<<dbVehicle.GetexitTime()<<"\t";
        std::cout<<dbVehicle.Getcost()<<"\t"<<std::endl;
      // ost << dbVehicle.Getnumber()+"|"+dbVehicle.GetentryTime()+"|"+dbVehicle.GetexitTime()+"|"+dbVehicle.Getcost();
       fout << dbVehicle.Getnumber() +"|"+ dbVehicle.GetentryTime() +"|"+ dbVehicle.GetexitTime() +"|"+std::to_string(dbVehicle.Getcost())+"\n";
    }
    fout.close();
}
