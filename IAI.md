```python
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

visited = []  # List to keep track of visited nodes.
queue = []  # Initialize a queue

def bfs(visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        s = queue.pop(0)
        print(s, end=" ")

        for neighbour in graph[s]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

bfs(visited, graph, 'A')

```

```python
# Using a Python dictionary to act as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

visited = set()  # Set to keep track of visited nodes.

def dfs(visited, graph, node):
    if node not in visited:
        print(node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
dfs(visited, graph, 'A')

```

```python
import numpy as np
import random
from time import sleep

def create_board():
    return np.zeros((3, 3), dtype=int)

def possibilities(board):
    return [(i, j) for i in range(3) for j in range(3) if board[i][j] == 0]

def random_place(board, player):
    selection = possibilities(board)
    current_loc = random.choice(selection)
    board[current_loc] = player
    return board

def row_win(board, player):
    return any(all(cell == player for cell in row) for row in board)

def col_win(board, player):
    return any(all(row[i] == player for row in board) for i in range(3))

def diag_win(board, player):
    return all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3))

def evaluate(board):
    for player in [1, 2]:
        if row_win(board, player) or col_win(board, player) or diag_win(board, player):
            return player

    if np.all(board != 0):
        return -1

    return 0

def play_game():
    board, winner, counter = create_board(), 0, 1
    print(board)
    sleep(2)

    while winner == 0:
        for player in [1, 2]:
            board = random_place(board, player)
            print(f"Board after {counter} move")
            print(board)
            sleep(2)
            counter += 1
        winner = evaluate(board)

        if winner != 0:
            break

    return winner

# Driver Code
print("Winner is:", play_game())

```

```python
class Solution:
    def solve(self, board):
        state_dict = {}
        flatten = [element for row in board for element in row]
        flatten = tuple(flatten)
        state_dict[flatten] = 0

        if flatten == (0, 1, 2, 3, 4, 5, 6, 7, 8):
            return 0

        return self.get_paths(state_dict)

    def get_paths(self, state_dict):
        cnt = 0
        while True:
            current_nodes = [x for x in state_dict if state_dict[x] == cnt]

            if len(current_nodes) == 0:
                return -1

            for node in current_nodes:
                next_moves = self.find_next(node)
                for move in next_moves:
                    if move not in state_dict:
                        state_dict[move] = cnt + 1
                    if move == (0, 1, 2, 3, 4, 5, 6, 7, 8):
                        return cnt + 1
                cnt += 1

    def find_next(self, node):
        moves = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4, 6],
            4: [1, 3, 5, 7],
            5: [2, 4, 8],
            6: [3, 7],
            7: [4, 6, 8],
            8: [5, 7],
        }

        results = []
        pos_0 = node.index(0)

        for move in moves[pos_0]:
            new_node = list(node)
            new_node[move], new_node[pos_0] = new_node[pos_0], new_node[move]
            results.append(tuple(new_node))

        return results

ob = Solution()
matrix = [
    [3, 1, 2],
    [4, 7, 5],
    [6, 8, 0]
]
print(ob.solve(matrix))

```

```python
from collections import defaultdict

jug1, jug2, aim = 4, 3, 2
visited = defaultdict(lambda: False)

def waterJugSolver(amt1, amt2):
    # Base case: check if the goal is reached
    if (amt1 == aim and amt2 == 0) or (amt2 == aim and amt1 == 0):
        print("Goal reached:", amt1, amt2)
        return True
    
    # Check if the current state has been visited
    if visited[(amt1, amt2)] == False:
        print("Current state:", amt1, amt2)
        visited[(amt1, amt2)] = True

        # Recursive calls for possible next states
        return (waterJugSolver(0, amt2) or
                waterJugSolver(amt1, 0) or
                waterJugSolver(jug1, amt2) or
                waterJugSolver(amt1, jug2) or
                waterJugSolver(amt1 + min(amt2, (jug1 - amt1)), amt2 - min(amt2, (jug1 - amt1))) or
                waterJugSolver(amt1 - min(amt1, (jug2 - amt2)), amt2 + min(amt1, (jug2 - amt2))))
    else:
        return False

print("Steps:")
waterJugSolver(0, 0)

```

