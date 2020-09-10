def solution(prices):
    answer = []
    for i,v in enumerate(prices) :
        #print(i,v)
        init = v
        count = 0
        for k in prices[i:]:
            count += 1
            if k < v :
                break
        answer.append(count-1)
    return answer
