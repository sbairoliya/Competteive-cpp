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
#define int long long


map<string, int> colorMap;
vector<string> colors;
vector<vector<bool>> canAppearTogether;
vector<int> best;
vector<int> current;
vector<bool> mark;
int mainCount = 0;

int N;

void recurse()
{

    if (current.size() == N)
    {
        mainCount++;
        if (best.empty())
        {
            for (int i : current)
            {
                best.push_back(i);
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!mark[i])
        {
            if (!current.empty() && !canAppearTogether[current.back()][i])
            {
                continue;
            }
            mark[i] = true;
            current.push_back(i);
            recurse();
            mark[i] = false;
            current.pop_back();
        }
    }
}

void solve()
{
    cin >> N;
    mark.clear();
    mark.resize(N, false);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        colors.push_back(s);
        colorMap[s] = i;
    }
    canAppearTogether.clear();
    canAppearTogether.resize(N, vector<bool>(N, true));
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string a, b;
        cin >> a >> b;
        canAppearTogether[colorMap[a]][colorMap[b]] = false;
        canAppearTogether[colorMap[b]][colorMap[a]] = false;
    }
    recurse();
    cout << mainCount << endl;
    for (int i = 0; i < N; i++)
    {
        cout << colors[best[i]] << " ";
    }
    cout << endl;
    mainCount = 0;
    colors.clear();
    colorMap.clear();
    best.clear();
}

int32_t main()
{
    fastio();

    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
}