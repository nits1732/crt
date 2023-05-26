#include<bits/stdc++.h>
#define ll long long int

using namespace std;
//Q koi x index pe mera subarray hai jo target ke equal hai
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
    ll idx,x;
    cin>>idx>>x;
    for(ll i=0;i<idx;i++){
        if(pref[idx]-x==pref[i]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
}
    