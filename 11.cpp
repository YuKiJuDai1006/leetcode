class Solution {
public:
    int maxArea(vector<int>& height) {
        int res;
        int n = height.size();
        int li = 0, ri = n-1;
        while(li < ri){
            if(height[li] < height[ri]){
                res = max(res, V(li, height[li], ri, height[ri]));
                li++;
            }
            if(height[li] >= height[ri]){
                res = max(res, V(li, height[li], ri, height[ri]));
                ri--;
            }
        }
        return res;
    }

    int V(int i1, int h1, int i2, int h2){
        int len = i2 - i1;
        int hei = min(h1, h2);
        return len * hei;
    }
};