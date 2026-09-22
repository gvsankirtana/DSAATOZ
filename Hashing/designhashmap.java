class MyHashMap {
     private static final int BUCKETS = 1000;
     private LinkedList<int[]>[] buckets;
    public MyHashMap() {
        buckets = new LinkedList[BUCKETS];
        for(int i=0;i<BUCKETS;i++){
            buckets[i] = new LinkedList<>();
        }
    }
    
    private int hash(int key){
        return key%BUCKETS;
    }
    public void put(int key, int value) {
        int idx = hash(key);
        for(int[]pair:buckets[idx]){
            if(pair[0]==key){
                pair[1]=value;
                return;
            }
        }
        buckets[idx].add(new int[]{key,value});
    }
    
    public int get(int key) {
        int idx = hash(key);
        for(int[] pair: buckets[idx]){
            if (pair[0]==key) return pair[1];
        }
        return -1;
    }
    
    public void remove(int key) {
        int idx = hash(key);
        Iterator<int[]> it = buckets[idx].iterator();
        while(it.hasNext()){
            if(it.next()[0]==key){
                it.remove();
                return ;
            }
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
