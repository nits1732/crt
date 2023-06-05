#include<bits/stdc++.h>
using namespace std;
bool findpath(vector<vector<int>>&matrix, pair<int,int>&quries,int low, int mid){
    int n=matrix.size();
    int m-matrix[0].size();
    vector<vector<int>>visited(n+1, vector<int>(m+1,0));
    vector<pair<int, int>> curr, mxt;
    for(auto itr:quries){
        int x.itr.first;
        int y= itr.second;
        visited[x][y]=1;
    }
    curr.push_back({1,1});
    visited[1][1]=1;
    while(curr.size()){
        for(auto itr:curr){
            int x=itr.first;
            int y=itr.second;
            if(x<=n and !visited[x])
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int q;
    cin>>q;
    vector<pair<int, int>> queries(q);
    for(int i-0;i<q;i++){
        cin>>queries[i].first>>queries[i].second;
    }
    int low=1, high=q;
    int ans=-1;
    while(low<=high) {
        int mid= (low+high)/2;
        if(findpath(matrix, queries, low, mid)){
            ans.first=queries[mid].first;
            ans.second=queries[mid].second;
            high=mid;
        }else{
            low=mid=1;
        }
    }
}