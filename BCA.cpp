#include <bits/stdc++.h>
using namespace std;

int n,m;
bool teach[11][33];       //[teacher][course], teacher [0] teach course [1]
bool conflict[31][31];    //[course][teacher], 2 course [0] and [1] are conflict
bool teaching[11][31];
int load[11];

int minload = INT_MAX;    // objective

bool check(int candi_teacher, int course_id)
{
    if(!teach[candi_teacher][course_id]) return false;
    for(int i=0;i<n;i++) {
        if(teaching[candi_teacher][i] && conflict[i][course_id]) {
            return false;
        }
    }
    // prune
    if(load[candi_teacher] + 1 >= minload) return false;
    return true;
}

void add(int teacher, int course_id)
{
    teaching[teacher][course_id] = true;
    ++load[teacher];
}

void del(int teacher, int course_id)
{
    teaching[teacher][course_id] = false;
    --load[teacher];
}

void nhan()
{
    int max_load = 0;
    int i;
    for(i=0;i<n;i++)
    {
        max_load = max(max_load, load[i]);
    }
    minload = min(max_load, minload);

}

void Try(int b)
{
    //assign

    int i;
    for(i=0;i<m;i++)
    {
        if(!check(i, b)) continue;
        add(i, b);
        if(b == n-1)
        {
            nhan();
        } else
            Try(b+1);

        del(i, b);
    }
}


int main()
{
    memset(teach, 0, sizeof(teach));
    memset(load, 0, sizeof(load));
    memset(conflict, 0, sizeof(conflict));
    cin >> m >> n;
    int i;
    for(i=0;i<m;++i)
    {
        int l;
        cin >> l;
        for(int j=0;j<l;++j)
        {
            int temp;
            cin >> temp;
            teach[i][temp-1] = true;
        }
    }

    int a;
    cin >> a;

    for(i=0;i<a;++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        conflict[temp1 - 1][temp2 - 1] = true;
        conflict[temp2 - 1][temp1 - 1] = true; 
    }

    Try(0);
    cout << minload;
}