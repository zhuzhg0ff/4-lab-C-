// main.cpp
#include <iostream>
#include "Money.h"

int main() {
    unsigned int rubles1, rubles2;
    short int kopeks1, kopeks2;

    // Ввод данных для первого объекта
    std::cout << "Введите рубли и копейки для первого объекта: ";
    std::cin >> rubles1 >> kopeks1;

    // Ввод данных для второго объекта
    std::cout << "Введите рубли и копейки для второго объекта: ";
    std::cin >> rubles2 >> kopeks2;

    // Создаем два объекта класса Money
    Money money1(rubles1, kopeks1);
    Money money2(rubles2, kopeks2);

    // Выводим введенные данные
    std::cout << "Первый объект: ";
    money1.display();
    std::cout << "Второй объект: ";
    money2.display();

    // Операция вычитания Money
    Money result = money1 - money2;
    std::cout << "Результат вычитания Money: ";
    result.display();

    // Операции инкремента и декремента
    ++money1;
    --money2;

    std::cout << "После инкремента первого объекта: ";
    money1.display();
    std::cout << "После декремента второго объекта: ";
    money2.display();

    // Преобразование типов
    unsigned int rubles_from_money = money1;
    double kopeks_from_money = static_cast<double>(money2);

    std::cout << "Первый объект как количество рублей: " << rubles_from_money << " рублей" << std::endl;
    std::cout << "Второй объект как копейки в рублях (неполные рубли): " << kopeks_from_money << std::endl;

    // Вычитание с беззнаковым целым числом
    unsigned int amount = 2;  // Например, 2 рубля
    Money result2 = money1 - amount;
    std::cout << "Результат вычитания с числом " << amount << " рублей: ";
    result2.display();

    return 0;
}
