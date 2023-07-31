#include<iostream>       
#include<memory> 

using std::unique_ptr;      
using std::cout;           
using std::endl;           

int main()                 // main function defined
{
    int a{ 10 }, b{ 20 };  // declaration of two integer variables a and b and initializig them with values 10 to a and 20 to b.

    unique_ptr<int> ap{new int};   // declaration of a unique_ptr of type int and initializing it with a dynamically allocated memory address the memory is not initialized to any specific value

    *ap = 23;              // dereference the unique_ptr and assigns a value of 23 to the memory it is pointing to

    cout << ap << endl;    // print the memory address that unique_ptr ap points to.

    cout << *ap << endl;   // print the value stored in the memory that unique_ptr is pointing to 23.

    ap.release();          // release the allocated memory from the unique_ptr ap.

    cout << ap << endl;    // print a null pointer as the allocated memory has been released 000000000000.

    unique_ptr<int> ap2 = &a;   // There is an error as we try to assign the address of a referenced variable &a to unique_ptr ap2.

    unique_ptr<int> ap3{ new int };  // declare a unique_ptr of type int and it is sinitialized.
                      
    *ap3 = 12;                       // dereferencing unique_ptr ap3 and assign the value 12 to the memory it points to.

    unique_ptr<int> ap4{ new int };  // declare a unique_ptr of type int and is initialized.

    *ap4 = 14;                       // dereferencing unique_ptr apr4 and assigning the value 14 to the memory it is pointing to.

    ap4 = ap3;                       //Error as by assigning ap3 to ap4 there is a memory leak and 
                                     //we need to corectly deallocate the memory of ap4.

    return 0;                        // no need to comment this line.
}
