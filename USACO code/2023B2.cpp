#include <bits/stdc++.h>
#include <limits>
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
	for(int i = 0; i <= n; ++i)
	{
		if(org[i] == '1')
		{
			temp +=1;
		}
		else if (temp > 0)
		{
			arr.pb(temp);
			temp = 0;
		} else {
			arr.pb(0);
		}
	}

	int nights = std::numeric_limits<int>::max();
	for (unsigned i = 0; i < arr.size(); ++i) {
		if (i == 0 && arr[i] != 0) {
			nights = min((1 + 2 * (arr[i] - 1) - 1) / 2, nights);
		} else if (i == arr.size() - 1 && arr[arr.size() - 1] != 0) {
			nights = min((1 + 2 * (arr[arr.size() - 1] - 1) - 1) / 2, nights);
		} else if (arr[i] != 0){
			nights = min((arr[i] - 1) / 2, nights); 
		}
	}
	std::cout << nights << std::endl;
	int ans = 0;
	for(int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == 0) {
			continue;
		}
		ans += arr[i] - 2 * nights;
	}
	cout << ans << endl;
	return 0;
}



