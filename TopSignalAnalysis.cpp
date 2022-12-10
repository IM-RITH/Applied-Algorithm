#include <bits/stdc++.h>
using namespace std;

// thi thu


#define f first
#define s second

typedef long long aa;
typedef pair<int, int> pp;

const int a = 1000000;
int b[a];

int main() {
    int n;
    cin >> n;

    int c = 0;
    int i;
    for( i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(i = 1;i < n-1; i++)
    {
        if(b[i] > b[i+1] && b[i] > b[i-1]) ++c;
    }

    cout << c;
}