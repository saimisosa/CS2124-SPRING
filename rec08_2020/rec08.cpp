// Saimanasa Juluru
// Rec 08
// CS2124
// 03.27.20

#include <iostream>
#include <string>
using namespace std;


class Rational {
    friend istream& operator>>(istream& is, Rational& rhs){
        char oper;
        is >> rhs.numerator >> oper >> rhs.denominator;
        rhs.normalize();
        return is;
    }
    friend ostream& operator<<(ostream& os, const Rational& rhs) {
        os << rhs.numerator << "/" << rhs.denominator << endl;
        return os;
    }

    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 1, int denominator = 1) : numerator(numerator), denominator(denominator) {
        normalize();
    }

    //+= operator
    Rational& operator+=(const Rational& rhs){
        if (rhs.denominator != denominator){
            numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
            denominator = (denominator * rhs.denominator);
        }
        else {
            numerator = numerator + rhs.numerator;
        }
        // need to normalize again since you're adding the numbers
        normalize();
        return *this;
    }
    // ++fraction
    Rational& operator++(){
        numerator+=denominator;
        return *this;
    }
    // fraction++
    Rational operator++(int dummy) {
        Rational result(*this);
        numerator+=denominator;
        return result;
    }

    explicit operator bool() const {
        return (numerator != 0);
    }

private:
    int numerator, denominator;

    // gcf
    int gcf(int numerator, int denominator){
        if (numerator < 0){
            numerator = -numerator;
        }
        else if (denominator < 0){
            denominator = -denominator;
        }
        while (denominator != 0) {
            int temp = numerator % denominator;
            numerator = denominator;
            denominator = temp;
        }
        return numerator;
    }

// makes sure theres no neg in denominator
    int posNeg(int num, int den){
        if (den < 0){
            den = -den;
            num = -num;
        }
        else if (den < 0 && num < 0){
            den = -den;
            num = -num;
        }
        return num, den;
    }

    void normalize() {
        int div = gcf(numerator, denominator);
        numerator /= div;
        denominator /= div;
        posNeg(numerator, denominator);
    }

};

// non-member non-friend + operator, calls the += operator
Rational operator+(const Rational& lhs, const Rational& rhs){
    Rational result(lhs);
    result += rhs;
    return result;
}

// non-member friend == operator
bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
}

// non-member non-friend != operator
bool operator !=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

// non-member non-friend --fraction
Rational& operator--(Rational& num){
    num += -1;
    return num;
}

// non-member non-friend fraction--
Rational operator--(Rational& num, int) {
    Rational result(num);
    num += -1;
    return result;
}

// non-member friend < operator
bool operator<(const Rational& lhs, const Rational& rhs) {
    int leftNum = lhs.numerator * rhs.denominator;
    int rightNum = rhs.numerator * lhs.denominator;
    return (leftNum < rightNum);
}
// non-member non-friend > operator
bool operator>(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs) && !(lhs == rhs);
}

// non-member non-friend >= operator
bool operator>=(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs);
}

// non-member non-friend <= operator
bool operator<=(const Rational& lhs, const Rational& rhs){
    return (lhs < rhs) || (lhs == rhs);
}


int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;

    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;

    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;

    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;

    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    // cout << "a-- -- = " << (a-- --) << endl;
    // cout << "a = " << a << endl;


    // Should report that 1 is true

    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : "
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;

}