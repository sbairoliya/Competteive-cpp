/*
 * Developed By : Shivam Bairoliya
 * Created on   : 10/10/2020 at 10:35 PM
 */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define vi vector<int>
#define vl vector<long long>
#define pll pair<long long, long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read(arr, n) for(int i = 0; i < n; i++) cin>>arr[i];
#define read1(arr, n) for(int i = 1;i <= n; i++) cin>>arr[i];

/************************************* SOLUTION BELOW ***************************************/
ll n;
vl arrayT;

void operate(vl operations) {
    vl tempArray(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        tempArray[i] = arrayT[i];
    }
    ll curr = n;
    ll index = 1;
    while (!operations.empty()) {
        ll operation = operations.back();
        operations.pop_back();
        for (int i = curr - operation + 1; i <= curr; ++i) {
            arrayT[index++] = tempArray[i];
        }
        curr = curr - operation;
    }
}

void solve() {
    cin >> n;
    arrayT.resize(n + 1, 0);
    read1(arrayT, n);
    vector<vl > allOperations;
    // If even start from right
    bool right = (n % 2 == 1);
    for (int i = 1; i <= n; ++i, right = !right) {
        vl currOperate;
        if (!right) {
            for (int j = 1; j < i; ++j) {
                currOperate.push_back(1);
            }
            ll count = 1;
            for (int j = i; j < n; ++j) {
                if (arrayT[j] != i) {
                    count++;
                } else {
                    break;
                }
            }
            currOperate.push_back(count);
            if (n - count - i + 1 != 0) {
                currOperate.push_back(n - count - i + 1);
            }
            if (currOperate.size() >= 2) {
                allOperations.push_back(currOperate);
                operate(currOperate);
            }
        } else {
            for (int j = 1; j < i; ++j) {
                currOperate.push_back(1);
            }
            ll count = 1;
            for (int j = (int)n - i + 1; j >= 1; --j) {
                if (arrayT[j] != i) {
                    count++;
                } else {
                    break;
                }
            }
            currOperate.push_back(count);
            if (n - count - i + 1 != 0) {
                currOperate.push_back(n - count - i + 1);
            }
            if (currOperate.size() >= 2) {
                reverse(currOperate.begin(), currOperate.end());
                allOperations.push_back(currOperate);
                operate(currOperate);
            }
        }
    }
    cout <<allOperations.size() << endl;
    for (vl operation: allOperations) {
        cout << operation.size() << " ";
        for (ll op: operation) {
            cout << op << " ";
        }
        cout << endl;
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    for (ll x: arrayT) {
        cout << x << " ";
    }
    cout << endl;
#endif
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
//    cin >> t;
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
