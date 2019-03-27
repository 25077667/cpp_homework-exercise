#include <bits/stdc++.h>
using namespace std;
int main() {
    int start, ending;
    string start_time, end_time;
    while (cout << "input start time && end time(**** ****)" && cin >> start_time >> end_time) {
        start = ((start_time[0] - '0') * 10 + (start_time[1] - '0')) * 60 + (start_time[2] - '0') * 10 + (start_time[3] - '0');
        ending = ((end_time[0] - '0') * 10 + (end_time[1] - '0')) * 60 + (end_time[2] - '0') * 10 + (end_time[3] - '0');
        if (start_time.length() != 4 || end_time.length() != 4 || start > 1440 || ending > 1440 || (start_time[0] - '0') * 10 + (start_time[1] - '0') > 24 || (end_time[0] - '0') * 10 + (end_time[1] - '0') > 24 || (start_time[2] - '0') * 10 + (start_time[3] - '0') > 59 || (end_time[2] - '0') * 10 + (end_time[3] - '0') > 59) {
            cout << "input error" << endl;
            continue;
        }
        struct tm t1 = {0}, t2 = {0};
        t1.tm_min = start;
        t2.tm_min = ending;
        int result = (difftime(mktime(&t2), mktime(&t1))) / 60;
        cout << "it is " << ((result > 0) ? result : result + 1440) << " minutes" << endl;
    }
}