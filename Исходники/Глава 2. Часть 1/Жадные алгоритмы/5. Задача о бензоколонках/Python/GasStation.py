l = 50
s = 50
gas_stations = [60]


def count_gas_station(gas_stations, s, l):
    way, count = s, 0
    right_stations = list()
    gas_stations.append(l)
    gas_stations.sort()  # = sorted(gas_stations)
    for station in range(len(gas_stations)):
        if gas_stations[0] > s:
            return -1
        if gas_stations[station] > way and way < l:
            right_stations.append(gas_stations[station - 1])
            way = gas_stations[station - 1] + s
            # way += s
    if way < l:
        return -1
    return len(right_stations)


print(count_gas_station(gas_stations,s,l))