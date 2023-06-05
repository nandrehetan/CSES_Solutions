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
ll prev_step[1011][1011];
ll dx[4]={-1,0,1,0};
ll dy[4]={0,1,0,-1};
string directions="URDL";
 
/*/-----------------------------Code begins----------------------------------/*/
void hetu()
{   
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    queue<pair<ll,ll>> q;
    pair<ll,ll> begin;
    pair<ll,ll> end;
 
    rep(i,0,n){
        rep(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]=='A'){
                begin=make_pair(i,j);
            }
            else if(arr[i][j]=='B'){
                end=make_pair(i,j);
            }
            
        }
    }
 
    q.push(begin);
    vis[begin.first][begin.second]=true;
 
    while(!q.empty()){
        pair<ll,ll> temp=q.front();
        q.pop();
        for(ll i=0;i<4;i++){
            pair<ll,ll> ok = make_pair(temp.first+dx[i],temp.second+dy[i]);
            if (ok.first<0 || ok.first>=n || ok.second<0 || ok.second>=m){
                continue;
            }
            if (arr[ok.first][ok.second]=='#'){
                continue;
            }
            if (vis[ok.first][ok.second]){
                continue;
            }
 
            vis[ok.first][ok.second] = true;
            prev_step[ok.first][ok.second] = i;
            q.push(ok);
        }
        // cout<<"HG";
    }
    // cout<<"HG";
 
    if (vis[end.first][end.second])
    {
        cout<<"YES"<<"\n";
        vector<ll>steps;
 
        while(end != begin){
            ll ok1 = prev_step[end.first][end.second];
            steps.push_back(ok1);
            end=make_pair(end.first-dx[ok1], end.second-dy[ok1]);
        }
 
        reverse(steps.begin(), steps.end());
 
        cout<<steps.size()<<"\n";
 
        for(auto it:steps){
            cout<<directions[it];
        }
        cout<<endl;
        
    }
    else
    {
        cout<<"NO"<<"\n";
        return;
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
      hetu();
   }
   return 0;
   
}
