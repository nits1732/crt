#define ll long long int
#include<bits/stdc++.h>
using namespace std;
void problem5(vector<ll>&temp, int n , int l, int r){
    int count=1;
    for(ll i=l;i<=r;i++){
        temp[i]+=count;
        count++;
    }
}
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) cin>>arr[i];
    int q;
    cin>>q;
    vector<ll>temp(n+1,0);
    while (q--)
    {
        ll l,r;
        cin>>l>>r;
        problem5(temp,n,l,r);
    }
    for(ll i=1;i<=n;i++) arr[i]+=temp[i];
    for(ll i=1;i<=n;i++) cout<<arr[i]<<endl;
    return 0;
}