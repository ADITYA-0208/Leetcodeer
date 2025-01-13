class Solution {
public:
    bool isvalid(const string& s, unordered_set<string>& deadendsSet, unordered_set<string>& visited) {
        if (deadendsSet.find(s) != deadendsSet.end() || visited.find(s) != visited.end()) {
            return false;
        }
        return true;
    }

    bool result1(const string& s, const string& target) {
        return s == target;
    }

    char rightturn(char c) {
        return (c == '9' ? '0' : c + 1);
    }

    char leftturn(char c) {
        return (c == '0' ? '9' : c - 1);
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        if (deadendsSet.find("0000") != deadendsSet.end()) return -1;
        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [top, k] = q.front();
            q.pop();

            if (result1(top, target)) return k;

            for (int i = 0; i < 4; i++) {
                string copy = top;
                copy[i] = rightturn(top[i]);
                if (isvalid(copy, deadendsSet, visited)) {
                    visited.insert(copy);
                    q.push({copy, k + 1});
                }
                copy[i] = leftturn(top[i]);
                if (isvalid(copy, deadendsSet, visited)) {
                    visited.insert(copy);
                    q.push({copy, k + 1});
                }
            }
        }
        return -1;
    }
};
