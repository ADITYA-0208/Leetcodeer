class Solution {
public:
    int find_set(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v], parent); // Path compression
    }

    void union_sets(int a, int b, vector<int>& parent) {
        int rootA = find_set(a, parent);
        int rootB = find_set(b, parent);
        if (rootA != rootB) {
            parent[rootA] = rootB; // Union
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Sort indices by values in nums
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // Union only elements within the limit range
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nums[indices[j]] - nums[indices[i]] <= limit) {
                union_sets(indices[i], indices[j], parent);
                j++;
            }
        }

        // Recompute parent for all elements
        for (int i = 0; i < n; i++) {
            parent[i] = find_set(i, parent);
        }

        // Group elements by their connected components
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find_set(i, parent)].push_back(i);
        }

        // Sort each group and assign values lexicographically
        for (auto& group : groups) {
            vector<int> indices = group.second;
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            for (int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = values[k];
            }
        }

        return nums;
    }
};
