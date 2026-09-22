class Solution {
    boolean f(int start, String s, Set<String> dict,int[]dp){
        if(start==s.length()){
            return true;
        }
        if (dp[start] != -1) {
            return dp[start] == 1;
        }
        for(int i=start;i<s.length();i++){
            String word = s.substring(start,i+1);
            if(dict.contains(word)){
                if (f(i + 1, s, dict,dp)) 
                {
                    dp[start] = 1;
                    return true;
                }
            }
        }

        dp[start]=0;
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>(wordDict);
        int []dp = new int [s.length()];
        Arrays.fill(dp, -1);
        return f(0, s, dict,dp);
    }
}
