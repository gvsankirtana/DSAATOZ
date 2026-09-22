class Solution {
    public int getWinner(int[] arr, int k) {
      //brute force use queue to solve it
        int win=0;
        int champion = arr[0];
        for(int i=1;i<arr.length;i++){
            if(arr[i]>champion){
                champion = arr[i];
                win = 1;
            }
            else{
                win++;
            }
            if(win==k) return champion;
        }
        return champion;
    }
}
