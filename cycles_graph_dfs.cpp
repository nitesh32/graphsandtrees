#include<bits/stdc++.h>
using namespace std;
long long n,i;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(ll n){return ((n&1)==0)?true:false;}
ll pov(ll n,ll m){ ll c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(ll x) { for (ll d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
const int N=10e5+3;
int vis[N];
vector<ll> g[N];
bool dfs(int vertex,int parent){
    vis[vertex]=1;
    bool loop=false;
    for(auto x:g[vertex]){
        if(vis[x]&&x==parent) continue;;
        if(vis[x]) return true;
        loop |=dfs(x,vertex);
        //cout<<x<<endl;
    }
    return loop;
    //cout<<vertex<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt","r",stdin);
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt","w",stdout);
#endif
    ll v,e;
    cin>>v>>e;
    for(i=0;i<e;i++){
        ll v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    //dfs(1,0);
    int ans =0;
    for(i=1;i<=v;i++){
        if(vis[i]!=1)
        ans |=dfs(i,0);
    }
    cout<<ans<<endl;
    // for(auto val : g){
    //     for(auto x:val){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
return 0;
}