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

// Constructor
List::List(unsigned int (*hFcn)(string))
{
    hashFcn = hFcn;
    hashTable = new Member *[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        hashTable[i] = nullptr;
    }
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (hashTable != nullptr)
        {
            delete hashTable[i];
        }
        delete[] hashTable;
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
        }

        hashTable[index] = &newElement;
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
            cout << i << " " << *hashTable[i] << endl;
        }
    }
}

////////////////////////////// Helper functions ///////////////////////////

// Description: returns true if list is empty, otherwise false
bool List::isEmpty() const
{
    return elementCount == 0;
}