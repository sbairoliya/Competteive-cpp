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
#define readNumbersArray2(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    ll up = 0, down = 0, left = 0, right = 0;
    ll mod = 1e18;
    string s;
    cin >> s;
    for (char i : s) {
        if (i == 'U') {
            up++;
        } else if (i == 'R') {
            right++;
        } else if (i == 'D') {
            down++;
        } else {
            left++;
        }
    }
    ll x1, y1;
    cin >> x1 >> y1;
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll x2, y2;
        cin >> x2 >> y2;
        ll xd = abs(x1 - x2) ;
        ll yd = abs(y1 - y2);
        ll ans = (xd + yd);
        if (x2 >= x1 && y2 >= y1 && xd <= right && yd <= up)
            cout << "YES " << ans << "\n";
        else if (x2 <= x1 && y2 <= y1 && xd <= left && yd <= down)
            cout << "YES " << ans << "\n";
        else if (x2 >= x1 && y2 <= y1 && xd <= right && yd <= down)
            cout << "YES " << ans << "\n";
        else if (x2 <= x1 && y2 >= y1 && xd <= left && yd <= up)
            cout << "YES " << ans << "\n";
        else
            cout << "NO\n";
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