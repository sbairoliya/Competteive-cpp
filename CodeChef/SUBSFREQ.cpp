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
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
unordered_map<ll , vl> combinationMap;
ll pascal[5001][5001] = { 0 };
ll powerOf2[5001];

ll ogTriangle[5001][5001] = { 0 };
void initialize()
{
    // 0C0 = 1
    powerOf2[0] = 1;
    for (int i = 1; i < 5001; ++i) {
        powerOf2[i] = modMultiply(2, powerOf2[i - 1]);
    }
    pascal[0][0] = 1;
    ogTriangle[0][0] = 1;
    for (int i = 1; i < 5001; i++) {
        // Set every nCr = 1 where r = 0
        ogTriangle[i][0] = 1;
        pascal[i][0] = 1;
        for (int j = 1; j < i + 1; j++) {
            // Value for the current cell of Pascal's triangle
            pascal[i][j] = modSum(pascal[i - 1][j - 1], pascal[i - 1][j]);
            ogTriangle[i][j] = modSum(ogTriangle[i][j - 1], pascal[i][j]);
        }
    }
}

void solve() {
    map<ll, ll> frequencyMap;
    unordered_map<ll, ll> valueMap;
    ll n;
    cin>>n;
    ll max = 1;
    for (int i = 1; i <= n; i++) {
        ll element;
        cin>>element;
        frequencyMap[element]++;
        max = max(max, frequencyMap[element]);
    }
    vl theVectorArray[max + 1];
    for(auto mapElement : frequencyMap) {
        for (int i = 1; i <= mapElement.second; ++i) {
            theVectorArray[i].push_back(mapElement.first);
        }
    }
    ll elementCounter = n;
    ll prevLen = 0;
    for (int i = max; i >= 1; i--) {
        vl curr = theVectorArray[i];
        ll len = curr.size();
        elementCounter = elementCounter - ((len - prevLen) * i);
        prevLen = len;
        ll moreMultiplier[len + 1];
        ll lessMultiplier[len + 1];
        moreMultiplier[len] = 1;
        lessMultiplier[0] = 1;
        for (int j = 0; j < len; ++j) {
            moreMultiplier[len - j - 1] = modMultiply(moreMultiplier[len - j],
                                                      ogTriangle[frequencyMap[curr[len - j - 1]]][i]);
            lessMultiplier[j + 1] = modMultiply(lessMultiplier[j],
                                                ogTriangle[frequencyMap[curr[j]]][i -1]);
        }
        for (int j = 0; j < len; ++j) {
            ll calc = modMultiply(moreMultiplier[j + 1], lessMultiplier[j]);
            calc = modMultiply(calc, pascal[frequencyMap[curr[j]]][i]);
            calc = modMultiply(calc, powerOf2[elementCounter]);
            if (valueMap.find(curr[j]) == valueMap.end()) {
                valueMap[curr[j]] = calc;
            } else {
                valueMap[curr[j]] = modSum(valueMap[curr[j]], calc);
            }
        }
    }
    for (int i = 1; i <=n ; ++i) {
        cout<<valueMap[i]<<" ";
    }
    cout<<endl;

}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in","w",stderr);
    auto start = high_resolution_clock::now();
#endif
    int t = 1;
    initialize();
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