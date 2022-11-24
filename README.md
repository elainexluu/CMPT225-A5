# CMPT225 Assignment 5

# Objectives
============

*   Create hash functions and verfiying their goodness through complexity analysis and experimentation.
*   Implement the open addressing collision resolution strategy called linear probing hashing.
*   And experience one of the advantages of ADT classes, namely the ability to replace its underlying data structure and the implementation of the methods of its public interface without having to change the client code (well, almost) :).

--------------
# Hashing-based List ADT Class

Hashing-based List ADT Class
In this assignment, we are asked to transform the data collection we created as part of our solution to Assignment 1, namely the List ADT class, such that it now uses the open addressing hashing strategy.

To do so, follow these steps:

1.  When we created this List ADT class as part of the solution to the problem described in our Assignment 1, we used the data member phone of the Member class since this class' description stated that each member had a unique cell phone number. In this assignment, we shall use this data member phone as our indexing key.

2.  Next, let's download List.h and have a look at it. Because we are transforming our List ADT class such that it now uses open addressing hashing strategy, List must have an array as its underlying data structure. Well, it already did. However, we have made some changes to this array:

```
Member * * hashTable = nullptr;  // HashTable - underlying data structure (array) of our Data Collection.
	                         // HashTable is a pointer to an array of pointers to objects of Member class.
```

Notice that our hashTable is now an array of pointers to objects of Member class, as opposed to being an array of objects of Member class (as it was before).

We do this so that we can detect whether an array cell is empty or not. If the array cell is empty, it will contain nullptr, otherwise it will contain an element, i.e., a pointer to an object of the Member class.

**Hint:** When allocating heap space for our hashTable (in our insert(   ) method perhaps), we would initialize each cell of our hashTable, i.e., each pointer, to nullptr.

If we find a different way of detecting whether an array cell is empty or not, feel free to modify the given declaration of our hashTable in List.h. Make sure we add comments that clearly describes what we are doing.

3.  We need to determine the size of our **hash table**. The given code initially set this size to **100**. Have a look at List.h to verify.


4.  Before we proceed to the implementation of our hash functions, we need to modify the implementation of the methods of our List ADT class:
..* First, we need to modify the implementation of the insert(   ) method such that it uses the hashing strategy and when collisions occur, it uses the open addressing collision resolution strategy called linear probing hashing to resolve these collisions.
..* Then, we need to modify the implementation of the search(   ) method such that it uses the hashing strategy and when collisions occur, it uses the open addressing collision resolution strategy called linear probing hashing to resolve these collisions.
..* Make sure these methods do throw the proper exceptions.
..* Notice that for this assignment, the List's public interface does not contain the method removeAll(), remove() and clear(). So, there is no need to modify their implementation.
..* Feel free to find inspiration from the hashDataCollection class seen in Lab 10 and our demo seen on Tuesday Nov. 22.

5.  The next step is to create various hash functions that will transform our indexing keys into hash table indices. To do so, use the file hashFunctionTestDriver.cpp provided in our Lab 10 and create three different hash functions. We are free to use any type of hash functions except the hash functions that transform string indexing keys into hash table indices by manipulating the ASCII value of each of its characters (as demo'ed during our lecture on Tuesday Nov. 22).

6.  Implement a function in hashFunctionTestDriver.cpp which will create a certain number of indexing keys of the expected format. The number of indexing keys this function is to create must be provided as an argument to this function.

7.  Once we have created our hash functions and created plenty of random test data (indexing keys), let's make sure our hash functions are good.

    If needed, let's refer to our lectures on hashing for a description of what we mean by good hash functions.

   To verify the goodness of each of our hash functions, we need to '   '

    1.    Analyse the time and space complexity (efficiency) of each of our hash function and add these results as a comment above the function, for example:

            ```
            // Time efficiency: ...
            // Space efficiency: ... 
            ```

    Finally, conclude whether or not this particular hash function is **easy to compute**.

    2. Experiment with our hash functions in order to ascertain whether they spread over the whole hash table the hash table indices they produce.

   Refer to our Lab 10, our demo of Tuesday Nov. 22 and have a look at the recording of Lecture 30 in order to get a sense of what this type of experimentation feels like.

   Experiment: Let's recycle the code used in our demo (for example, histogram and printStats from hashDataCollection class) or write our own in order to see how well our hash functions spread over the whole hash table the hash table indices they produce.

   Note: Contrary to our demo, in which we compared indexing keys of different lengths, note that, in the context of our Assignment 1, the length of our indexing keys is fixed.

   Let's observe the results we obtain: can we ascertain which of our three hash functions is/are good?

     If none of them spread the hash table indices well enough, let's tweak at least one of our hash functions until it produces a good spread of hash table indices. If we are to tweak (modify) one or more of our hash functions, let's first copy and paste the initial hash function that needs to be tweaked, then rename its copy and then tweak it. This way, we get to keep all our hash functions.


    3. Let's record our results as comments above each hash function. More specifically

        * Supply a description of the spread of the hash table indices.

        * Indicate the number of empty cells in the hash table once all elements have been inserted.

        * State the number of elements that were inserted into the hash table using one probe, the number of elements that were inserted into the hash table using more than one probe and the number of probes done in each hash table cell.

        * Any other results we wish to report on.

        If we do not have enough space to report our results as comments above each hash function, we can add them as comments at the bottom of our file.

    4. Finally, conclude which hash function best spreads over the whole hash table the hash table indices it produces.

-------------
# Reflections

1.  Let's cast our mind back to our Assignment 1, its problem statement and its requirements. Do we think implementing our data collection, here the List, based on the hashing strategy is a good idea? Using such List, are we satisfying all the requirements of Assignment 1? Are we completely solving its problem?

2.  Let's cast our mind back to our Assignment 1, its problem statement and its requirements. Do we think implementing our data collection, here the List, based on the hashing strategy is a good idea? Using such List, are we satisfying all the requirements of Assignment 1? Are we completely solving its problem?

No need to hand in the results of these reflections.

----------------
# Marking Scheme

When marking Assignment 5, we shall consider some or all of the following criteria:

*   Compilation: Does our code compile?
*   Execution: Does our solution (code) solve the problem stated in this assignment and satisfy the requirements stated in this assignment?
*   Experimentation result: Are we clearly and completely reporting the results of our complexity analysis and our experimentation?
*   Coding style: Has Good Programming Style, described on the Good Programming Style web page of our course web site, been used?
*   Remember: We cannot make use of the C++ STL library nor can we use code that has not been written by we in the context of this course (this semester) or provided by this instructor.

-----------------


