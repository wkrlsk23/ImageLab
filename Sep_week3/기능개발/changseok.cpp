#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> release;
    for(int i=0;i<progresses.size();i++)
    {
        int temp = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]==0)
        {
            release.push_back(temp);
        }
        else
        {
            release.push_back(temp+1);
        }
    }
    int index=0;
    int day=release[0];
    answer.push_back(1);
    for(int j=1; j<release.size() ; j++)
    {
        if(release[j] <= day)
        {
            //현재 인덱스값 증가
            answer[index]++;
        }
        else
        {
            //다음 인덱스에 추가
            answer.push_back(1);
            index++;
            day = release[j];
        }
    }
    return answer;
}
