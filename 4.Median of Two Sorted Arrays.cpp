/*  对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1] , 
    若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    1.如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    2.反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    3.如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
*/
class Solution {  
public:  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {  
        // write your code here  
        int len1=nums1.size();  
        int len2=nums2.size();  
        int len=len1+len2;  
        if(len & 1){  
            return findKth(nums1,0,nums2,0,len/2+1);  
        }  
        return (findKth(nums1,0,nums2,0,len/2)+findKth(nums1,0,nums2,0,len/2+1))/2;  
    }  
  
    double findKth(vector<int>& nums1,int i1,vector<int>& nums2,int i2,int k){  
        if(i1>=nums1.size()){  
            return nums2[i2+k-1];  
        }  
        if(i2>=nums2.size()){  
            return nums1[i1+k-1];  
        }  
        if(k==1){  
            return min(nums1[i1],nums2[i2]);  
        }  
  
        int key1=i1+k/2-1>=nums1.size()?INT_MAX:nums1[i1+k/2-1];  
        int key2=i2+k/2-1>=nums2.size()?INT_MAX:nums2[i2+k/2-1];  
        if(key1<key2){  
            return findKth(nums1,i1+k/2,nums2,i2,k-k/2);  
        }else{  
            return findKth(nums1,i1,nums2,i2+k/2,k-k/2);  
        }  
    }  
  
}; 
/*
归并计数法: Merge and Count
复杂度:
    时间O(n) 空间O(1)
思路:
    如果对时间复杂度没有要求，这个方法是实现起来最简单的，我们只需要从下往上依次数(n+m)/2个元素即可。
    由于两个数组都已经排序，我们可以使用两个指针指向数组“底部”，通过比较两个数组“底部”的元素大小来决定
    计哪一个元素，同时将其所在数组的指针“向上”移一位。为了方便处理总元素为偶数的情况，
    这里将找中位数变成找第k小的元素。
注意：
    计数的循环是用来找到第k-1个元素的，最后return的时候再判断第k个元素是哪一个
    在每次计数的循环中要先判断两个数组指针是否超界，在最后return之前也要判断一次
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        if(total % 2==0){
            return (findKth(nums1,nums2,total/2)+findKth(nums1,nums2,total/2+1))/2.0;
        } else {
            return findKth(nums1,nums2,total/2+1);
        }
    }
    int findKth(vector<int>& nums1, vector<int>& nums2, int k){
        int p = 0, q = 0;//p计数nums1,q计数nums2;
        for(int i = 0; i < k - 1; i++){
            if(p>=nums1.size() && q<nums2.size()){
                q++;
            } else if(q>=nums2.size() && p<nums1.size()){
                p++;
            } else if(nums1[p]>nums2[q]){
                q++;
            } else {
                p++;
            }
        }
        if(p>=nums1.size()) {
            return nums2[q];
        } else if(q>=nums2.size()) {
            return nums1[p];
        } else {
            return min(nums1[p],nums2[q]);
        }
    }
};

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
}; 

//暴力解法
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

