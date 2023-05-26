#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//Q koi x index pe mera subarray hai jo target ke equal hai for n queries
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
    map<ll,ll> m;
    for(int i=n;i>=1;i--){
        m[pref[i]]=i;
    }
    ll q; cin>>q;
    while (q--)
    {
        /* code */
        ll idx,x;
        cin>>idx>>x;
        ll temp=pref[idx]-x;
        if(!m.count(temp)){ // if temp is not present in the map
            cout<<"NO"<<endl;
        }else{
            //if it is not in the range
            if(m[temp]>idx-1) cout<<"NO";
            else cout<<"YES"<<endl;
            return 0;
        }
    }
    

}
    