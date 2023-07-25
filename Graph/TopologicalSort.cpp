
/*
DEFINATION:
toplogical sorting always done in DAG(Directed Acyclic Graph) it is a linear ordering of vertices such that for every directed edge u v,vertex u comes before v in the ordering


*/
private:
    void dfs(int node,vector<int>*adj,vector<bool>&vis,vector<int>&ans){
        vis[node]=true;
        for(auto &it:adj[node]) if(!vis[it]) dfs(it,adj,vis,ans);
        ans.push_back(node);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    
	    vector<bool>vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}


    