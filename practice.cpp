/*
 * Developed By : Shivam Bairoliya
 * Created on   : 11/17/2020 at 10:04 PM(UTC +5.5)
 */

//#define ONLINE_JUDGE
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
ll grid[5001][5001];
ll n, m;
ll total;
vector<string> out;

void printxy(pair<ll, ll> temp) {
    string s = to_string(temp.first) + " " + to_string(temp.second) + " ";
    out.push_back(s);
    grid[temp.first][temp.second] = !grid[temp.first][temp.second];
}

void flip(ll x, ll y) {
    ll count = 0;
    vector<pair<ll, ll>> ones;
    vector<pair<ll, ll>> zeros;
    if (grid[x][y] == 1) {
        count++;
        ones.emplace_back(x, y);
    } else {
        zeros.emplace_back(x, y);
    }
    if (grid[x + 1][y] == 1) {
        count++;
        ones.emplace_back(x + 1, y);
    } else {
        zeros.emplace_back(x + 1, y);
    }
    if (grid[x][y + 1] == 1) {
        count++;
        ones.emplace_back(x, y + 1);
    } else {
        zeros.emplace_back(x, y + 1);
    }
    if (grid[x + 1][y + 1] == 1){
        count++;
        ones.emplace_back(x + 1, y + 1);
    } else {
        zeros.emplace_back(x + 1, y + 1);
    }
    if (count == 0) {
        return;
    }
    if (count == 1) {
        printxy(ones[0]);
        printxy(zeros[0]);
        printxy(zeros[1]);
        out.push_back("\n");
        total++;
        zeros.push_back(ones[0]);
        ones.push_back(zeros[0]);
        ones.push_back(zeros[1]);
        zeros.erase(zeros.begin());
        zeros.erase(zeros.begin());
        ones.erase(ones.begin());
        count++;
    }
    if (count == 2) {
        printxy(ones[0]);
        printxy(zeros[0]);
        printxy(zeros[1]);
        out.push_back("\n");
        printxy(ones[1]);
        printxy(zeros[0]);
        printxy(zeros[1]);
        out.push_back("\n");
        total += 2;
        return;
    }
    if (count == 3) {
        printxy(ones[0]);
        printxy(ones[1]);
        printxy(ones[3]);
        out.push_back("\n");
        total++;
        return;
    }
    if (count == 4) {
        printxy(ones[0]);
        printxy(ones[1]);
        printxy(ones[2]);
        out.push_back("\n");
        printxy(ones[1]);
        printxy(ones[2]);
        printxy(ones[3]);
        out.push_back("\n");
        printxy(ones[0]);
        printxy(ones[2]);
        printxy(ones[3]);
        out.push_back("\n");
        printxy(ones[0]);
        printxy(ones[1]);
        printxy(ones[3]);
        out.push_back("\n");
        total += 4;
        return;
    }
}


void solve() {
    total = 0;
    out.clear();
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (ll j = 0; j < m; ++j) {
            if (s[j] == '0') {
                grid[i][j + 1] = 0;
            } else {
                grid[i][j + 1] = 1;
            }
        }
    }
    bool check = false;
    if (m % 2 == 0) {
        check = true;
    }
    for (ll i = 1; i < n; i += 2) {
        for (ll j = 1; j < m; j += 2) {
            flip(i, j);
        }
        if (!check) {
            flip(i, m - 1);
        }
    }
    if (n % 2 != 0) {
        for (ll j = 1; j < m; j += 2) {
            flip(n - 1, j);
        }
        if (!check) {
            flip(n - 1, m - 1);
        }
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
