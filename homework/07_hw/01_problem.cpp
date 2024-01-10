#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool find(vector<string> v, string find);

int main() {
	
	ifstream input01, input02;
	ofstream output01, output02;
	vector<string> words;
	vector<string> wordsUnique;
	input01.open("gentle.txt");
	input02.open("quijote.txt");
	output01.open("output01.txt");
	output02.open("output02.txt");

	string temp;
	while(input01>>temp){
		words.push_back(temp);
	}

	for(auto w : words){
		if(!(find(wordsUnique, w)))
			wordsUnique.push_back(w);
	}

	sort(wordsUnique.begin(), wordsUnique.end());

	for(auto w : wordsUnique)
		output01<<w<<endl;

	input01.close();
	output01.close();

	vector<string> palabras;
	vector<string> palabrasUnicas;

	string add;
	while(input02>>add){
		palabras.push_back(add);
	}

	for(auto p : palabras){
		if(!(find(palabrasUnicas, p)))
			palabrasUnicas.push_back(p);
	}

	sort(palabrasUnicas.begin(), palabrasUnicas.end());

	for(auto p : palabrasUnicas)
		output02<<p<<endl;

	input02.close();
	output02.close();

	return 0;
}

bool find(vector<string> v, string find){
	for(auto a : v){
		if(find==a)
			return true;
	}
	return false;
}
