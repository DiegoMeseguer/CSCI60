#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Algorithms
void bubble_sort_v1(int arr[], size_t size);
void selection_sort_v1(int arr[], size_t size);
void insertion_sort_v1(int arr[], size_t size);

//Utility Functions
void swap(int & a, int & b);
void print(int arr[], int brr[]);
void print_finish(int arr[], int brr[]);
void setup(int arr[], int brr[]);

const int EVEN_SIZE = 10;
const int ODD_SIZE = 11;

int main() {
	srand(time(0));

	int evenArray[EVEN_SIZE];
	int oddArray[ODD_SIZE];

	cout<<"==selection_sort_v1==\n";
	setup(evenArray, oddArray);
	print(evenArray, oddArray);
	selection_sort_v1(evenArray, EVEN_SIZE);
	selection_sort_v1(oddArray, ODD_SIZE);
	print_finish(evenArray, oddArray);
	cout<<endl;

	cout<<"==bubble_sort_v1==\n";
	setup(evenArray, oddArray);
	print(evenArray, oddArray);
	bubble_sort_v1(evenArray, EVEN_SIZE);
	bubble_sort_v1(oddArray, ODD_SIZE);
	print_finish(evenArray, oddArray);
	cout<<endl;

	cout<<"==insertion_sort_v1==\n";
	setup(evenArray, oddArray);
	print(evenArray, oddArray);
	insertion_sort_v1(evenArray, EVEN_SIZE);
	insertion_sort_v1(oddArray, ODD_SIZE);
	print_finish(evenArray, oddArray);
	cout<<endl;

	return 0;
}

//SORTING FUNCTIONS

//Here the i and j iterate over the array in the same direction.
//Also, apparently we only need to keep track of the index.
void selection_sort_v1(int arr[], size_t size) {
	size_t indexMin;

	if(size == 0)
		return;	//To avoid assigning a negative to a size_t.

	for (size_t i = 0; i < size - 1; ++i) {
		indexMin = i;

		for (size_t j = i + 1; j < size; ++j) {
			if(arr[j] < arr[indexMin])
				indexMin = j;
		}
		
		swap(arr[i], arr[indexMin]);
	}
}

void bubble_sort_v1(int arr[], size_t size) {
	int counter = -1; // Give counter a value diff than 0 so the algorithm starts

	for (int k = 0; k < size; ++k) {
		if (counter == 0)   //if counter is 0 then not a single swap was made							
			return;         //and array is sorted

		counter = 0;
		for (int i = 0, j = i + 1; j < size; ++i, ++j) {
			if (arr[i] >  arr[j]) {
				swap(arr[i], arr[j]);
				counter++;
			}
		}
	}
}

void insertion_sort_v1(int arr[], size_t size) {
	int temp;	//We store the value to be inserted here.
	size_t hole;	//This is to keep track of the index where
			//the insertion shall ocurr, since this index
			//may float as we compare the sorted elements
			//of the array with temp.

	for (int i = 1; i < size; ++i) {
		temp = arr[i];	//Set temp to be the first element of the unsorted part.
		hole = i;	//If the unsorted element is already sorted, then we just
				//assign it to itself.

		while(hole > 0 && arr[hole - 1] > temp)	{
			arr[hole] = arr[hole - 1];
			hole--;
		}

		arr[hole] = temp;	//We saved the value to be inserted in a temp
					//variable, since we may have had to move up
					//the elements before it in order to find the
					//correct spot to insert. Now it's time to insert
					//the unsorted element in its rightful place. If
					//everything was already sorted, then hole should have
					//the same value as i for this iteration of the for
					//loop.
	}
}

//MISC FUNCTIONS

void swap(int & a, int & b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void setup(int arr[], int brr[]) {
	for (int i = 0; i < EVEN_SIZE; ++i)
		arr[i] = ((rand() % 50) + 1);

	for (int j = 0; j < ODD_SIZE; ++j)
		brr[j] = ((rand() % 50) + 1);
}

void print(int arr[], int brr[]) {
	for (int i = 0; i < EVEN_SIZE; ++i) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for (int j = 0; j < ODD_SIZE; ++j) {
		cout<<brr[j]<<" ";
	}
	cout<<endl;
}

void print_finish(int arr[], int brr[]) {
	cout<<"Sorted Even Array\n";
	for (int i = 0; i < EVEN_SIZE; ++i) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Sorted Odd Array\n";
	for (int j = 0; j < ODD_SIZE; ++j) {
		cout<<brr[j]<<" ";
	}
	cout<<endl;
}


// CRAP STARTS HERE

// void merge_sort(int data[], size_t n) {
// 	size_t n1;	//Size of the first subarray.
// 	size_t n2;	//Size of the second subarray.

// 	//The Base Case is implicit
// 	if (n > 1) {
// 		n1 = n / 2;	//Compute sizes of the subarrays.
// 		n2 = n - n1;	//We can see that n2 will be either
// 				//equal to n1 or n1 + 1.

// 		//The two subarrays are sorted with recursive calls.
// 		merge_sort(data, n1);	//Sort from data[0] through data[n1-1].
// 		merge_sort((data + n1), n2);	//Sort from data[n1] to the end.

// 		merge(data, n1, n2);	//Merge the two sorted halves.
	
// }


// void meme(int data[], size_t startIndex, size_t endIndex) {

//     int temp;
//     size_t hole;

//     for (int i = startIndex + 1; i <= endIndex; ++i) {
//         temp = data[i];
//         hole = i;

//         while(hole > 0 && data[hole - 1] > temp) {
//             data[hole] = data[hole - 1];
//             hole--;
//         }

//         data[hole] = temp;
//     }
 
// }

// void selection_sort(node * head) {
//     int minValue;

//     for (node * p = head; (p->link())->link() != NULL ; p = p->link()) {
//         minValue = p->data();

//         for (node * q = p->link(); q->link() != NULL; q = q->link()) {
            
//             if(q->data() < minValue)
//                 minValue = q->data();
//                 q->data() = p->data();
//         }

//         swap(p->data(), minValue);
//     }
// }

// void selection_sort_v1(int arr[], size_t size) {
// 	size_t indexMax;
// 	int max;

// 	if (size == 0)
// 		return; //To avoid assigning a negative to a size_t.

// 	for (size_t i = size - 1; i > 0; --i) {
// 		max = arr[0];
// 		indexMax = 0;

// 		for (size_t j = 1; j <= i; ++j) {
// 			if (arr[j] > max) {
// 				max = arr[j];
// 				indexMax = j;
// 			}
// 		}

// 		swap(arr[i], arr[indexMax]);
// 	}
// }

