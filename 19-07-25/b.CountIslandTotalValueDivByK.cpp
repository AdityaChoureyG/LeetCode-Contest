#define ll long long

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;

    bool valid(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]==0)  return 0;
        return 1;
    }

    ll dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        ll sum = grid[i][j];
        
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            // cout<<ni<<'a'<<nj<<endl;

            if(valid(ni, nj, grid, vis)){
                vis[ni][nj] = 1;
                sum += dfs(ni, nj, grid, vis);
            }
        }

        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m=grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                    vis[i][j] = 1;
                    int sum = dfs(i, j, grid, vis);
                    // cout<<i<<' '<<j<<" "<<sum<<endl;
                    if(sum%k==0) cnt++;
                }
            }
        }

        return cnt;
    }
};