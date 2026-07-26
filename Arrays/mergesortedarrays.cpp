class Solution {
public:
void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
      }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //brute force TC=O(N+M) SC=O(N+M)
        vector<int> arr3(m + n);
        int left = 0, right = 0, index = 0;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                arr3[index++] = nums1[left++];
            }
            else{
                arr3[index++] = nums2[right++];
            }
        }
        while(left < m){
            arr3[index++] = nums1[left++];
        }
        while(right < n){
            arr3[index++] = nums2[right++];
        }
        for(int i = 0; i < m + n; i++){
            nums1[i] = arr3[i];
        }
       // optimal solution 1 TC->O(min(n,m))+O(nlogn)+O(mlogm) SC-> O(1)
        int left = m - 1;
        int right = 0;
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        //optimal solution 2 shell sort TC->log(n+m)xO(n+m)
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // nums1 and nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // nums2 and nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // nums1 and nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
        //most optimal solution using 3 pointers TC->O(m+n) SC->O(1)
        int i = m - 1;       // Last valid element in nums1
        int j = n - 1;       // Last element in nums2
        int k = m + n - 1;   // Last position in nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
        // Copy remaining elements of nums2
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        }
};
