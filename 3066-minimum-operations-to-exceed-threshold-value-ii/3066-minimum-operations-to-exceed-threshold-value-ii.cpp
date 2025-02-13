class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int counts= 0;

        while (pq.top() < k) {
            if (pq.size() < 2) return -1; // If not enough elements, return failure

            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            int new_val = min(x, y) * 2 + max(x, y);
            pq.push(new_val);
            counts++;
    }

    return counts;
    }
};