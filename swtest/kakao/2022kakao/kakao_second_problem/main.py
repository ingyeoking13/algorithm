import api
from typing import Deque, cast, List, Optional, Tuple
from queue import PriorityQueue

scenarios = [200, 1000]
auth_key = ''

class Hotel():
    # 1: 한 층에 20개의 객실이 있는 3층 건물입니다.
    # 2: 한 층에 200개의 객실이 있는 10층 건물입니다.
    rooms: List[List[Deque[api.ReservationInfo]]]
    def __init__(self, problem_number:int):
        if problem_number == 1:
            self.rooms = [[Deque() for _ in range(20)] for _ in range(3)]
        else: 
            self.rooms = [[Deque() for _ in range(200)] for _ in range(10)]

    def _is_valid_room(self, checked_infos: Deque[api.ReservationInfo], will_check: api.ReservationInfo):
        if len(checked_infos) == 0:
            return True

        result = True
        for checked_info in checked_infos: 
            result &= ( checked_info.check_out_date <= will_check.check_in_date or 
                        will_check.check_out_date <= checked_info.check_in_date)

        return result

    def get_first_fit(self, floor_rooms: List[List[api.ReservationInfo]], info: api.ReservationInfo) -> Optional[Tuple[int, int]]:
        _length = 0
        for i in range(len(floor_rooms)):
            cur:Deque[api.ReservationInfo] = floor_rooms[i]
            if not self._is_valid_room(cur, info):
                _length = 0
                continue
            _length += 1
            if _length == info.amount:
                return [i-_length+1, i]

        return None

    def validate(self, info:api.ReservationInfo) -> int:
        for row in range(len(self.rooms)):
            row_room = self.rooms[row]
            room_number = self.get_first_fit(row_room, info)
            if not room_number:
                continue

            self.update_room_reservation_info(row_room, info, room_number[0])
            return 1000*(row+1) + room_number[0] +1

        return -1
    
    def update_room_reservation_info(self, floor_rooms: List[List[api.ReservationInfo]], info :api.ReservationInfo, room_number:int):
        for i in range(info.amount):
            checked_infos = floor_rooms[room_number + i]
            idx = 0 
            for j in range(len(checked_infos)):
                checked_info = checked_infos[j]
                if checked_info.check_out_date <= info.check_in_date:
                    idx +=1
                elif info.check_out_date <= checked_info.check_in_date:
                    idx = j
                    break
            checked_infos.insert(idx, info)
                
        
    def cleanup(self, day:int):
        rows = len(self.rooms)
        cols = len(self.rooms[0])
        for row in range(rows):
            for col in range(cols):
                infos = self.rooms[row][col]
                if len(infos) == 0:
                    continue
                if infos[0].check_out_date == day:
                    infos.popleft()
                    break
            
    
    def show(self, ver='min', day=0):
        rows = len(self.rooms)
        cols = len(self.rooms[0])
        for row in reversed(range(rows)):
            if ver == 'min':
                print(row, ":", end='')
                for col in range(cols):
                    checked_infos = self.rooms[row][col]
                    checkd = False
                    for checked_info in checked_infos:
                        if not (checked_info.check_out_date <= day or day <= checked_info.check_in_date):
                            print( checked_info.id, end=', ' )
                            checkd = True
                    if not checkd:
                        print('[]', end='')
                print('')

            else: 
                print(row, ' :' ,self.rooms[row])



pq = PriorityQueue()
pq_2 = PriorityQueue()


def main():

    auth_key, problem, day = api.start_api(2)
    hotel = Hotel(problem)
    solve(auth_key, problem, scenarios[int(problem)])
    for _ in range(scenario2):
        infos:List[api.ReservationInfo] = api.reservation_api(auth_key)

        for info in infos:
            info.day = day
            pq.put(info)

        while not pq.empty():
            _info = pq.queue[0]
            info = cast(api.ReservationInfo, _info)

            if info.check_in_date < day:
                pq.get()
                continue

            result = hotel.validate(info)
            if result == -1:
                pq.get()
                api.reply_api(auth_key, [{'id': info.id, 'reply': 'refused'}])
            else:
                api.reply_api(auth_key, [{'id': info.id, 'reply': 'accepted'}])
                pq_2.put(api.OrderReservationInfo(**{**dict(info), 'room_number': result}))
                pq.get()

        request = []
        while not pq_2.empty():
            _info = pq_2.queue[0]
            info = cast(api.OrderReservationInfo, _info)

            if info.check_in_date == day:
                request.append( {'id': info.id, 'room_number': info.room_number})
                pq_2.get()
            else:
                break
        
        day, fail_count = api.simulate_api(auth_key, request)
        # print('requesting',  request)
        # print(day, fail_count)


main()
print(api.score_api(auth_key))

# --------------------- 1000 ^^~~~~
# requesting []
# 1001 0
# (80.0, 10.0, 101.8907706207874, 488.1092293792126)