// Money.cpp
#include "Money.h"
#include <iostream>

// Конструктор по умолчанию
Money::Money() : rubles(0), kopeks(0) {}

// Конструктор с параметрами
Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k) {
    normalize();
}

// Нормализация копеек (если больше 100 или меньше 0)
void Money::normalize() {
    if (kopeks >= 100) {
        rubles += kopeks / 100;
        kopeks = kopeks % 100;
    } else if (kopeks < 0) {
        rubles -= (-kopeks) / 100 + 1;
        kopeks = 100 - (-kopeks) % 100;
    }
}

// Метод для вывода денег
void Money::display() const {
    std::cout << "Деньги: " << rubles << " рублей и " << kopeks << " копеек." << std::endl;
}

// Операция вычитания Money
Money Money::operator-(const Money& other) const {
    int total_kopeks1 = rubles * 100 + kopeks;
    int total_kopeks2 = other.rubles * 100 + other.kopeks;
    int result_kopeks = total_kopeks1 - total_kopeks2;

    if (result_kopeks < 0) {
        return Money(0, 0);
    }

    unsigned int result_rubles = result_kopeks / 100;
    short int result_kopeks_final = result_kopeks % 100;

    return Money(result_rubles, result_kopeks_final);
}

// Операция вычитания с беззнаковым числом
Money Money::operator-(unsigned int amount) const {
    int total_kopeks = (rubles * 100 + kopeks) - (amount * 100);

    if (total_kopeks < 0) {
        return Money(0, 0);
    }

    return Money(total_kopeks / 100, total_kopeks % 100);
}

// Префиксный инкремент
Money& Money::operator++() {
    kopeks++;
    normalize();
    return *this;
}

// Префиксный декремент
Money& Money::operator--() {
    kopeks--;
    normalize();
    return *this;
}

// Преобразование к unsigned int (рубли)
Money::operator unsigned int() const {
    return rubles;
}

// Преобразование к double (копейки в рубли)
Money::operator double() const {
    return kopeks / 100.0;
}
