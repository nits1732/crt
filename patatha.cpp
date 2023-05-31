#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll noofParatha(ll rank, ll t, ll p){
    ll low=0, high=p,ans=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        ll timetakentocookmid=rank*mid*(mid+1)/2;
        if(timetakentocookmid<=t){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
        return ans;
    }
}
int main(){
    ll n;cin>>n;
    vector<ll> rank(n+1);
    for(ll i=0;i<n;i++){
        cin>>rank[i];
    }
    ll h;
    cin>>h;
    ll low=0, high=1e18 ,ans=0;
;
    while (low<=high)
    {
        ll mid=(low+high)/2;
        ll maxparata=0;
        for(auto x: rank){
            //ek chef kitna partha banyega
            ll ekchefkitnabnayega=noofParatha(x, mid, p);
            // ek chef ko kitna time lgega
            ll maxparata+=ekchefkitnabnayega;
            if(maxparata>=p){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    }
    cout<<ans;
}