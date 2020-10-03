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
#include <cstring>


using namespace std;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;


#define vi vector<int> \
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}

//************************************* SOLUTION BELOW ***************************************//
int n = 100001;
int factors[100001];

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (factors[i] == k) {
            count++;
        }
    }
    cout << count << endl;
}

int32_t main() {
    fastio();
    for (int i = 0; i < n; ++i) {
        factors[i] = 0;
    }

    for (int i = 2; i < n; i++) {
        if (factors[i] == 0) {
            factors[i] = 1;
            for (int j = i * 2; j < n; j += i) {
                factors[j]++;
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}