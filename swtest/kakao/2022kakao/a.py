from datetime import datetime
from typing import Dict

def add_month(cur_date: datetime, month: int) -> datetime:
    cur_years = cur_date.year
    cur_month =  cur_date.month
    cur_day = cur_date.day
    cur_month += month
    cur_day -= 1
    if cur_day == 0:
        cur_day = 28
        cur_month -= 1
    cur_years += (cur_month-1)//12
    cur_month = ((cur_month-1)%12)+1
    return datetime(cur_years, cur_month, cur_day)

def solution(strtoday, strterms, strprivacies):
    tupled = list(map(lambda d: tuple(d.split(' ')), strterms))
    terms: Dict[str, int] = { tup[0] : int(tup[1]) for tup in tupled}

    today:datetime = datetime.strptime(strtoday, '%Y.%m.%d')

    privacies = list(map(lambda d: tuple(d.split(' ')), strprivacies))

    answer = []
    for idx, privacy in enumerate(privacies):
        strinsdate, term = privacy
        insdate = datetime.strptime(strinsdate, "%Y.%m.%d")
        expired_date = add_month(insdate, terms[term])
        if expired_date < today:
            answer.append(idx+1)

    return answer

# solution("2022.05.19", 1 , 2)
solution("2022.05.19", ["A 6", "B 12", "C 3"] , 
    ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"])
