/*
 * Developed By : Shivam Bairoliya
 */

#include <iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<chrono>


using namespace std;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define vi vector<int>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vi safe;

void define() {
    for (int i = 1; i <= 9; ++i) {
        safe.push_back(i);
    }
    for (int i = 10; i <= 99; ++i) {
        bool possible = true;
        int first = i / 10;
        int second = i % 10;
        if (second == 0) {
            if (first == 3 || first == 6 || first == 9)
                possible = false;
        } else if (first > second) {
            possible = false;
        } else {
            int firstMod = (first % 3) ? first % 3 : 3;
            int secondMod = (second % 3) ? second % 3 : 3;
            if (firstMod > secondMod) {
                possible = false;
            }
        }
        if (possible) {
            safe.push_back(i);
        }
    }
    safe.push_back(100);
    for (int i = 110; i <= 180; ++i) {
        int firstTwo = i / 10;
        if (find(safe.begin(), safe.end(), firstTwo) == safe.end()) {
            continue;
        }
        bool possible = true;
        int second = i % 10;
        int first = firstTwo % 10;
        if (second == 0) {
            if (first == 3 || first == 6 || first == 9)
                possible = false;
        } else if (first > second) {
            possible = false;
        } else {
            int firstMod = (first % 3) ? first % 3 : 3;
            int secondMod = (second % 3) ? second % 3 : 3;
            if (firstMod > secondMod) {
                possible = false;
            }
        }
        if (possible) {
            safe.push_back(i);
        }
    }
}

void solve() {
    int t;
    cin >> t;
    if (t > 176 || t < 10) {
        cout << t << endl;
        return;
    }
    int out = -1;
    for (int i = 1; i < safe.size(); ++i) {
        if (safe[i] > t) {
            if (t - safe[i - 1] < safe[i] - t) {
                out = safe[i - 1];
            } else {
                out = safe[i];
            }
            break;
        }
    }
    cout << out << endl;
}

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    define();
    while (t--) {
        solve();
    }
}