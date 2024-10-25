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
		int n;
	cin >> n;
	string org;
	cin >> org;
	vector <int> arr;
	int temp = 0;
	int temp_ans= 0;
	for(int i = 0; i <= n; ++i)
	{
		if(org[i] == '1')
		{
			temp +=1;
			temp_ans++;
		}
		else if (temp > 0)
		{
			arr.pb(temp);
			temp = 0;
		} else {
			arr.pb(0);
		}
	}
	vector <int> ans;
	ans.pb(temp_ans);
	for(int night = 1; night < n; ++night)
	{
		ans.pb(arr[i])
	}
	return 0;
}



