class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        double nums[n];
        int id1 = 0, id2 = 0;
        int index = 0;
        while(id1 < n1 && id2 < n2){
            if(nums1[id1] < nums2[id2]){
                nums[index++] = nums1[id1++];
            }
            else{
                nums[index++] = nums2[id2++];
            }
        }

        if(id1 < n1){
            for(;id1 < n1; id1++)
                nums[index++] = nums1[id1];
        }
        if(id2 < n2){
            for(;id2 < n2; id2++)
                nums[index++] = nums2[id2];
        }

        double res;
        if(n % 2 == 0)
            res = (nums[n/2] + nums[n/2 - 1]) / 2;
        else
            res = nums[n/2];
        return res;
    }
};