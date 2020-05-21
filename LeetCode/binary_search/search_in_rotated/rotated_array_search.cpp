// 33. Search in Rotated Sorted Array - LeetCode
#include <bits/stdc++.h>
using namespace std;

void In_Out(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void display(std::vector<int> v){
	cout<<" [";
    for(auto item:v){
        cout<<" "<<item<<" ";
    }
    cout<<"] "<<endl;
}

int search(vector<int>& nums, int target){
	int first, mid, last;
	first = 0;
	last = nums.size() - 1;
	while(first <= last){
		mid = (first + last)/2;
		if(target == nums[mid]){
			return mid;
		}else if(nums[first] < nums[mid]){ // check for left sorted
			if(nums[first] <= target && target <= nums[mid]){
				// element found in left sorted half
				last = mid - 1;
			}else{
				first = mid + 1;
			}
		}else if(nums[mid] < nums[last]){ // check for right sorted
			if(nums[mid] <= target && target <= nums[last]){
				// element found in right sorted half
				first = mid + 1;
			}else{
				last = mid - 1;
			}
		}else if(first == mid && last == mid + 1){ // if we have only 2 elements
			if(nums[mid] == target){
				return mid;
			}else if(nums[mid+1] == target){
                return mid + 1;
            }else return -1;
		}else return -1;
	}
	return -1;
}

int main(){

	In_Out();

	size_t size;
	cin>>size;
	std::vector<int> nums(size);         
	for(size_t i = 0; i < size; i++){
		cin>>nums[i];
	}
	int target;
	cin>>target;

	int search_index = search(nums, target);
	cout<<search_index;
}


// Example - 
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1