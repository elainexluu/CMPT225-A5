all: ltd

ltd: ListTestDriver.o List.o Member.o ElementDoesNotExistException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o UnableToInsertException.o
	g++ -Wall -o ltd ListTestDriver.o List.o Member.o ElementDoesNotExistException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o UnableToInsertException.o
	
ListTestDriver.o: List.h Member.h ListTestDriver.cpp
	g++ -Wall -c ListTestDriver.cpp

Member.o: Member.h Member.cpp
	g++ -Wall -c Member.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp

clean:
	rm -f ltd *.o