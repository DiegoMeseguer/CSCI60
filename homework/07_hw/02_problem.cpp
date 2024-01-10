#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
	
	ifstream input01, input02;
	ofstream output01, output02;
	set<string> words;
	input01.open("gentle.txt");
	input02.open("quijote.txt");
	output01.open("output01.txt");
	output02.open("output02.txt");

	string temp;
	while(input01>>temp){
		words.insert(temp);
	}

	for(auto w : words)
		output01<<w<<endl;

	set<string> palabras;

	string add;
	while(input02>>add){
		palabras.insert(add);
	}

	for(auto p : palabras)
		output02<<p<<endl;

	input01.close();
	output01.close();
	input02.close();
	output02.close();

	return 0;
}
