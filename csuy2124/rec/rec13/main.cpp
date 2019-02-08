// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

void printRanged(const vector<int>& vec);
void printRanged(const vector<string>& vec);
void printRanged(const list<int>& list);
void printIterator(const vector<int>& myVec);
void printIterator(const list<int>& myList);
void printEveryOther(const list<int>& myList);
void printEveryOther(const vector<int>& myVec);
void printEveryOtherAuto(const list<int>& myList);
void printEveryOtherAuto(const vector<int>& myVec);
list<int>::const_iterator findIt (const list<int>& haystack, int needle);
list<int>::const_iterator findAuto (const list<int>& haystack, int needle);
bool isEven(int i);
list<int>::iterator ourFind (list<int>::iterator start, list<int>::iterator end, auto needle);
template <typename t>
t ourFind (t start, t end, auto needle);


class MyFunctor {
public:
    bool operator () (int i) {
        return i % 2 == 0;
    }
};

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";

    vector<int> myVec({10, 23, 2, 8, 12, 98});
    printRanged(myVec);

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> myList(myVec.begin(), myVec.end());
    printRanged(myList);
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(myVec.begin(), myVec.end());
    printRanged(myVec);
    printRanged(myList);

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    cout << '[';
    for (size_t i = 0; i < myVec.size(); i+=2) {
        cout << myVec[i] << ' ';
    }
    cout << "]\n";

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    // cout << '[';
    // for (size_t i = 0; i < myList.size(); i+=2) {
    //     cout << myVec[i] << ' ';
    // }
    // cout << "]\n";    

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    printEveryOther(myVec);

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    printEveryOther(myList);

    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    myList.sort();
    printRanged(myList);

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printIterator(myList);

    cout << "\n=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printRanged(myList);

    cout << "\n=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printEveryOtherAuto(myList);

    cout << "\n=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << "Found it: " << *findIt(myList, 2);
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << "Found it auto: " << *findAuto(myList, 2);
    cout << "\n=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << "Found it with built in: " << *find(myList.begin(), myList.end(), 2);
    cout << "\n=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    cout << "Found even number using callback: " << *find_if(myList.begin(), myList.end(), isEven);
    cout << "\n=======\n";

    // 16a. Functor
    cout << "Task 16a:\n";
    cout << "Found even number using functor: " << *find_if(myList.begin(), myList.end(), MyFunctor());
    cout << "\n=======\n";
    
    // 16b. Lambda
    cout << "Task 16b:\n";
    cout << "Found even number using lambda: " << *find_if(myList.begin(), myList.end(), [](int i) -> bool { return i % 2 == 0; });
    cout << "\n=======\n";

    // 17. Generic algorithms: copy to an array
    cout << "Task 17:\n";
    int arr[myVec.size()];
    copy(myVec.begin(), myVec.end(), arr);
    for (int* i = arr; i < arr + myVec.size(); ++i) {
        cout << *i << ' ';
    }
    cout << "\nFound even number using callback: " << *find_if(arr, arr + myVec.size(), isEven);
    cout << "\nFound even number using functor: " << *find_if(arr, arr + myVec.size(), MyFunctor());
    cout << "\nFound even number using lambda: " << *find_if(arr, arr + myVec.size(), [](int i) -> bool { return i % 2 == 0; });
    
    cout << "\n=======\n";

    //
    // Templated Functions
    //

    // 18. Implement find as a function for lists
    cout << "Task 18:\n";
    cout << "\nFound even number using callback: " << *ourFind(myList.begin(), myList.end(), isEven);
    cout << "\nFound even number using functor: " << *ourFind(myList.begin(), myList.end(), MyFunctor());
    cout << "\nFound even number using lambda: " << *ourFind(myList.begin(), myList.end(), [](int i) -> bool { return i % 2 == 0; });
    cout << "\n=======\n";
    
    // 19. Implement find as a templated function
    cout << "Task 19:\n";
    cout << "\nFound even number using callback: " << *ourFind<vector<int>::iterator>(myVec.begin(), myVec.end(), isEven);
    cout << "\nFound even number using functor: " << *ourFind<vector<int>::iterator>(myVec.begin(), myVec.end(), MyFunctor());
    cout << "\nFound even number using lambda: " << *ourFind<vector<int>::iterator>(myVec.begin(), myVec.end(), [](int i) -> bool { return i % 2 == 0; });
    cout << "=======\n";

    //
    // Associative collections
    //

    // 20. Using a vector of strings, print a line showing 
    cout << "Task 20:\n";
    fstream ifs("pooh-nopunc.txt");
    string i;
    vector<string> seen;
    while(ifs >> i) {
        if (find(seen.begin(), seen.end(), i) == seen.end()) seen.push_back(i);
    } 
    cout << seen.size() << endl;
    //printRanged(seen);
    ifs.close();
    cout << "\n=======\n";

    // 21. Repeating previous step, but using the set
    cout << "Task 21:\n";
    fstream ifs2("pooh-nopunc.txt");
    string j;
    set<string> seenSet;
    while(ifs2 >> j) {
        seenSet.insert(j);
    } 
    cout << seenSet.size() << endl;
    ifs2.close();
    cout << "=======\n";

    // 22. Word co-occurence using map
    cout << "Task 22:\n";
    fstream ifs3("pooh-nopunc.txt");
    int index;
    string k;
    map<string, vector<int>> seenMap;
    while(ifs3 >> j) {
        seenMap[j].push_back(index);
        ++index;
    } 
    cout << seenMap.size() << endl;
    ifs3.close();
    cout << "=======\n";
}

