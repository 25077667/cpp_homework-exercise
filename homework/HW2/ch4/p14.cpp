#include <bits/stdc++.h>
using namespace std;
void convert_time(string start_time, string end_time, int& start, int& ending) {
    stringstream ss;
    ss.str("");
    ss.clear();
    ss << start_time;
    ss >> start;
    ss.str("");
    ss.clear();
    ss << end_time;
    ss >> ending;
}
int main() {
    string start_time, end_time;
    while (cout << "input start time && end time(**** ****)" && cin >> start_time >> end_time) {
        if (start_time.length() != 4 || end_time.length() != 4) {
            cout << "input error" << endl;
            continue;
        }
        int start, ending;
        convert_time(start_time, end_time, start, ending);
        cout << start_time << " " << end_time << " " << start << " " << ending << endl;
        struct tm t1 = {0};
        struct tm t2 = {0};
        t1.tm_hour = start / 100;
        t1.tm_min = start % 100;
        t2.tm_hour = ending / 100;
        t2.tm_min = ending % 100;
        int result = (difftime(mktime(&t2), mktime(&t1))) / 60;
        cout << "it is " << ((result > 0) ? result : result + 1440) << " minutes" << endl;
    }
}