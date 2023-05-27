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
    ll ans=0, evencount=1,oddcount=0,prefSum=0;
    for(ll i=0;i<n;i++){
        prefSum+=arr[i];
        if(prefSum%2==0){
            ans+=oddcount;
            evencount++;
        }else{
            ans+=evencount;
            oddcount++;
        }
    }
    cout<<ans;
    return 0;
}
    