/*
    迪杰斯特拉 dijkstra
    单源最短路径，source为源点，dis为到各个点的最短路
*/

#define ll long long
const ll MX = LLONG_MAX/2;
const ll mod = 1e9+7;

vector<ll>  dijkstra(vector<vector<int>>& roads, int n, int source){
    vector<vector<ll>> g(n, vector<ll>(n, MX));
    int m = roads.size();
    for(auto& r : roads){
        g[r[0]][r[1]]=r[2];
        g[r[1]][r[0]]=r[2];
    }
    vector<ll> dis(n, MX); // source 到各个点的距离
    vector<bool> vis(n, false); // 是否访问过该点
    for(int i=0;i<n;i++){
        dis[i] = g[source][i];
    }
    dis[source] = 0;vis[source]=true;
    for(int i=0;i<n-1;i++){
        int node = -1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&(node==-1||dis[j]<dis[node])) node=j;
        }
        for(int j=0;j<n;j++){
            dis[j] = min(dis[j], dis[node]+g[node][j]);
        }
        vis[node]=true;
    }
    return dis;
}