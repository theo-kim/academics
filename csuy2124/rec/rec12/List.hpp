#ifndef LIST_HPP

#define LIST_HPP

#include <iostream>

namespace Lister {
	class List {
		friend std::ostream& operator<< (std::ostream& os, const List& l);
	public:
		struct Node {
			Node(int data, Node* next, Node* prev);
			int data;
			Node* next;
			Node* prev;
		};

		class Iterator {
			friend class List;
			friend boziaool operator==(const Iterator& lhs, const Iterator& rhs);
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs);
		public:
			explicit Iterator(Node* cursor);
			Iterator& operator++();
			Iterator& operator--();

			int operator*() const;
		private:
			Node* cursor;
		};

		List();
		List(const List& original);
		~List();
		
		void push_back(int data);
		void pop_back();
		void push_front(int data);
		void pop_front();

		int front();
		int back();

		int size();
		void clear();

		int& operator[] (int index);
		List& operator=(const List& rhs);

		Iterator insert(Iterator i, int data);
		Iterator erase(Iterator i);

		Iterator begin();
		Iterator end();
	private:
		Node* head;
		Node* tail;
		int length;
	};
}

#endif