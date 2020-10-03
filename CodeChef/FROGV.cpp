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
#define vl vector<long long>
#define int long long
#define MOD 1000000009
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}

//************************************* SOLUTION BELOW ***************************************//

int binarySearch(ll arr[], int l, int r, ll x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    ll array[n + 1];
    array[0] = 0;
    ll sortedArray[n + 1];
    sortedArray[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        array[i] = sortedArray[i] = x;
    }
    ll size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    sort(sortedArray, sortedArray + size);
    bool arrayCheck[n];
    arrayCheck[0] = false;
//    for (int i = 1; i <= n; ++i) {
//        mapIt.insert(sortedArray[i], i);
//    }
    for (int i = 1; i < n; ++i) {
        if (sortedArray[i + 1] - sortedArray[i] > k) {
            arrayCheck[i] = false;
        } else {
            arrayCheck[i] = true;
        }
    }
    //mapIt.find(array[a])->second
    //mapIt.find(array[b])->second
    for (int i = 1; i <= p; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "Yes" << endl;
            continue;
        }
        bool check = true;
        int j = binarySearch(sortedArray, 1, n, array[a]);
        while (true) {
            if (!arrayCheck[j]) {
                check = false;
            }
            j++;
            if (j == n || sortedArray[j] == array[b])
                break;
        }
        if (check) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
}



// We reach here when element is not
// present in array

int32_t main() {
    fastio();
    int t = 1;
    while (t--) {
        solve();
    }
}