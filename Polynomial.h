#pragma once
#include<iostream>

class Polynomial
{
    int size_; // size of the array of coefficients
    double* coeff; // coefficients
public:
    Polynomial(); // default constructor
    Polynomial(std::initializer_list<double> lst); // initializer-list constructor
    Polynomial(const Polynomial& other); // copy constructor
    Polynomial(Polynomial&& a); // move constructor
    Polynomial& operator=(const Polynomial& other); // assignment operator
    Polynomial& operator=(Polynomial&& a); // move operator=
    ~Polynomial(); // destructor

    int degree() const; // returns the degree of the polynomial
    double getCoeff(int i) const; // returns the coefficient of x^i

    Polynomial operator+(const Polynomial& other) const; // addition operator
    Polynomial operator-(const Polynomial& other) const; // subtraction operator
};

// Default constructor
Polynomial::Polynomial() : size_(1)
{
    coeff = new double[size_];
    coeff[0] = 0;
}

// Initializer-list constructor
Polynomial::Polynomial(std::initializer_list<double> lst) : size_(lst.size())
{
    coeff = new double[size_];
    int i = 0;
    for (auto it = lst.begin(); it != lst.end(); it++, i++)
       coeff[i] = *it;
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : size_(other.size_)
{
    coeff = new double[size_];
    for (int i = 0; i < size_; i++)
        coeff[i] = other.coeff[i];
}

// Move constructor
Polynomial::Polynomial(Polynomial&& a) : size_(a.size_), coeff(a.coeff)
{
    a.size_ = 0;
    a.coeff = nullptr;
}

// Copy assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this == &other)
        return *this;
    delete[] coeff;
    size_ = other.size_;
    coeff = new double[size_];
    for (int i = 0; i < size_; i++)
        coeff[i] = other.coeff[i];
    return *this;
}

// Move assignment operator
Polynomial &Polynomial::operator=(Polynomial &&a)
{
    if (this == &a)
        return *this;
    delete[] coeff;
    size_ = a.size_;
    coeff = a.coeff;
    a.size_ = 0;
    a.coeff = nullptr;
    return *this;
}

// Destructor
Polynomial::~Polynomial()
{
    delete[] coeff;
}

// Returns the degree of the polynomial
int Polynomial::degree() const
{
    return size_ - 1;
}

// Returns the coefficient of x^i
double Polynomial::getCoeff(int i) const
{
    if (i < 0 || i >= size_)
        return 0;
    return coeff[i];
}

// Addition operator
Polynomial Polynomial::operator+(const Polynomial& other) const
{
    int n = std::max(size_, other.size_);
    Polynomial res;
    delete[] res.coeff;
    res.size_ = n;
    res.coeff = new double[n];
    for (int i = 0; i < n; i++)
        res.coeff[i] = getCoeff(i) + other.getCoeff(i);
    return res;
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial& other) const
{
    int n = std::max(size_, other.size_);
    Polynomial res;
    delete[] res.coeff;
    res.size_ = n;
    res.coeff = new double[n];
    for (int i = 0; i < n; i++) {
        double c1 = i < size_ ? coeff[i] : 0.0;
        double c2 = i < other.size_ ? other.coeff[i] : 0.0;
        res.coeff[i] = c1 - c2;
    }
    return res;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    for (int i = p.degree(); i >= 0; --i) {
        if (p.getCoeff(i) != 0) {
            if (i == 0) {
                out << p.getCoeff(i);
            }
            else if (i == 1) {
                out << p.getCoeff(i) << "x + ";
            }
            else {
                out << p.getCoeff(i) << "x^" << i << " + ";
            }
        }
    }
    return out;
}