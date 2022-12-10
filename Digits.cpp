#include <bits/stdc++.h>
using namespace std;

// thi thu


typedef long long aa;
typedef pair<int, int> pp;

#define f first
#define s second

int n, a[7], answer(0);

bool check_a() {
    int v = a[0] * 100 + a[1] * 10 + a[2] - 62 - a[3] * 100 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[2];
    if (v == n) return true;
    return false;
}

bool check_b(int b, int v) {
    for (int i = 0; i < b; ++i) {
        if (a[i] == v) return false;
    }
    return true;
}

void Try(int b) {
    for (int i = 1; i <= 9; ++i) {
        if (!check_b(b, i)) continue;
        a[b] = i;
        if (b == 6) {
            if (check_a()) ++answer;
        } else 
            Try(b + 1);
    }
}

int main() {
    cin >> n;
    Try(0);
    cout << answer;
}