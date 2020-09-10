#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k);

int main()
{
    vector<int> vec = solution(3, 5);

    vector<int>::iterator iter = vec.begin();

    for (iter = vec.begin(); iter != vec.end(); iter++) 
    {
        cout << *iter << endl;
    }


}

vector<int> solution(int n, long long k)
{
	vector<int> answer;
	// 자리수 벡터
	vector<int> number;
	//int* arr = new int[n];

	long long fac = 1;
	int value;

	// 자릿수 배열에 숫자 대입
	for (int i = 1; i <= n; i++)
	{
		number.push_back(i);
		fac *= i;
	}

	while (n > 0)
	{
		fac /= n;

		if (k == 0)
		{
			//value = n - 1;
			for (vector<int>::reverse_iterator iter = number.rbegin(); iter != number.rend(); iter++)
			{
				answer.push_back(*iter);
			}
			break;
		}
		else
		{
			value = (k - 1) / fac;
		}

		answer.push_back(number[value]);

		number.erase(number.begin() + value);

		k %= fac;
		n--;
	}


	return answer;
}
