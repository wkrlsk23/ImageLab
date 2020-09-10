#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size()-1;
    vector<int> answer(size, 1);
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(prices[i]>prices[j])
            {
                break;
                
            }
            else
            {
                answer[i]++;
            }
        }
    }
    answer.push_back(0);
    return answer;
}
