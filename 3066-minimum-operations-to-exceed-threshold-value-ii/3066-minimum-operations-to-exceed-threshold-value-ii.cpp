class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int counts= 0;

        while (pq.top() < k) {
            if (pq.size() < 2) return -1; // If not enough elements, return failure

            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            long long nx = min(x, y) * 2LL+ max(x, y);
            pq.push(nx);
            counts++;
    }

    return counts;
    }
};