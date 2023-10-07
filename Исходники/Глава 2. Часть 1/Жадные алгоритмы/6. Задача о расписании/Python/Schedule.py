# Есть программист, которому нужно выполнить n-ое количество заказов.
# У каждого заказа есть срок - di и штраф - fi (di, fi - положительные числа целые).
# Штраф начисляется если выполнить заказ позже срока.
# Чтобы выполнить заказ, нужна ровно одна единица времени.
# Выполнение первого заказа начинается в момент времени 0 и заканчивается в момент 1,
# выполнение второго заказа начинается в момент времени 1 и заканчивается в момент 2, и т.д.
# Нужно найти расписание, при котором сумма штрафов будет минимальной.


class Order:
    def __init__(self, deadline, fine, number):
        self.deadline = deadline
        self.fine = fine
        self.number = number


def sort_order(best_order):
    begin = list()
    best_order = sorted(best_order, key=lambda x: x.deadline)
    for order in best_order:
        begin.append(order.number)
    return begin


def init(deadlines, fines, n):
    orders = list()
    for num_order in range(n):
        order = Order(deadlines[num_order], fines[num_order], num_order + 1)
        orders.append(order)
    return sorted(orders, key=lambda x: x.fine, reverse=True)


def make_schedule(deadlines, fines, n):
    end, best_order = list(), list()
    orders = init(deadlines, fines, n)
    num_order = 0
    for time in range(max(deadlines)+1):
        if num_order < n:
            curr_order = orders[num_order]
            if time <= curr_order.deadline:
                best_order.append(curr_order)
            else:
                end.append(curr_order.number)
            num_order += 1
    begin = sort_order(best_order)
    return begin + end


# print(make_schedule(deadlines, fines, n))
