class Solution {
    public int maxArea(int[] height) {
        //brute force method O(n^2) 
        // int max = 0;
        // for(int i=0;i<height.length;i++){
        //     for(int j=i+1;j<height.length;j++){
        //           int w = j-i;
        //           int h = Math.min(height[i],height[j]);
        //           int area = w*h;
        //           max = Math.max(max,area);
        //     }
        // }
        // return max;
        //optimal solution O(n)
        int l = 0;
        int r = height.length-1;
        int max = 0;
        while(l<=r){
           int w = Math.abs(l-r);
           int h = Math.min(height[l],height[r]);
           int area = w*h;
           max = Math.max(max,area);
           if(height[l]<height[r]){
            l++;
           }
           else{
            r--;
           }
        }
     return max;
    }
}
