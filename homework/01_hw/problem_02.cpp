#include <iostream>
#include <string>
using namespace std;

const int SIZE = 49;
const int POPULATION = 7;

struct Animal
{
	string name;
	string gender;
	int age;
	double price;
	string type;
};

Animal cheapest(string type, Animal a[], int size);
bool livetogether(Animal a, Animal b);

int main() {
	
	Animal shelter[SIZE] = {
		{"Bobby", "Male", 12, 199.99, "Dog"},
		{"Betty", "Female", 4, 350, "Cat"},
		{"Alf", "Male", 6, 230, "Dog"},
		{"Alfred", "Male", 2, 500, "Cat"},
		{"Elsa", "Female", 4, 110, "Cat"},
		{"Bufford", "Male", 10, 120, "Dog"},
		{"Marinette", "Female", 4, 480.20, "Cat"}
	};
	Animal dog_inexpensive = cheapest("Dog", shelter, POPULATION);
	Animal cat_inexpensive = cheapest("Cat", shelter, POPULATION);

	cout<<dog_inexpensive.name<<endl;
	cout<<cat_inexpensive.name<<endl;

	cout<<livetogether(shelter[0], shelter[2])<<endl;
	cout<<livetogether(shelter[2], shelter[4])<<endl;

	return 0;

}

Animal cheapest(string type, Animal a[], int size) {

	int min, index;

	for(int i = 0; i < size; i++) {
		if(a[i].type == type) {
			min = a[i].price;
			index = i;
			break;
		}
	}
	
	for(int i = 0; i < size; i++) {
		if(a[i].price < min && a[i].type == type) 
			index = i;
	}

	return a[index];
}

bool livetogether(Animal a, Animal b) {

	return(a.type == b.type);
}
