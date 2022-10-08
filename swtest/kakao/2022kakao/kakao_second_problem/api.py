import json
import requests
from typing import Dict, Tuple, cast, List, Optional
from pydantic import BaseModel
import functools


base_url = 'https://68ecj67379.execute-api.ap-northeast-2.amazonaws.com/api'
x_token = '68bf2112d9082beba4d412c10d8f7c96'


@functools.total_ordering
class ReservationInfo(BaseModel):
    id: int
    amount: int
    check_in_date: int
    check_out_date: int
    day: Optional[int]

    def __gt__(self, other):
        other = cast(ReservationInfo, other)
        if self.check_in_date == other.check_in_date:
            return self.amount < other.amount
        return self.check_in_date > other.check_in_date 

class OrderReservationInfo(ReservationInfo):
    room_number: int


def start_api(problem_number: int) -> Tuple[str, str, str]:
    response : requests.Response = requests.post(f'{base_url}/start', 
        headers={
            'X-Auth-Token':x_token, 
            'Content-Type': 'application/json'
        },
        data= json.dumps({
            "problem": problem_number
        })
    )
    _response:Dict = response.json()
    auth_key = _response.get('auth_key')
    problem = _response.get('problem')
    day = _response.get('day')
    return auth_key, problem, day


def simulate_api(auth, req:List) -> Tuple[int, int]:
    response : requests.Response = requests.put(f'{base_url}/simulate', 
        headers={
            'Authorization': auth, 
            'Content-Type': 'application/json'
        },
        data= json.dumps({
            "room_assign": req
        })
    )
    _response:Dict = response.json()
    day = _response.get('day')
    fail_count = _response.get('fail_count')
    return int(day), int(fail_count)

def score_api(auth) -> Tuple[float, float, float, float]:
    response : requests.Response = requests.get(f'{base_url}/score', 
        headers={
            'Authorization': auth, 
            'Content-Type': 'application/json'
    })
    _response:Dict = response.json()
    accuracy_score = _response.get('accuracy_score')
    efficiency_score = _response.get('efficiency_score')
    penalty_score = _response.get('penalty_score')
    score = _response.get('score')
    return accuracy_score, efficiency_score, penalty_score, score

def reservation_api(auth): 
    response : requests.Response = requests.get(f'{base_url}/new_requests', 
        headers={
            'Authorization': auth, 
            'Content-Type': 'application/json'
    })
    _response:Dict = response.json()
    _reservations = _response.get('reservations_info')
    reservations = [ReservationInfo(**d) for d in _reservations]
    return reservations

def reply_api(auth, replies):
    response : requests.Response = requests.put(f'{base_url}/reply', 
        headers={
            'Authorization': auth, 
            'Content-Type': 'application/json'
        },
        data= json.dumps({
            "replies": replies
        })
    )
    _response:Dict = response.json()
    day = _response.get('day')
    return int(day)

