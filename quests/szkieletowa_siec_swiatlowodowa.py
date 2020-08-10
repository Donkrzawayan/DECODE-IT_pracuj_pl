class DisjointSet:

    def __init__(self, arr):
        self.container = []
        for i in set(arr):
            self.container.append([i])

    def _get_index(self, edge):
        for i in self.container:
            if edge in i:
                return self.container.index(i)
        return None

    def union(self, e1, e2):
        index_e1 = self._get_index(e1)
        index_e2 = self._get_index(e2)
        if index_e1 != index_e2 and index_e1 is not None and index_e2 is not None:
            self.container[index_e1] = self.container[index_e1] + self.container[index_e2]
            del self.container[index_e2]
        return self.container

    def find(self, edge):
        for component in self.container:
            if edge in component:
                return self.container[self.container.index(component)]
        return None

    def check_same_component(self, e1, e2):
        comp_e1 = self.find(e1)
        comp_e2 = self.find(e2)
        if comp_e1 is not None and comp_e1 == comp_e2:
            return "T"
        return "N"


def process_data():
    ips = []
    unions = []
    while True:
        line = input()
        line = line.split()
        if line[0] == 'B':
            if line[1] not in ips:
                ips.append(line[1])
            if line[2] not in ips:
                ips.append(line[2])
            unions.append((line[1], line[2]))
        else:
            disjoint = DisjointSet(ips)
            for union in unions:
                disjoint.union(union[0], union[1])
            print(disjoint.check_same_component(line[1], line[2]))


try:
    process_data()
except EOFError:
    pass

# 24
