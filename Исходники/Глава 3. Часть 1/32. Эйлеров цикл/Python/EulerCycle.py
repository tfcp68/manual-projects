

def check_node_power(graph):

    # Перебираем все вершины графа
    for vertex in graph:

        # Если степень вершины нечётная
        if len(graph[vertex]) % 2 != 0:

            # Проверка не пройдена
            return False

    # Проверка пройдена
    return True


def euler_cycle(graph, start_vertex):

    # Если в графе есть вершина с нечётной степенью
    if not check_node_power(graph):

        # В графе нет эйлерова цикла
        return -1

    cycle = []

    # Добавляем стартовую вершину в стек
    stack = [start_vertex]

    # Пока стек полный
    while stack:

        # Берём значение вершины из стека
        current_vertex = stack[-1]

        # Если у вершины есть непосещённые соседи
        if len(graph[current_vertex]) > 0:

            # Извлекаем соседа текущей вершины
            next_vertex = graph[current_vertex].pop()

            # Удаляем обратное ребро с этим соседом
            graph[next_vertex].remove(current_vertex)

            # Добавляем следующую вершину в стек
            stack.append(next_vertex)

            # Обновляем цикл
            cycle = list(stack)

        else:

            # Если все соседи текущей вершины посещены,
            # удаляем вершину из стека
            stack.pop()

    # Если последняя вершина не стартовая
    if cycle[len(cycle) - 1] != start_vertex:

        # Добавляем в конец стартовую вершину
        cycle.append(start_vertex)

    return cycle








