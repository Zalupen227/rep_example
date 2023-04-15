#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 1e9;

int n; // Количество вершин
int s, t; // Исток и сток
int c[100][100]; // Пропускные способности
int f[100][100]; // Потоки
int d[100]; // Расстояние до вершины

bool bfs() {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (d[v] == -1 && f[u][v] < c[u][v]) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int u, int flow) {
    if (u == t) return flow;
    for (int v = 0; v < n; v++) {
        if (d[v] == d[u] + 1 && f[u][v] < c[u][v]) {
            int new_flow = min(flow, c[u][v] - f[u][v]);
            int temp_flow = dfs(v, new_flow);
            if (temp_flow > 0) {
                f[u][v] += temp_flow;
                f[v][u] -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int find_min_flow() {
    int max_flow = 0;
    while (bfs()) {
        int flow;
        do {
            flow = dfs(s, INF);
            max_flow += flow;
        } while (flow > 0);
    }
    return max_flow;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n = 8;
    int s = 0;
    int t = 9;
    vector<vector<int>> c(n, vector<int>(n));

    c[0][1] = c[1][0] = 2;

    c[0][4] = c[4][0] = 3;

    c[1][4] = c[4][1] = 2;

    c[1][5] = c[5][1] = 2;

    c[4][5] = c[5][4] = 3;

    c[1][2] = c[2][1] = 3;

    c[5][6] = c[6][5] = 1;

    c[2][6] = c[6][2] = 2;

    c[2][3] = c[3][2] = 4;

    c[3][6] = c[6][3] = 2;

    c[3][7] = c[7][3] = 2;

    c[7][6] = c[6][7] = 3;
    int min_flow = find_min_flow();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] > 0 && f[i][j] > 0) {
                cout << "Ребро " << i << " -> " << j << ": " << f[i][j] << endl;
            }
        }
    }
    return 0;
}
