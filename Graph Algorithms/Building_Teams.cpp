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
vector<vector<ll>>adj ;
vector<bool>vis;
vector<ll>ok(100001); //To store the colors
 
bool dfs(ll curNode, ll color)
{
    //Mark the current node as visited and assign the color
    vis[curNode] = true;
    ok[curNode] = color;
 
    for(auto it:adj[curNode]){
        if (!vis[it])
        {
            bool temp = dfs(it,color^1); //XOR the current color with 1 to change it from adjacent node's color
            if (temp==false)
            {
                return false;
            }
            else
            {
                if (ok[curNode] == ok[it])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
/*/-----------------------------Code begins----------------------------------/*/
void solve()
{
    cin>>n>>m;
 
    adj.assign(n+1,{});
    vis.assign(n+1,false);
 
    while(m--){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    bool check = true;
 
    for (ll i = 1; i <= n; ++i){
        if (!vis[i]) //If the given node is unvisited, perform dfs travesal
        {
            check = dfs(i,0);
            if (!check){
                break;
            }
        }
    }
 
    if (!check){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }
 
    //Print the color given to each pupil
    for (int i = 1; i <= n; ++i){
        cout<<ok[i]+1<<" ";
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
