#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(ll n){return ((n&1)==0)?true:false;}
ll pov(ll n,ll m){ ll c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(ll x) { for (ll d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
void dfs(ll st,int** arr,ll n,int* vis,int* sum,int* eve){
    //cout<<st<<" ";
    vis[st]=1;
    ll a=0;
    sum[st]+=st;
    if(iseven(st)){
        eve[st]++;
    }
    for(ll i=1;i<=n;i++)
    {
        if(i==st) continue;
        else{
            if(arr[st][i]==1&&vis[i]==0){
                dfs(i,arr,n,vis,sum,eve);
                // if(iseven(i)){
                //     eve[i]++;
                // }
                eve[st]+=eve[i];
                //sum[i]+=i;
                sum[st]+=sum[i];
                //cout<<i<<" "<<st<<" "<<eve[st]<<" "<<eve[i]<<endl;
            }
        }
    }
    
}
int main(){
#ifndef ONLINE_JUDGE
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt","r",stdin);
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt","w",stdout);
#endif
    cin>>n;
    int** arr=new int*[n+1];
    for(ll i=1;i<=n;i++){
        arr[i]=new int[n+1];
        for(ll j=1;j<=n;j++){
            arr[i][j]=0;
        }
    }
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int* vis =new int[n+1];
    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
    int* sum =new int[n+1];
    for(ll i=1;i<=n;i++){
        sum[i]=0;
    }
    int* eve =new int[n+1];
    for(ll i=1;i<=n;i++){
        eve[i]=0;
    }
    dfs(1,arr,n,vis,sum,eve);
    for(ll i=1;i<=n;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    for(ll i=1;i<=n;i++){
        cout<<eve[i]<<" ";
    }
    // ll q;
    // cin>>q;
    // while(q--){
    //     ll v;
    //     cin>>v;
    //     vector<int> vec;
    //     dfs(1,arr,n, v,vis,0,vec);
    //     for(auto val : vec){
    //         cout<<val<<" ";
    //     }
    //     for(ll i=1;i<=n;i++){
    //     vis[i]=0;
    //     }
    //     cout<<endl;
    //     //cout<<&sum<<endl;
    // }
    
    

    
return 0;
}