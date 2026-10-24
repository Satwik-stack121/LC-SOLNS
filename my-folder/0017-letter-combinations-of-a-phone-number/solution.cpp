class Solution {
public:
    vector<string> lookup = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> ans;
    int n;

    void solve(string digits, vector<string> parts, int index) {

        if(index == n) {
            string temp;

            for(auto &i : parts)
                temp += i;

            ans.push_back(temp);
            return;
        }

        string letters = lookup[digits[index] - '0'];

        for(auto &j : letters) {
            parts.push_back(string(1, j));

            solve(digits, parts, index + 1);

            parts.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        vector<string> parts;

        n = digits.size();

        solve(digits, parts, 0);

        return ans;
    }
};
