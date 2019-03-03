#include <bits/stdc++.h>
using namespace std;
const int kilobits_per_megabyte = 8000;
double video_size(int bit_rate,double video_duration) {
    return video_duration * 60 * bit_rate / kilobits_per_megabyte;
}
int main() {
    double video_duration,bit_rate;  //in minutes
    cout << "Please input the Bit rate" << endl;
    cin>>bit_rate;
    cout << "Please input the video duration in minurtes" << endl;
    cin >> video_duration;
    cout << video_size(bit_rate,video_duration) << " megabytes." << endl;
}