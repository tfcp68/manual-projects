#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_gas_stations(vector<int> stations, int s, int l) {
    int way = s;
    vector<int> answer;
    stations.push_back(l);
    sort(stations.begin(), stations.end());
    for (int i = 1; i < stations.size(); i++) {
        if (stations[0] > s) { return -1; }
        if (stations[i] > way and way < l) {
            answer.push_back(stations[i - 1]);
            way = stations[i - 1] + s;
        }
    };
    if (way < l) { return -1; }
    return answer.size();
}
