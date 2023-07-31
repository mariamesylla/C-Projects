#include<iostream>

class vector {
    int sz; // the size
    double* elem;	// a pointer to the elements
public:
    vector(int s) : sz(s), elem(new double[s]) // constructor
    {
        for (int i{ 0 }; i < s; ++i) elem[i] = 0;
    }

    vector(const vector& other) :sz{ other.sz }, elem{ new double[other.sz] } {
        for (int i = 0; i < sz; ++i) elem[i] = other.elem[i];
    }
    // copy method
    void copy(const vector* other) {
        // delete existing elements
        delete[] elem;
        // allocate new elements
        sz = other->sz;
        elem = new double[sz];
        // copy elements
        for (int i = 0; i < sz; ++i) elem[i] = other->elem[i];
    }
    ~vector() // destructor
    {
        delete[] elem;
    }
    double get(int n) const { return elem[n]; }; // access:read
    void set(int n, double v) { elem[n] = v; } // access:write
    int size() const { return sz; }	// the current size

    // a member function that would display the values of the vector object
    void display() {
        for (int i{ 0 }; i < sz; ++i)
            std::cout << elem[i] << " ";
    }

    /* a member function resize(int newSz) that resizes the vector to the new size,
    preserving all the existing  elements */
    void resize(int newSz)
    {
        double* tmp = new double[newSz]; // allocate new space
        for (int i{ 0 }; i < sz; ++i) // copy the existing values
            tmp[i] = elem[i];
        for (int i{ sz }; i < newSz; ++i) // the rest of the places are filled with 0s
            tmp[i] = 0;
        delete[] elem; // release the space pointed to by elem
        elem = tmp; // reassign the elem pointer to the newly allocated array
        sz = newSz; // update the size
    }

};
// not "frending" it with vector class this time
// overloading the output operator<< to be used with objects of this class
std::ostream& operator<<(std::ostream& out, const vector& v)
{
    for (int i{ 0 }; i < v.size(); ++i)
        out << v.get(i) << " ";
    return out;
}

int main() {
    vector b(40);
    // fill out with 2, 4, 6, ...
    for (int i{ 0 }; i < b.size(); ++i)
        b.set(i, (i + 1) * 2);
    std::cout << "the vector b: \n" << b << std::endl;

    // create vector c with 3 elements
    vector c(3);

    // copy vector b into c using copy() method
    c.copy(&b);
    std::cout << "The vector c: \n" << c << "\n";
}
