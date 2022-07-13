#include <bits/stdc++.h>
using namespace std;
long long n, i;
string s;
typedef long long ll;
#define nit(i, n) for (i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
bool iseven(ll n) { return ((n & 1) == 0) ? true : false; }
ll pov(ll n, ll m)
{
    ll c = 1;
    while (m > 0)
    {
        if (!iseven(m))
        {
            c = c * n;
        }
        n = n * n;
        m = m >> 1;
    }
    return c;
}
unsigned int intlen(unsigned int n) { return n ? intlen(n / 10) + 1 : 0; }
bool isprime(ll x)
{
    for (ll d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}
void dfs(int st, vector<int> vec[], int *vis, int* arr)
{
    //cout << st << " ";
    vis[st] = 1;
    for (auto val : vec[st])
    {
        if (vis[val])
            continue;
        arr[val]=(st);
        dfs(val, vec, vis, arr);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt", "r", stdin);
    freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt", "w", stdout);
#endif
    ll e;
    cin >> n >> e;
    vector<int> g[n + 1];
    for (i = 0; i < e; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int *vis = new int[n];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    int* h=new int[n+1];
    
    dfs(1, g, vis, h);
    // for (i = 1; i <= n; i++)
    // {
    //     for (auto val : h[i]){
    //         cout<<i<<" "<<val<<endl;
    //     }
    
    // }
    ll x,y;
    cin>>x>>y;
    vector<int> w,r;
    while(true){
        w.push_back(h[x]);
        x=h[x];
        if(x==1){
            break;
        }
    }
    //cout<<endl;
    while(true){
        r.push_back(h[y]);
        y=h[y];
        if(y==1){
            break;
        }
    }
    // for(auto val : w){
    //     cout<<val<<" ";
    // }
    // for(auto val : r){
    //     cout<<val<<" ";
    // }
    //int end=min(w.size(),r.size());
    int f=w.size()-1;
    int l=r.size()-1;
    int ans;
    while(f>=0&&l>=0){
        if(w[f]==r[l]){
            //cout<<w[f]<<" ";
            ans=w[f];
        }
        else{
            break;
        }
        f--;
        l--;
    }
    cout<<ans<<endl;
    return 0;
}