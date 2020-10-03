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
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {
    int l, n;
    cin >> l >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    int p = sizeof(array) / sizeof(array[0]);
    sort(array, array + p);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] > l / 2) {
            index = i;
            break;
        }
    }
    if (index > 0) {
        int max = (l - array[0] > array[n - 1]) ? l - array[0] : array[n - 1];
        int min = (l - array[index] > array[index - 1]) ? l - array[index] : array[index - 1];
        cout<<min<<" "<<max<<endl;
    }
}

int32_t main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}