class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> map1;
        int maxsum = -1;
        for (auto num : nums) {
            int sum = 0, num1 = num;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            if (map1.find(sum) != map1.end()) {
                maxsum = max(maxsum, num1 + map1[sum]);
            }
            map1[sum] = max(map1[sum], num1);
        }
        return maxsum;
    }
};