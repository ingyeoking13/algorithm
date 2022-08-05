from copy import deepcopy
from pydantic import BaseModel
from queue import Queue
from typing import List, cast
import time

class Solver(BaseModel):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def validate(self, source: List[List[str]], target: List[List[str]]):
        if not source or not target:
            raise RuntimeError()
    
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
        queue  = Queue()
        visited = set()
        visited.add(state_str)
        queue.put((state, px,py, '', 0))

        while not queue.empty():
            _state, px, py, grab, distance = queue.get()
            # print(_state, px, py, distance)
            next_state = deepcopy(cast(List[List[str]], _state))
            # put! 
            if grab and next_state[px][py] == '0':
                next_state[px][py] = grab
                grab = ''
                state_str = self.stringifyState(next_state, px, py)
                if state_str not in visited:
                    visited.add(state_str)
                    if target_str.split(',')[:-2] == state_str.split(',')[:-2]: return distance+1
                    queue.put((deepcopy(next_state), px, py, grab, distance+1))
                grab = next_state[px][py]
                next_state[px][py] = '0'

            # grab!
            if not grab and next_state[px][py] != '0':
                grab = next_state[px][py]
                next_state[px][py] = '0'
                state_str = self.stringifyState(next_state, px, py)
                if state_str not in visited:
                    visited.add(state_str)
                    queue.put((deepcopy(next_state), px, py, grab, distance+1))
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
                    queue.put((deepcopy(next_state), next_px, next_py, grab, distance+1))

        return -1

solver = Solver()
# source = [[ '0', '9', '7', '0', 'H'], 
#           ['4', '13', '1', '10', '5'],
#           ['11', '2', 'H', '0', '8'],
#           ['6', '0', '0', '12', '3']]
# target = [[ '1', '0', '3', '10', 'H'],
#           ['13', '8', '0', '4', '12' ],
#           ['6', '0', 'H', '7', '0'],
#           ['11', '5', '0', '9', '2' ]]

source = [[ '1', '2', '3'],
          ['4', '0', '5'], 
          ['6','7','8']
          ]
target = [[ '1', '2', '3'],
          ['4', '5', '0'],
          ['6', '7', '8'] ]

st = time.time()
print(solver.solve(source, target))
end = time.time()
print(end- st)
