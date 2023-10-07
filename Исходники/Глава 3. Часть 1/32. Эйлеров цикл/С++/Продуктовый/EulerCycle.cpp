#include <iostream>
#include <vector>
#include <unordered_map>


bool check_node_power(std::unordered_map<int, std::vector<int>> graph) {

    // Перебираем все вершины графа
    for (std::pair<int, std::vector<int>> vertex : graph) {

        // Если степень вершины нечётная
        if (vertex.second.size() % 2 != 0) {

            // Проверка не пройдена
            return false;
       }

    }
    // Проверка пройдена
    return true;
}


std::vector<int> euler_cycle(std::unordered_map<int, std::vector<int>> &graph, int start_vertex) {

    // Если все степени вершин графа чётные
    if (!check_node_power(graph)) {

        // Цикла эйлера в графе нет
        return std::vector<int> { -1 };
    }

    std::vector<int> cycle;

    // Добавляем стартовую вершину в стек
    std::vector<int> stack;
    stack.push_back(start_vertex);

    // Пока стек полный
    while (!stack.empty()) {

        // Берём значение вершины из стека
        int current_vertex = stack.back();

        // Если у вершины есть непосещённые соседи
        if (graph[current_vertex].size() > 0) {

            // Извлекаем соседа текущей вершины
            int next_vertex = graph[current_vertex].back();

            graph[current_vertex].pop_back();

            // Удаляем обратное ребро с этим соседом
            graph[next_vertex].erase(

                std::remove(graph[next_vertex].begin(), 
                            graph[next_vertex].end(), 
                            current_vertex), 

                graph[next_vertex].end()
            );

            // Добавляем следующую вершину в стек
            stack.push_back(next_vertex);

            // Обновляем цикл
            cycle = stack;

            
        }

        else {

            // Если все соседи текущей вершины посещены,
            // удаляем вершину из стека
            stack.pop_back();
        }
    }

    // Если последняя вершина не стартовая
    if (cycle.back() != start_vertex) {

        // Добавляем в конец стартовую вершину
        cycle.push_back(start_vertex);
    }

    return cycle;
}

