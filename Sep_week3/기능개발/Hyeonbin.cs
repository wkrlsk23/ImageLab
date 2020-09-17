using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(int[] progresses, int[] speeds)
    {
        List<int> list = new List<int>();
        int index = 0;
        int finish;
        int i;

        while (index < progresses.Length)
        {
            finish = 0;

            for (i = 0; i < progresses.Length; i++)
            {
                progresses[i] += speeds[i];
            }

            for (i = index; i < progresses.Length; i++)
            {
                if (progresses[i] < 100)
                    break;

                if (progresses[i] >= 100)
                {
                    index++;
                    finish++;
                }
            }

            if (finish != 0)
            {
                list.Add(finish);
            }
        }

        int[] answer = list.ToArray();
        return answer;
    }
}