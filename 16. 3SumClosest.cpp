#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	
	int result;
	int distance=INT_MAX;
	int sum=0;
	sort(nums.begin(),nums.end());
	
	int n = nums.size();
	for(int i=0; i< n-2; i++){
		if (i>0 && nums[i-1]==nums[i]) continue;
		int a=nums[i];
		int low=i+1;
		int high=n-1;
		while(low<high){
			sum=a+nums[low]+nums[high];
			if(sum==target){
				return sum;
			}
			else{
				if(abs(sum-target)<distance){
					distance = abs(sum - target);
                    result = sum;	
				}
				if(sum<target){
					while(low<n && nums[low]==nums[low+1]) low++;
					low++;
				}
				if(sum>target){
					while(high>0 && nums[high]==nums[high-1]) high--;
					high--;
				}
			}		
		}
	}
	return result;
}



int main(){
	  int a[] = {-1,2,1,-4};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    int target=1;
    int result = threeSumClosest(n,target);
    cout<<result;
	  return 0;
}