```python
V = 4
answer = []

def tsp(graph, v, currPos, n, count, cost):
    if count == n and graph[currPos][0]:
        answer.append(cost + graph[currPos][0])
        return

    for i in range(n):
        if not v[i] and graph[currPos][i]:
            v[i] = True
            tsp(graph, v, i, n, count + 1, cost + graph[currPos][i])
            v[i] = False

# Driver code
if __name__ == '__main__':
    n = 4
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    v = [False for _ in range(n)]
    v[0] = True

    tsp(graph, v, 0, n, 1, 0)

    print("Minimum weight Hamiltonian Cycle:", min(answer))

```

```python
# Recursive Python function to solve the tower of hanoi
def TowerOfHanoi(n, source, destination, auxiliary):
    if n == 1:
        print("Move disk 1 from source", source, "to destination", destination)
        return

    TowerOfHanoi(n - 1, source, auxiliary, destination)
    print("Move disk", n, "from source", source, "to destination", destination)
    TowerOfHanoi(n - 1, auxiliary, destination, source)

# Driver code
n = 4
TowerOfHanoi(n, 'A', 'B', 'C')
# A, C, B are the name of rods

```

```python
# Global Variable i
i = 0

def Monkey_go_box(x, y):
    global i
    i = i + 1
    print('step:', i, 'monkey slave', x, 'Go to', y)

def Monkey_move_box(x, y):
    global i
    i = i + 1
    print('step:', i, 'monkey take the box from', x, 'deliver to', y)

def Monkey_on_box():
    global i
    i = i + 1
    print('step:', i, 'Monkey climbs up the box')

def Monkey_get_banana():
    global i
    i = i + 1
    print('step:', i, 'Monkey picked a banana')

# Read the input operating parameters
monkey = input("Enter monkey's location: ")
banana = input("Enter banana's location: ")
box = input("Enter box's location: ")

print('The steps are as follows:')

# Please use the least steps to complete the monkey picking banana task
Monkey_go_box(monkey, box)
Monkey_move_box(box, banana)
Monkey_on_box()
Monkey_get_banana()

```

```python
# working of Alpha-Beta Pruning
# Initial values of Alpha and Beta
MAX, MIN = 1000, -1000

# Returns optimal value for current player
# (Initially called for root and maximizer)
def minimax(depth, nodeIndex, maximizingPlayer,
            values, alpha, beta):
    # Terminating condition. i.e
    # leaf node is reached
    if depth == 3:
        return values[nodeIndex]

    if maximizingPlayer:
        best = MIN
        # Recur for left and right children
        for i in range(0, 2):
            val = minimax(depth + 1, nodeIndex * 2 + i,
                          False, values, alpha, beta)
            best = max(best, val)
            alpha = max(alpha, best)
            # Alpha Beta Pruning
            if beta <= alpha:
                break
        return best
    else:
        best = MAX
        # Recur for left and right children
        for i in range(0, 2):
            val = minimax(depth + 1, nodeIndex * 2 + i,
                          True, values, alpha, beta)
            best = min(best, val)
            beta = min(beta, best)
            # Alpha Beta Pruning
            if beta <= alpha:
                break
        return best

# Driver Code
if __name__ == "__main__":
    values = [3, 5, 6, 9, 1, 2, 0, -1]
    print("The optimal value is:", minimax(0, 0, True, values, MIN, MAX))

```

```python
# Python program to solve N Queen problem
global N
N = 4

def printSolution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()

def isSafe(board, row, col):
    # Check this row on the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on the left side
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solveNQUtil(board, col):
    # Base case: If all queens are placed, return true
    if col >= N:
        return True

    # Consider this column and try placing this queen in all rows one by one
    for i in range(N):
        if isSafe(board, i, col):
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Recur to place the rest of the queens
            if solveNQUtil(board, col + 1):
                return True

            # If placing the queen in the current position doesn't lead to a solution
            # then remove the queen from board[i][col]
            board[i][col] = 0

    # If the queen can't be placed in any row in this column, then return false
    return False

def solveNQ():
    board = [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ]

    if not solveNQUtil(board, 0):
        print("Solution does not exist")
        return False

    printSolution(board)
    return True

# Driver program to test above function
solveNQ()

```
