#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long k) {
    k--;
    vector<int> temp;
    vector<int> answer;
    int Positioner=0;
    long long Divider=1;
    for (int i = 1; i <= n; i++)
    {
        temp.push_back(i);
        if (i > 1)
        {
            Divider = Divider*(i - 1);
        }
    }
    
    while (true)
    {
        n--;
        Positioner = k / Divider;
        k = k % Divider;
        Divider = Divider / n;
        
        answer.push_back(temp[Positioner]);
   
        if (Positioner == 0)
        {
            it = temp.erase(temp.begin());
        }
        else
        {
            temp.erase(temp.begin() + Positioner );
        } 
        if (n == 1)
        {
            answer.push_back(temp.at(0));
            break;
        }
    }
    return answer;
}
