#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> possible_hay_types(int N, vector<int>& preferences) {
    unordered_map<int, int> count;
    vector<int> possible_types;
    for (int i : preferences) {
        count[i]++;
    }
	double threshold = N/2.0;
    for (auto& p : count) {
        if (p.second > threshold) {
            possible_types.push_back(p.first);
        }
        else if (p.second == threshold  && N > 2) {
        	possible_types.push_back(p.first);
		}
    }

    if (possible_types.size() == 0) {
        return vector<int>{-1}; 
    }

    sort(possible_types.begin(), possible_types.end());
    return possible_types;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> preferences(N);
        for (int i = 0; i < N; ++i) {
            cin >> preferences[i];
        }

        vector<int> result = possible_hay_types(N, preferences);
        if(result.size() == 1)
        {
        	cout << result[0] << endl;
		}
		else
		{
			for (int i = 0; i < result.size(); ++i) 
			{
            	if(i == result.size()-1)
            	{
            		cout << result[i] << endl;
				}
				else
				{
					cout << result[i] << " ";
				}
        	}	
		}
    }

    return 0;
}

