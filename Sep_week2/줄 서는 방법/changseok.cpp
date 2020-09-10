#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    long long* fact = new long long[20];
    fact[0] = 1;
    
    //사전작업
    for(int i=1;i<=n;i++)
    {
        fact[i]=fact[i-1]*i;
        people.push_back(i);
    }
    
   
    int i=1;
    int div;
    while(!people.empty())
    {
        div = (k-1)/fact[n-i];
        answer.push_back(people[div]);
        people.erase(people.begin()+div);
        k -= div*fact[n-i];
        i++;
    }
    
    
    return answer;
}
