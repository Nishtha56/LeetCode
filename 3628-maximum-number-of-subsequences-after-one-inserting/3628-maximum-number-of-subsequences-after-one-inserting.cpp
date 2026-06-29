class Solution {
public:
    long long countLCT(string &s) {
        long long L = 0, LC = 0, LCT = 0;

        for (char ch : s) {
            if (ch == 'L')
                L++;
            else if (ch == 'C')
                LC += L;
            else if (ch == 'T')
                LCT += LC;
        }

        return LCT;
    }

    void buildPrefix(string &s, vector<long long> &preL, vector<long long> &preLC) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            preL[i + 1] = preL[i];
            preLC[i + 1] = preLC[i];

            if (s[i] == 'L')
                preL[i + 1]++;
            else if (s[i] == 'C')
                preLC[i + 1] += preL[i];
        }
    }

    void buildSuffix(string &s, vector<long long> &postT, vector<long long> &postCT) {
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            postT[i] = postT[i + 1];
            postCT[i] = postCT[i + 1];

            if (s[i] == 'T')
                postT[i]++;
            else if (s[i] == 'C')
                postCT[i] += postT[i + 1];
        }
    }

    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<long long> preL(n + 1, 0), preLC(n + 1, 0);
        vector<long long> postT(n + 1, 0), postCT(n + 1, 0);

        buildPrefix(s, preL, preLC);
        buildSuffix(s, postT, postCT);

        long long original = countLCT(s);
        long long ans = original;

        for (int i = 0; i <= n; i++) {
            // Insert 'L'
            ans = max(ans, original + postCT[i]);

            // Insert 'C'
            ans = max(ans, original + preL[i] * postT[i]);

            // Insert 'T'
            ans = max(ans, original + preLC[i]);
        }

        return ans;
    }
};