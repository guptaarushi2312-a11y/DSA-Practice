class Solution {
public:
    bool isVowel(char c)
    {
        char s=tolower(c);
        return s=='a'||s=='e'||s=='i'||s=='o'||s=='u';
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length()-1;
        while(left<right)
        {
            while(left<right && !isVowel(s[left]))
            {
                left++;
            }
            while(left<right && !isVowel(s[right]))
            {
                right--;
            }
            swap(s[left],s[right]);

        }
        return s;
    
    }
};
