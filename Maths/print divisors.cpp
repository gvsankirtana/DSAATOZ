class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> a;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                a.push_back(i);
                if((n/i)!=i) {
                a.push_back(n/i);
                }
            }
        }
        sort(a.begin(), a.end());
        return a;
    }
};
