#include <stdio.h>

typedef struct {
    long num, den;
} Fraction;

long gcd(long first, long second) {
    while (second != 0) { long rest = first % second; first = second; second = rest; }
    return first < 0 ? -first : first;
}

Fraction simplify(Fraction value) {
    long divisor = gcd(value.num, value.den);
    value.num /= divisor;
    value.den /= divisor;
    return value;
}

Fraction add(Fraction first, Fraction second) {
    Fraction sum = {first.num * second.den + second.num * first.den, first.den * second.den};
    return simplify(sum);
}

Fraction multiply(Fraction first, Fraction second) {
    Fraction product = {first.num * second.num, first.den * second.den};
    return simplify(product);
}

int main(void) {
    Fraction first = {1, 3}, second = {1, 4}, oneThird = {1, 3};
    Fraction taken = add(first, second);
    Fraction rest = {taken.den - taken.num, taken.den};     // 1 - taken
    Fraction third = multiply(rest, oneThird);
    Fraction left = add(taken, third);
    printf("Partner 1: %ld/%ld\nPartner 2: %ld/%ld\nPartner 3: %ld/%ld\n",
           first.num, first.den, second.num, second.den, third.num, third.den);
    printf("Reinvested: %ld/%ld of profit\n", left.den - left.num, left.den);
    return 0;
}
