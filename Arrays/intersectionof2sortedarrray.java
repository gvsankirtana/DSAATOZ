class Solution {
    public int[] intersectionArray(int[] nums1, int[] nums2) {
      //brute force
      //use a visited array to if visited then add 1 and loop n1 and n2 and 
      //check for each n1 if n2 exists and check if not visited then add to interested array
      //optimised solution TC->O(n1+n2) sc->o(1)
        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        int n1 = nums1.length, n2 = nums2.length;
        
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                // nums1[i] == nums2[j] → common element found
                if (result.size() == 0 || result.get(result.size() - 1) != nums1[i]) {
                    result.add(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        int[] intersectArr = new int[result.size()];
        for (int k = 0; k < result.size(); k++) {
            intersectArr[k] = result.get(k);
        }
        return intersectArr;
    }
}
