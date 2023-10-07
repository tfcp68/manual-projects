#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int count_gas_station(vector<int> gas_stations, int step, int all_way) {
    int way = step;
    vector<int> right_stations;
    gas_stations.push_back(all_way);
    int first_station = gas_stations[0];
    if (first_station > step) { 
        return -1;
    }
    sort(gas_stations.begin(), gas_stations.end());
    for (int station = 1; station < gas_stations.size(); station++) {
        if (gas_stations[station] > way and way < all_way) {
            right_stations.push_back(gas_stations[station - 1]);
            way = gas_stations[station - 1] + step;
        }
    };
    if (way < all_way) { 
        return -1; 
    }
    return right_stations.size();
}
