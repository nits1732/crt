#include<bits/stdc++.h>
using namespace std;
int KokoEatbanana(vector<int> &piles,int mid){
    int hour=0;
    for(auto x:piles){
        hour+=(x+mid-1)/mid;
    }
    return hour;
}
int main() {
    int n;cin>>n;
    vector<int> piles(n+1);
    for(int i=0;i<n;i++) cin>>piles[i];
    int h; cin>>h;
    int low=1;
    int high=1e9;
    int ans =-1;
    while (low<=high){
        int mid=(low+high)/2;
        ans=KokoEatbanana(piles, mid);
        if(ans>h){
            low=mid+1;
        }else{
            ans=mid;
            high=mid-1;
        }
    }
    cout<<ans;
    return 0;
}


//ciel(x/y)=x+y-1/y