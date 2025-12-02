class Solution {
public:
    void helper(vector<vector<int>>& adjl, int V, vector<bool>& visited, vector<bool>& inStack, vector<bool>& safe, bool& unsafe){
        inStack[V] = true;
        visited[V] = true;
        for(int neigh: adjl[V]){
            if(!visited[neigh]){
                if(unsafe) safe[V] = false;
                unsafe = false;
                helper(adjl, neigh, visited, inStack, safe, unsafe);
            }    
            else if(inStack[neigh]){
                safe[neigh] = false;
                unsafe = true;
            }
            else if(!safe[neigh]) unsafe = true;
        }
        if(!safe[V]) unsafe = true;
        if(unsafe) safe[V] = false;
        inStack[V] = false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> safe(V, true);
        bool unsafe = false;
        vector<bool> visited(V, false);
        vector<bool> inStack(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                unsafe = false;
                helper(graph, i, visited, inStack, safe, unsafe);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};