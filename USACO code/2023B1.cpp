#include <bits/stdc++.h>

//defining before
using ll = long long;

//set barriers
#define pb push_back
#define f first
#define s second
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	vector <int> cowHeight;
	int temp;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		cowHeight.pb(temp);
	}
	vector<pair<int, int>> candyHeight(m);
    for (int i = 0; i < m; ++i) 
	{
		candyHeight[i].first = 0;
        cin >> candyHeight[i].second;
    }
	int maxHeight = *max(cowHeight.begin(), cowHeight.end());
	for(int i = 0; i < m; ++i)
	{
		int currCow = 0;
		bool isNotEaten = true;
		while(isNotEaten)
		{
			if(currCow == n)
			{
				currCow = 0;
			}
			cout << "candy height: " << candyHeight[i].second << " cow height: " << cowHeight[currCow] << endl;
			if(candyHeight[i].second >= cowHeight[currCow] && candyHeight [i].first < cowHeight[currCow])
			{
				cout << "candy height is bigger" << endl;
				int temp = candyHeight[i].first;
				candyHeight[i].first = cowHeight[currCow];
				cowHeight[currCow] += (cowHeight[currCow] - temp);
				cout << "minimal candy height: " << candyHeight[i].first << " cow height: " << cowHeight[currCow] << endl;
			}
			else if (cowHeight[currCow] < candyHeight[i].first) {cout << "cow cant reach candy" << endl;
			}
			else if (candyHeight[i].first < cowHeight[currCow])
			{
				cout << "candy height is smaller" << endl;
				cowHeight[currCow] +=candyHeight[i].second;	
			}
			if(candyHeight[i].first >= maxHeight)
			{
				cout << "candy base has passsed heights of all cows" << endl;
				isNotEaten = false;	
			}	
			currCow++;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << cowHeight[i] << endl;
	}
	return 0;
}



