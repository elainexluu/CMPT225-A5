/*
 * ListTestDriver.cpp
 *
 * Description: Test Driver for data collection List class.
 *
 * Author: alavergn
 * Created on: Sept. 2022
 *
 */

#include "List.h"
#include "Member.h"
#include <iostream>

using namespace std;

// Hash Function #1
// Description: Implements the type of hash function called
//              "modular arithmetic" in which we use the modulo
//              operator to produce the "hash index".
unsigned int hashModulo(string indexingKey)
{

    // stoul -> string-to-unsigned int function
    // "hashCode" is an intermediate result
    unsigned int hashCode = stoul(indexingKey);

    return hashCode % List::CAPACITY;
}

int main()
{

    // Test: List(), insert(), getElementCount(), printList(), ~List()

    string indexingKey = "123456789";

    // Test case 1:
    // Create a List of size CAPACITY (100) using default constructor.
    // Testing List()
    cout << endl
         << "Create a default List -> testing constructor List()." << endl;
    cout << "Expected Result: empty List." << endl;
    List *member = new List(hashModulo);
    cout << "Actual Result: " << endl;
    member->printList();
    cout << endl;

    // Test case 2:
    // Insert a Member into the List.
    // Testing insert()
    cout << "Insert a Member into the List -> testing insert()." << endl;
    cout << "Expected Result: List with one Member." << endl;
    Member *newMember = new Member("John Smith", "778-681-1234", "john@gmail.com", "1122334455667788");
    member->insert(*newMember);
    cout << "Actual Result: " << endl;
    member->printList();
    cout << endl;

    return 0;
}