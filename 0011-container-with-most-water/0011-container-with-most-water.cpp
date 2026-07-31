class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int maxheight=min(height[left],height[right]);
            water=max(water,maxheight*(right-left));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return water;
    }
};