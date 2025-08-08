class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int scaled = (n + 24) / 25;
        vector<vector<double>> dp(scaled + 1, vector<double>(scaled + 1, -1.0));
        dp[scaled][scaled] = calProb(scaled, scaled, dp);

        return dp[scaled][scaled];
    }

    double calProb(int typeA, int typeB,  vector<vector<double>>& dp) {
        if (typeA <= 0 && typeB <= 0) return 0.5;
        else if (typeA <= 0) return 1.0;
        else if (typeB <= 0) return 0.0;
        
        if (dp[typeA][typeB] != -1) return dp[typeA][typeB];

        dp[typeA][typeB] = 0.25 * ( calProb(typeA - 4, typeB, dp) + 
                                    calProb(typeA - 3, typeB - 1, dp) +
                                    calProb(typeA - 2, typeB - 2, dp) +
                                    calProb(typeA - 1, typeB - 3, dp));

        return dp[typeA][typeB];
    }
};