#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll>employee(n,0);
    for(ll i=0;i<n;i++) cin>>employee[i];
    sort(employee.begin(),employee.end());
    vector<ll>pref(n+1,0);
    vector<ll>suff(n+1,0);
    for(ll i=0;i<n;i++){
        if(i%2)pref[i]=pref[i-1];
        else pref[i]=pref[i-1]+(employee[i]-employee[i-1]);
    }
    for(ll i=n;i>=1;i--){
        if(i%2)suff[i]=suff[i+1];
        else suff[i]=suff[i+1]+(employee[i+1]-employee[i]);
    }

    ll ans=1e18;
    for(ll i=1;i<=n;i++){
        ll left=i-1;
        if(left%2){
            ans=min(ans,pref[i-1]+suff[i+1]+(employee[i+1]-employee[i]));
        }else{
            ans=min(ans,pref[i-1]+suff[i+1]);
        }
    }
    cout<<ans<<endl;
}