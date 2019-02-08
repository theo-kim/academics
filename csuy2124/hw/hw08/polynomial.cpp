#include "polynomial.hpp"

Node::Node(int _data = 0, Node* _next = nullptr) : data(_data), next(_next) {}

// Constructors / Deconstructors
Polynomial::Polynomial() : degree(0), coefficients(new Node(0, nullptr)) {}

Polynomial::Polynomial(std::vector<int> _coefficients) 
: coefficients(nullptr), degree(_coefficients.size() - 1) {
	for (size_t i = 0; i < _coefficients.size(); ++i) {
		coefficients = new Node(_coefficients[i], coefficients);
	}
}

Polynomial::Polynomial(const Polynomial& original) 
: degree(original.degree) {
	Node* cursor = original.coefficients;
	Node* copyCursor = nullptr;
	coefficients = nullptr;
	for (int exp = 0; exp < degree + 1; ++exp) {
		if (coefficients == nullptr) {
			coefficients = new Node(cursor->data, nullptr);
			copyCursor = coefficients;
		}
		else {
			copyCursor->next = new Node(cursor->data, nullptr);
			copyCursor = copyCursor->next;
		}
		cursor = cursor->next;
	}	
}

Polynomial::~Polynomial() {
	Node* cursor = coefficients;
	Node* next = coefficients->next;
	while (cursor != nullptr) {
		next = cursor->next;
		delete cursor;
		cursor = next;
	}
}

// Functions
int Polynomial::evaluate(int x) const {
	Node* cursor = coefficients;
	int output = 0;
	for (int exp = 0; exp < degree + 1; ++exp) {
		int xVal = 1;
		for (int i = 0; i < exp; ++i) {
			xVal *= x;
		}
		output += cursor->data * xVal;
		cursor = cursor->next;
	}
	return output;
}



// Operators
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
	Node* cursor = p.coefficients;
	for (int exp = 0; exp < p.degree + 1; ++exp) {
		if (cursor->data != 0) {
			if (cursor->data != 1 || exp == 0) {
				if (cursor->data == -1) {
					os << '-';
				} else {
					os << cursor->data;
				}
			}
			if (exp != 0 && exp != 1) {
				os << "x^" << exp;
			}
			else if (exp == 1) {
				os << "x";
			}
			if (cursor->next != nullptr && cursor->next->data > 0) {
				os << "+";
			}
		}
		cursor = cursor->next;
	}
	if (p.degree == 0 && p.coefficients->data == 0) {
		os << 0;
	}
	return os;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	Node* cursor = coefficients;
	Node* next = coefficients->next;
	while (cursor != nullptr) {
		next = cursor->next;
		delete cursor;
		cursor = next;
	}
	degree = rhs.degree;
	cursor = rhs.coefficients;
	coefficients = nullptr;
	for (int exp = 0; exp < rhs.degree + 1; ++exp) {
		coefficients = new Node(cursor->data, coefficients);
		cursor = cursor->next;
	}
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	*this = *this + rhs;
	return *this;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
	if (lhs.degree == rhs.degree) {
		Node* leftCursor = lhs.coefficients;
		Node* rightCursor = rhs.coefficients;
		for (int exp = 0; exp < lhs.degree + 1; ++exp) {
			if (leftCursor->data != rightCursor-> data) {
				return false;
			}
			leftCursor = leftCursor->next;
			rightCursor = rightCursor->next;
		}
	}
	return false;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
	return !(lhs == rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial output;
	int degree = 0;
	Node* leftCursor = lhs.coefficients;
	Node* rightCursor = rhs.coefficients;
	Node* outputCursor = nullptr;

	if (lhs.degree > rhs.degree) degree = lhs.degree;
	else degree = rhs.degree;

	output.degree = degree;

	for (int i = 0; i < degree + 1; ++i) {
		int co = 0;
		if (leftCursor == nullptr) {
			co = rightCursor->data;
			rightCursor = rightCursor->next;
		}
		else if (rightCursor == nullptr) {
			co = leftCursor->data;
			leftCursor = leftCursor->next;
		}
		else {
			co = leftCursor->data + rightCursor->data;
			leftCursor = leftCursor->next;
			rightCursor = rightCursor->next;
		}
		if (i == 0) {
			output.coefficients->data = co;
			outputCursor = output.coefficients;
		}
		else {
			outputCursor->next = new Node(co, nullptr);
			outputCursor = outputCursor->next;
		}
	}

	return output;
}