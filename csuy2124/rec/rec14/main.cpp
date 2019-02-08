#include <iostream>
#include <climits>
using namespace std;

// Write a function to determine if a non-negative integer has an even number of ones in its binary representation. Return true if it does and false otherwise.
bool evenBits(int input) {
	if (input == 0) return true; 
	if (input == 1) return false;
	int next = input / 2;
	int result = (input % 2) + (next % 2);
	if (result != 1) return true == evenBits(next / 2);
	else return false == evenBits(next / 2);
}

bool f(unsigned n) {
	return n == 0 ? 1 : (n & 1) ^ f(n >> 1);
}

// Write a function to create and return a new list that is the sum of the values in the the two lists passed in. You may assume that the two lists are the same length. (By a list, I mean a Node*, not an instance of a list class.)
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {} 
	int data;
	Node* next;
};
Node* addLists (Node* first, Node* second) {
	if (first == nullptr && second == nullptr) return nullptr;
	return new Node(first->data + second->data, addLists(first->next, second->next));
}

// Write a function to return the maximum of the values in a binary tree. Use the attached code. Note, there is a constant INT_MIN defined in the include file <climits> that is the value of the smallest possible int. This could make your life easier.
struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  if (root == nullptr) return 0;
  else {
  	int leftMax = max(root->left);
  	int rightMax = max(root->right);
  	if (leftMax > root->data) {
  		if (leftMax > rightMax) return leftMax;
  		else return rightMax;
  	}
  	else return root->data;
  }
}

//Implement a function palindrome. It will be passed an array Note that when an array is passed to a function, only the address of the first element is passed. So, what your function is really being passed is the starting point of the array and how many characters there are. Of course, to use it you can just pass in the name of the array, as the name is equivalent to its address.
bool palindrome (char* s, int length) {
	if (length <= 1) return true;
	if (*s == *(s + (length - 1))) return true && palindrome(s + 1, length - 2);
	else return false;
}

// Implement the function to solve the towers of hanoi problem. However, your function should not print anything. Instead it should just return the number of moves needed.
int towers(int rings, char start, char helper, char end) {
	if (rings == 1) return 1;
  	return towers(rings - 1, start, end, helper) + towers(rings - 1, helper, start, end) + 1;
}

int main() {
	// Test first function
	for (int i = 1; i < 11; ++i) cout << i << ": " << evenBits(i) << endl;
	
	// Test second function
	Node* list = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	Node* listTwo = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	Node* sum = addLists(list, listTwo);
	Node* cursor = sum;
	while (cursor != nullptr) {
		cout << cursor->data << ", ";
		cursor = cursor->next;
	}
	cout << "\n";

	// Test third code
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;

	// Test fourth code
	char s[] = "kayak";
	if (palindrome(s, 5)) { cout << "Yes!\n"; }

	// Test fifth code
	cout << "Number of moves:" << towers(5, 'a', 'b', 'c') << endl;
	cout << "it should be: " << 31;
}