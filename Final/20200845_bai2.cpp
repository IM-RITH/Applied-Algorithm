// Một mạng truyền thông G bao gồm N máy chủ 1,2,...,N được kết nối với nhau bơi M đường truyền ( 2 chiều ). Giữa 2 máy chủ i và j có thể có đường truyền hoặc không có. trong trường hợp giữa 2 máy chủ i và j có đường truyền thì c(i,j) là chi phí thuê đường truyền này.
// Một công ty cần tính toán phương án thuê 1 số đường truyền nào đó của mạng G để kết nối liên thông một số máy chủ trong tập R(R là tập con của {1, 2,..., N}). Hãy tính toán phương án thuê đường truyền với tổng chi phí thuê là ít nhất. 
// Input
// dòng 1: ghi 2 số nguyên dương N và M(1<=N, M<=30).
// dòng 2 đến M: mỗi dòng ghi 3 số nguyên dương i,j,w: có đường truyền giữa i và j với chi phí thuê là w(w=c(i,j)).
// dòng M+2: ghi số nguyên dương K.
// dòng M+3: ghi k số nguyên dương đôi một khác nhau là chỉ số của các máy chủ trong R.
// Output
// ghi ra tổng chi phí thuê nhỏ nhất tìm được. Dùng c++ để viết bài này.
// Dùng c++ để giải bài này.
// test 

// input
// 6 10
// 1 2 1
// 1 3 2
// 1 5 5
// 2 4 7
// 2 5 6
// 3 4 30
// 3 5 4
// 4 5 8
// 4 6 3
// 5 6 7
// 4
// 1 2 3 4

// output
// 10


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
