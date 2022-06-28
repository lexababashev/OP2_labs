#include "ASeries.h"
#include "GSeries.h"

#include <iostream>
using namespace std;

int main()
{
    srand(time(nullptr));
    long int n, m;
    do
    {
    cout << "Enter POSITIVE n and m " << endl; cin >> n; cin >> m; cout << endl;
    } while (m<=0||n<=0);

    
    long int max_n = 0, max_sum = 0;

    for (int i = 0; i < n; i++)
    {
        long int firstMember = rand() % 11+1;
        long int step = rand() % 11+1;
        cout << i + 1 << ") first number is " << firstMember << " step is " << step << endl;

        if (i % 2 == 0)
        {
            GSeries gSeries(firstMember, step);
            cout << "n number is " << gSeries.FindNElement(n) << " sum is " << gSeries.Sum(m) << endl << endl;
            if (gSeries.FindNElement(n) > max_n)
            {
                max_n = gSeries.FindNElement(n);
                max_sum = gSeries.Sum(m);
            }
        }
        else
        {
            ASeries aSeries(firstMember, step);
            cout << "n number is " << aSeries.FindNElement(n) << " sum is " << aSeries.Sum(m) << endl << endl;
            if (aSeries.FindNElement(n) > max_n)
            {
                max_n = aSeries.FindNElement(n);
                max_sum = aSeries.Sum(m);
            }
        }
    }
    cout <<endl << "max n number is " << max_n << " with sum of first m numbers  " << max_sum << endl;

}


