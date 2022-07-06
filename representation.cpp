#include <bits/stdc++.h>
using namespace std;
long long n, i;
string s;
typedef long long ll;
#define nit(i, n) for (i = 0; i < n; i++)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
bool iseven(int n) { return ((n & 1) == 0) ? true : false; }
int pov(int n, int m)
{
    int c = 1;
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
bool isprime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/ipt.txt", "r", stdin);
    freopen("/Users/nitesh/Documents/cp/mnbdhcxf'/out.txt", "w", stdout);
#endif
    ll m;
    cin >> n >> m;
    ll arr[n + 1][n + 1];
    map<ll,vector<ll> > vec;
    for (i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    // using adjancy matrix form;
    for (i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // using adjancy list ;
    for (auto val : vec){
        cout<<val.first<<"->";
        for(auto x: val.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }
        return 0;
}