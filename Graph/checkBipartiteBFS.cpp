/*
Defination:
Bipartite Graph:=>Color the graph with 2 colors such that no adjacent nodes have same color.

ALGORITHM AND INITIAL THOUGHTS:

step 1: colour any node with any colour and colour its all adjacent nodes with another colour 

step 2: if any adjacent node if previously colured by any other node then there is two case
    a)if both are of different colours than continue to next step
    b)else print "not bipartite" as it has cycle in between them

WE CAN USE BFS AND DFS (its just about implementation)

Here we are using BFS
Time Complexity:O(V+E) (here V=n)
Space Complexity:O(V+V) (here V=n)
*/


//here graph[] is adjacency list and n is number of nodes
bool isBipartite(int n, vector<int>graph[]){
    //Here initially colouring every node with same colour i.e -1
    //here in implementation we are taking our 2 colours as 0 and 1
    vector<int>vis(n,-1);

    //as usual bfs algo stuff we have to takke queue
    queue<int>q;

    //graph can be in parts also thats why we are using this to handle multiple components of a graph
    for(int i=0;i<n;i++){
        //if it is not coloured then push and use algorithm 
        if(vis[i]==-1){
            q.push(i);
            vis[i]=0;
            while(!q.empty()){

                int node=q.front();
                q.pop();

                for(auto &it:graph[node]){
                    //we check whether the neighbour has been coloured or not
                    if(vis[it]!=-1){
                        //if it is coloured then it should be opposit if not it is not bipartite graph
                        if(vis[it]==vis[node]) return false;
                    }
                    else{
                        vis[it]=!vis[node];
                        q.push(it);
                    }
                }
            }
        }
    }
        
    return true;
}

/*
Practice problem or application:
    Problem 1: https://leetcode.com/problems/possible-bipartition/

*/