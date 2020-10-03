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

#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int>

void solve() {
    int n;
    cin >> n;
    map<string, vi > countryMap;
    for (int i = 0; i < n; ++i) {
        string s;
        int year;
        cin >> s >> year;
        countryMap[s].push_back(year);
    }
    for(auto i: countryMap) {
        sort(i.second.begin(), i.second.end());
        countryMap[i.first] = i.second;
    }
    int query;
    cin>>query;
    for (int i = 0; i < query; ++i) {
        string country;
        int trip;
        cin>>country>>trip;
        cout<<countryMap[country][--trip]<<endl;
    }

}

int32_t main() {
    fastio();

    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}