from queue import PriorityQueue

class SearchTree():
    def __init__(self, graph, straight_line):
        self.graph = graph
        self.straight_line = straight_line

    def search(self, start, end, method='ucs'):
        if method == 'ucs':
            index = 0
        elif method == 'a*':
            index = 2
        else:
            raise Exception(f'Invalid comparison metric: {method}')

        answer = 2 ** 31 - 1
        q = PriorityQueue()
        q.put((0, start, [start]))
        visited = {}
        for key in self.graph.keys():
            visited[key] = 0
        while not q.empty():
            dist, s, path = q.get()
            visited[s] = 1
            print(s)
            if s == end:
                answer = min(answer, dist)
                print(path)
                continue

            children = self.graph[s].items()
            for child, props in children:
                #print(f"Child Node is {child}, priority {props[0] + dist}")
                if not visited[child]:
                    visited[child] = 1
                    if method == 'a*':
                        dist_to_goal = self.straight_line[end][child]
                        q.put((dist_to_goal, child, path + [child]))

                    elif method == 'ucs':
                        q.put((dist + props[0], ))
        return answer

class Castles():
    def __init__(self, names):
        self.castles = dict([(name, {}) for name in names])

    def __getitem__(self, castle):
        return self.castles[castle]

    def add_connection(self, castleA, castleB, distances):
        assert (castleA in self.castles and castleB in self.castles),\
             "castle not in dictionary"
        self.castles[castleA][castleB] = distances
        pair_distances = distances.copy()
        pair_distances[1] *= -1
        self.castles[castleB][castleA] = pair_distances

castles = Castles([chr(i) for i in range(65, 65 + 10)])
castles.add_connection('A', 'B', [5, 200, 3])
castles.add_connection('A', 'C', [5, 600, 3])
castles.add_connection('A', 'D', [5, 100, 3])
castles.add_connection('B', 'F', [5, 100, 3])
castles.add_connection('C', 'E', [5, -300, 3])
castles.add_connection('D', 'E', [5, 200, 3])
castles.add_connection('D', 'F', [10, 200, 7])
castles.add_connection('E', 'G', [10, -200, 7])
castles.add_connection('E', 'H', [5, 200, 3])
castles.add_connection('F', 'I', [5, 100, 3])
castles.add_connection('G', 'H', [5, 400, 3])
castles.add_connection('G', 'J', [5, 400, 3])
castles.add_connection('H', 'J', [5, 400, 3])
castles.add_connection('I', 'J', [5, 100, 3])

def main():
    graph = {
    #distance, elevation change, straight line dist (heuristic)
        'A': {'B': [5, 200, 3], 'C': [5, 600, 3], 'D': [5, 100, 3]},
        'B': {'A': [5, -200, 3], 'F': [5, 100, 3]},
        'C': {'A': [5, -600, 3], 'E': [5, -300, 3]},
        'D': {'A': [5, -100, 3], 'E': [5, 200, 3], 'F': [10, 200, 7]},
        'E': {'C': [5, 300, 3], 'D': [5, -200, 3], 'G': [10, -200, 7], 'H': [5, 200, 3]},
        'F': {'B': [5, -100, 3], 'D': [10, -200, 7], 'I': [5, 100, 3]},
        'G': {'E': [10, -200, 7], 'H': [5, 400, 3], 'J': [5, 400, 3]},
        'H': {'E': [5, -200, 3], 'G': [5, -400, 3], 'J': [5, 0, 3]},
        'I': {'F': [5, -100, 3], 'J': [5, 100, 3]},
        'J': {'G': [5, -400, 3], 'H': [5, 0, 3], 'I': [5, -100, 3]}
    }
    straight_line = {
        'A': {'A': 0},
        'B': {'A': 3, 'B': 0},
        'C': {'A': 3, 'B': 7, 'C': 0},
        'D': {'A': 3, 'B': 3, 'C': 3, 'D': 0},
        'E': {'A': 7, 'B': 7, 'C': 3, 'D': 3, 'E': 0},
        'F': {'A': 7, 'B': 3, 'C': 11, 'D': 7, 'E': 11, 'F': 0},
        'G': {'A': 11, 'B': 7, 'C': 15, 'D': 7, 'E': 7, 'F': 3, 'G': 0},
        'H': {'A': 11, 'B': 11, 'C': 7, 'D': 7, 'E': 3, 'F': 7, 'G': 3, 'H': 0},
        'I': {'A': 15, 'B': 11, 'C': 15, 'D': 15, 'E': 11, 'F': 3, 'G': 3, 'H': 7, 'I': 0},
        'J': {'A': 15, 'B': 15, 'C': 15, 'D': 15, 'E': 11, 'F': 7, 'G': 3, 'H': 3, 'I': 3, 'J': 0},
    }
    st = SearchTree(graph, straight_line)
    ans = st.search('A', 'J', 'a*')
    print(ans)