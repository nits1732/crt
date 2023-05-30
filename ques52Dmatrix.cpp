#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// using prefix sum
bool sumvalid(vector<vector<ll>>&pref, ll n, ll k, ll mid){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll l=i-mid+1;
            ll r=j-mid+1;
            if(l<=0 or r<=0) continue;
            ll sum=pref[i][j]-pref[l-1][j]-pref[i][j-1]+pref[l-1][j-1];
            if(sum<=k){
                return true;
            }
        }
    }
    return false;
}

//slidig window
int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<ll>>arr(n+1,vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<ll>>pref(n+1,vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }
    ll low=0,high=n;
    ll ans=-1;
    while (low<=high)
    {
        ll mid=(low+high)/2;
        if(sumvalid(pref,n,k,mid)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
}