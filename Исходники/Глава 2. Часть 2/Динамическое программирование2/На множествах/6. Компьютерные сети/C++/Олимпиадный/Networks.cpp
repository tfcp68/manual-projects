#include<vector>
#include <iostream>


int count_computers(std::vector<std::vector<int>> graph, int size_graph) {
	int node_from_set = 0;
	std::vector<int> sets(1 << size_graph, 0);

    // ���� �� ����������
    for (int set = 1; set < (1 << size_graph); set++) {

        // ���� �� �������� ���������
        for (int node = 0; node < size_graph; node++) {

            // �������� ������� ������� ����������� ���������
            if (set & (1 << node)) {
                node_from_set = node;
                break;
            }
        }
        // ���� ������� ��������
        sets[set] = sets[set - (1 << node_from_set)];

        // ���� �� ���� �������� �� node_from_set
        for (int node = node_from_set + 1; node < size_graph; node++) {

            // ���� ������� �� ��������� ������� � ������ ��������
            if (graph[node_from_set][node] == 1 and (set & (1 << node))) {
                int curr_count_computer = sets[set - (1 << node_from_set) - (1 << node)] + 1;

                sets[set] = std::max(curr_count_computer, sets[set]);
            }
        }
    }
	return sets[(1 << size_graph) - 1] * 2;
}