/*
Implement a problem of minimum work to be done 
per day to finish given tasks within D days problem. 
Statement: Given an array task[] of size N denoting 
amount of work to be done for each task, the problem 
is to find the minimum amount of work to be done on 
each day so that all the tasks can be completed in at 
most D days. Note: On one day work can be done for 
only one task. 
Input: task[] = [3, 4, 7, 15],  D = 10                     
Output: 4 
Input: task[] = [30, 20, 22, 4, 21], D = 6              
Output: 22
*/
#include <iostream>

using namespace std;

int calculateWork(int task[], int low, int N)
{
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp += (task[i] + low - 1) / low;
    }
    return temp;
}

int main()
{

    int N, task[10], days, low = 1;
    cout << "Enter size : ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i << "th work :";
        cin >> task[i];
    }
    cout << "enter max number of days: ";
    cin >> days;

    while (true)
    {
        int work = calculateWork(task, low, N);
        if (work <= days)
        {
            cout << "Minimum work to be done per day: " << low << endl;
            break;
        }
        low++;
    }

    return 0;
}