all_queries = 0
all_queries_expired_replies = 0
all_queries_room_count = 0
all_accepteds = 0
all_accepteds_room_count = 0

# 구분	공식
# 정확성 점수	U * 80
# 효율성 점수	Σ V / T1 * 10
# 페널티 점수	Σ P / T2 * 5000 + Σ A / T2 * 900 + R / T3 * 40
# 총점	max(0, 500 + 정확성 점수 + 효율성 점수 - 페널티 점수)
# ※ 객실 이용률 = Σ (객실 이용 날짜 수) / (호텔의 객실 수 * 시뮬레이션 길이) * 100
# ※ U = (min(객실 이용률, 목표치) / 목표치)^2
# ※ V = 예약 요청의 (답변 기한 - 답변 날짜)
# ※ T1 = 모든 예약 요청의 (답변 기한 - 요청 날짜)
# ※ P = 승낙했으나 객실 배정에 실패한 예약의 객실 수
# ※ A = 거절한 예약 요청의 객실 수
# ※ T2 = 모든 예약 요청의 객실 수
# ※ R = 예약 요청을 거절한 횟수
# ※ T3 = 모든 예약 요청의 수

def local_score():
    U = 80
    V = 0
    T1 = 1
    P = 0
    A = all_queries_room_count - all_accepteds_room_count
    T2 = all_queries_room_count
    R = all_queries - all_accepteds
    T3 = all_queries
    print(all_queries)
    print(all_accepteds)
    print(all_queries_room_count)
    print(all_accepteds_room_count)
    print('a:', A/T2 * 900)
    print('r:', R/T3 * 40)
    return A/T2 * 900 + R/T3 * 40

    global auth_key
    global all_queries
    global all_queries_expired_replies
    global all_queries_room_count
    global all_accepteds
    global all_accepteds_room_count 
