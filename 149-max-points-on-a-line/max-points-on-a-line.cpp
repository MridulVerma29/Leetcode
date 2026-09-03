class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slope;
            int duplicates = 0;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                // Duplicate point
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                // Reduce the fraction
                int g = gcd(abs(dy), abs(dx));

                dy /= g;
                dx /= g;

                // Keep only one representation
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                // Vertical line
                if (dx == 0)
                    dy = 1;

                slope[{dy, dx}]++;
                best = max(best, slope[{dy, dx}]);
            }

            ans = max(ans, best + duplicates + 1);
        }

        return ans;
    }
};