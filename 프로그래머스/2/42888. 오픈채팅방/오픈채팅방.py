def solution(record):
    answer = []
    nickname = {}
    for r in record:
        parts = r.split()
        cmd, uid = parts[:2]
        if cmd == "Enter" or cmd == "Change":
            nickname[uid] = parts[2]
    
    for r in record:
        parts = r.split()
        cmd, uid = parts[:2]
        if cmd == "Enter":
            answer.append(f"{nickname[uid]}님이 들어왔습니다.")
        elif cmd == "Leave":
            answer.append(f"{nickname[uid]}님이 나갔습니다.")
    return answer