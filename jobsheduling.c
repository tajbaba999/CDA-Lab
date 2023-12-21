#include <stdio.h>

struct Job
{
    int id;
    int profit;
    int deadline;
};

void scheduleJobs(struct jobs[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Job[j].deadline < Job[j + 1].deadline)
            {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    int result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (result[j] == -1)
            {
                result[j] = i;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            printf("%d ", jobs[result[i]].id);
        }
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter the pofit and deadline of each job :\n");
    for (int i = 0; i < n; i++)
    {
        Job[i].id = i + 1;
        printf("Job - %d", i + 1);
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
    }
    scheduleJobs(jobs, n)
}
