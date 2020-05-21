#include <bits/stdc++.h>
using namespace std;
void display(std::vector<int> v);
int get_pivot(std::vector<int> v);

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
// Hint - 
// as we have a sorted and rotated array after applying binary search the array is divied in 2 parts
//  left and right and evry time only one of these 2 sides is going to be sorted and the other
//  will be unsorted everytime...and our element will always be present in the unsorted part be-
// cause of the array being sorted-rotated.
//  if arr[mid] >= last ---- right side is unsorted
//  if arr[mid] <= first ---- left side is unsorted
// Edge cases -- it is possible that the sorted-rotated array is divided into both sorted parts 
//  unlike the above 2 cases, so -
// edge case 1 - when the mid element is greater than both its nearest neighbour elements
// edge case 2 - when the mid element is smaller than both its nearest neighbour elements

int get_pivot(std::vector<int> v){
	int first, last, mid;
	first = 0;
	last = v.size() - 1;
	while(first <= last){
		mid = (first + last)/2;
		if(v[mid] < v[mid-1] && v[mid] < v[mid+1]){  // edge case-2
			return mid-1;
		}else if(v[mid] > v[mid-1] && v[mid] > v[mid+1]){  // edge case-1
			return mid;
		}else if(v[mid] >= last){  // right unsorted
			first = mid + 1;
		}else { // left unsorted
			last = mid - 1;
		}
	}
}

int main(){
	In_Out();

	size_t size;
	cin>>size;
	std::vector<int> v(size);         
	for(size_t i = 0; i < size; i++){
		cin>>v[i];
	}
	
	int pivot_index = get_pivot(v);
	cout<<pivot_index;
	
}