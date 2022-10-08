from typing import List

skills = {}

def matcher(users) -> List[List[int]]:
    global skills
    l :List[List[int]] = []
    sorted(users, key=lambda u: skills.get(u['id'],0), reverse=True)
    
    i = 0
    while i < len(users): 
        if i+1 == len(users):
            i+=1
            continue

        l.append([users[i]['id'], users[i+1]['id']])
        i+=2

    return l