#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll> bulb(n,0);
    vector<ll>pos(n,0);
    for(ll i=0;i<n;i++) cin>>bulb[i];
    for(ll i=0;i<n;i++) cin>>pos[i];
    ll x;
    cin>>x;
    vector<ll>ans(x+2,0),pref(x+2,0);
    for(ll i=0;i<n;i++){
        ll l=max(1ll, bulb[i]-pos[i]);
        ll r=min(x,bulb[i]+pos[i]);
        ans[l]+=1;
        ans[r+1]-=1;
    }
    for(int j=1;j<=x;j++){
        pref[j]=pref[j-1]+ans[j];
    }
    ll count=0;
    for(ll i=1;i<=x;i++){
        cout<<pref[i]<<" ";
        if(pref[i]==0) count++;
    }
    cout<<count<<endl;
    return 0;
}