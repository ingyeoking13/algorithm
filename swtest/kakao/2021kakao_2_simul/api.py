import json
import requests
from typing import Dict, Tuple

base_url = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
x_token = 'c64afcc0e6254b412e7042f9070edf2f'

def start_api(problem_number: int) -> Tuple[str, str, str]:
    response : requests.Response = requests.post(f'{base_url}/start', 
        headers={'X-Auth-Token':x_token, 'Content-Type': 'application/json'},
        data= json.dumps({
            "problem": problem_number
        })
    )
    _response:Dict = response.json()
    auth_key = _response.get('auth_key')
    problem = _response.get('problem')
    time = _response.get('time')
    return auth_key, problem, time

def get_waiting(auth_key:str):
    response = requests.get(f'{base_url}/waiting_line', headers={
        'Authorization': auth_key,
        'Content-Type': 'application/json'
    })
    # print(response.content)
    _response = response.json()
    waiting_line = _response.get('waiting_line')
    return waiting_line

def get_userinfo(auth_key:str):
    response = requests.get(f'{base_url}/user_info', headers={
        'Authorization': auth_key,
        'Content-Type': 'application/json'
    })
    _response = response.json()
    print(_response)

def get_gameresult(auth_key:str):
    response = requests.get(f'{base_url}/game_result', headers={
        'Authorization': auth_key,
        'Content-Type': 'application/json'
    })
    _response = response.json()
    return _response

def put_match(auth_key:str, array_user):
    response = requests.put(f'{base_url}/match',
        headers={
            'Authorization': auth_key,
            'Content-Type': 'application/json'
        },
        data = json.dumps({
            'pairs': array_user
        }))

    _response = response.json()
    print(_response)
    