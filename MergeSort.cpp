#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000000007
#define N        1000005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void merg(ll a[],ll low,ll mid,ll high)
{
    ll i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++)
    {
        a[i]=b[i];
    }
}
void mergsort(ll a[],ll low,ll high)
{
    ll mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergsort(a,low,mid);
        mergsort(a,mid+1,high);
        merg(a,low,mid,high);///merg two array
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    set<ll>s;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n;
    ll a[n+1];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    mergsort(a,0,n-1);
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
///time--->O(nlog(n))
///space-->O(nlog(n))
