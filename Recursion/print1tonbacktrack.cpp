class Solution {
  public:
  void printnback(int i,int n){
      if(i<1)return;
      printnback(i-1,n);
      cout<<i<<endl;
  }
    void printNumbers(int n) {
         printnback(n,n);
    }
};
