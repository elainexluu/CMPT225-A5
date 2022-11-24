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
#include <string.h>

#include "List.h"
#include "ElementAlreadyExistsException.h"
#include "UnableToInsertException.h"

// Constructor
List::List(unsigned int (*hFcn)(string))
    : hashFcn(hFcn), hashTable(nullptr), elementCount(0) 
{}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
// List::~List()
// {
   
// }


// Description: Returns a pointer to the target element if found.
// Postcondition: List remains unchanged.
// Exception: Throws EmptyDataCollectionException if the List is empty.
// Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
Member* List::search( Member & target ) const
{
    int index = hashFcn(target); // compute hash index

    if (isEmpty()) // list is empty
    {
        throw EmptyDataCollectionException("Data collection is empty.");
    }
    else if (hashTable[index] == target) // index is the target key
    {
        return (&hashTable[index]);
    }
    else
    {
        if ()
    }
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
// void List::printList() const
// {

// }

// Description: returns true if list is empty, otherwise false
bool List::isEmpty() {
    return elementCount == 0;
}