// Money.h
#ifndef MONEY_H
#define MONEY_H

class Money {
private:
    unsigned int rubles;  // Рубли
    short int kopeks;     // Копейки

    void normalize();

public:
    // Конструктор по умолчанию
    Money();

    // Конструктор с параметрами
    Money(unsigned int r, short int k);

    // Метод для вывода денег
    void display() const;

    // Операции с деньгами
    Money operator-(const Money& other) const;
    Money operator-(unsigned int amount) const;

    // Операции инкремента и декремента
    Money& operator++();
    Money& operator--();

    // Преобразования типов
    operator unsigned int() const;
    operator double() const;
};

#endif // MONEY_H
