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
#define MOD 1000000009
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}

//************************************* SOLUTION BELOW ***************************************//
int arr[1000003];

void calculate() {
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i < 1000003; ++i) {
        arr[i] = (arr[i - 2] + arr[i - 3]) % MOD;
    }
}

void solve() {
    int x;
    cin >> x;
    cout << arr[x] << endl;
}

int32_t main() {
    fastio();
    calculate();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}