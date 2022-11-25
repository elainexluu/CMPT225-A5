/*
 * List.h
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

#ifndef LIST_H
#define LIST_H

// You can add #include statements if you wish.
#include <string>
#include "Member.h"

class List
{

private:
  /*
   * For experimentation purposes, you can add private data members to this List class.
   */

  Member **hashTable = nullptr;         // HashTable - underlying data structure (array) of our Data Collection.
                                        // HashTable is a pointer to an array of pointers to objects of Member class
  unsigned int elementCount = 0;        // Current number of elements stored into Data Collection.
  unsigned int (*hashFcn)(string name); // Pointer to hash function.

  // Description: Checks if the table is empty.
  // Postcondition: List remains unchanged.
  bool isEmpty() const;

public:
  /*
   * You can add more private methods to this class, but you cannot remove the public methods below nor can you change their prototype.
   * For experimentation purposes, you can add public methods to this List class.
   *
   */

  const static unsigned int CAPACITY = 100; // Size of hashTable - underlying data structure (array) of List.

  // Constructor
  List(unsigned int (*hFcn)(string));

  // Destructor
  // Description: Destruct a List object, releasing heap-allocated memory.
  ~List();

  // Description: Returns the total element count currently stored in List.
  // Postcondition: List remains unchanged.
  unsigned int getElementCount() const;

  // Description: Insert an element.
  // NOTE: You do not have to expand the hashTable when it is full.
  // Precondition: newElement must not already be in in the List.
  // Postcondition: newElement inserted and elementCount has been incremented.
  // Exception: Throws UnableToInsertException if we cannot insert newElement in the List.
  //            For example, if the operator "new" fails, or hashTable is full (temporary solution).
  // Exception: Throws ElementAlreadyExistsException if newElement is already in the List.
  void insert(Member &newElement);

  // Description: Returns a pointer to the target element if found.
  // Postcondition: List remains unchanged.
  // Exception: Throws EmptyDataCollectionException if the List is empty.
  // Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
  Member *search(Member &target) const;

  // Description: Prints all elements stored in the List (unsorted).
  // Postcondition: List remains unchanged.
  void printList() const;

}; // end List.h
#endif