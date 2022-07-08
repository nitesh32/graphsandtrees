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
void func(int **arr,ll n,ll pt,int* vis){
    //cout<<pt<<" ";
    vis[pt]=1;
    for(ll i=1;i<=n;i++){
        if(i==pt){
            continue;
        }
        if(arr[pt][i]==1&&vis[i]!=1){
            func(arr,n,i,vis);
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt","r",stdin);
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt","w",stdout);
#endif
    ll m;
    cin>>n>>m;
    int** arr=new int*[n+1];
    for(ll i=1;i<=n;i++){
        arr[i]=new int[n+1];
        for(ll j=1;j<=n;j++){
            arr[i][j]=0;
        }
    }
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int* vis = new int[n+1];
    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
    ll c=0;
    for(i=1;i<=n;i++){
        if(vis[i]!=1){
            func(arr,n,i,vis);
            c++;
        }
    }
    cout<<c<<endl;
    
return 0;
}