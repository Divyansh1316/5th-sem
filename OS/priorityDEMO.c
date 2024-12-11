#include <stdio.h>
#include <string.h>
int main()
{
    char pn[10][10], t[10];
    int priority[10], arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, j, n, temp;
    int totwt = 0, tottat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Process ID, Arrival Time & Burst Time & Priority : ");
        scanf("%s%d%d%d", &pn[i], &arr[i], &bur[i], &priority[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (priority[i] < priority[j] && arr[i] < arr[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = bur[i];
                bur[i] = bur[j];
                bur[j] = temp;

                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            star[i] = arr[i];
        else
            star[i] = finish[i - 1];
        wt[i] = star[i] - arr[i];
        finish[i] = star[i] + bur[i];
        tat[i] = finish[i] - arr[i];
    }
    printf("\nPID \tArrival time\tBurst time\tPriority\tWait time\tStart \tTAT \tFinish");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pn[i], arr[i], bur[i], priority[i], wt[i], star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\nAverage Waiting time:%f", (float)totwt / n);
    printf("\nAverage Turn Around Time:%f", (float)tottat / n);
    return 0;
}