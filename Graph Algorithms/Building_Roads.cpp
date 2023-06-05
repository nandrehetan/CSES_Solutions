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
vector<ll> adj[200001];
vector<bool>vis(200001);
vector<ll>paths;
 
void dfs(int node)
{
    vis[node]=true;
 
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
 
/*/-----------------------------Code begins----------------------------------/*/
void solve()
{   
 
    
    ll ans=0;
    cin>>n>>m;
    while(m--){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
     
    fill(vis.begin(),vis.end(),false);
    
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            paths.push_back(i);
            dfs(i);
        }
    }
    cout<<paths.size()-1<<endl;
    for(ll i=1;i<paths.size();i++){
        cout<<paths[i]<<" "<<paths[i]-1<<endl;;
    }
 
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
