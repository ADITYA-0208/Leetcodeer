class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                ans.push_back(i);
            }
        }
        
        if (ans.size() < 2) return {-1, -1};

        int diff = INT_MAX, x = -1, y = -1;
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] - ans[i - 1] < diff) {
                diff = ans[i] - ans[i - 1];
                x = ans[i - 1];
                y = ans[i];
            }
        }
        return {x, y};
    }

private:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
};
