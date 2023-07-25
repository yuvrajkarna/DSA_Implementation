/*
Defination:
Bipartite Graph:=>Color the graph with 2 colors such that no adjacent nodes have same color.

ALGORITHM AND INITIAL THOUGHTS:

step 1: colour any node with any colour and colour its all adjacent nodes with another colour 

step 2: if any adjacent node if previously colured by any other node then there is two case
    a)if both are of different colours than continue to next step
    b)else print "not bipartite" as it has cycle in between them

WE CAN USE BFS AND DFS (its just about implementation)

Here we are using DFS
Time Complexity:O(V+E) (here V=n)
Space Complexity:O(V+V) (here V=n)
*/

// this just check the one component of a graph
bool dfsCheck(int node,int colourOfNode,vector<int>*adj,vector<int>&colour){
    colour[node]=colourOfNode;
    
    for(auto adjacentNode:adj[node]){
        if(colour[adjacentNode] == colourOfNode){
            return false;
        }
        else{
            if(colour[adjacentNode] == -1)
            {
                //colourOfNode^1 it will make 0 to 1 and 1 to 0
                if(dfsCheck(adjacentNode,colourOfNode^1,adj,colour) == false) return false;
            }
        }
    }
    return true;
}

//this is the main function to check
bool isBipartite(int V, vector<int>adj[]){
    vector<int>colour(V,-1);
    
    for(int node=0;node<V;node++){
        if(colour[node]==-1) {
            int initialColour=0;
            if(dfsCheck(node,initialColour,adj,colour) == false) return false;
        }
    }
    
    return true;
}

/*
Practice problem or application:
    Problem 1: https://leetcode.com/problems/possible-bipartition/

*/