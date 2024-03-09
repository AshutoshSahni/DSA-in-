#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
private:
	const int TABLE_SIZE = 10;
	vector<list<pair<int, string>>> table;

	//hash function
	int get_hash(int key) {
		return key % TABLE_SIZE;
	}

public:
	HashTable() : table(TABLE_SIZE) {};

	// INSERTION
	void insert(int key, string value) {
		int index = get_hash(key);
		table[index].emplace_back(key, value);
	}

	// DELETION
	void remove(int key) {
		int index = get_hash(key);
		auto& bucket = table[index];
		for(auto it = bucket.begin(); it != bucket.end(); it++) {
			if(it->first == key) {
				bucket.erase(it);
				return;
			}
		}
	}

	// SEARCH
	string search(int key) {
		int index = get_hash(key);
		for(const auto& pair : table[index]) {
			if(pair.first == key)
				return pair.second;
		}

		return "No not found!";
	}

	// show the hash table
	void display() {
		for(int i = 0; i < TABLE_SIZE; i++) {
			cout << "Bucket " << i << ": ";
			for(const auto& pair: table[i]) 
				cout << "(" << pair.first << ", " << pair.second << ") ";
			cout << endl;
		}
	}
};

// driver code
int main() {
	HashTable ht;

	ht.insert(1, "one");
	ht.insert(2, "two");
	ht.insert(3, "three");
	ht.search(2);
	ht.remove(3);

	ht.display();

	return 0;
}
