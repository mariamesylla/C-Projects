#include <iostream>

using namespace std;

float sumOfSquares(float x, float y, float z) {
    float sum1=0;
    sum1= (x * x + y * y + z * z);
    return sum1;
}

const float& sumOfSquaresRef(const float& x, const float& y, const float& z) {
    static float sum2;
    sum2 = x * x + y * y + z * z;
    return sum2;
}

const float* sumOfSquaresP(const float* x, const float* y, const float* z) {
    static float sum3;
    sum3 = (*x) * (*x) + (*y) * (*y) + (*z) * (*z);
    return &sum3;
}

int main() {
    float x = 9.8, y = 1.2, z = 2.3, result;
    result = sumOfSquares(x, y, z);
    cout << " The value of sumOfSquares in the first case is: " << result << endl;

    result = sumOfSquaresRef(x, y, z);
    cout << " The value of sumOfSquaresRef by reference is:  " << result << endl;

    result = *sumOfSquaresP(&x, &y, &z);
    cout << "The value of sumOfSquaresP by pointers is: " << result << endl;

    return 0;
}
