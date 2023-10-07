#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

bool comp(ii appl_1, ii appl_2) {
    return appl_1.second < appl_2.second;
}

int count_applications(vector<ii>  applications) {
    sort(applications.begin(), applications.end(), comp);
    vector<ii> answer;

    ii last_application = make_pair(0, 0);
    for (ii application : applications) {
        if (last_application.second <= application.first) {
            answer.push_back(application);
            last_application = application;
        }
    }
    return answer.size();
}