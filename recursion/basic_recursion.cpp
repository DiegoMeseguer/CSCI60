#include <iostream>
using namespace std;

int poder(int a, int n);
int factorial(int a);
int mult(int a, int b);
int fib(int f);
//a_(n)=2a_(n-1)+4, a_0 =5
int seq(int n);
double seq2(int n);
// a_(n) = (1/2.0)^n
int count(int arr[], int size, int find);
int maxi(int arr[], int size);

void binary(int length, string start);



int main() {
	int base(3), exp(4);
	int base2(5), exp2(3);

	cout<<"Poder"<<endl;
	cout<<poder(base, exp)<<endl;
	cout<<poder(base2, exp2)<<endl;

	cout<<"Factorial"<<endl;
	cout<<factorial(5)<<endl;
	cout<<factorial(4)<<endl;

	int factor01(5), factor02(4);
	int factor03(7), factor04(11);
	cout<<"Mult"<<endl;
	cout<<mult(factor01, factor02)<<endl;
	cout<<mult(factor03, factor04)<<endl;

	cout<<"Fib"<<endl;
	cout<<fib(8)<<endl;
	cout<<fib(5)<<endl;
	cout<<fib(9)<<endl;

	cout<<"Seq"<<endl;
	cout<<seq(3)<<endl;
	cout<<seq(1)<<endl;
	cout<<seq(4)<<endl;

	cout<<"Seq2"<<endl;
	cout<<seq2(5)<<endl;	
	cout<<seq2(4)<<endl;
	cout<<seq2(1)<<endl;

	cout<<"Recursion with array - find & count"<<endl;
	int a[] = {1, 3, 6, 1, 1, 3};
	int b[] = {1, 7, 6, 1, 7, 3, 5, 7, 7};
	cout<<count(a, 6, 1)<<endl;
	cout<<count(b, 9, 7)<<endl;

	cout<<"Recursion with array - find max"<<endl;
	int c[] = {3, 5, 12, 943, 1094, 20999, 3, 32, 43, 1004};
	cout<<maxi(a, 6)<<endl;
	cout<<maxi(b, 9)<<endl;
	cout<<maxi(c, 10)<<endl;



	string buba = "";
	binary(6, buba);

	return 0;
}

int poder(int a, int n){
	if(n==0)
		return 1;
	else
		return(a * poder(a, n-1));
}

int factorial(int a){
	if(a==0)
		return 1;
	else
		return(a * factorial(a-1));
}

int mult(int a, int b){
	if(b==0)
		return 0;
	else
		return(a + mult(a, b-1));
}

int fib(int f){
	if(f==1)
		return 1;
	else if(f==2)
		return 1;
	else
		return(fib(f-1)+fib(f-2));
}

int seq(int n){
	if(n==0)
		return 5;
	else
		return((2*seq(n-1))+4);
}

double seq2(int n){
	if(n==0)
		return 1;
	else
		return((1/2.0)*(seq2(n-1)));
}

int count(int arr[], int size, int find){
	if(size==0)
		return 0;
	else{
		if(arr[size-1]==find)
			return(1 + count(arr, size-1, find));
		else
			return(count(arr, size-1, find));
	}
}

int maxi(int arr[], int size){
	if(size==1)
		return arr[0];
	else{
		if(arr[size-1] >= maxi(arr, size-1))
			return(arr[size-1]);
		else
			return(maxi(arr, size-1));
	}
}




void binary(int length, string start) {



	//Base Case
	if(length==0){
		cout<<start<<endl;

	}
	else{

		// start.push_back('0');
		binary(length-1, start + '0');
		// start.push_back('1');
		binary(length-1, start + '1');
	}

}















