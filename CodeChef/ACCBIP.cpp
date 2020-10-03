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


ll numberOfTriangles(vl count, ll len) {
    if (len < 3) {
        return 0;
    }
    ll sum1 = 0;
    for (int i = 0; i < len; i++)
        sum1 += count[i];

    // calculating sum2. sum2 = m1*m2 + m2*m3 + ...
    ll sum2 = 0;
    ll temp[sum1];  // Needed for sum3
    for (int i = 0; i < len; i++) {
        temp[i] = count[i] * (sum1 - count[i]);
        sum2 += temp[i];
    }
    sum2 /= 2;

    // calculating sum3 which gives the final answer
    // m1 * m2 * m3 + m2 * m3 * m4 + ...
    ll sum3 = 0;
    for (int i = 0; i < len; i++)
        sum3 += count[i] * (sum2 - temp[i]);
    sum3 /= 3;

    return sum3;
}
ll knapSack(ll W, vl wt, vl val, ll n)
{
    ll i, w;
    ll K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(
                        val[i - 1] + K[i - 1][w - wt[i - 1]],
                        K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
void solve() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<map<ll, int>> theVector(c + 1, map<ll, int>());

    for (int i = 1; i <= n; i++) {
        ll slope, b, color;
        cin >> slope >> b >> color;
        theVector[color][slope]++;
    }
    ll removeArray[c];
    for (int i = 1; i <= c; ++i) {
        cin >> removeArray[i];
    }
    vl value;
    vl weight;
    ll totalSum = 0;
    for (ll i = 1; i < c + 1; ++i) {
      map<ll, int> currMap = theVector[i];
      ll size = currMap.size();
      if (size < 3) {
          continue;
      }
      vl array;
      for (auto j: currMap) {
          array.push_back(j.second);
      }
      sort(array.begin(), array.end());
      ll currSum = numberOfTriangles(array, size);
      totalSum += currSum;
      while (true) {
        array[0]--;
        if (array[0] == 0) {
            array.erase(array.begin());
        }
        if (array.size() < 3) {
            break;
        }
        ll newSum = numberOfTriangles(array, array.size());
        value.push_back(currSum - newSum);
        weight.push_back(removeArray[i]);
        currSum = newSum;
      }
      value.push_back(currSum);
      weight.push_back(removeArray[i]);
    }
    ll size = value.size();
    ll minus = knapSack(k, weight, value, size);
    cout<<(totalSum - minus)<<endl;
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
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}