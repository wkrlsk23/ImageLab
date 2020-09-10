#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long k) {
    k--;
    vector<int> temp;
    vector<int>::iterator it=temp.begin();
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
    it = temp.begin();
   
  /*  cout << "배열";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }
    cout << endl;
    cout << "n : " << n << " divider : " << Divider << " POSITIONER : " << Positioner << endl;*/
    while (true)
    {
        
        n--;
       
        Positioner = k / Divider;
       

        k = k % Divider;
      

        Divider = Divider / n;
        
       
      
       
      //  cout << "n : "<<n<<" divider : "<<Divider<<" POSITIONER : "<< Positioner<< endl;


        answer.push_back(temp[Positioner]);

        //배열 삭제
        if (Positioner == 0)
        {
           // cout << "첫번째 삭제" << endl;
            
            it = temp.erase(temp.begin());

          /*  for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i];
            }
            cout << endl;*/
        }
        else
        {
           // cout << Positioner << "삭제" << endl;
            
             temp.erase(temp.begin() + Positioner );
           /* for (int i = 0; i < temp.size(); i++)
            {
                cout << temp.at(i);
            }
            cout << endl;*/
        }
        
        if (n == 1)
        {
           
            answer.push_back(temp.at(0));
            break;
        }
      
    }

 /*   for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
   }*/

  
    return answer;
}