void printRanged (const vector<int>& vec) {
    for (int i : vec) {
        cout << i << ' ';
    }
}

void printRanged (const list<int>& list) {
    for (int i : list) {
        cout << i << ' ';
    }
}

void printRanged (const vector<string>& list) {
    for (string i : list) {
        cout << i << ' ';
    }
}

void printIterator (const vector<int>& myVec) {
    for (vector<int>::const_iterator i = myVec.begin(); i != myVec.end(); ++i) {
        cout << *i << ' ';
    }
}

void printIterator (const list<int>& myList) {
    for (list<int>::const_iterator i = myList.begin(); i != myList.end(); ++i) {
        cout << *i << ' ';
    }
}

void printEveryOther (const vector<int>& myVec) {
    for (vector<int>::const_iterator i = myVec.begin(); i != myVec.end(); ++(++i)) {
        cout << *i << ' ';
    }
}

void printEveryOther (const list<int>& myList) {
    for (list<int>::const_iterator i = myList.begin(); i != myList.end(); ++(++i)) {
        cout << *i << ' ';
    }
}

void printEveryOtherAuto (const vector<int>& myVec) {
    for (auto i = myVec.begin(); i != myVec.end(); ++(++i)) {
        cout << *i << ' ';
    }
}

void printEveryOtherAuto (const list<int>& myList) {
    for (auto i = myList.begin(); i != myList.end(); ++(++i)) {
        cout << *i << ' ';
    }
}

list<int>::const_iterator findIt (const list<int>& haystack, int needle) {
    for (list<int>::const_iterator i = haystack.begin(); i != haystack.end(); ++i) {
        if (*i == needle) return i;
    }
}

list<int>::const_iterator findAuto (const list<int>& haystack, int needle) {
    for (auto i = haystack.begin(); i != haystack.end(); ++i) {
        if (*i == needle) return i;
    }
}

bool isEven(int i) {
    return i % 2 == 0;
}

list<int>::iterator ourFind (list<int>::iterator start, list<int>::iterator end, auto needle) {
    cout << "\nOur find";
    for (auto i = start; i != end; ++i) {
        if (needle(*i)) return i;
    }
}

template<typename t>
t ourFind (t start, t end, auto needle) {
    cout << "\nOur find template";
    for (t i = start; i != end; ++i) {
        if (needle(*i)) return i;
    }
}