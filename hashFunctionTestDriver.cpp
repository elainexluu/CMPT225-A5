/*
 * hashFunctionTestDriver.cpp
 * Description: Experimenting with hash functions
 *
 * Author: AL
 * Modification Date: Nov. 2022
 */


#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include "Member.h"

#include <stdlib.h> // for rand()
#include <time.h>   // for time()

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::__cxx11::stoul;

// Description: Creates "size" elements of "digitCount" digits.
//              and prints each element on its own line on stdout.
//              Each digit is randomly selected from the range [0..9].
void createRandomTestData( unsigned int size, unsigned int digitCount ) {

  for ( unsigned int i = 0; i < size; i++ ) {
    for ( unsigned int i = 0; i < digitCount; i++ ) {
      cout << rand() % 10;
    }
    cout << endl;
  }
  return;
}	

// Hash Function #1
// Description: Implements the type of hash function called 
//              "modular arithmetic" in which we use the modulo 
//              operator to produce the "hash index".
unsigned int hashModulo( string indexingKey ) {

  // stoul -> string-to-unsigned int function
  // "hashCode" is an intermediate result
  unsigned int hashCode = stoul(indexingKey);
 
  return hashCode % List::CAPACITY;
}

// Hash Function #2
// Description: Implements the type of hash function called "Folding -> shift" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s).
unsigned int hashFoldShift( string indexingKey ) {

    // "hashCode" is an intermediate result
    unsigned int hashCode = 0;
    unsigned int sumOfPart = 0;

    unsigned int part1 = stoul(indexingKey.substr(0, 3));
    unsigned int part2 = stoul(indexingKey.substr(4, 3));
    unsigned int part3 = stoul(indexingKey.substr(8, 4));

    // Testing purposes
    // cout << "partition 1 of indexing key: " << part1 << endl;
    // cout << "partition 2 of indexing key: " << part2 << endl;
    // cout << "partition 3 of indexing key: " << part3 << endl;

    sumOfPart = (part1 + part2 + part3);

    hashCode = sumOfPart % List::CAPACITY;
    // cout << "hashCode: " << hashCode << endl;
  	
  return hashCode;
}

// For you to do:
// Hash Function #3
// Description: Implements the type of hash function called "Folding -> boundary" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s). In this type of folding,
//              the alternate parts (2nd, 4th ... parts) are reversed (i.e., flipped).
unsigned int hashFoldBoundary( string indexingKey ) {

  // Implements the Folding -> boundary hash function.

  // "hashCode" is an intermediate result
  unsigned int hashCode = 0;
  	
  return hashCode;
}


int main(int argc, char *argv[]) {

  List *testingModulo = new List(hashFoldShift);
  Member *newMember = new Member("John Smith", "778-681-1234", "john@gmail.com", "1122334455667788");
  string anIndexingKey = "123456789";
  
  // If you enter the command: ./hftd 100 16
  // createRandomTestData( 100, 16 ) is called
  // and will create 100 elements and 
  // print each element on its own line on stdout.
  // Each of these elements will be made of 16 digits.
  // Each digit will be randomly selected from the range [0..9].
  // If you enter the command: ./hftd 100 16 > dataFile_100_16.txt
  // all of these 100 elements will be stored into 
  // the file dataFile_100_16.txt, which can be read later.
  if ( argc == 3 ) 
    createRandomTestData( stoul(argv[1]), stoul(argv[2]) );
  else {
    // If you enter the command: ./hftd dataFile_100_16.txt
    // each element of dataFile_100_16.txt is read as 
    // an indexing key, which is then inserted into "testingModulo",
    // which is an object of the hashDataCollection class.
    // As part of inserting this newElement (i.e., anIndexingKey),
    // anIndexingKey is hashed and the produced hash index is
    // used to insert anIndexingKey into the hashTable. 
    // See the implementation of insert(...) in hashDataCollection.cpp.
    if ( argc == 2 ) {
      ifstream myfile( argv[1] );
      if ( myfile.is_open() ) {
        while ( getline( myfile, anIndexingKey ) ) {      
          // cout << "The indexing key read is " << anIndexingKey << endl; 
          testingModulo->insert( *newMember );
        } 
        myfile.close();
		
        // Print the content of the hashTable 
        // Print an histogram showing how well (or poorly) the hash indices
        // are distributed over the whole hashTable.
        // cout << "***Experimenting with the modulo hash function***" << endl;
        // testingModulo->print();
        // testingModulo->histogram();
        // testingModulo->printStats();                
	
      }
      else 
        cout << "Unable to open file"; 
    }
    else 
      cout << "Forgot the file name? Try again!" << endl;
  }

  delete testingModulo;
  testingModulo = nullptr;
  
  return 0;
}
