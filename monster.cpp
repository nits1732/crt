#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> bfs(int n, vector<pair<int, int>>pos, vector<vector<int>>&mat){
    vector<pair<int, int>> curr, nxt;
    vector<vector<int>> visited(n+1, vector<int>(n+1,0));
    vector<vector<int>> distance(n+1,vector<int>(n+1,1e9));
    for(auto itr:pos){
        curr.push_back(itr);
        visited[itr.first][itr.second]=1;
        distance[itr.first][itr.second]=0;
    }
    while (curr.size()){
        for(auto itr: curr){
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int neighx=itr.first +dx[i];
                int neighy=itr.second+dy[i];
                if(neighx>=1 and neighx<=n and neighy>=1 and neighy<=n and !visited[neighx][neighy] and mat[neighx][neighy]==1){
                    nxt.push_back({neighx, neighy});
                    visited[neighx][neighy]=1;
                    distance[neighx][neighy]=distance[itr.first][itr.second]+1;
                }
            }
        }
        swap(curr,nxt);nxt.clear();
    }
    return distance;
    
}
// bool pathExists(vector<vector<int>> &mat, int n, int m, int meriPositionX, int meriPositionY){
//     vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
//     vector<pair<int,int>> curr, nxt;
//     curr.push_back({meriPositionX, meriPositionY});
//     visited[meriPositionX][meriPositionY]=1;

//     while(curr.size()){
//         for(auto itr : curr){
//             int x = itr.first;
//             int y = itr.second;

//             // (x, y) = (x+1, y+0), (x+0, y+1), (x+(-1), y+0), (x+0, y+(-1))
//             int dx[] = {1, 0, -1, 0};
//             int dy[] = {0, 1, 0, -1};
//             for(int i=0;i<4;i++){
//                 int ngbX = x+dx[i];
//                 int ngbY = y+dy[i];
//                 if(ngbX>=1 and ngbX<=n and ngbY>=1 and ngbY<=m and !visited[ngbX][ngbY] and mat[ngbX][ngbY]==1){
//                     nxt.push_back({ngbX, ngbY});
//                     visited[ngbX][ngbY]=1;
//                 }
//             }

//         }
//         swap(curr, nxt);
//         nxt.clear();
//     }

//     return visited[n][m];
// }
int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>>  monster(m);
    for(int i=0;i<n;i++){
        cin>>monster[i].first>>monster[i].second;
    }
    int x, y;
    cin>>x>>y;
    vector<vector<int>> matWithAll(n+1, vector<int>(n+1,1));
    vector<vector<int>> dist1=bfs(n ,monster,matWithAll);
    dist1[n][n]=1e9;
    vector<vector<int>> dist2=bfs(n ,{{x,y}},matWithAll);
    vector<vector<int>> dist3(n+1, vector<int>(n+1, 0));
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;i++){
            dist3[i][j]=(dist1[i][j]<=dist2[i][j]?1:0);
        }
    }
    vector<vector<int>> dist4=bfs(n, {{x,y}},dist3);
    if(dist4[n][n]<1e9) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
}