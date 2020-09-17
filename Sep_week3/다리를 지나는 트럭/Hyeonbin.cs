using System;

public class Solution
{
    public int solution(int bridge_length, int weight, int[] truck_weights)
    {
        int answer = 0;
        int sum_weight = 0;
        int next = 0;
        int[] progress = new int[truck_weights.Length];
        int[] index = new int[truck_weights.Length];

        for (int i = 0; i < truck_weights.Length; i++)
        {
            index[i] = 2;
            progress[i] = bridge_length + 1;
        }

        while (true)
        {
            for (int i = 0; i < progress.Length; i++)
            {
                if (index[i] == 1)
                {
                    progress[i]--;
                }

                if (progress[i] == 0)
                {
                    index[i] = 0;
                    sum_weight -= truck_weights[i];
                }
            }

            if ((next < truck_weights.Length) && ((sum_weight + truck_weights[next]) <= weight))
            {
                sum_weight += truck_weights[next];
                index[next] = 1;
                next++;
            }

            if (progress[progress.Length - 1] == 0)
                break;

            answer++;
        }

        return answer;
    }
}