#include<bits/stdc++.h>
using namespace std;

struct meeting {
    int pos;   // original index
    int start;
    int end;
};

// Custom comparator to sort meetings by end time, then by position
bool comparator(meeting a, meeting b) {
    if (a.end < b.end) return true;
    else if (a.end > b.end) return false;
    else if (a.pos < b.pos) return true;
    return false;
}

vector<int> maxMeeting(int s[], int e[], int n) {
    meeting meet[n];
    for(int i = 0; i < n; i++) {
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i + 1;  // position is 1-based
    }

    sort(meet, meet + n, comparator);

    vector<int> result;       // stores selected meeting positions
    int endLimit = meet[0].end;
    result.push_back(meet[0].pos);  // first meeting always selected

    for(int i = 1; i < n; i++) {
        if(meet[i].start > endLimit) {
            result.push_back(meet[i].pos);
            endLimit = meet[i].end;
        }
    }
    return result;
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);

    vector<int> selected = maxMeeting(s, e, n);

    cout << "Maximum number of meetings: " << selected.size() << endl;
    cout << "Meetings selected (by original position): ";
    for(int i : selected)
        cout << i << " ";
    cout << endl;

    return 0;
}
