class Solution {
    public int trap(int[] height) {
        //brute force time complexity O(3N) SC->O(2N)
        int n = height.length;
        int[] prefixmax = new int[n];
        int[] suffixmax = new int[n];
        prefixmax[0] = height[0];
        for(int i=1;i<n;i++){
            prefixmax[i] = Math.max(prefixmax[i-1],height[i]);
        } 
        suffixmax[n-1] = height[n-1];
        for(int i=n-2;i>0;i--){
           suffixmax[i] = Math.max(suffixmax[i+1],height[i]);
        }
        int total = 0;
        for(int i=0;i<n;i++){
        int leftmax = prefixmax[i], rightmax = suffixmax[i];
        if(height[i]<leftmax&&height[i]<rightmax){
            total+= Math.min(leftmax,rightmax) - height[i];
        }
        }
        return total;
        //optimal solution TC->O(N) SC->O(1)
        int n = height.length;
        int total = 0;
        int l = 0, r = n-1;
        int leftmax=0,rightmax=0;
        while(l<r){
            if(height[l]<=height[r]){
               if(leftmax>height[l]){
                total+=leftmax-height[l];
               }
               else{
                leftmax = height[l];
               }
               l++;
            }
            else{
              if(rightmax>height[r]){
                total+=rightmax-height[r];
               }
               else{
                rightmax = height[r];
               }
              r--;
            }
        }
        return total;
    }
}
