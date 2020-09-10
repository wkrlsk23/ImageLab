using System;

namespace ConsoleApp1
{
    public class Solution
    {
        public int[] solution(int[] prices)
        {
            int[] answer = new int[prices.Length];
            int fall;

            for (int i = 0; i < prices.Length - 1; i++)
            {
                fall = 0;

                for (int j = i + 1; j < prices.Length; j++)
                {
                    fall++;
                    if (prices[i] > prices[j])
                    {
                        break;
                    }

                }
                answer[i] = fall;
            }

            return answer;
        }
    }
}
