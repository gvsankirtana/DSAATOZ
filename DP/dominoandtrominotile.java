class Solution {
    public int numTilings(int n) {
        int md = 1_000_000_007;
        ArrayList <Long> v = new ArrayList<>(1001);
        for (int i = 0; i <= 1000; i++) {
            v.add(0L);
        }
        v.set(1, 1L);
        v.set(2, 2L);
        v.set(3, 5L);
        if(n<=3) return v.get(n).intValue();
        for(int i=4;i<=n;i++){
            v.set(i, (2 * v.get(i - 1) + v.get(i - 3)) % md);
        }
        return v.get(n).intValue();
    }
}
