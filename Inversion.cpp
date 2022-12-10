#include <bits/stdc++.h>
using namespace std;

// it's still partial.. chua xong 
int n, a[100000], result = 0;
const int mo = 1e9 + 7;
int tem[100000];

void merge_s(int a[], int b, int c) {
    if(b >= c - 1) return;
    int middle = (b + c)/2;
    merge_s(a, b, middle);
    merge_s(a, middle, c);
    for(int i = b, li = b, ri = middle; i < c; ) {
         if(li >= middle) {
            tem[i++] = a[ri++];
         } else if(ri >= c) {
            tem[i++] = a[li++];
         } else if(a[li] <= a[ri]) {
            tem[i++] = a[li++];
         } else {
            tem[i++] = a[ri++];
            result = (result + (middle - li)) % mo;
         }

    }
    for(int i = b; i < c; ++i) a[i] = tem[i];

}

int main()
{
    cin >> n;
    for( int i = 0; i<n; ++i) cin >> a[i];
    merge_s(a, 0, n);
    cout << result;
    return 0;

}
