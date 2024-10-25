#include <bits/stdc++.h>

using namespace std;

void shiftArrayDown(int arr[], int size) {
    // Store the last element
    int last = arr[size - 1];
    
    // Shift elements down
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Put the last element at the first position
    arr[0] = last;
}

int main()
{
    freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
    int ans = 1e9;
    int n; cin >> n;
    int arr[n];
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        int score = 0;
        for(int j =0; j< n; j++)
        {
            score += arr[j] * j;
        }
        ans = min(score, ans);
        shiftArrayDown(arr, n);
    }
    cout << ans << endl;
    return 0;
}