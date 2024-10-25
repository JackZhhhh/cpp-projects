#include <iostream>
#include <vector>
#include <algorithm>

void reconstructPermutation(int N, std::vector<int>& hints) {
    std::vector<int> permutation(N);
    std::vector<bool> used(N, false);

    permutation[0] = 1;
    used[0] = true;

    for (int i = 1; i < N; i++) {
        if (hints[i - 1] == 1) {
            int j = i - 1;
            while (permutation[j] != 0) {
                j--;
            }
            permutation[j] = i + 1;
            used[i] = true;
        } else {
            int j = N - 1;
            while (permutation[j] != 0) {
                j--;
            }
            permutation[j] = i + 1;
            used[i] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            std::cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << permutation[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> hints(N - 1);
        for (int i = 0; i < N - 1; i++) {
            std::cin >> hints[i];
        }

        reconstructPermutation(N, hints);
    }

    return 0;
}