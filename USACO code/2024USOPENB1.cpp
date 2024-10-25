#include <bits/stdc++.h>

using namespace std;


struct Point {
    int x, y;
};

int distance(Point p1, Point p2) {
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}

int cow_distance(Point start, Point end, vector<Point>& posts) {
    int min_distance = INT_MAX;
    for (const auto& post : posts) {
        int d1 = distance(start, post);
        int d2 = distance(end, post);
        int total_distance = d1 + d2;
        min_distance = min(min_distance, total_distance);
    }
    return min_distance;
}

int main() {
    int N, P;
    cin >> N >> P;

    vector<Point> posts(P);
    for (int i = 0; i < P; ++i) {
        cin >> posts[i].x >> posts[i].y;
    }

    vector<Point> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].x >> cows[i].y;
        Point start = {cows[i].x, cows[i].y};
        cin >> cows[i].x >> cows[i].y;
        Point end = {cows[i].x, cows[i].y};

        cout << cow_distance(start, end, posts) << endl;
    }
    return 0;
}
