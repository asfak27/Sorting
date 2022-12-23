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
ll partition(ll a[],ll l,ll r)
{
    ll cnt=0;
    ll pivot=a[l];

    for(ll i=l+1;i<=r;i++)
    {
        if(a[i]<=pivot)cnt++;
    }
    ll idx=l+cnt; ///pivot index
    swap(a[l],a[idx]);///replace right position

    ll i=l;
    ll j=r;
    while(i<idx && j>idx)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }

        if(i<idx && j>idx)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    return idx;
}

void quick_sort(ll a[],ll l,ll r)
{
    if(l>=r)return;

    ll idx=partition(a,l,r);///pick a value to set into right position and return his index

    quick_sort(a,l,idx-1);
    quick_sort(a,idx+1,r);

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
    quick_sort(a,0,n-1);
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
///best->O(n log(n))
///average->O(n log(n))
///worse->O(n^2))
///space complexity ->O(log(n))
