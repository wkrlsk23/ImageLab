#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;
    bool first = true;     
    vector<int> passing;//다리위 트럭들
    vector<int> passing_time; //다리 위에 있든 트럭들이 얼마나 오래있었는지
    vector<int> passied; //다리를 지난 트럭들
    
    while (true)
    {
        answer++;

        if (passing_time.size())
        {
            
            if (passing_time.at(0) > bridge_length)//트럭이 다 지나갔는지
            {
                weight += passing.at(0);
                passing.erase(passing.begin());
                passing_time.erase(passing_time.begin());
            }
        }


        if (truck_weights.size())
        {
            if (weight - truck_weights.at(0) >= 0)//다음 트럭이 다리위로 올라갈수 있는지
            {
                passing.push_back(truck_weights.at(0));
                
                if (first)
                {
                    passing_time.push_back(0);
                    first = false;
                }
                else passing_time.push_back(1);
                weight -= truck_weights.at(0);
                truck_weights.erase(truck_weights.begin());
            }

        }

        for (int i = 0; i < passing_time.size(); i++)//트럭들을 한칸씩 전진
        {
            passing_time.at(i)++;
        }
        if (passing.size() ==0)
        {
            cout << answer << endl;*/
            return answer-1;
        }

    }

    return answer;
}
