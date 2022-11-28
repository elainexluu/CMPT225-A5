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

// Hash Function #2
// Description: Implements the type of hash function called "Folding -> shift"
//              in which we partition the indexing key into parts and combine
//              these parts using arithmetic operation(s).
unsigned int hashFoldShift(string indexingKey)
{

    // "hashCode" is an intermediate result
    unsigned int hashCode = 0;
    unsigned int sumOfPart = 0;

    unsigned int part1 = stoul(indexingKey.substr(0, 3));
    unsigned int part2 = stoul(indexingKey.substr(4, 3));
    unsigned int part3 = stoul(indexingKey.substr(8, 4));

    // Testing purposes
    cout << "partition 1 of indexing key: " << part1 << endl;
    cout << "partition 2 of indexing key: " << part2 << endl;
    cout << "partition 3 of indexing key: " << part3 << endl;

    sumOfPart = (part1 + part2 + part3);

    hashCode = sumOfPart % List::CAPACITY;
    cout << "hashCode: " << hashCode << endl;

    return hashCode;
}

// Hash Function #3
// Description: Implements the type of hash function called "Folding -> boundary"
//              in which we partition the indexing key into parts and combine
//              these parts using arithmetic operation(s). In this type of folding,
//              the alternate parts (2nd, 4th ... parts) are reversed (i.e., flipped).
unsigned int hashFoldBoundary(string indexingKey)
{

    // Implements the Folding -> boundary hash function.
    unsigned int hashCode = 0;
    unsigned int sumOfPart = 0;

    string part2str = indexingKey.substr(4, 3);
    string part2rev;

    // reverse part2

    for (int i = part2str.length() - 1; i >= 0; i--)
    {
        part2rev += part2str[i];
    }

    unsigned int part1 = stoul(indexingKey.substr(0, 3));
    unsigned int part2 = stoul(part2rev);
    unsigned int part3 = stoul(indexingKey.substr(8, 4));

    // Testing purposes
    // cout << "partition 1 of indexing key: " << part1 << endl;
    // cout << "partition 2 of indexing key: " << part2 << endl;
    // cout << "partition 3 of indexing key: " << part3 << endl;

    sumOfPart = (part1 + part2 + part3);

    hashCode = sumOfPart % List::CAPACITY;
    cout << "hashCode: " << hashCode << endl;

    return hashCode;
}

// Description: creates a certain number of indexing keys of the expected format.
//              Each digit is randomly selected.
string randomKeyGenerator(unsigned int num)
{
    string appendNum = "";
    unsigned int randomNum = 0;
    int count = 0;

    for (unsigned int i = 0; i < num; i++)
    {
        unsigned int randomNum = rand() % 10;
        // cout << "key: " << key % 10 << endl;
        appendNum = appendNum + to_string(randomNum);
        count++;
    }

    while (count != 10) // append indexing key with zeroes
    {
        appendNum += "0";
        count++;
    }

    string generatedKey = appendNum.substr(0, 3) + "-" +
                        appendNum.substr(3, 3) + "-" +
                        appendNum.substr(7, 4);

    // Testing purposes
    // cout << "generatedKey: " << generatedKey << endl;
    // cout << "appendNum: " << appendNum << endl;

    return generatedKey;
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
    List *member = new List(hashFoldBoundary);
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

    // Testing randomKeyGenerator function
    // cout << randomKeyGenerator(0) << endl;
    // cout << randomKeyGenerator(1) << endl;
    // cout << randomKeyGenerator(5) << endl;
    // cout << randomKeyGenerator(2) << endl;
    // cout << randomKeyGenerator(8) << endl;
    // cout << randomKeyGenerator(10) << endl;


    // Testing randomKeyGenerator with hash functions
    // cout << hashFoldShift(randomKeyGenerator(3)) << endl;
    // cout << hashFoldBoundary(randomKeyGenerator(6)) << endl;

    return 0;
}