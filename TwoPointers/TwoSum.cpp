class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> myVector;
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            int sum = numbers[i]+numbers[j];

            if(sum<target)
            {
                i++;
            }
            else if(sum>target)
            {
                j--;
            }
            else
            {
                myVector.push_back(i+1);
                myVector.push_back(j+1);
                return myVector;
            }
        }
        myVector.push_back(-1);
        myVector.push_back(-1);
        return myVector;
    }
};
