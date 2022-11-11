#include <bits/stdc++.h>
using namespace std;

typedef long long aa;

bool no_wrong_number = true;
map<string, aa> num_calls_from;
map<string, aa> num_time_calls_from;
aa num_total_calls;

void check(string num)
{
    if(num.size() != 10)
    {
        no_wrong_number = false;
    } else {
        for(int i=0;i<10;i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                no_wrong_number = false;
            }
        }
    
    }
}

aa total_time(string from_time, string to_time)
{
    aa from_hour, from_minute, from_second, to_hour, to_minute, to_second;
    from_hour = (from_time[0] - '0') * 10 + (from_time[1] - '0');
    from_hour = (from_time[3] - '0') * 10 + (from_time[4] - '0');
    from_hour = (from_time[6] - '0') * 10 + (from_time[7] - '0');
    to_hour = (to_time[0] - '0') * 10 + (to_time[1] - '0');
    to_hour = (to_time[3] - '0') * 10 + (to_time[4] - '0');
    to_hour = (to_time[6] - '0') * 10 + (to_time[7] - '0');
    return (to_hour - from_hour) * 3600 + (to_minute - from_minute) * 60 + (to_second - from_second);
}

int main()
{
    string in;
    cin >> in;
    while (in !="#")
    {
        string from_num, to_num, date, from_time, to_time;
        cin >> from_num >> to_num >> date >> from_time >> to_time;
        if(no_wrong_number)
        {
            check(from_num);
            check(to_num);
        }
        num_calls_from[from_num] += 1;
        num_time_calls_from[from_num] += total_time(from_time, to_time);
        ++num_total_calls;
        cin >> in;
    }
    cin >> in;
    while (in !="#")
    {
       if (in == "?check_phone_number") {
        cout << int(no_wrong_number) << endl;
       } else if (in == "?number_calls_from") {
        string num;
        cin >> num;
        cout << num_calls_from[num] << endl;
       } else if (in == "?number_total_calls") {
        cout << num_total_calls << endl;
       } else if (in == "?count_time_calls_from") {
        string num;
        cin >> num;
        cout << num_time_calls_from[num] << endl;
       }
       cin >> in;
    }
    
}