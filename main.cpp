#include <iostream>
#include "ParkingManager.h"
#include <map>
using namespace std;

int main()
{

map<std::string, string> sample_map;
//  sample_map.insert(pair<std::string, string>("1", "one"));
//  sample_map.insert(pair<std::string, string>("2", "two"));
//  sample_map.insert(pair<std::string, string>("1", "werrer"));
//
//  cout << sample_map["1"] << " " << sample_map["2"] << sample_map["1"] << endl;
//

    ParkingManager parkingManager;


    parkingManager.updateList("newvehicle.txt");
    //cout << argv[1];
    return 0;
}
