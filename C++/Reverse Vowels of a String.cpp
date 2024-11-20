class Solution {
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        
        while(left<right)
        {
            while(left<n && !isVowel(s[left]))
            {
                left++;
            }
            
            while(right>=0 && !isVowel(s[right]))
            {
                right--;
            }
            
            if(left<right)
            {
                swap(s[left++],s[right--]);
            }
        }
        return s;
    }
};
