#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Skyrim : public Elder {
	friend ostream& operator<<(const ostream& os, Elder& elder) {
		os << "Skrim Name: " << elder.name << endl;
		os << "Number of Dragons" << elder.dragons.size() << endl;
		for (int i = 0; i < elder.dragons.size(); ++i) {
			os << elder.dragons[i] << endl;
		}
	}
	friend bool operator==(const Elder& lhs, const Elder& rhs) {
		if (lhs.name == rhs.name) {
			if (lhs.dragons.size() == rhs.dragons.size()) {
				for (int i = 0; i < ljhs.dragons.size(); ++i) {
					if (lhs.dragons[i] != rhs.dragons[i]) {
						return false;
					}
				}
				return true;
			}
		}
		return false
	} 
public:
	Skyrim(const string& _name, const string& _code) 
	: Elder(_code), name(_name) {}

	Skyrim(const Skyrim& rhs) : Elder(rhs), name(rhs.name) {
		for (int i = 0; i < rhs.dragons.size(); ++i) {
			dragons.push_back(new Dragon(*rhs.dragons[i])));
		}
	}

	~Skyrim() {
		for (int i = 0; i < dragons.size(); ++i) {
			delete dragons[i];
		}
		dragons.clear();
	}

	Skyrim& operator=(const Skyrim& rhs) {
		if (&rhs != this) {
			Elder::operator=(rhs);
			name = rhs.name;
			for (int i = 0; i < rhs.dragons.size(); ++i) {
				dragons.push_back(new Dragon(*rhs.dragons[i])));
			}
		}
		return *this;
	}

private:
	vector<Dragon*> dragons;
	string name;
}
