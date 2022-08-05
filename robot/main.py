from copy import deepcopy
import functools
from pydantic import BaseModel
from queue import PriorityQueue, Queue 
from typing import List, Optional, Any
import time
source = [[ '1', '2', '3'],
          ['4', '0', '6'], 
          ['7','5','8']
          ]
target = [[ '1', '2', '3'],
          ['4', '5', '0'],
          ['6', '7', '8'] ]
# source = [[ '0', '9', '7', '0', 'H'], 
#           ['4', '13', '1', '10', '5'],
#           ['11', '2', 'H', '0', '8'],
#           ['6', '0', '0', '12', '3']]

# target = [[ '1', '0', '3', '10', 'H'],
#           ['13', '8', '0', '4', '12' ],
#           ['6', '0', 'H', '7', '0'],
#           ['11', '5', '0', '9', '2' ]]

@functools.total_ordering
class Node:
    state:List[List[str]]
    px:int
    py:int
    grab:str
    distance:int

    def ManhattanDistance(self):
        result = 0
        row = len(self.state)
        col = len(self.state[0])

        for i in range(row):
            for j in range(col):
                elem = self.state[i][j]
                if elem == '0': 
                    continue
                # Variable to break the outer loop and avoid unnecessary processing
                found = False
                # Loop to find element in goal state and MD
                for k in range(row):
                    for l in range(col):
                        if target[k][l] == elem:
                            result += abs(k - i) + abs(j - l)
                            found = True
                            break
                    if found: break

        return result

    def __init__(self, state, px, py, grab, distance) -> None:
        self.state = state
        self.px = px
        self.py = py
        self.grab = grab
        self.distance = distance

    def __gt__(self, other):
        if not isinstance(other, Node):
            raise NotImplemented
        
        return self.ManhattanDistance() > other.ManhattanDistance()


class Solver(BaseModel):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    queue: Optional[Any]

    def __init__(self, **data) -> None:
        super().__init__(**data)
    
    def stringifyState(self, state:List[List[str]], px:int, py:int):
        state_str = ','.join([ char for  row in  state for char in row ])
        state_str += ',' + str(px) + ',' + str(py)
        return state_str

    def solve(self, source: List[List[str]], target: List[List[str]]):
        rows = len(source)
        cols = len(source[0])
        px = 0
        py = 0

        state = deepcopy(source)
        state_str = self.stringifyState(state, px, py)
        target_str = self.stringifyState(target, 0, 0)
        queue = self.queue
        # queue  = Queue()
        visited = set()
        visited.add(state_str)
        queue.put(Node(state, px,py, '', 0))

        while not queue.empty():
            node: Node= queue.get()
            state, px, py, grab, distance = (node.state , node.px, node.py, node.grab, node.distance)
            # print(_state, px, py, distance)
            next_state = deepcopy(state)
            # put! 
            if grab and next_state[px][py] == '0':
                next_state[px][py] = grab
                grab = ''
                state_str = self.stringifyState(next_state, px, py)
                if state_str not in visited:
                    visited.add(state_str)
                    if target_str.split(',')[:-2] == state_str.split(',')[:-2]: return distance+1
                    queue.put(Node(deepcopy(next_state), px, py, grab, distance+1))
                grab = next_state[px][py]
                next_state[px][py] = '0'

            # grab!
            if not grab and next_state[px][py] != '0':
                grab = next_state[px][py]
                next_state[px][py] = '0'
                state_str = self.stringifyState(next_state, px, py)
                if state_str not in visited:
                    visited.add(state_str)
                    queue.put(Node(deepcopy(next_state), px, py, grab, distance+1))
                next_state[px][py] = grab
                grab = ''

            # or... just move!
            for dir in range(4):
                next_px = px + self.dx[dir]
                next_py = py + self.dy[dir]
                if next_px < 0 or next_py < 0  or next_px >= rows or next_py >= cols: 
                    continue
                if grab: 
                    if next_state[next_px][next_py] != '0':
                        continue
                    
                state_str = state_str = self.stringifyState(next_state, next_px, next_py)
                if state_str not in visited:
                    visited.add(state_str)
                    queue.put(Node(deepcopy(next_state), next_px, next_py, grab, distance+1))

        return -1

solver = Solver(queue=Queue())

st = time.time()
print(solver.solve(source, target))
end = time.time()
print(end- st)
