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
#include <stdlib.h> // for rand()
#include <time.h>   // for time()
#include <fstream>
#include <sstream>

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
// string randomKeyGenerator(unsigned int num)
// {
//     string appendNum = "";
//     unsigned int randomNum = 0;
//     int count = 0;

//     for (unsigned int i = 0; i < num; i++)
//     {
//         unsigned int randomNum = rand() % 10;
//         // cout << "key: " << key % 10 << endl;
//         appendNum = appendNum + to_string(randomNum);
//         count++;
//     }

//     while (count != 10) // append indexing key with zeroes
//     {
//         appendNum += "0";
//         count++;
//     }

//     string generatedKey = appendNum.substr(0, 3) + "-" +
//                           appendNum.substr(3, 3) + "-" +
//                           appendNum.substr(7, 4);

//     // Testing purposes
//     // cout << "generatedKey: " << generatedKey << endl;
//     // cout << "appendNum: " << appendNum << endl;

//     return generatedKey;
// }

// Description: creates a certain number of indexing keys of the expected format.
//              Each digit is randomly selected.
void randomKeyGenerator(unsigned int num)
{
    // open file "randomKeys.txt" for writing the generated keys in overwriting mode
    ofstream outFile;
    outFile.open("randomKeys.txt", ios::trunc);

    // digitCount signifies the number of digits in the indexing key - In this case, phone number
    // is the indexing key and it has 10 digits.
    unsigned int digitCount = 10;
    string appendNum;
    for (unsigned int i = 0; i < num; i++)
    {
        appendNum = "";
        for (unsigned int i = 0; i <= digitCount; i++)
        {
            appendNum = appendNum + to_string(rand() % 10);
        }
        string generatedKey = appendNum.substr(0, 3) + "-" +
                              appendNum.substr(3, 3) + "-" +
                              appendNum.substr(7, 4);
        // cout << "generatedKey: " << generatedKey << endl;
        // cout << generatedKey << endl;
        outFile << generatedKey << endl;
        // cout << endl;
    }
    return;
}

// Description: creates a certain number of credit card numbers of the expected format.
//              Each digit is randomly selected.
void randomCardGenerator(unsigned int num)
{
    // open file "randomCardNums.txt" for writing the generated keys in overwriting mode
    ofstream outFile;
    outFile.open("randomCardNums.txt", ios::trunc);

    // digitCount signifies the number of digits in the indexing key - In this case, phone number
    // is the indexing key and it has 12 digits.
    unsigned int digitCount = 12;
    string appendNum;
    for (unsigned int i = 0; i < num; i++)
    {
        appendNum = "";
        for (unsigned int i = 0; i <= digitCount; i++)
        {
            appendNum = appendNum + to_string(rand() % 10);
        }
        outFile << appendNum << endl;
        // cout << endl;
    }
    return;
}

// Description: reads the names file line by line and creates a text file of email addresses
//             using the names in the names file.
void emailGenerator()
{
    // open file "randomEmails.txt" for writing the generated keys in overwriting mode
    ofstream outFile;
    outFile.open("randomEmails.txt", ios::trunc);

    // open file "names.txt" for reading
    ifstream inFile;
    inFile.open("names.txt");

    string line;
    string firstName;
    string lastName;
    string email;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        ss >> firstName >> lastName;
        email = firstName + "." + lastName + "@gmail.com";
        outFile << email << endl;
    }

    return;
}

// Description: takes name, phone number, email address, and credit card number as input
//             from a function and bundles them into a member data structure.
void createMemberAndInsert(string name, string phone, string email, string card, List *member)
{
    Member *newMember = new Member(name, phone, email, card);
    member->insert(*newMember);
}

// Description: reads the files containing the names, phone numbers, email addresses, and credit card numbers
//             and passes them to the createMember function to create a member data structure.
void readFilesAndCreateMembers(List *member)
{
    // open file "names.txt" for reading
    ifstream inFile;
    inFile.open("names.txt");

    // open file "randomKeys.txt" for reading
    ifstream inFile2;
    inFile2.open("randomKeys.txt");

    // open file "randomEmails.txt" for reading
    ifstream inFile3;
    inFile3.open("randomEmails.txt");

    // open file "randomCardNums.txt" for reading
    ifstream inFile4;
    inFile4.open("randomCardNums.txt");

    string first_name;
    string last_name;
    string phone;
    string email;
    string card;

    while (inFile >> first_name >> last_name && inFile2 >> phone && inFile3 >> email && inFile4 >> card)
    {
        // for testing purposes
        cout << "Inserting: " << first_name << " " << last_name << " " << phone << " " << email << " " << card << endl;
        cout << endl;
        string name = first_name + " " + last_name;
        createMemberAndInsert(name, phone, email, card, member);
    }

    inFile.close();
    inFile2.close();
    inFile3.close();
    inFile4.close();
}

// Description: takes a quantity of members to be created as input and calls the requisite functions to do that
void createMembers(unsigned int num, List *member)
{
    randomKeyGenerator(num);
    emailGenerator();
    randomCardGenerator(num);
    readFilesAndCreateMembers(member);
}

int main()
{

    // Test: List(), insert(), getElementCount(), printList(), ~List()

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
    // cout << "Insert a Member into the List -> testing insert()." << endl;
    // cout << "Expected Result: List with one Member." << endl;
    // Member *newMember = new Member("John Smith", "778-681-1234", "john@gmail.com", "1122334455667788");
    // member->insert(*newMember);
    // cout << "Actual Result: " << endl;
    // member->printList();
    // cout << endl;

    // Test Case 3:
    // Inserting 20 members into the list using the createMembers function.

    cout << "Inserting 20 members into the list using the createMembers function -> testing insert()." << endl;
    cout << "Expected Result: List with 20 Members." << endl;
    createMembers(20, member);
    cout << "Actual Result: " << endl;
    member->printList();
    cout << endl;

    return 0;
}