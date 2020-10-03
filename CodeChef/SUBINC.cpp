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
#define int long long
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}

//************************************* SOLUTION BELOW ***************************************//
void solve() {
    int n;
    cin >> n;
    int arr[n + 1];
    readNumbersArray1(n, arr);
    int dp[n + 10];
    int length = 1;
    dp[1] = 1;
    int count = 1;
    for (int i = 2; i <= n; ++i) {
        if (arr[i - 1] <= arr[i]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        count += dp[i];
    }
    cout<<count<<endl;
}

int32_t main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}