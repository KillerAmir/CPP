#include <iostream>
#include <list>
#include <vector>

using namespace std;


class HashTable {
private:
    static const int tableSize = 10; 
    vector<list<int>> table;         

public:
    
    HashTable() : table(tableSize) {}

    
    int hashFunction(int key) {
        return key % tableSize;
    }

    
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

  
    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true; 
            }
        }
        return false;
    }

   
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

   
    void displayTable() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "Index " << i << ": ";
            for (int value : table[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
   
    HashTable hashTable;

   
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);
    hashTable.insert(15);

    
    cout << "Initial Hash Table:" << endl;
    hashTable.displayTable();
    cout << endl;

   
    cout << "Search for key 20: " << (hashTable.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search for key 25: " << (hashTable.search(25) ? "Found" : "Not Found") << endl;

    
    hashTable.remove(20);

    
    cout << "\nHash Table after Removing Key 20:" << endl;
    hashTable.displayTable();

    return 0;
}
