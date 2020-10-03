/*
 * Developed By : Shivam Bairoliya
 */

#define ONLINE_JUDGE

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
void solve(ll caseNumber) {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll diff = (a - c) + (b - c);
    if (diff > (n - c)) {
        cout << "Case #" << caseNumber << ": IMPOSSIBLE" << endl;
        return;
    }
    if (n == 1) {
        cout << "Case #" << caseNumber << ": 1" << endl;
        return;
    }
    if (n == 2) {
        if (a == b) {
            cout << "Case #" << caseNumber << ": 2 2" << endl;
        } else if (a > b) {
            cout << "Case #" << caseNumber << ": 1 2" << endl;
        } else {
            cout << "Case #" << caseNumber << ": 2 1" << endl;
        }
        return;
    }
    ll suppress = n - c - diff;
    cout << "Case #" << caseNumber << ": ";
    a -= c;
    b -= c;
    if (a == 0 && b == 0) {
        cout << n << " ";
        for (int i = 0; i < suppress; ++i) {
            cout << 1 << " ";
        }
        for (int i = 1; i < c; ++i) {
            cout << n << " ";
        }
        cout<<endl;
        return;
    }
    if (a >= b) {
        cout << 2 << " ";
        for (int i = 0; i < suppress; ++i) {
            cout << 1 << " ";
        }
        for (int i = 1; i < a; ++i) {
            cout << 2 << " ";
        }
        for (int i = 0; i < c; ++i) {
            cout << n << " ";
        }
        for (int i = 0; i < b; ++i) {
            cout << 2 << " ";
        }
        cout << endl;
        return;
    } else  {
        for (int i = 0; i < a; ++i) {
            cout << 2 << " ";
        }
        for (int i = 0; i < c; ++i) {
            cout << n << " ";
        }
        for (int i = 0; i < suppress; ++i) {
            cout << 1 << " ";
        }
        cout << 2 << " ";
        for (int i = 1; i < b; ++i) {
            cout << 2 << " ";
        }
        cout << endl;
    }
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
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}