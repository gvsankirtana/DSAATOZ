class Solution {
  public:
  int printn(int i,int n){
        if(i<=0) return 0;
        cout<<i<<endl;
        printn(i-1,n);
        return i;
    }
    void printNumbers(int n) {
        // Your code goes here
        int i=n;
        printn(i,n);
    }
};
