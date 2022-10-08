from api import *
from logic import *
import time


auth_key, _, _ = start_api(1)
minutes = 540
# w = get_waiting(auth_key)
d = put_match(auth_key, [])

for i in range(minutes):
    w = get_waiting(auth_key)
    l = matcher(w)
    d = put_match(auth_key, l)
    r = get_gameresult(auth_key)
    print(w, r)
    
    # get_userinfo(auth_key)
    time.sleep(0.3)
# get_wating()
# get_wating()
# get_wating()

