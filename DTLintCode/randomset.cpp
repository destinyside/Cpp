#include<iostream>
#include<unordered_set>
#include<ctime>
using namespace std;
class RandomizedSet {
	unordered_set<int> set;
public:

	RandomizedSet() {
		// do intialization if necessary
		set.clear();
	}

	/*
	* @param val: a value to the set
	* @return: true if the set did not already contain the specified element or false
	*/
	bool insert(int val) {
		// write your code here
		set.insert(val);
		return true;
	}

	/*
	* @param val: a value from the set
	* @return: true if the set contained the specified element or false
	*/
	bool remove(int val) {
		// write your code here
		set.erase(val);
		return true;
	}

	/*
	* @return: Get a random element from the set
	*/
	int getRandom() {
		// write your code here
		cout << set.size() << endl;
		srand((unsigned)clock()); 
		int p = rand()%set.size();
		cout << p << endl;
		for (int n : set) {
			if (p == 0) {
				return n;
			}
			p--;
		}
	}
};
//int main() {
//	RandomizedSet s;
//	s.insert(2);
//	s.insert(1);
//	s.insert(3);
//	s.insert(4);
//	s.insert(6);
//	s.insert(5);
//	cout << s.getRandom() << endl;
//	cout << s.getRandom() << endl;
//	cout << s.getRandom() << endl;
//	cout << s.getRandom() << endl;
//	cout << s.getRandom() << endl; 
//	cout << s.getRandom() << endl;
//}