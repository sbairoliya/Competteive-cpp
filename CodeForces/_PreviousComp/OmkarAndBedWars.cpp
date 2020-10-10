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
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;


#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3) {
        cout << 0 << endl;
        return;
    }
    int count = 0;
    if (n == 5) {
        s.compare("LLLLL")
    }
    if (n < 5) {
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[s.length() - 1] == s[s.length() - 2] && s[s.length() - 1] == s[0]) {
                if (s[n - 1] == 'R') {
                    s[n - 1] = 'L';
                } else {
                    s[n - 1] = 'R';
                }
                count++;
            }
            if (s[0] == s[1] && s[n - 1] == s[0]) {
                count++;
            }
            cout << count << endl;
            return;
        }
    }
    for (int i = 2; i < s.length() - 3; ++i) {
        if (s[i] == s[i - 1] && s[i + 1] == s[i] && s[i] == s[i - 2] && s[i] == s[i + 2]) {
            count++;
            if (s[i] == 'R') {
                s[i] = 'L';
            } else {
                s[i] = 'R';
            }
        } else if (s[i] == s[i - 1] && s[i + 1] == s[i]) {
            count++;
            if (s[i] == 'R') {
                s[i] = 'L';
            } else {
                s[i] = 'R';
            }
        }
    }
    if (s[s.length() - 1] == s[s.length() - 2] && s[s.length() - 1] == s[0]) {
        if (s[n - 1] == 'R') {
            s[n - 1] = 'L';
        } else {
            s[n - 1] = 'R';
        }
        count++;
    }
    if (s[0] == s[1] && s[n - 1] == s[0]) {
        count++;
    }
    cout << count << endl;
}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in", "w", stderr);
    auto start = high_resolution_clock::now();
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}