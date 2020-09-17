#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0; //답 ==시간초
    bool first = true; //첫 트럭이 올라가는지     
    vector<int> passing;//다리위 트럭들
    vector<int> passing_time; //다리 위에 있든 트럭들이 얼마나 오래있었는지
    vector<int> passied; //다리를 지난 트럭들
    
    while (true)
    {
        answer++; //시간초++

        if (passing_time.size())//다리 위에 트럭이 있다고 할때
        {
            
            if (passing_time.at(0) > bridge_length)// 맨 앞 트럭이 다리를 건넜는지 확인
            {
                weight += passing.at(0); //다리를 지났으니 그만큼 여유 무게 +
                passing.erase(passing.begin());//다리위 트럭들에서 삭제
                passing_time.erase(passing_time.begin()); // 다 지나간 트럭의 시간초 삭제
            }
        }


        if (truck_weights.size())
        {
            if (weight - truck_weights.at(0) >= 0)//다음 트럭이 다리위로 올라갈수 있는지
            {
                passing.push_back(truck_weights.at(0));//트럭추가
                
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
        if (passing.size() ==0)//트럭이 다 지나갔는지 확인
        {
            cout << answer << endl;*/
            return answer-1; //무조건 여기서 종료, 0초 관련해서도 while문이 돌아서 -1을 해줬습니다
        }

    }

    return answer;
}
