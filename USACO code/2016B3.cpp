#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ofstream cout ("cowsignal.out");
    ifstream cin ("cowsignal.in");
    int m, n, k;
    cin >> m >> n >> k;
    char a[10][10];
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    string output = "";
    for(int i = 0; i < m; ++i)
    {
        output  = "";
        for(int j = 0; j < n; ++j)
        {
            for(int z = 0; z < k; ++z)
            {
                cout << a[i][j];
                output += a[i][j];
            }
        }
        cout << endl;
        for(int z = 1;  z < k; ++z)
        {
            cout << output << endl;
        }
    }
    return 0;
}