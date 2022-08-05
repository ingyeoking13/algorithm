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
# source = [[ '1', '2', '3'],
#           ['4', '0', '6'], 
#           ['7','5','8']
#           ]
# target = [[ '1', '2', '3'],
#           ['4', '5', '0'],
#           ['6', '7', '8'] ]

# source = [[ '1', '2', '3'],
#           ['4', '0', '5'] ]
# target = [[ '1', '2', '3'],
#           ['4', '5', '0']]
# source = [[ '1', '0']]
# target = [[ '0', '1' ]]

tupled_target = tuple(char for row in target for char in row)


@functools.total_ordering
class Node:
    state:Tuple[str]
    p:int
    grab:str
    distance:int

    def ManhattanDistance(self):
        result = 0
        col = len(source[0])
        for i in range(len(self.state)):
            elem = self.state[i]
            if elem == '0': 
                continue

            for j in range(len(self.state)):
                if tupled_target[j] == elem:
                    diff = abs(j-i)
                    diff = int(diff/col) + diff%col 
                    result += diff
                    break

        return result

    def __init__(self, state:Tuple[str], p:int, grab:str, distance:int) -> None:
        self.state = state
        self.p = p
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
    solved_state: Optional[str]
    visited:Optional[Any]

    def __init__(self, **data) -> None:
        super().__init__(**data)
    
    def solve(self, source: List[List[str]], target: List[List[str]]):
        rows = len(source)
        cols = len(source[0])
        p = 0

        source_state = tuple(char for row in source for char in row)
        tupled_target = tuple(char for row in target for char in row)

        source_state_merged = source_state + (p,)
        answer = tupled_target + (p,)

        queue = cast(Queue, self.queue)
        visited = self.visited = {}
        visited[source_state_merged] = ''
        queue.put(Node(source_state, p, '', 0))

        while not queue.empty():
            node: Node= queue.get()
            state, p, grab, distance = (node.state , node.p, node.grab, node.distance)
            # print(state, p, grab)

            # put! 
            if grab and state[p] == '0': 
                next_state = state[:p] + (grab,) + state[p+1:]
                state_merged = next_state + (p,)
                if state_merged not in visited:
                    visited[state_merged] = {'map': state, 'grab': grab, 'p': p }

                    # we solve!
                    if answer[:-1] == state_merged[:-1]: 
                        self.solved_state = state_merged
                        return distance+1

                    queue.put(Node(next_state, p, '', distance+1))


            # grab!
            if not grab and state[p] != '0':
                next_state = state[:p] +  ('0',) + state[p+1:]
                state_merged = next_state  +(p,)
                if state_merged not in visited:
                    visited[state_merged] = {'map': state, 'grab': grab, 'p':p}
                    queue.put(Node(next_state, p, state[p], distance+1))

            # or... just move!
            for dir in range(4):
                next_px = int(p/cols) + self.dx[dir]
                next_py = p%cols + self.dy[dir]

                if next_px < 0 or next_py < 0  or next_px >= rows or next_py >= cols: 
                    continue

                next_p = next_px*cols + next_py
                if grab and state[next_p] != '0':
                    continue
                    
                state_merged =  state + (next_p,)
                if state_merged not in visited:
                    visited[state_merged] = {'map': state, 'grab': grab, 'p': p}
                    queue.put(Node(state, next_p, grab, distance+1))

        return -1

    def printPath(self):
        # print(self.visited)
        pass


solver = Solver(queue=PriorityQueue())
# solver = Solver(queue=Queue())

st = time.time()
result = solver.solve(source, target)
print('solved: ', result, ' with times operator') if result >= 0 else print('unsolved')

if result > 0:
    solver.printPath()

end = time.time()

print(end- st)
