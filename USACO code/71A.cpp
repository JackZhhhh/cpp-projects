#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int N;
    cin >> N;
    while(N--)
    {
        string temp;
        cin >> temp;
        if(temp.size()>10)
        {
            cout << temp[0] << temp.size()-2 << temp[temp.size()-1] << endl;
        }
        else
            cout << temp << endl;
    }
}