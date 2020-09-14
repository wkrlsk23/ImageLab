def solution(bridge_length, weight, truck_weights):
    #변수 선언
    total = len(truck_weights) 
    truck_weights = list(reversed(truck_weights))
    answer = 0
    curr_weights = 0
    passing = []
    passed = []
    
    while len(passed) < total :
        
        answer += 1
        
        #시간이 지나면 꺼낸다.
        if len(passing) > 0 :
            if answer - passing[0][1] >= bridge_length :
                weights = passing[0][0]
                curr_weights -= weights
                passed.append(weights)
                del passing[0]
        
        #더 넣을수 있을때 넣어준다.
        if len(truck_weights) > 0 :
            if curr_weights + truck_weights[-1] <= weight :
                curr_weights += truck_weights[-1]
                passing.append((truck_weights.pop(),answer))
            
    return answer
