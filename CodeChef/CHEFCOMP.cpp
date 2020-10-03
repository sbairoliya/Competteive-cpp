/*
 * Developed By : Shivam Bairoliya
 */

#include<cstdio>
#include<cstring>
#include<iostream>
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
#define sl set<long >
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/


void DFS(sl graph[], ll *population, ll *flowers, ll currNode, ll initialNode,
         bool *vis, ll *days, ll currentDay) {
    if (vis[currNode]) {
        return;
    }
    vis[currNode] = true;
    if (flowers[currNode] != 0) {
        if (population[initialNode] >= flowers[currNode]) {
            flowers[currNode] = 0;
            days[currNode] = currentDay;
        } else {
            flowers[currNode] -= population[initialNode];
        }
    }
    for (auto j : graph[currNode]) {
        DFS(graph, population, flowers, j, initialNode, vis, days, currentDay);
    }
}

void addEdge(sl graph[], ll u, ll v) {
    graph[u].insert(v);
    graph[v].insert(u);
}

void removeAllEdges(sl graph[], ll edge) {
    for (auto i : graph[edge]) {
        graph[i].erase(edge);
    }
}

void solve() {
    ll N;
    cin >> N;
    sl graph[N + 1];
    ll permute[N + 1];
    ll population[N + 1];
    ll flowers[N + 1];
    for (int i = 1; i < N; ++i) {
        ll u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> permute[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> population[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> flowers[i];
    }
    ll days[N + 1];
    memset(days, -1, sizeof(days));
    for (int i = 1; i <= N; ++i) {
        bool vis[N + 1];
        memset(vis, 0, sizeof(vis));
        DFS(graph, population, flowers, permute[i], permute[i], vis, days, i);
        removeAllEdges(graph, permute[i]);
    }
    for (int i = 1; i <= N; i++) {
        cout << days[i] << " ";
    }
    cout<<endl;
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