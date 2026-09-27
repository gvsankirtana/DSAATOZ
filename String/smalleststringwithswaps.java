
class Solution {

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {

        char[] str = s.toCharArray();

        Map<Integer, PriorityQueue<Character>> map = new HashMap<>();

        UnionFind uf = new UnionFind(str.length);

        // 1. Connect all indices that can be swapped
        for (List<Integer> pair : pairs) {
            uf.unify(pair.get(0), pair.get(1));
        }

        // 2. Group characters by their connected component
        for (int i = 0; i < str.length; i++) {

            int parentId = uf.getAbsoluteParent(i);

            PriorityQueue<Character> pq =
                    map.getOrDefault(parentId, new PriorityQueue<>());

            pq.offer(str[i]);

            map.put(parentId, pq);
        }

        // 3. Put the smallest available character
        // at each index in the component
        for (int i = 0; i < str.length; i++) {

            int parentId = uf.getAbsoluteParent(i);

            str[i] = map.get(parentId).poll();
        }

        return new String(str);
    }


    // ---------------- UNION FIND ----------------

    class UnionFind {

        int[] parent;
        int[] rank;

        UnionFind(int n) {

            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int getAbsoluteParent(int x) {

            if (parent[x] == x) {
                return x;
            }

            // Path compression
            parent[x] = getAbsoluteParent(parent[x]);

            return parent[x];
        }

        void unify(int x, int y) {

            int parentX = getAbsoluteParent(x);
            int parentY = getAbsoluteParent(y);

            if (parentX == parentY) {
                return;
            }

            // Union by rank
            if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } 
            else if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } 
            else {
                parent[parentY] = parentX;
                rank[parentX]++;
            }
        }
    }
}
