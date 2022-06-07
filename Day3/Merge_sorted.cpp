class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,k=0;
        for(i=m;i<nums1.size();i++){
            nums1[i]=nums2[k];
            k++;
        }
           sort(nums1.begin(),nums1.end());
    }
};
