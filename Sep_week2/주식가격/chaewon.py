def solution(prices):
    length = len(prices)
    answer = [0]*length
    for i, v in enumerate(prices):
        buffer = 0
        for j in range(i,length):
            if prices[i] == 1:
                answer[i] = length-i-1
                break
            if prices[i] > prices[j]:
                answer[i] = buffer
                break
            if j == length -1:
                answer[i] = buffer
            buffer += 1
    return answer
