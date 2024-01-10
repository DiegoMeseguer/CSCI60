#include <iostream>
#include <vector>

using namespace std;

struct Folder{    
	string name; 
	string* files;    
	int nfiles;    
	Folder* folders;    
	int nfolders;
};

void print(Folder f);

int main(){
	string hws[] = {"hw1.txt", "hw2.txt", "hw3.txt"};    
	Folder f1 = {"Folder1", hws, 3, nullptr, 0};    
	Folder f2 = {"Empty", nullptr, 0, nullptr, 0};    
	Folder fs[2] = {f1, f2};    
	string tests[] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt"};    
	Folder f3 = {"Folder3", tests, 4, fs, 2};    
	print(f3);    
	return 0;
}

void print(Folder f){
	cout<<f.name<<endl; 
	if(f.nfiles>0) 
		cout<<f.name<<"'s files: "; 
	for(int i=0; i<f.nfiles; i++)     
	cout<<f.files[i]<<" "; 
	cout<<endl; 

	//Go through all of f's folders, and print out their stuff too.  
	if(f.nfolders>0) 
		cout<<f.name<<"'s folders: "<<endl;
	for(int i=0; i<f.nfolders; i++){
		print(f.folders[i]);
	}
}
