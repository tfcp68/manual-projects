#include <iostream>
#include <vector>
#include <unordered_map>


bool check_node_power(std::unordered_map<int, std::vector<int>> graph) {

    // ���������� ��� ������� �����
    for (std::pair<int, std::vector<int>> vertex : graph) {

        // ���� ������� ������� ��������
        if (vertex.second.size() % 2 != 0) {

            // �������� �� ��������
            return false;
       }

    }
    // �������� ��������
    return true;
}


std::vector<int> euler_cycle(std::unordered_map<int, std::vector<int>> &graph, int start_vertex) {

    // ���� ��� ������� ������ ����� ������
    if (!check_node_power(graph)) {

        // ����� ������ � ����� ���
        return std::vector<int> { -1 };
    }

    std::vector<int> cycle;

    // ��������� ��������� ������� � ����
    std::vector<int> stack;
    stack.push_back(start_vertex);

    // ���� ���� ������
    while (!stack.empty()) {

        // ���� �������� ������� �� �����
        int current_vertex = stack.back();

        // ���� � ������� ���� ������������ ������
        if (graph[current_vertex].size() > 0) {

            // ��������� ������ ������� �������
            int next_vertex = graph[current_vertex].back();

            graph[current_vertex].pop_back();

            // ������� �������� ����� � ���� �������
            graph[next_vertex].erase(

                std::remove(graph[next_vertex].begin(), 
                            graph[next_vertex].end(), 
                            current_vertex), 

                graph[next_vertex].end()
            );

            // ��������� ��������� ������� � ����
            stack.push_back(next_vertex);

            // ��������� ����
            cycle = stack;

            
        }

        else {

            // ���� ��� ������ ������� ������� ��������,
            // ������� ������� �� �����
            stack.pop_back();
        }
    }

    // ���� ��������� ������� �� ���������
    if (cycle.back() != start_vertex) {

        // ��������� � ����� ��������� �������
        cycle.push_back(start_vertex);
    }

    return cycle;
}

