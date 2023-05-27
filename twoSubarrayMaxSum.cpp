#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main(){
    // Maximum Valid Subarray Sum ending at given index (Google intern OA'21 Easy Version) 
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);
    ll n; 
    cin>>n;
    vector<ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    vector<ll> brr(n+1,0);
    for(ll i=0;i<=n;i++) cin>>brr[i];
    ll idx; cin>>idx;
    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i];
    }
    vector<ll> brrf(n+1, 0);
    for(ll i=1;i<=n;i++){
        brrf[i]=brrf[i-1]+brr[i];
    }
    ll val=brrf[idx];
    ll  minimum=1e18;
    for(ll i=0;i<idx;i++){
        if(brrf[i]==val){
            minimum=min(minimum,pref[i]);
        }
    }
    cout<<val-minimum;
    return 0;
}
    