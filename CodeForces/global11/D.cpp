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
    ll index = 0;
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
    ll temp = n;
    if (n % 2 == 0)
        temp--;
    for (int i = 1; i <= temp; ++i) {
        vl currentOperation;
        vl tempOperation;
        if (i % 2 == 0) {
            int j = 1;
            for (; j < i; ++j) {
                currentOperation.push_back(1);
                tempOperation.push_back(1);
            }
            int k = j;
            for (; k <= n; k++) {
                if (arrayT[k] == i) {
                    break;
                }
            }
            if (k - j > 0) {
                currentOperation.push_back(k - j);
                tempOperation.push_back(k - j);
            }
            if (n - k > 0) {
                currentOperation.push_back(n - k);
                tempOperation.push_back(n - k);
            }
            operate(tempOperation);
        } else {
            int k = 1;
            for (; k <= n - i + 1; ++k) {
                if (arrayT[k] == i) {
                    break;
                }
            }
            if (k - 1 > 0) {
                currentOperation.push_back(k - 1);
                tempOperation.push_back(k - 1);
            }
            if (n - i + 1 - k + 1 > 0) {
                currentOperation.push_back(n - i + 1 - k + 1);
                tempOperation.push_back(n - i + 1 - k + 1);
            }
            for (int j = 1; j < i; ++j) {
                tempOperation.push_back(1);
                currentOperation.push_back(1);
            }
            operate( tempOperation);
        }
        if (currentOperation.size() >= 2)
            allOperations.push_back(currentOperation);
    }
    if (n % 2 == 0) {
        vl operatfsaf;
        for (int i = 1; i <= n; ++i) {
            operatfsaf.push_back(1);
        }
        allOperations.push_back(operatfsaf);
    }
    cout << allOperations.size() << endl;
    for (vl operation : allOperations) {
        cout << operation.size() << " ";
        for (ll i: operation) {
            cout << i << " ";
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
