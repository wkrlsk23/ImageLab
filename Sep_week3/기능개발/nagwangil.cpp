#include <string>
#include <vector>
using namespace std;

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	
	vector<int> temp; //각 작업마다 몇일걸리는지
	vector<int> answer;//한번에 낼수 있는 작업수
	
	for (int i = 0; i < progresses.size(); i++)
	{
		int day=0;

		day= (100 - progresses.at(i)) / speeds.at(i);
		if ((100 - progresses.at(i)) % speeds.at(i))
		{
			day++;
		}
		temp.push_back(day);
	}

	for (int i = 0; i < temp.size(); i++)
	{
		int count = 0;//작업수 세기		뒤에있는작업중 기준값보다 크면 answer에 추가하기
		for (int j = i; j < temp.size(); j++)
		{
			if (temp.at(i) < temp.at(j))
			{
				answer.push_back(count);
				i = j-1;
				break;
			}
			else if (j +1 == temp.size())
			{
				answer.push_back(count+1);
				i = temp.size();
				break;
			}
			count++;
		}
	}
	return answer;
}
