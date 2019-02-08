#include "List.hpp"

namespace Lister {
	List::List()
		: head(new Node(0, nullptr, nullptr)), tail(new Node(0, nullptr, nullptr)), length(0) {
			head->next = tail;
			tail->prev = head;
		}

	List::List(const List& original) : length(0) {
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, nullptr, head);
		head->next = tail;
		Node* cursor = original.head->next;
		while (cursor != original.tail) {
			push_back(cursor->data);
			cursor = cursor->next;
		}
	}

	List::~List() {
		clear();
	}

	void List::push_back(int data) {
		Node* temp = new Node(data, tail, tail->prev);
		tail->prev->next = temp;
		tail->prev = temp;
		++length;
	}

	void List::pop_back() {
		 Node* temp = tail->prev;
		 tail->prev = temp->prev;
		 temp->prev->next = tail;
		 delete temp;
		 --length;
	}

	void List::push_front(int data) {
		Node* temp = new Node(data, head->next, head);
		head->next = temp;
		temp->next->prev = temp;
		++length;
	}

	void List::pop_front() {
		 Node* temp = head->next;
		 head->next = temp->next;
		 temp->next->prev = head;
		 delete temp;
		 --length;
	}

	int List::front() {
		if (length > 0) {
			return head->next->data;
		}
		exit(1);
	}

	int List::back() {
		if (length > 0) {
			return tail->prev->data;
		}
		exit(1);
	}

	int List::size() {
		return length;
	}

	void List::clear() {
		while (length > 0) {
			pop_back();
		}
	}

	List::Iterator List::begin() { return Iterator(head->next); }
  	List::Iterator List::end() { return Iterator(tail); }

  	List::Iterator List::insert(List::Iterator i, int data) {
  		Node* temp = new Node(data, i.cursor, i.cursor->prev);
  		i.cursor->prev->next = temp;
  		i.cursor->prev = temp;

  		++length;

  		return Iterator(temp);
  	}

  	List::Iterator List::erase(List::Iterator i) {
  		Node* temp = i.cursor;
  		Iterator output(temp->next);
  		temp->prev->next = temp->next;
  		temp->next->prev = temp->prev;

  		delete temp;

  		--length;

  		return output;
  	}


	List::Node::Node(int data = 0, Node* next = nullptr, Node* prev = nullptr)
		: data(data), next(next), prev(prev) {}	

	std::ostream& operator<<(std::ostream& os, const List& l) {
		List::Node* cursor = l.head->next;
		os << '[';
		for (int i = 0; i < l.length; ++i) {
			os << cursor->data << ", ";
			cursor = cursor->next;
		}
		os << ']';
		return os;
	}

	List& List::operator=(const List& rhs) {
		clear();
		Node* cursor = rhs.head->next;
		while (cursor != rhs.tail) {
			push_back(cursor->data);
			cursor = cursor->next;
		}
		return *this;
	}

	int& List::operator[] (int index) {
		Node* cursor = head->next;
		for (int i = 0; i < index + 1; ++i) {
			cursor = cursor->next;
		}
		return cursor->data;
	}

	List::Iterator::Iterator(Node* cursor = nullptr) : cursor(cursor) {};

	List::Iterator& List::Iterator::operator++() {
		cursor = cursor->next;
		return *this;
	}

	List::Iterator& List::Iterator::operator--() {
		cursor = cursor->prev;
		return *this;
	}

	int List::Iterator::operator*() const {
		return cursor->data;
	}

	bool operator==(const List::Iterator& lhs, const List::Iterator& rhs) {
		return lhs.cursor == rhs.cursor;
	}

	bool operator!=(const List::Iterator& lhs, const List::Iterator& rhs) {
		return !(lhs == rhs);
	}
}
