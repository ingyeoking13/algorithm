import pytest
import time
from src.robotarm import Solver as FreeArmRobotSolver
from src.appliedConstraintRobotArm import Solver as AppliedConstraintRobotArmSolver
from src.justSlidingPuzzle import Solver as SlidingPuzzleSolver

source_target = [
    ([[ '0', '9', '7', '0', 'H'], 
      ['4', '13', '1', '10', '5'],
      ['11', '2', 'H', '0', '8'], 
      ['6', '0', '0', '12', '3']],
     [[ '1', '0', '3', '10', 'H'], 
      ['13', '8', '0', '4', '12' ],
      ['6', '0', 'H', '7', '0'], 
      ['11', '5', '0', '9', '2' ]]),
    ([[ '0', '9', '7', '0', 'H'], 
      ['4', '13', '1', '10', '5'],
      ['11', '2', 'H', '0', '8'],
      ['6', '0', '0', '12', '3']],
     [[ '9', '0', '7', '0', 'H'], 
      ['4', '13', '1', '10', '5'],
      ['11', '2', 'H', '0', '8'],
      ['6', '0', '0', '12', '3']]),
    ([[ '1', '2', '3'],
      ['4', '0', '6'], 
      ['7','5','8']],
     [[ '1', '2', '3'],
      ['4', '5', '0'],
      ['6', '7', '8']]),
    ([['0', '3', '5'], 
      ['4', '7', '1'], 
      ['8', '2', '6']],
     [[ '1', '2', '3'],
      ['4', '5', '6'],
      ['7', '8', '0']]),
    ([[ '1', '2', '3'],
      ['4', '0', '5']],
     [[ '1', '2', '3'],
      ['4', '5', '0']]),
    ([[ '1', '0']],
     [[ '0', '1' ]])
]


# 로봇 팔이 장애물을 넘어가지 못하는 경우  (문제 1)
@pytest.mark.parametrize("source, target",source_target)
def test_constrainedArmRobotSolver(source, target):
    solver = AppliedConstraintRobotArmSolver()
    solver.printOption = 'test'
    st = time.time()
    result = solver.solve(source, target)
    et = time.time()
    print('solved: ', result, ' with times operator') if result >= 0 else print('unsolved')
    print('Elapsed time: ', et - st, ' (sec)')
    print('hit', solver.hit)
    # if result >= 0:
    #     solver.printPath()

# 로봇 팔을 제외한, 슬라이딩 퍼즐 알고리즘   (문제 2)
@pytest.mark.parametrize("source, target",source_target)
def test_slidingpuzzleSolver(source, target):
    solver = SlidingPuzzleSolver()
    solver.printOption = 'test'
    st = time.time()
    result = solver.solve(source, target)
    et = time.time()
    print('solved: ', result, ' with times operator') if result >= 0 else print('unsolved')
    print('Elapsed time: ', et - st, ' (sec)')
    print('hit', solver.hit)
    if result >= 0:
        solver.printPath()


# 로봇 팔이 장애물을 넘어갈 수 있는 경우 (서비스)
@pytest.mark.parametrize("source, target",source_target)
def test_freeArmRobotSolver(source, target):
    solver = FreeArmRobotSolver()
    solver.printOption = 'test'
    st = time.time()
    result = solver.solve(source, target)
    et = time.time()
    print('solved: ', result, ' with times operator') if result >= 0 else print('unsolved')
    print('Elapsed time: ', et - st, ' (sec)')
    print('hit', solver.hit)
    if result >= 0:
      solver.printPath()

