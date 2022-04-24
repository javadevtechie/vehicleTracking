#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
    private:
        int id;
        std::string number;
        std::string entryTime;
        std::string exitTime;
        double cost;
    public:
        Vehicle();
        Vehicle(std::string vnumber, std::string ventryTime,std::string vexitTime,double vcost,int id){
                number = vnumber;
                entryTime = ventryTime;
                exitTime = vexitTime;
                cost = vcost;
                id=id;
        };
        int Getid() { return id; }
        void Setid(int val) { id = val; }
        std::string Getnumber() { return number; }
        void Setnumber(std::string val) { number = val; }
        std::string GetentryTime() { return entryTime; }
        void SetentryTime(std::string val) { entryTime = val; }
        std::string GetexitTime() { return exitTime; }
        void SetexitTime(std::string val) { exitTime = val; }
        double Getcost() { return cost; }
        void Setcost(double val) { cost = val; }

    protected:

};

#endif // VEHICLE_H
