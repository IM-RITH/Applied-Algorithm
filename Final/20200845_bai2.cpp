#include <bits/stdc++.h>
using namespace std;

const int infi = 1e9;

int graph[31][31];
bool inR[31];
bool visited[31];
int dist[31];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int k;
    cin >> k;

    // Đánh dấu các nút thuộc tập R
    for (int i = 0; i < k; ++i) {
        int node;
        cin >> node;
        inR[node] = true;
    }

    // Tìm nút đầu tiên để tạo cây khung
    int startNode = 1;
    while (!inR[startNode]) ++startNode;

    // Khởi tạo các giá trị ban đầu
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; ++i) dist[i] = infi;
    dist[startNode] = 0;

    // Duyệt cây để tìm các nút trong tập R
    int current = startNode, sum = 0, cnt = 1;
    while (cnt < k) {
        visited[current] = true;
        for (int i = 1; i <= n; ++i) { 
            if (graph[current][i] > 0 && !visited[i] && (inR[i] || cnt == k)) {
                dist[i] = min(dist[i], graph[current][i]);
            }
        }

        // Tìm nút tiếp theo có chi phí thấp nhất để kết nối tới cây
        int nextNode;
        int minDist = infi;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                nextNode = i;
            }
        }

        // them nut tiep theo vao cay khung
        sum += minDist;
        current = nextNode;
        dist[current] = 0;
        cnt++;
    }

    cout << sum << endl;

    return 0;
}
