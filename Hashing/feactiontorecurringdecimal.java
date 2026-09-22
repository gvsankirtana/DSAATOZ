class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        int n = numerator, d = denominator;
        StringBuilder ans = new StringBuilder();
        if(n==0&&d==0) {
            ans.append("0");
            return ans.toString();
        }
        if(((n<0)&&(d>0))||((n>0)&&(d<0))){
            ans.append("-");
        }
        long a = Math.abs((long) n);
        long b = Math.abs((long) d);
        long remainder = a%b;
        ans.append(a/b);
        if(remainder==0){
          return ans.toString();
        }
        ans.append(".");
        HashMap <Long,Integer> map = new HashMap<>();
        while(remainder!=0){
            if(map.containsKey(remainder)){
                int pos = map.get(remainder);
                ans.insert(pos,"(");
                ans.append(")");
                break;
            }
            map.put(remainder,ans.length());
            ans.append(remainder*10/b);
            remainder = remainder*10 % b;
        }
      return ans.toString();
    }
}
