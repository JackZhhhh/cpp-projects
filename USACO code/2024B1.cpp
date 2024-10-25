#include <bits/stdc++.h>

//defining before
using ll = long long;

//set barriers
#define pb push_back
#define f first
#define s second
using namespace std;

int count_broken_targets(int N, int S, map<int, pair<int, int>>& locations) {
    int targets_broken = 0;
    vector<bool> visited(N+1, false);
    int power = 1;
    int direction = 1;
    int current_pos = S;
    int run_times = 0;
    while (current_pos >= 1 && current_pos <= N)
	{
		if(run_times > N)
		{
			break;
		}
		run_times++;
		if (locations[current_pos].first == 1 && power >= locations[current_pos].second && (visited[current_pos] == false)) 
		{
            targets_broken++;
    	}
        if (locations[current_pos].first == 0) 
		{
            direction *= -1;
            power += locations[current_pos].second;
        } 
        visited[current_pos] = true;
        current_pos += direction * power;
	}
	return targets_broken;
}
    
int main()
{
	int N, S;
    cin >> N >> S;
    map<int, pair<int, int>> locations;
    for (int i = 1; i <= N; ++i) {
        int q, v;
        cin >> q >> v;
        locations[i] = make_pair(q, v);
    }
    cout << count_broken_targets(N, S, locations) << endl;
	return 0;
}



