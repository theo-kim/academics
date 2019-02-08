#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void iterate(T start, T end) {
	for (T s = start; s != end; ++s) {
		cout << *s << ' ';
	}
}


int gcd (int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main () {
	list<int> myList({1, 2, 3, 4});
	vector<int> myVector({6, 3, 4, 5});

	iterate(myList.begin(), myList.end());
	cout << endl;
	iterate(myVector.begin(), myVector.end());
	cout << endl;
	cout << "gcd(48, 10)" << gcd(48, 10) << endl;
}
