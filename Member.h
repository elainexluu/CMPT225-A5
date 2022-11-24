/*
 * Member.h
 * 
 * Class Description: Models a Fitness Studio Registration System.
 * Class Invariant: Each member has a unique cell phone number.
 *                  This cell phone number must have 12 digits.
 *                  This cell phone number must have the following format: XXX-XXX-XXXX.
 *                  This cell phone number cannot be modified. 
 *
 * Author: Elaine Luu
 * Last modified: Sept. 21, 2022
 */

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

using namespace std;

class Member {

/* You cannot change this file (i.e., the definition of this class). */
 	
private:

    constexpr static const int SIZE_OF_PHONE_NUMBER = 12;

    string name;                      
    string phone;
    string email;
    string creditCard;

    // Description: Sets the member's cell phone number - Private method
    // Reflection: Why is this method not part of the public interface?
    void setPhone(const string aPhone);

public:

    // Default Constructor
    // Description: Create a member with a cell phone number of "000-000-0000". 
    // Postcondition: All data members set to an empty string, 
    //                except the cell phone number which is set to "000-000-0000".
    Member();

    // Parameterized Constructor
    // Description: Create a member with the given cell phone number.
    // Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
    //                All other data members set to an empty string.
    Member(string aPhone);
	
    // Parameterized Constructor
    // Description: Create a member with the given name, cell phone number, email and credit card number.
    // Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
    Member(string aName, string aPhone, string anEmail, string aCreditCard);


    // Getters and setters
    // Description: Returns member's name.
    string getName() const;

    // Description: Returns member's phone.
    string getPhone() const;

    // Description: Returns member's email.
    string getEmail() const;
	
    // Description: Returns member's credit card.
    string getCreditCard() const;

    // Description: Sets the member's name.
    void setName(const string aName);

    // Description: Sets the member's email.
    void setEmail(const string anEmail);
	
    // Description: Sets the member's credit card number.
    void setCreditCard(const string aCreditCard);


    // Overloaded Operators
    // Description: Comparison operator. Compares "this" Member object with "rhs" Member object.
    //              Returns true if both Member objects have the same cell phone number.
    bool operator == (const Member & rhs);

    // Description: Greater than operator. Compares "this" Member object with "rhs" Member object.
    //              Returns true if the cell phone number of "this" Member object is > the 
    //              cell phone number of "rhs" Member object.
    bool operator > (const Member & rhs);
	
    // Description: Less than operator. Compares "this" Member object with "rhs" Member object.
    //              Returns true if the cell phone number of "this" Member object is < the 
    //              cell phone number of "rhs" Member object.
    bool operator < (const Member & rhs);
	
    // For testing purposes!
    // Description: Prints the content of "this".
    // Example: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
    friend ostream & operator<<(ostream & os, const Member & p);

}; // end of Member.h
#endif