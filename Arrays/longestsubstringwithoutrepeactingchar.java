class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < 256; i++) {
          map.put((char) i, -1);
        }
        int l=0,r=0,maxlen=0;
        int n = s.length();
        while(r<n){
            char a = s.charAt(r);
            if(map.get(a)!=-1){
            if(map.get(a)>=l){
               l = map.get(a)+1;
            }
            }
            int len = r-l+1;
            maxlen = Math.max(len,maxlen);
            map.put(a,r);
            r++;
        }
        return maxlen;
    }
}
