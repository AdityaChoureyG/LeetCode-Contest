#define pi pair<int, int>

class Solution {

    void dfs(int node, vector<vector<pi>>& adj, vector<int>& vis, int& mid){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it.first] && it.second<=mid){
                dfs(it.first, adj, vis, mid);
            }
        }
    }

    int f(vector<vector<pi>>& adj, int mid, int n){
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis, mid);
            }
        }

        return cnt;
    }
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pi>> adj(n);
        for(auto it : edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int ans = 1e6, lo=0, hi=1e6;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int comp = f(adj, mid, n);

            if(comp <= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};