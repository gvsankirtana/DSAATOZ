class Solution {
public:
    bool isPalindrome(int x) {
        long revnum=0;
        if(x<0) return false;
        int y=x;
        while(y>0){
            int ld=y%10;
            revnum=(revnum*10)+ld;
            y=y/10;
        }
        if(x==revnum)return true;
        else return false;
    }
};
