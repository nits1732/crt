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
    ll prefixSum=0, ans=INT16_MIN , maxm=0;
    for(ll i=0;i<=n;i++){
        prefixSum+=arr[i];
        maxm=min(maxm,prefixSum);
        ans=max(ans,prefixSum-maxm);
    }
    cout<<ans<<endl;
    return 0;
}
    