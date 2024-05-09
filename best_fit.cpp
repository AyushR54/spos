#include <iostream>
using namespace std;

void best_fit(int blocksize[], int m, int processsize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int min = 0, final, best = 9999, j = 0;
        while (j < m)
        {
            min = blocksize[j] - processsize[i];
            if (min < best && min > 0)
            {
                best = min;
                allocation[i] = j;
            }
            j++;
        }
        blocksize[allocation[i]] = blocksize[allocation[i]] - processsize[i];
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
    int blocksize[] = {100, 500, 200, 300, 600};
    int processsize[] = {212, 417, 112, 426};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processsize) / sizeof(processsize[0]);
    best_fit(blocksize, m, processsize, n);
}