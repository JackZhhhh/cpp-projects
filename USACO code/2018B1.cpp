#include <bits/stdc++.h>

using namespace std;

int main ()
{
    freopen("mixmilk.in", "r", stdin);
    vector <int> capacities(3);
    vector <int> current (3);
    for (int i = 0; i < 3; i++) { scanf("%d %d", &capacities[i], &current[i]); }
    for(int i = 0; i < 100; i++)
    {
        int curr_bucket = i%3;
        if(curr_bucket == 2)
        {
            if(capacities[0] > current[curr_bucket] + current[0])
            {
                current[0] += current[curr_bucket];
                current[curr_bucket] = 0;
            }
            else
            {
                int flown = capacities[0] - current[0];
                current[0] = capacities[0];
                current[curr_bucket] = current[curr_bucket] - flown;
            }
        }
        if(curr_bucket == 1)
        {
            if(capacities[2] > current[curr_bucket] + current[2])
            {
                current[2] += current[curr_bucket];
                current[curr_bucket] = 0;
            }
            else
            {
                int flown = capacities[2] - current[2];
                current[2] = capacities[2];
                current[curr_bucket] = current[curr_bucket] - flown;
            }
        }
        if(curr_bucket == 0)
        {
            if(capacities[1] > current[curr_bucket] + current[1])
            {
                current[1] += current[curr_bucket];
                current[curr_bucket] = 0;
            }
            else
            {
                int flown = capacities[1] - current[1];
                current[1] = capacities[1];
                current[curr_bucket] = current[curr_bucket] - flown;
            }
        }
    }
    freopen("mixmilk.out", "w", stdout);
    for(int i = 0; i < 3; i ++)
    {
        cout << current[i] << endl;
    }
    return 0;
}