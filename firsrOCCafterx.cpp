#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    map<int,vector<ll>> occ;
    for(ll i=1;i<=n;i++){
        occ[arr[i]].push_back(i);
    }
    int q;
    cin>>q;
    while (q--)
    {
        ll x,y;
        cin>>x>>y;
        for(int i=0;i<(ll)occ[x].size()-1;i++){
            ll low=0;
            ll high=(ll)occ[x].size();
            ll mid=(low+high)/2;
            ll ans=-1;
            while(low<=high){
                if(occ[x][mid]>y){
                    ans=occ[x][mid];
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            cout<<ans;
        }
    }

}
    
