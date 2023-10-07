#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> first_application,
    pair<int, int> second_application) {
    return first_application.second < second_application.second;
}

int count_applications(vector<pair<int, int>>  applications) {
    sort(applications.begin(), applications.end(), compare);
    vector<pair<int, int>> amount_application;

    pair<int, int> last_application = make_pair(0, 0);
    for (pair<int, int> application : applications) {
        if (last_application.second <= application.first) {
            amount_application.push_back(application);
            last_application = application;
        }
    }
    return amount_application.size();
}