#include <iostream>
#include "DoublyList.hpp"
using namespace std;

int main() {
    DoublyList<int> list;

    // Append elements
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "After appending 10, 20, 30:\n";
    cout << list << endl;

    // Insert element at position 1
    list.insert(1, 15);
    cout << "After inserting 15 at position 1:\n";
    cout << list << endl;

    // Get element at position 2
    cout << "Element at position 2: " << list.getElement(2) << endl;

    // Replace element at position 0
    /*list.replace(0, 5);
    cout << "After replacing position 0 with 5:\n";
    cout << list << endl;*/

    // Remove element at position 2
    list.remove(2);
    cout << "After removing element at position 2:\n";
    cout << list << endl;

    // Search for a value
    if (list.search(20)) {
        cout << "Found 20 in the list!\n";
    } else {
        cout << "20 not found in the list.\n";
    }

    return 0;
}
