class Solution {
public:
bool ispal(int i,string s,int n){
    if(i>=n/2)return true;
    if(s[i]!=s[n-i-1]) return false;
    return ispal(i+1,s,n);
}
    bool isPalindrome(string s) {
        string clean;
        // for (char c : s) {
        //     if (isalnum(c)) 
        //         clean += tolower(c);
        // }
        int n= s.length();
        return ispal(0,s,n);
    }
};
