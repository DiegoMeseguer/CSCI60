#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool find(vector<string> v, string find);
int count(vector<string> v, string target);

int main() {
	
	ifstream input01, input02;
	ofstream output01, output02;
	vector<string> words;
	vector<string> wordsUnique;
	vector<int> wordsCount;
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

	for(auto w : wordsUnique){
		wordsCount.push_back(count(words, w));
	}

	vector<string>::iterator i1;
	vector<int>::iterator i2;
	for(i1 = wordsUnique.begin(), i2 = wordsCount.begin();
		i1 != wordsUnique.end(); i1++, i2++){

		output01<<(*i1)<<"\t"<<(*i2)<<endl;
	}

	vector<string> palabras;
	vector<string> palabrasUnicas;
	vector<int> palabrasContadas;

	string add;
	while(input02>>add){
		palabras.push_back(add);
	}

	for(auto p : palabras){
		if(!(find(palabrasUnicas, p)))
			palabrasUnicas.push_back(p);
	}

	sort(palabrasUnicas.begin(), palabrasUnicas.end());

	for(auto p : palabrasUnicas){
		palabrasContadas.push_back(count(palabras, p));
	}

	vector<string>::iterator j1;
	vector<int>::iterator j2;
	for(j1 = palabrasUnicas.begin(), j2 = palabrasContadas.begin();
		j1 != palabrasUnicas.end(); j1++, j2++){

		output02<<(*j1)<<"\t"<<(*j2)<<endl;
	}

	input01.close();
	output01.close();
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

int count(vector<string> v, string target){
	int count = 0;

	for(auto a : v){
		if(a == target)
			count++;
	}
	return count;
}
