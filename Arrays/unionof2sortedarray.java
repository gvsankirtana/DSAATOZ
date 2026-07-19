class Solution {
    public int[] unionArray(int[] nums1, int[] nums2) {
        //brute force TC->2(n1+n2)(logn) sc->o(n1+n2)+o(n1+n2)
        // Set<Integer> st = new TreeSet<>();
        // for(int i=0;i<nums1.length;i++){
        //     st.add(nums1[i]);
        // }
        // for(int j=0;j<nums2.length;j++){
        //     st.add(nums2[j]);
        // }
        // int[] unionArr = new int[st.size()];
        // int i=0;
        // for(int it:st){
        //     unionArr[i]=it;
        //     i++;
        // }
        // return unionArr;
        //optimised solution TC->O(n1+n2) SC->O(n1+n2) 2 pointer approach
        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        int n1 = nums1.length, n2 = nums2.length;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                if (result.size() == 0 || result.get(result.size() - 1) != nums1[i]) {
                    result.add(nums1[i]);
                }
                i++;
            } else {
                if (result.size() == 0 || result.get(result.size() - 1) != nums2[j]) {
                    result.add(nums2[j]);
                }
                j++;
            }
        }
        while (i < n1) {
            if (result.size() == 0 || result.get(result.size() - 1) != nums1[i]) {
                result.add(nums1[i]);
            }
            i++;
        }
        while (j < n2) {
            if (result.size() == 0 || result.get(result.size() - 1) != nums2[j]) {
                result.add(nums2[j]);
            }
            j++;
        }
        
        int[] unionArr = new int[result.size()];
        for (int k = 0; k < result.size(); k++) {
            unionArr[k] = result.get(k);
        }
        return unionArr;
    }
}
