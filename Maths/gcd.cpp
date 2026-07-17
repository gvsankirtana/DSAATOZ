class Solution {
public:
    int GCD(int n1,int n2) {
        //brute force TC --> O(min(n1,n2))
        int gcd = 0;
        for(int i=1;i<=min(n1,n2);i++){
            if(n1%i==0&&n2%i==0){
                gcd=i;
            }
        }
        return gcd;
        //optimised solution 1 TC --> O(min(n1,n2))
        for(int i=min(n1,n2);i>=0;i--){
            if(n%i==0&&n2%i==0){
                break;
            }
        }
        return i;
        //optimised solution euclidean algo
        while(n1>0&&n2>0){
            if(n1>n2) n1=n1%n2;
            else n2=n2%n1;
        }
        if(a==0) return b;
        else return a;
    }
};
