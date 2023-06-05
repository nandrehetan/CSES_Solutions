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
 
void bfs(vector<ll>adj[], int start, int end)
{
    vector<ll> ans;
    bool vis[end+20];
    vector<ll> temp(end+20);
    temp[start]=-1;     
    memset(vis,false,sizeof(vis)); 
 
    vis[start] = true;
 
    queue<ll>q;
    q.push(start);
 
    while(!q.empty()){
        ll ok = q.front();
        for(auto it:adj[ok]){
            if(!vis[it]){
                vis[it]=true;
                temp[it]=ok;
                q.push(it);
            }
        }
        q.pop();
    }
    if (vis[end]){
        for(ll i=end; i!=-1; i=temp[i]){
            ans.push_back(i+1);
        }
    }
 
    reverse(ans.begin(),ans.end());
 
    if (ans.empty())
    {
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }
 
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    
}
/*/-----------------------------Code begins----------------------------------/*/
void solve()
{   
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+1];
    while(m--){
         ll a,b;
         cin>>a>>b;
         a--;b--;
         adj[a].push_back(b);
         adj[b].push_back(a);
    }
    bfs(adj,0,n-1);
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
