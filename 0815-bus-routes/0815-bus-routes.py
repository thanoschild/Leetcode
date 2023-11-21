class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        n = len(routes)
        mp = defaultdict(list)
        for bus in range(n):
            for stops in routes[bus]:
                mp[stops].append(bus)

        pq = []
        pq.append(source)
        busStop, bus, buses = {}, {}, 0
        busStop[source] = 1

        while pq:
            l = len(pq)
            for _ in range(l):
                t = pq.pop(0)

                if t == target: 
                    return buses
                
                for it in mp[t]:
                    if bus.get(it, 0) == 0:
                        bus[it] = 1
                        for stop in routes[it]:
                            if busStop.get(stop, 0) == 0:
                                pq.append(stop)
                                busStop[stop] = 1

            buses += 1

        return -1

                    

                    
