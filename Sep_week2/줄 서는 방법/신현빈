using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] prices = new int[] { 1, 2, 3, 2, 3 };
            int[] buffer;
            Solution sol = new Solution();
            buffer = sol.solution(prices);
            
            foreach(int num in buffer)
                Console.WriteLine(num);
        }
    }

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
