/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 *                    Based on the Hashing strategy and the open addressing
 *                    collision resolution strategy called linear probing hashing.
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates).
 *
 * Author: AL
 * Date: Last modified: Nov. 2022
 */

#include <iostream>
#include <string>

#include "List.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using namespace std;
unsigned int insertCount = 0;

// Constructor
List::List(unsigned int (*hFcn)(string))
{
    hashFcn = hFcn;
    hashTable = new Member *[CAPACITY];
    collisions = new unsigned int[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        hashTable[i] = nullptr;
        collisions[i] = 0;
    }
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i] != nullptr)
        {
            delete hashTable[i];
            hashTable[i] = nullptr;
        }
    }

    // Release all heap memory
    if (hashTable != nullptr)
    {
        delete[] hashTable;
        hashTable = nullptr;
    }

    if (collisions != nullptr)
    {
        delete[] collisions;
        collisions = nullptr;
    }
}

// Description: Returns the total element count currently stored in List.
// Postcondition: List remains unchanged.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Description: Insert an element.
// NOTE: You do not have to expand the hashTable when it is full.
// Precondition: newElement must not already be in in the List.
// Postcondition: newElement inserted and elementCount has been incremented.
// Exception: Throws UnableToInsertException if we cannot insert newElement in the List.
//            For example, if the operator "new" fails, or hashTable is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the List.
void List::insert(Member &newElement)
{
    if (elementCount == CAPACITY)
    {
        throw UnableToInsertException("Unable to insert element. List is full.");
    }
    else
    {
        int index = hashFcn(newElement.getPhone());

        if (hashTable[index] == &newElement)
        {
            throw ElementAlreadyExistsException("Unable to insert element. Element already exists.");
        }

        while (hashTable[index] != nullptr)
        {
            index = (index + 1) % CAPACITY;
            collisions[index]++;
        }

        // if (hashTable[index] == nullptr)
        // {
        //     insertCount++;
        // }

        hashTable[index] = &newElement;
        // collisions[index]++;

        elementCount++;
    }
}

// Description: Returns a pointer to the target element if found.
// Postcondition: List remains unchanged.
// Exception: Throws EmptyDataCollectionException if the List is empty.
// Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
Member *List::search(Member &target) const
{
    int index = hashFcn(target.getPhone()); // compute hash index

    if (isEmpty()) // list is empty
    {
        throw EmptyDataCollectionException("Data collection is empty.");
    }
    else if (hashTable[index] == &target) // index is the target key
    {
        return (hashTable[index]);
    }
    else // target key not found
    {
        if (hashTable[index] == nullptr) // throw exception if cell is empty
        {
            throw ElementDoesNotExistException("Element does not exist in hash table.");
        }
        else // cell is not empty -> collision
        {
            int i = 0;
            while (hashTable[index] != &target)
            {
                index = (index + i) % CAPACITY;
                i++;
            }
        }
    }
    return (hashTable[index]);
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
void List::printList() const
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i] != nullptr)
        {
            // cout << hashTable[i]->getName() << " " << hashTable[i]->getPhone() << endl;
            cout << i << " " << *hashTable[i];
        }
    }
}

////////////////////////////// Helper functions ///////////////////////////

// Description: returns true if list is empty, otherwise false
bool List::isEmpty() const
{
    return elementCount == 0;
}

// Description: Prints an histogram showing distribution of hash indices over the hash table.
void List::histogram()
{
    cout << endl
         << "Histogram showing distribution of hash indices over the hash table: " << endl;
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        cout << "At hashTable[" << i << "]: ";
        for (unsigned int j = 0; j < collisions[i]; j++)
            cout << "*";
        cout << endl;
    }
    return;
}

// Description: Prints various stats.
void List::printStats()
{
    unsigned int emptyCell = 0;
    unsigned int oneProbe = 0;
    unsigned int moreProbes = 0;

    cout << endl
         << "In the process of inserting " << this->elementCount << " elements, number of collisions ... " << endl;
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        if (collisions[i] == 0)
            emptyCell++;
        else if (collisions[i] == 1)
            oneProbe++;
        else
        {
            if (collisions[i] > 1)
            {
                moreProbes++;
                cout << "at hashTable[" << i << "] = " << collisions[i] << endl;
            }
        }
    }

    cout << endl
         << "There are " << emptyCell << " empty cells." << endl;
    cout << oneProbe << " elements inserted without collisions." << endl;
    cout << "There were " << moreProbes << " collisions." << endl;

    return;
}

unsigned int List::returnInsertCount()
{
    return insertCount;
}