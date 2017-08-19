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

