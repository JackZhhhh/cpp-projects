#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cowHeight(n);
    for(int i = 0; i < n; ++i) {
        cin >> cowHeight[i];
    }

    vector<pair<int, int>> candyHeight(m);
    for(int i = 0; i < m; ++i) {
        cin >> candyHeight[i].second;
    }

    for(int i = 0; i < m; ++i) {
        int candyMin = 0;
        int candyMax = candyHeight[i].second;

        for(int j = 0; j < n; ++j) {
            int eatenHeight = min(cowHeight[j], candyMax - candyMin);
            cowHeight[j] += eatenHeight;
            candyMin += eatenHeight;
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << cowHeight[i] << endl;
    }

    return 0;
}

