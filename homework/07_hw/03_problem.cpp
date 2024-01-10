#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	
	ifstream input;
	map<int, pair<int, vector<string>>> histogram;
	string temp;
	int score, scoreGiven;
	int max_score(0), frequency(0);
	char ans;
	input.open("scorename.txt");

	while(getline(input, temp)){
		score = stoi(temp.substr(0, temp.find(" ")));
		histogram[score].first++;
		histogram[score].second.push_back(temp.substr(temp.find(" ") + 1));
		if(score > max_score)
			max_score = score;
	}

	for(int i = 0; i <= max_score; i++){
		frequency = histogram[i].second.size();
		cout<<i;
		for(int i = 0; i < frequency; i++)
			cout<<"x";
		cout<<endl;
	}

	cout<<"Would you like to see the names of people who got"
		<<"a given score? (yes/no): ";
	cin>>ans;
	cin.ignore(1000, '\n');
	if(ans == 'y' || ans == 'Y'){
		do
		{
			cout<<"Please enter score: ";
			cin>>scoreGiven;
			for(int i = 0; i < histogram[scoreGiven].second.size(); i++){
				cout<<histogram[scoreGiven].second.at(i)<<endl;
			}
			cout<<"Would you like to see other names (yes/no): ";
			cin>>ans;
			cin.ignore(1000, '\n');
		} while(ans == 'y' || ans == 'Y');
	}

	return 0;
}
