#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       int
#define mod      1000000007
#define N        100002
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(gcd(a,b))
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void counting_sort(ll a[],ll n)
{
    ll mx=0,i;
    for(ll i=0;i<n;i++)
    {
        mx=max(mx,a[i]);
    }
    ll cnt[mx+1]={0};
    ll temp[n+1];
    for(i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    for(i=1;i<=mx;i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        cnt[a[i]]--;
        temp[cnt[a[i]]]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=temp[i];
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<pair<ll,ll>>v,p;
    ll i,j,m,r,l,k,n;
    cin>>n;
    ll a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    counting_sort(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
///time complexity
///best->O(n + k)
///average->O(n + k)
///worse->O(n + k)
///space complexity ->O(max)
