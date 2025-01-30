/*
 * @lc app=leetcode id=2493 lang=cpp
 *
 * [2493] Divide Nodes Into the Maximum Number of Groups
 */

// @lc code=start
class Solution {
public:
     bool checkbipartile(vector<vector<int>> &adj, int n) {
    vector<int> color(n+1, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
    int findmaxlevelBFS(vector<int>& max_distance,vector<vector<int>>&adj,vector<bool>& visited,int source){
        queue<int>q;
        q.push(source);
        visited[source]=true;

        int max_level=-1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            max_level=max(max_level,max_distance[curr]);
            for(int nbr:adj[curr]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return max_level;
    }
    int countlevel(vector<vector<int>>&adj,int n,int source){
        vector<bool>visited(n+1,false);
        queue<int>q;
        visited[source]=true;
        q.push(source);

        int levels=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                int curr=q.front();
                q.pop();

                for(int nbr:adj[curr]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            levels++;
        }
        return levels;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
             vector<vector<int>> adj(n+1);
             for(auto edge:edges){
                  adj[edge[0]].push_back(edge[1]);
                  adj[edge[1]].push_back(edge[0]);  
             }

             if(!checkbipartile(adj,n))
             return -1;
           
             vector<int>maxdistance(n+1);
             for(int i=1;i<=n;++i){
                  maxdistance[i]=countlevel(adj,n,i);
             }
              int total_levels=0;
                  vector<bool>visited(n+1,false);
                 
                  for(int i=0;i<=n;++i){
                    if(!visited[i])
                    total_levels+=findmaxlevelBFS(maxdistance,adj,visited,i);
                  }
                
               return total_levels;
    }
};
// @lc code=end

