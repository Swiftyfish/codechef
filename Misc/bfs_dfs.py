from collections import deque

def dfs(graph, node, target, output_list):
    output_list.append(node)
    if node == target:
        return True
    children = graph[node]
    for child in children:
        if dfs(graph, child, target, output_list):
            return True
    return False

def run_dfs(graph, node, target):
    output_list = []
    dfs(graph, node, target, output_list)
    return output_list

def bfs(graph, node, target):
    queue = deque()
    output_list = []
    visited = [False for pair in list(graph.items())]
    visited[node - 1] = True
    queue.append(node)
    while len(queue):
        output_list.append(queue.popleft())
        for child in graph[node]:
            if(not visited[child - 1]):
                visited[child - 1] = True
                queue.append(child)

    return output_list

def main():    
    graph = {1: [2, 3], 2: [4], 3: [], 4: []}
    dfs(graph, 1, 4)
    bfs(graph, 1, 4)

if __name__ == '__main__':
    main()