#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream inFile("in.txt", ios::in);
	if(!inFile){
		cout << "Open file error!" <<endl;
		return 0;
	}
	char ch;
	while(inFile.get(ch)){
		switch(ch){
			case '\n':{
				  cout<<endl;
				  break;
				  }
			default:{
				cout << ch;
				break;
				}
		}
	}
	inFile.close();
	return 0;
}
