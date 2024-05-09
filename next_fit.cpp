#include <iostream>
using namespace std;

void next_fit(int blocksize[], int m, int processsize[], int n)
{
    int allocation[n], point = 0;
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = point; j < m; j++)
        {
            if (processsize[i] <= blocksize[j])
            {
                allocation[i] = j;
                blocksize[j] = blocksize[j] - processsize[i];
                point = j;
                break;
            }
        }
    }

    cout << "Process"
         << "\t"
         << "Block no." << endl;
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
        {
            cout << "p" << i << "\t" << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "p" << i << "\t"
                 << "Not allocated" << endl;
        }
    }
}

int main()
{
    int blocksize[] = {5, 10, 20};
    int processsize[] = {10, 20, 30};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processsize) / sizeof(processsize[0]);
    next_fit(blocksize, m, processsize, n);
}