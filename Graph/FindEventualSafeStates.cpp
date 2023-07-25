

/*
Problem link: https://leetcode.com/problems/find-eventual-safe-states/

Solution Approach :
The core concept is to find the nodes which dont have any possible path going to any cycle 

here safe nodes are those nodes which is not connected with cycle
*/


class Solution {
private:
    bool dfs(int node,vector<bool>&vis,vector<bool>&pathVis,vector<int>*adj){
        vis[node]=true;
        pathVis[node]=true;

        for(auto &adjacentNode:adj[node]){
            if(vis[adjacentNode]==false){
                if(dfs(adjacentNode,vis,pathVis,adj) == true) {
                    return true;
                }
            }
            else if(pathVis[adjacentNode]==true){
                return true;
            }
        }
        
        pathVis[node]=false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(auto &ele:graph[i]){
                adj[i].push_back(ele);
            }
        }

        vector<bool>vis(n,false);
        vector<bool>pathVis(n,false);

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                //here we are trying out all nodes
                dfs(i,vis,pathVis,adj);
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++) if(pathVis[i]==false) ans.push_back(i);

        return ans;
    }
};