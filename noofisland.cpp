#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    map<int, vector<int>>adjm;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        adjm[x].push_back(y);
        adjm[y].push_back(x);
    }
    vector<int>visited (n+1,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            count++;
            vector<int> curr, nxt;
            curr.push_back(i);
            visited[i]=true;
            while (curr.size())
            {
                for(auto itr: curr){
                    for(auto neighbour:adjm[itr]){
                        if(!visited[neighbour]){
                            nxt.push_back(neighbour);
                            visited[neighbour]=1;
                        }
                    }
                }
                swap(curr,nxt);
                nxt.clear();
            }
            
        }
    }
    cout<<count<<endl;
    return 0;
}