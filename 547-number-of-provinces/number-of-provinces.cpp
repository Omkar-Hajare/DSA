class Solution {
private:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) {
            return node;
        }
 
        parent[node] = findParent(parent[node], parent);
 
        return parent[node];
    }
 
    bool unite(int u, int v, vector<int>& parent, vector<int>& size) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
 
        if (pu == pv) {
            return false;
        }
 
        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }
 
        parent[pv] = pu;
 
        size[pu] += size[pv];
 
        return true;
    }
 
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> size(n, 1);
        int provinces = n;
 
        for (int city = 0; city < n; city++) {
            parent[city] = city;
        }
 
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                if (isConnected[row][col] == 1 && unite(row, col, parent, size)) {
                    provinces--;
                }
            }
        }
         return provinces;
    }
};