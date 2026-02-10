class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        while(left<n)
        {
            if(nums[left]==val)
            {
                nums[left] = nums[n-1];
                n--;
            }
            else
            {
                left++;
            }
        }
        return n;
        
    }
};
