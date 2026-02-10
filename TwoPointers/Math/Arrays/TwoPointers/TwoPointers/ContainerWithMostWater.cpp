class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int minHt,width,water,maxWater=0;
        while(left<right)
        {
            minHt = min(height[left],height[right]);
            width = right-left;
            water = width*minHt;
            maxWater = max(maxWater,water);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;
        
    }
};
