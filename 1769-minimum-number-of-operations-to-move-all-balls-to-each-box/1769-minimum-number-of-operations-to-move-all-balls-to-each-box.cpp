class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        vector<int> vec;
        int sum = 0, k = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                sum += i;
                k++;
                vec.push_back(i);
            }
        }
        for (int i = 0; i < boxes.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                ans[i] += abs(vec[j] - i);
            }
        }
        return ans;
    }
};
