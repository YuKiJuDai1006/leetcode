class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        while(x > 0 || y > 0){
            if(x%2 != y%2) ++diff;
            x /= 2;
            y /= 2;
        }
        return diff;
    }
};