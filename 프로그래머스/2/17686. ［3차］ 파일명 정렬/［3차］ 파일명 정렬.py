def sort_key(file):
    head = ""
    head_idx = None
    for i, c in enumerate(file):
        if c >= '0' and c <= '9':
            head = file[:i]
            head_idx = i
            break

    number = file[head_idx:]
    for i in range(head_idx, len(file)):
        if file[i] < '0' or file[i] > '9':
            number = file[head_idx:i]
            break
    
    return (head.lower(), int(number))

def solution(files):
    answer = []
    
    return sorted(files, key=sort_key)