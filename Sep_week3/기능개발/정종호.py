def solution(s):
    answer = []
    result = ""
    if len(s) == 1:
        return 1
    #절반까지만 탐색  실행(최대가 절반)
    for cut in range(1, len(s) // 2 + 1): 
        c = 1
        tempStr = s[:cut] 
        #tempStr은 cut 까지 자르고 파악한다.
        #아래 반복문은 그 이후부터 끝까지 cut 만큼의 간격으로 탐색
        for i in range(cut, len(s), cut):
            if s[i:i+cut] == tempStr:
                c += 1
            else:
                #합쳐주는 과정, 같은게 없으면 숫자를 안붙임.
                if c == 1:
                    c = ""
                result += str(c) + tempStr
                #결과를 합쳐준 이후, 자른 부분을 다시 옮김
                tempStr = s[i:i+cut]
                c = 1
        #합쳐주는 과정, 같은게 없으면 숫자를 안붙임.
        if c == 1:
            c = ""
        result += str(c) + tempStr
        answer.append(len(result))
        result = ""
    
    return min(answer)
