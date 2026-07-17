class Solution{	
	public:
    int printsum(int i,int sum){
        if(i<1){
            return 0;
        }
        return printsum(i-1,sum+i);
    }
	int NnumbersSum(int N){
			//your code goes here
            return printsum(N,0);   
		}
};
