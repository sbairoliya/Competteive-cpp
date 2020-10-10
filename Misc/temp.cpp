// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>

using namespace std;

int max(int count, int curr);

string solution(string &forth) {
    int nCount = 0;
    int eCount = 0;
    int wCount = 0;
    int curr = 0;
    for (char a: forth) {
        if (a == 'N')
            nCount++;
        else {
            if (a == 'E') {
                curr++;
                eCount = (eCount > curr) ? eCount : curr;
            } else {
                curr--;
                wCount = (wCount < curr) ? wCount : curr;
            }
        }
    }
    wCount = abs(wCount);
    int wDist = 1 + 1 + wCount + wCount + nCount + curr;
    int eDist = 1 + 1 + eCount + eCount + nCount - curr;
    cout << eDist << endl;
    cout << wDist << endl;
    string x = "";
    if (wDist <= eDist) {
        x += "W";
        for (int i = 0; i < wCount + curr; ++i) {
            x += "W";
        }
        for (int i = 0; i < nCount; ++i) {
            x += "S";
        }
        for (int i = 0; i < wCount; ++i) {
            x += "E";
        }
        x += "E";
    } else {
        x += "E";
        for (int i = 0; i < eCount - curr; ++i) {
            x += "E";
        }
        for (int i = 0; i < nCount; ++i) {
            x += "S";
        }
        for (int i = 0; i < eCount; ++i) {
            x += "W";
        }
        x += "W";
    }
    return x;
}

int main() {
    string x = "NENENWWWWN";
    cout << solution(x) << endl;
}

