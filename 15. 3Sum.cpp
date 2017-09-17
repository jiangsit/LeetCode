#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
	
	vector< vector<int> > result;
	
	sort(nums.begin(),nums.end());
	
	int n = nums.size();
	for(int i=0;i<n-2;i++){
		if(i>0 && nums[i-1]==nums[i])
			continue;
		int a = nums[i];
		int low = i+1;
		int high = n-1;
		while(low < high){
			int b = nums[low];
			int c = nums[high];
			if(a+b+c==0){
				vector<int> v;
				v.push_back(a);
				v.push_back(b);
				v.push_back(c);
				result.push_back(v);
				while(low<n-1 && nums[low]==nums[low+1]) low++;//跳过重复的数字 
				while(high>0 && nums[high]==nums[high-1]) high--;
				low++;
				high--;
			} 
			else if(a+b+c>0){
				while(high>0 && nums[high]==nums[high-1]) high--;
				high--;
			}
			else if(a+b+c<0){
				while(low<n-1 && nums[low]==nums[low+1]) low++;
				low++;
			}
		}
	}
	return result;  
}

void printMatrix(vector<vector<int> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
    cout << endl;
}

int main(){
	  int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    vector< vector<int> > result = threeSum(n);
    printMatrix(result); 
	  return 0;
}
