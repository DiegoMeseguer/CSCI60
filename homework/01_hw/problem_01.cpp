#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

const int SIZE = 499;

void writeletter(string names[], int size, char letter, ostream& out);
void writename(string names[], int size, ostream& out);

int main() {
	
	ifstream inStream;
	ofstream outStream;
	int counter(0);
	string arr[SIZE];

	inStream.open("names.txt");
	if(inStream.fail()) {
		cout<<"names.txt file opening failed.\n";
		exit(1); 
	}

	outStream.open("sorted_names.txt");
	if(outStream.fail()) {
		cout<<"sorted_names.txt file opening failed.\n";
		exit(1); 
	}

	while(inStream>>arr[counter]) {
		counter++;
	}

	inStream.close();

	writename(arr, counter, outStream);

	outStream.close();

	return 0;
}

void writeletter(string names[], int size, char letter, ostream& out) {

	for(int i = 0; i < size; i++) {
		if(tolower(names[i][0]) == letter)
			out<<names[i]<<endl;
	}
}

void writename(string names[], int size, ostream& out) {

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for(int i = 0; i < alphabet.length(); i++) {
		writeletter(names, size, alphabet[i], out);
	}
}
