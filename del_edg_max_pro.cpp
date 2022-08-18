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
void dfs(int st,int* vis,vector<int> vec[],int* sum,int* arr){
    //cout<<st<<" ";
    vis[st]=1;
    sum[st]+=arr[st];
    for(auto val: vec[st]){
        if(vis[val]) continue;
        
        //cout<<endl;
        
        dfs(val,vis,vec,sum,arr);
        //sum[val]=max(sum[val],arr[val]);
        sum[st]+=sum[val];
        //cout<<val<<" "<<sum[val]<<" "<<st<<" "<<sum[st];
    }

}
void df(int st,vector<int> vec[],int* vis,int* ans,int sum,int* sub){
    //cout<<st<<" ";
    ans[st]=sum-sub[st];
    vis[st]=1;
    for(auto val : vec[st]){
        if(vis[val]) continue;
        df(val,vec,vis,ans,sum,sub);
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt","r",stdin);
freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt","w",stdout);
#endif
    cin>>n;
    int* arr=new int[n+1];
    ll sum=0;
    for(i=1;i<=n;i++){
        ll x;
        cin>>x;
        arr[i]=x;
        sum+=arr[i];
    }
    vector<int> vec[n+1];
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int* vis=new int[n+1];
    for(i=1;i<=n;i++){
        vis[i]=0;
    }
    int* su=new int[n+1];
    for(i=1;i<=n;i++){
        su[i]=0;
    }
    dfs(1,vis,vec,su,arr);
    int* ans = new int[n+1];
    ll z=0;
    for(i=1;i<=n;i++){
        ans[i]=sum-su[i];
        ll to=ans[i]*su[i];
        if(to>z){
            z=to;
        }
    }
    cout<<z<<endl;
    // cout<<sum<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<su[i]<<" ";
    // }
    // cout<<endl;
    // for(i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }
    
return 0;
}