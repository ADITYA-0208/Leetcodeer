class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size(), len2 = num2.size();
        vector<int> product(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;

                int sum = mul + product[pos2];
                product[pos2] = sum % 10;
                product[pos1] += sum / 10;
            }
        }

        string result;
        for (int digit : product) {
            if (!(result.empty() && digit == 0))
                result += (digit + '0');
        }

        return result.empty() ? "0" : result;
    }
};
