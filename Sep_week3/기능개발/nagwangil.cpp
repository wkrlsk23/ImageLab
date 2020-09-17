#include <string>
#include <vector>
using namespace std;

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	
	vector<int> temp; //각 작업마다 몇일걸리는지
	vector<int> answer;//답
	
	for (int i = 0; i < progresses.size(); i++)
	{
		int day=0;//완성하는 날짜

		day= (100 - progresses.at(i)) / speeds.at(i); // 남은 작업량 / 작업속도
		if ((100 - progresses.at(i)) % speeds.at(i)) //나머지가 0이상이면 1일추가
		{
			day++;
		}
		temp.push_back(day); // 소요일 저장
	}

	for (int i = 0; i < temp.size(); i++) // i = 출시하는 것중 맨 앞에잇는 소요일 
	{
		int count = 0;//한번에 낼수 있는 작업의 수		뒤에있는작업중 기준값보다 크면 answer에 추가하기
		for (int j = i; j < temp.size(); j++)
		{
			if (temp.at(i) < temp.at(j)) //다음 작업의 소요일이 크면 한번에 출시할수 없음
			{
				answer.push_back(count);// 답 넣기						    세개 묶기 여기 4번으로 포인터 잡아주기
				i = j-1;// 묶어서 출시하는것들은 필요없으니 안묶인것들 중 첫번째로 갈수 있도록 설정 ((3,2,1),4,5,6,7)
				break;
			}
			else if (j +1 == temp.size())// 마지막까지 확인할때 답에 넣어야하므로
			{
				answer.push_back(count+1);  // 아래줄에  count++이라 마지막 작업을 더해줘야함
				i = temp.size();
				break;
			}
			count++;
		}
	}
	return answer;
}
