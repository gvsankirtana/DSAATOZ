class Node {
    int key;
    int value;
    Node prev;
    Node next;

    Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
class LRUCache {
   
    int capacity;
    HashMap<Integer, Node> map;
    Node head;
    Node tail;
    public LRUCache(int capacity) {
    this.capacity = capacity;
    map = new HashMap<>();
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head.next = tail;
    tail.prev = head;
    }
    void delNode(Node node){
        Node prevnode = node.prev;
        Node afternode = node.next;
        prevnode.next = afternode;
        afternode.prev = prevnode;
    }
    void insertNode(Node node){
        Node currAfterhead = head.next;
        node.next = currAfterhead;
        node.prev = head;
        currAfterhead.prev = node;
        head.next = node;
    }
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }
        Node node = map.get(key);
        delNode(node);
        insertNode(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);
            node.value = value;
            delNode(node);
            insertNode(node);
        }
        else{
            Node node = new Node(key, value);
            map.put(key, node);
            insertNode(node);
            if(map.size()>capacity){
                Node lru = tail.prev;
                map.remove(lru.key);
                delNode(lru);
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
