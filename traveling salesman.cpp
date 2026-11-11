
#include <iostream>
using namespace std;

#define INF 99999

int n;
int cost[10][10];
int visited[10];
int minCost = INF;

void tsp(int city, int count, int totalCost) {

    if (count == n) {
        if (cost[city][0] != INF) {
            int finalCost = totalCost + cost[city][0];

            if (finalCost < minCost) {
                minCost = finalCost;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {

        if (!visited[i] && cost[city][i] != INF) {

            visited[i] = 1;

            tsp(i, count + 1, totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
        visited[i] = 0;
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    if (minCost == INF)
        cout << "No possible tour exists.";
    else
        cout << "Minimum travelling cost: " << minCost;

    return 0;
}
