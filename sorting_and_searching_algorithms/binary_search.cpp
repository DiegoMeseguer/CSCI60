#include <iostream>
#include <string>
using namespace std;

int binary_search(int arr[], int start, int end, int target);

int main() {
	
	int a[] = {1, 3, 6, 10, 14, 23, 25, 28, 30, 31, 37};
	// from index 0 to 10;

	cout<<binary_search(a, 0, 10, 25)<<endl;

	return 0;
}

int binary_search(int arr[], int start, int end, int target){
	int middle;
	if(start > end)
		return -1;
	else{
		middle = (start + end) / 2;
		if(target == arr[middle])
			return middle;
		else if(target > arr[middle]){
			start = middle + 1;
			return(binary_search(arr, start, end, target));
		}
		else{
			end = middle - 1;
			return(binary_search(arr, start, end, target));
		}
	}
}
