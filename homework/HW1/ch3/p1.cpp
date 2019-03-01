#include <bits/stdc++.h>
using namespace std;
const int kilobits_per_megabyte = 8000;
int main() {
    double video_duration;  //in minutes
    cout << "Please input the video duration in minurtes" << endl;
    cin >> video_duration;
    cout << video_duration * 60 * 1000 / kilobits_per_megabyte << endl;
}