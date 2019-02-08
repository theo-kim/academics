#ifndef POLYNOMIAL_H

#define POLYNOMIAL_H

#include <iostream>
#include <vector>

struct Node {
    Node(int data, Node* next);
    int data;
    Node* next;
};

class Polynomial {
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	Polynomial();
	Polynomial(std::vector<int> _coefficients);
	Polynomial(const Polynomial& original);
	~Polynomial();

	int evaluate(int x) const;

	Polynomial& operator=(const Polynomial& rhs);
	Polynomial& operator+=(const Polynomial& rhs);
private:
	int degree;
	Node* coefficients;
};

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

#endif