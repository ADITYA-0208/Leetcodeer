class Solution {

public:
    long long subArrayRanges(vector<int>& nums) {
        return abs(sumSubarrayMins(nums));
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse1(n), psee1(n);
        nse(nse1, arr);
        psee(psee1, arr);

        long long total = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long right = nse1[i] - i;
            long long left = i - psee1[i];
            total = (total + (right * left % MOD) * arr[i] % MOD) % MOD;
        }
        return total;
    }

    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge1(n), pgee1(n);
        nge(nge1, arr);
        pgee(pgee1, arr);

        long long total = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long right = nge1[i] - i;
            long long left = i - pgee1[i];
            total = (total + (right * left % MOD) * arr[i] % MOD) % MOD;
        }
        return total;
    }

    void nse(vector<int>& nse, vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            nse[i] = n;
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }

    void psee(vector<int>& psee, vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            psee[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                psee[i] = st.top();
            }
            st.push(i);
        }
    }

    void nge(vector<int>& nge, vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            nge[i] = n;
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
    }

    void pgee(vector<int>& pgee, vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pgee[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pgee[i] = st.top();
            }
            st.push(i);
        }
    }
};

