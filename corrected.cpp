#include<iostream>
#include<memory>

using std::unique_ptr;
using std::cout;
using std::endl;

int main()
{
    int a{ 10 }, b{ 20 };
    unique_ptr<int> ap{ new int };
    *ap = 23;
    cout << ap << endl;
    cout << *ap << endl;
    ap.release();

    cout << ap << endl;

    // unique_ptr<int> ap2 = &a; //  error

    unique_ptr<int> ap3{ new int };
    *ap3 = 12;
    unique_ptr<int> ap4{ new int };
    *ap4 = 14;
    ap4 = move(ap3);

    return 0; // no need to comment this line
}
