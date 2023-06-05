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
char arr[1011][1011];
bool vis[1011][1011];
 
void dfs(ll i, ll j)
{
    if ((i < 0) || (j < 0) || (i >= n) || (j >= m) || vis[i][j]==true || arr[i][j]=='#')
    {
        return;
    }
 
    vis[i][j] = true;
 
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
 
/*/-----------------------------Code begins----------------------------------/*/
void hetu()
{   
    ll ans = 0;
 
    cin>>n>>m;
    
    rep(i,0,n){
        rep(j,0,m){
            cin>>arr[i][j];
        }
    }
    
    memset(vis,false,sizeof(vis));
    
 
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if (!vis[i][j] && arr[i][j]=='.')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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
      hetu();
   }
   return 0;
   
}
