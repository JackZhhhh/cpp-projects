#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long min_applications(int N, vector<long long>& bacteria_levels) {
    long long total_applications = 0;

    for (int i = 0; i < N - 1; ++i) {
        long long required_change = abs(bacteria_levels[i]);
        total_applications += required_change;
        bacteria_levels[i + 1] += bacteria_levels[i]; // Propagate the change to the next patch
    }

    total_applications += abs(bacteria_levels[N - 1]); // Last patch

    return total_applications;
}

int main() {
    int N;
    cin >> N;

    vector<long long> bacteria_levels(N);
    for (int i = 0; i < N; ++i) {
        cin >> bacteria_levels[i];
    }

    cout << min_applications(N, bacteria_levels) << endl;

    return 0;
}

