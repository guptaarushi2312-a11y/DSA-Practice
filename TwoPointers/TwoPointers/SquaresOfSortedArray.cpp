class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        vector<int> result;
        int curr = n-1;
        while(left<=right)
        {
            int value;
            if(nums[left]*nums[left]>nums[right]*nums[right])
            {
                value = nums[left]*nums[left];
                result.insert(result.begin(),value);
                left++;
                curr--;

            }
            else
            {
                value = nums[right]*nums[right];
                result.insert(result.begin(),value);
                right--;
                curr;
            }
        }
        return result;


    }
};
