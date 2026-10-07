class Solution {
private:
    int m, n;
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int color) {
        if (r<0||r>=m||c<0||c>=n||image[r][c] != originalColor) return;
        image[r][c] = color;
        dfs(image, r + 1, c, originalColor, color);
        dfs(image, r - 1, c, originalColor, color);
        dfs(image, r, c + 1, originalColor, color);
        dfs(image, r, c - 1, originalColor, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
