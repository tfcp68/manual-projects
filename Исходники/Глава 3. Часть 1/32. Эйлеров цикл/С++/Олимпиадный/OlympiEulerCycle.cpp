#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


typedef vector<int> vi;
typedef unordered_map<int, vector<int>> mivi;
typedef pair<int, vector<int>> ivi;


bool check(mivi graph) {

    for (ivi v : graph) {

        if (v.second.size() % 2 != 0) {
            return 0;
        }

    }
    return 1;
}


vi euler_cycle(mivi & graph, int s) {

   
    if (!check(graph)) {

        return vi { -1 };
    }

    vi res;
    res.push_back(s);

    vector<int> stack;
    stack.push_back(s);

   
    while (!stack.empty()) {

        int curr = stack.back();

        if (graph[curr].size() > 0) {

            int next = graph[curr].back();

            graph[curr].pop_back();

            graph[next].erase(

                std::remove(graph[next].begin(),
                            graph[next].end(), curr),

                graph[next].end()
            );

            stack.push_back(next);

            res = stack;
        }

        else {
            stack.pop_back();
        }
    }

    if (res.back() != s) {
        res.push_back(s);
    }

    return res;
}

