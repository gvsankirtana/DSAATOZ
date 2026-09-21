class Solution {
    public int firstUniqChar(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(!mp.containsKey(c)){
               q.add(i);
            }
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        while (!q.isEmpty() && mp.get(s.charAt(q.peek())) > 1) {
            q.poll(); 
        }
        if(q.isEmpty()) return -1;
        return q.peek();
    }
}
