#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
class Truck
{
    public:
    int truckWeight;
    int currentPosition=0;
    Truck(int truckWeight)
    {
        this->truckWeight = truckWeight;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int totalWeight=0;
    int clock =0;
    vector<Truck*> bridge;
    queue<Truck*> truckQue;
    for(int i=0;i<truck_weights.size();i++)
    {
        Truck* truck = new Truck(truck_weights[i]);
        truckQue.push(truck);
    }
    
    bridge.push_back(truckQue.front());
    truckQue.pop();
    bridge[0]->currentPosition++;
    totalWeight = bridge[0]->truckWeight;
    clock++;
    while(!(bridge.empty()&&truckQue.empty()))
    {
        //다리위에 있는 트럭의 현재 위치들을 1증가
        for(auto t : bridge)
        {
            t->currentPosition++;
        }
        //선두에있는 트럭이 다리를 통과하면 삭제
        if(bridge[0]->currentPosition>bridge_length){
            totalWeight -= bridge[0]->truckWeight;
            bridge.erase(bridge.begin());
        }
        
        if(!truckQue.empty() && ((totalWeight+truckQue.front()->truckWeight)<=weight) && (bridge.size() < bridge_length)){
            bridge.push_back(truckQue.front());
            bridge.back()->currentPosition++;
            totalWeight += bridge.back()->truckWeight;
            truckQue.pop();
        }
        clock++;
    }
    answer = clock;
    return answer;
}
