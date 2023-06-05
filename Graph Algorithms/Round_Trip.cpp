/*
  Compete against Yourself.
  Author - Hetan Hemant Nandre (@hetanhnandre)
*/
 
#include <bits/stdc++.h>
using namespace std;
//Hetan Nandre's code 
 
// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
// Constants 
#define INF 2147483647
#define EPS 1e-9
#define MOD 1000000007
 
// Macros
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define pb push_back
#define MAX 1e18
#define new "\n"
#define in(a)        for(auto &i:a) cin>>i
#define MP make_pair
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
typedef vector<int>vi;
 
ll n,m;
ll start,en;
vector<vector<ll>>adj;
vector<bool>vis;
vector<ll>parent;
 
 
bool dfs(ll curNode, ll curParent)
{
    vis[curNode] = true;
    parent[curNode] = curParent;
 
    for(auto it:adj[curNode]){
        if(it==curParent){
            continue;
        }
        if(vis[it]){
            start = it;
            en = curNode;
            return true;
        }
        if (!vis[it])
        {
            if (dfs(it,curNode))
            {
                return true;
            }
        }
    }
    return false;
}
 
bool visit_all()
{
    for (ll i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i,-1))
            {
                return true;
            }
        }
    }
    return false;
}
 
 
/*/-----------------------------Code begins----------------------------------/*/
void solve()
{
    cin>>n>>m;
 
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    parent.resize(n+1);
 
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (!visit_all())   
    {
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }
    ll ok = en;
    vector<ll> cycle;
    cycle.push_back(en);
    while(ok != start){
        cycle.push_back(parent[ok]);
        ok = parent[ok];
    }
    cycle.push_back(en);
    cout<<cycle.size()<<"\n";
    for(auto it:cycle){
        cout<<it<<" ";
    }
    cout<<endl;
 
}
//Note : Always check for the following things
//1. Max value of N
//2. Mod value
//3. Test for your own case
 
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll t;
   t=1;
   // cin>>t;
   while(t--)
   {
      solve();
   }
   return 0;
   
}
