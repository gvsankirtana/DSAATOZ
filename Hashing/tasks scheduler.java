class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        int maxfreq=0;
        int countmax=0;
        for (char task : tasks) {
           freq[task - 'A']++;
        }
        for(int f:freq){
            maxfreq = Math.max(maxfreq,f);
        }
        for(int f:freq){
            if(f==maxfreq) countmax++;
        }
        int formula = (maxfreq-1)*(n+1)+countmax;
        return Math.max(tasks.length,formula);
    }
}
