#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Создадим класс заказа, чтобы проще было извлекать информацию
class Order {
public:
    int deadline;
    int fine;
    int number;

    Order(int new_deadline, int new_fine, int new_number) {
        deadline = new_deadline;
        fine = new_fine;
        number = new_number;
    }
};


bool compare_for_fine(Order order_1, Order order_2) {
    return order_1.fine > order_2.fine;
}


// Считываем заказы и сортируем их по убыванию штрафов
vector<Order> init(vector<int> deadlines,
    vector<int> fines, int number_orders) {
    vector<Order> orders;
    for (int num_order = 0; num_order < number_orders; num_order++) {
        Order order(deadlines[num_order],
            fines[num_order], num_order + 1);
        orders.push_back(order);
    }
    sort(orders.begin(), orders.end(), compare_for_fine);
    return orders;
}


bool compare_for_deadline(Order order_1, Order order_2) {
    return order_1.deadline < order_2.deadline;
}


//Сортируем выполненные заказы в порядке возрасстания сроков
vector<int> sort_order(vector<Order> complet_orders) {
    vector<int> new_complet_orders;
    sort(complet_orders.begin(),
         complet_orders.end(), compare_for_deadline);
    for (Order order : complet_orders) {
        new_complet_orders.push_back(order.number);
    }
    return new_complet_orders;
}


// Решение задача
vector<int> make_schedule(vector<int> deadlines,
    vector<int> fines, int  number_orders) {
    vector<int> overdue_orders, answer;
    vector<Order> complet_orders;
    vector<Order> orders = init(deadlines, fines, number_orders);
    int num_order = 0;
    int end_time = *max_element(deadlines.begin(), deadlines.end()) + 1;
    for (int time = 0; time < end_time; time++) {
        if (num_order < number_orders) {
            Order curr_order = orders[num_order];
            if (time <= curr_order.deadline) {
                complet_orders.push_back(curr_order);
            }
            else {
                overdue_orders.push_back(curr_order.number);
            }
            num_order += 1;
        }
    }
    vector<int> new_complet_orders = sort_order(complet_orders);
    answer.insert(answer.begin(), new_complet_orders.begin(), new_complet_orders.end());
    answer.insert(answer.end(), overdue_orders.begin(), overdue_orders.end());
    return answer;
}