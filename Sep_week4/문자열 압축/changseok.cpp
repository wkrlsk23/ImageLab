#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//n개 단위로 문자를 잘라 압축, 압축한 결과를 반환
string zip(string s, int n){
    string result = ""; //최종 반환값을 저장할 변수
    string val ="";//잘라낸 문자열
    stack<string> temp;//이전 문자열이 무엇이었는지 저장하기 위한 스택
    int count=1; //문자열이 몇번 반복되었는지 확인하는 변수
    
    //처음에 스택이 비어있기 때문에 사전작업
    val = s.substr(0,n);
    temp.push(val);
    s.erase(0,n);

    while(s.size()>=n)
    {
        val = s.substr(0,n);    //문자열을 n개 단위로 자르고 처음 문자열에서 지운다
        s.erase(0,n);
        if(val == temp.top()){ //스택의 탑에 있는 문자열과 같으면 count를 1 증가
            count++;
            
        }else{//스택의 탑에 있는 문자열과 다르고 count가 2 이상이면(1이면 압축하는 의미가 없으므로)반복된 횟수와 문자열을 
              //result에 추가, 스택의 탑을 변경해주고 count를 초기화 해준다
            
            if(count>=2)
            {
                result += to_string(count);
            }
            result+=temp.top();
            temp.push(val);
            count = 1;
        }
    }
    //반복문을 돌고 문자열이 남아있는 경우 1. 같은 문자열이 반복되다가 끝나는 경우  2. 다른 문자열이 오고 끝나는 경우
    if(count>=2)// 1번의 경우이다, 반복된 횟수와 문자열을 추가해주고 남아있는 문자열을 추가해준다.
    {
        result += to_string(count)+temp.top()+s;
        
    }else result = result+temp.top()+ s;//2번의 경우이다 반복된 사항이 없으므로 스택에 남아있는 문자열과 나머지 문자열을 추가해준다.
    return result;
}

int solution(string s) {
    int answer = 0;
    string result;
    result = zip(s,1);

    int min = result.size();//min값을 초기화 해주기 위해 루프 바깥에서 n=1인 경우를 시행
    
    for(int i=2;i<=s.size()/2;i++){//  s의 길이/2 보다 큰 갯수로 문자열을 자르는 것은 의미가 없기 때문에
        result = zip(s,i);

        if(min>result.size())
        {
            min = result.size();//최솟값을 업데이트해준다.
        };
    }
    answer = min;
    return answer;
}
