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
	vector <ll> list;
	for(int i = 0; i < n; ++i)
	{
		ll temp;
		cin >> temp;
		list.pb(temp);
	}
	sort(list.begin(), list.end());
	ll ans = 0;
	ll tution = 0;
	int cowsAttending = n;
	for(int i =0; i < n; i++)
	{
		ll temp_total = cowsAttending * list[i];
		if(temp_total > ans) 
		{
			tution = list[i];
			ans = temp_total;
		}
		cowsAttending--;
	}
	cout << ans << " "<<tution<<endl;
	return 0;
}



