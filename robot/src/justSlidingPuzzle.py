import functools
from pydantic import BaseModel
from queue import PriorityQueue
from typing import  Any, List, Optional, Tuple

def ManhattanDistance(state:Tuple, tupled_target:Tuple, col:int):
    result = 0
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
    printOption : Optional[str]

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

        queue = PriorityQueue()
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
                            n = Node(next_state, distance+1)
                            n.manhattan = ManhattanDistance(next_state, tupled_target, len(source[0]))
                            queue.put(n)

        return -1

    def printPath(self):
        prints = []
        state = self.solved_state
        while state:
            prints.append(state)
            state = self.visited[state]
        
        prints.reverse()
        for state in prints:
            if self.printOption != 'test':
                for i, c in enumerate(state):
                    print(c, end=', ' if i%self.col!=self.col-1  else '\n')
            print('-----------------------')

