from copy import deepcopy
import functools
from pydantic import BaseModel
from queue import PriorityQueue, Queue 
from typing import  Any, cast, List, Optional, Tuple
import time

source = [[ '0', '9', '7', '0', 'H'], 
          ['4', '13', '1', '10', '5'],
          ['11', '2', 'H', '0', '8'],
          ['6', '0', '0', '12', '3']]

target = [[ '1', '0', '3', '10', 'H'],
          ['13', '8', '0', '4', '12' ],
          ['6', '0', 'H', '7', '0'],
          ['11', '5', '0', '9', '2' ]]

# source = [[ '0', '9', '7', '0', 'H'], 
#           ['4', '13', '1', '10', '5'],
#           ['11', '2', 'H', '0', '8'],
#           ['6', '0', '0', '12', '3']]

# target = [[ '9', '0', '7', '0', 'H'], 
#           ['4', '13', '1', '10', '5'],
#           ['11', '2', 'H', '0', '8'],
#           ['6', '0', '0', '12', '3']]

# source = [[ '1', '2', '3'],
#           ['4', '0', '6'], 
#           ['7','5','8']
#           ]
# target = [[ '1', '2', '3'],
#           ['4', '5', '0'],
#           ['6', '7', '8'] ]

# source = [['0', '3', '5'], 
#         ['4', '7', '1'], 
#         ['8', '2', '6']]
# target = [[ '1', '2', '3'],
#           ['4', '5', '6'],
#           ['7', '8', '0']]

# source = [[ '1', '2', '3'],
#           ['4', '0', '5'] ]
# target = [[ '1', '2', '3'],
#           ['4', '5', '0']]
# source = [[ '1', '0']]
# target = [[ '0', '1' ]]

tupled_target = tuple(char for row in target for char in row)


def ManhattanDistance(state:Tuple):
    result = 0
    col = len(source[0])
    for i in range(len(state)):
        elem = state[i]
        if elem == '0': 
            continue

        for j in range(len(state)):
            if tupled_target[j] == elem:
                diff = abs(j-i)
                diff = int(diff/col) + diff%col 
                result += diff
                break

    return result

@functools.total_ordering
class Node:
    state:Tuple[str]
    distance:int
    manhattan:int

    def __init__(self, state:Tuple[str], distance:int) -> None:
        self.state = state
        self.distance = distance
        self.manhattan = ManhattanDistance(state)

    def __gt__(self, other):
        if not isinstance(other, Node):
            raise NotImplemented
        
        return self.manhattan > other.manhattan


class Solver(BaseModel):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    queue: Optional[Any]
    solved_state: Optional[str]
    visited:Optional[Any]
    adjacent = {}
    row = 0
    col = 0
    hit = 0

    def __init__(self, **data) -> None:
        super().__init__(**data)
    
    def adjacentfill(self, source:List[List[str]]):
        count = 0
        self.row = row = len(source)
        self.col = col = len(source[0])
        dd  = [[0]*col]*row
        for i in range(row):
            for j in range(col):
                dd[i][j] = count
                count += 1
        
        self.adjacent = {}
        for i in range(row):
            for j in range(col):
                p = i*col + j
                for dir in range(4):
                    next_i = i + self.dx[dir]
                    next_j = j + self.dy[dir]

                    if next_i < 0 or next_j < 0  or next_i >= row or next_j >= col: 
                        continue

                    next_p = next_i*col+next_j
                    _list = self.adjacent.get(p, []) 
                    self.adjacent[p] = [*_list, next_p]
    
    def solve(self, source: List[List[str]], target: List[List[str]]):
        self.adjacentfill(source)

        source_state = tuple(char for row in source for char in row)
        tupled_target = tuple(char for row in target for char in row)

        source_state_merged = source_state
        answer = tupled_target

        queue = cast(Queue, self.queue)
        visited = self.visited = {}
        visited[source_state_merged] = ''
        queue.put(Node(source_state, 0))

        while not queue.empty():
            self.hit += 1
            node: Node= queue.get()
            state, distance = (node.state, node.distance)
            # print(state, distance)
            if answer == state:
                self.solved_state = state
                return distance+1
            # ...^^
            for p in self.adjacent.keys():
                if state[p] == '0' or state[p] == 'H':
                    continue

                for next_p in self.adjacent[p]:
                    if state[next_p] == '0':
                        c = state[p]

                        next_state = state[:p] + ('0',) + state[p+1:]
                        next_state = next_state[:next_p] + (c, ) + next_state[next_p+1:]

                        if next_state not in visited:
                            visited[next_state] = state
                            queue.put(Node(next_state, distance+1))

        return -1

    def printPath(self):
        prints = []
        state = self.solved_state
        while state:
            prints.append(state)
            state = self.visited[state]
        
        prints.reverse()
        for state in prints:
            for i, c in enumerate(state):
                print(c, end=', ' if i%self.col!=self.col-1  else '\n')



solver = Solver(queue=PriorityQueue())
# solver = Solver(queue=Queue())

st = time.time()
result =  solver.solve(source, target)
end = time.time()
print('solved: ', result, ' with times operator') if result >= 0 else print('unsolved')
print('Elapsed time: ', end- st, ' (sec)')
print('hit', solver.hit)

if result > 0:
    solver.printPath()