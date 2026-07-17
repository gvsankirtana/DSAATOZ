class Solution {
public:
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
    int factorial(int n) {
        return fact(n);
    }
};
//tc--> O(N)
//SC-->O(N)
