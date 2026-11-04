class Solution {
public:
    int bfs (int node, unordered_map<int, vector<int>>& adj, int d, int n){
        queue<pair<int, int>>q;
        q.push({node, 0});
        vector<bool>visited(n, false);
        visited[node] = true;

        int count = 0;

        while(!q.empty()){
            int curr = q.front().first;
            int dist = q.front().second;

            q.pop();

            if(dist > d){
                continue;
            }

            count++;

            for(auto & nghbr : adj[curr]){
                if(visited[nghbr] == false){
                    visited[nghbr] = true;
                    q.push({nghbr, dist+1});
                }
            }
        }

        return count;
    }
    vector<int> findCount(vector<vector<int>>& edges, int d){
        int n = edges.size()+1;

        unordered_map<int, vector<int>> adjList;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>result(n);
        for(int i = 0 ; i < result.size(); i++){
            result[i] = bfs(i, adjList, d, n);
        }

        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<int>result1 = findCount(edges1, k);
        vector<int>result2 = findCount(edges2, k-1);

        int maxInTree2 = *max_element(begin(result2), end(result2));

        for(int i = 0; i < result1.size(); i++){
            result1[i] += maxInTree2;
        }

        return result1;
    }
};