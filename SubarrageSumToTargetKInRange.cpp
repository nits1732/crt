#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);
    ll n; 
    cin>>n;
    vector<ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i];
    }
    ll target; cin>>target;
    map<ll,ll> m;
    ll count=0;
    for(ll i=0;i<=n;i++){
        if(m.count(pref[i]-target)){
            count+=m[pref[i]-target];
        }
        m[pref[i]]++;
    }
    cout<<count<<endl;
    return 0;
}
    