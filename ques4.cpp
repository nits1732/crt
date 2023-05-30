#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// using prefix sum
bool sumvalid(vector<ll>&pref, ll n, ll k, ll mid){
    for(int i=1;i<=n;i++){
        ll l=i-mid+1;
        if(l<1) continue;
        if(pref[l]-pref[i-1]<=k){
            return true;
        }
    }
}

//slidig window
int main(){
    int n, k;
    cin>>n>>k;
    vector<ll> nums(n+1, 0);
    for(ll i=1;i<=n;i++){
        cin>>nums[i];
    }
    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+nums[i];
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