#include "ParkingManager.h"
#include "FileUtil.h"
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

FileUtil file;
std::list<Vehicle> vehicleList;
std::list<Vehicle> inputVehicleList;
std::list<Vehicle> costCalculatedVeh;
ParkingManager parking;
ParkingManager::ParkingManager()
{

    vehicleList= file.getListOfVehicle("vehicle.txt");
    inputVehicleList= file.getListOfVehicle("newvehicle.txt");
}

std::list<Vehicle> ParkingManager::dropVehicle(Vehicle v, std::list<Vehicle> v_list)
{
    std::list<Vehicle> temporary;
    for (Vehicle inputVehicle : v_list)
    {
        if(inputVehicle.Getnumber().compare(v.Getnumber())!=0)
        {
            temporary.push_front(inputVehicle);
        }

    }
    for (Vehicle dbVehicle :temporary )
    {
        std::cout<<dbVehicle.Getnumber()<<std::endl;
    }
    return temporary;
}
std::list<Vehicle> ParkingManager::getUnresolvedVehicleList(std::list<Vehicle> vlist)
{

    for (Vehicle inputVehicle : vlist)
    {
        bool exit=false;
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
                //vlist= parking.dropVehicle(inputVehicle,vlist);
                std::list<Vehicle> temporary;
                for (Vehicle v : vlist)
                {
                    if(inputVehicle.Getnumber().compare(v.Getnumber())!=0)
                    {
                        temporary.push_front(inputVehicle);
                    }

                }

                std::cout<<vlist.size()<<std::endl;
            }
        }
    }
    return inputVehicleList;
}
void ParkingManager::updateList(std::string filePath)
{

    std::list<Vehicle> resolveInputVehicleList=  parking.getUnresolvedVehicleList(inputVehicleList);
    bool exit;
    if(resolveInputVehicleList.size()>0)
    {
        for (Vehicle inputVehicle : resolveInputVehicleList)
        {
            for (Vehicle dbVehicle :vehicleList )
            {
                exit=false;
                if(inputVehicle.Getnumber().compare(dbVehicle.Getnumber())==0)
                {
                    exit=true;
                    if(inputVehicle.GetexitTime().compare("-")!=0  && dbVehicle.GetentryTime().compare("-")!=0)
                    {
                        Vehicle veh;
                        double parkingTime = (file.getTotalTime(inputVehicle.GetexitTime())-file.getTotalTime(dbVehicle.GetentryTime()))/3600;
                        if(parkingTime>-1)
                        {
                            double cost = file.getPartkingCost(parkingTime);
                            std::cout<<"VehicleNo:";
                            std::cout<<dbVehicle.Getnumber()<<std::endl;
                            std::cout<<"parkingTime--";
                            std::cout<<parkingTime<<std::endl;
                            std::cout<<cost<<std::endl;
                            veh=inputVehicle;
                            veh.SetexitTime(inputVehicle.GetexitTime());
                            veh.SetentryTime(dbVehicle.GetentryTime());
                            veh.Setcost(cost);
                            costCalculatedVeh.push_front(veh);
                        }
                    }
                }
            }
            if(!exit)
            {
                vehicleList.push_front(inputVehicle);
            }
        }
    }
    std::cout<<"-------------------------------------------"<<std::endl;
    for (Vehicle dbVehicle :costCalculatedVeh )
    {
        std::cout<<dbVehicle.Getnumber()<<"\t";
        std::cout<<dbVehicle.GetentryTime()<<"\t";
        std::cout<<dbVehicle.GetexitTime()<<"\t"<<std::endl;

    }

}
