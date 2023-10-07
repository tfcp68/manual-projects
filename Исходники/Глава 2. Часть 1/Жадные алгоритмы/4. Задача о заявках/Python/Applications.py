# Даны заявки на проведение занятий в некоторой аудитории.
# В каждой заявке указаны начало и конец занятия (si и fi для i-ой заявки).
# Нужно из всех заявок оставить как можно больше так, чтобы они не пересекались.
# При этом если одна заявка закончилась во время t,
# а следующая началась во время t, то их можно ставить подряд.

applications = [(5, 7), (7, 10), (6, 7), (12, 15), (13, 14)]


def count_applications(applications):
    applications = sorted(applications, key=lambda x: x[1])
    ans = list()

    last_application = (0, 0)
    for i in applications:
        if last_application[1] <= i[0]:
            ans.append(i)
            last_application = i
    return len(ans)


# print(count_applications(applications))