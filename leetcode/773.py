from queue import Queue
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        source:str =''
        target:str ='123450'
        width:int = 3
        height:int = 2
            
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
            
        for row in board:
            for number in row:
                source += str(number)
        visit = set()
        visit.add(source)
        q = Queue()
        q.put((source, 0))
        
        while not q.empty():
            state, depth = q.get()
            if state == target: 
                return depth
            
            for i in range(len(state)):
                for j in range(4):
                    nx = int(i/width) + dx[j]
                    ny = int(i%width) + dy[j]
                    if nx<0 or ny<0 or nx>=height or ny >= width:
                        continue
                    ni = nx*width+ny
                    # print(nx, width, ny, ni)
                    if state[ni] != '0':
                        continue
                    # swap
                    next_state = state
                    # print(next_state[ni], state[i])
                    next_state = next_state[:ni] + state[i] + next_state[ni+1:]
                    next_state = next_state[:i] + '0' + next_state[i+1:]
                    if next_state in visit:
                        continue
                    visit.add(next_state)
                    q.put((next_state, depth+1))
        return -1
       