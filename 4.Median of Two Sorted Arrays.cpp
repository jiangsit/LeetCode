//找到两个数组中第k大的元素，二分法
double findKth(int a[], int m, int b[], int n, int k)  
{  
    //always assume that m is equal or smaller than n  
    if (m > n)  
        return findKth(b, n, a, m, k);  
    if (m == 0)  
        return b[k - 1];  
    if (k == 1)  
        return min(a[0], b[0]);  
    //divide k into two parts  
    int pa = min(k / 2, m), pb = k - pa;  
    if (a[pa - 1] < b[pb - 1])  
        return findKth(a + pa, m - pa, b, n, k - pa);  
    else if (a[pa - 1] > b[pb - 1])  
        return findKth(a, m, b + pb, n - pb, k - pb);  
    else  
        return a[pa - 1];  
}  
  
class Solution  
{  
public:  
    double findMedianSortedArrays(int A[], int m, int B[], int n)  
    {  
        int total = m + n;  
        if (total & 0x1)  
            return findKth(A, m, B, n, total / 2 + 1);  
        else  
            return (findKth(A, m, B, n, total / 2)  
                    + findKth(A, m, B, n, total / 2 + 1)) / 2;  
    }  
};  
/*//暴力解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int m=nums1.size();
        int n=nums2.size();
        vector<int> nums;
        for(int i=0;i<m;i++){
            nums.push_back(nums1[i]);
        }
        for(int j=0;j<n;j++){
            nums.push_back(nums2[j]);
        }
        sort(nums.begin(),nums.end());
        if((m+n)&0x1)
            res=(double)nums[(m+n)/2];
        else
            res=(double)(nums[(m+n)/2-1]+nums[(m+n)/2])/2.0;
        return res;
    }
};
*/
