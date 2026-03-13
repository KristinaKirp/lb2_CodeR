/*Дано число D и указатель P1 на вершину непустого стека.
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

//FIX_ME: убираем using namespace std и подключаем header файл
#include <iostream>
#include <string>
#include "Header.h"

//using namespace std;

int main()
{
    std::setlocale(LC_ALL, "rus");

    Stack StackObject;

    std::string InputChoice;
    std::string InputValue;

    int Choice;
    int Value;

    while (true)
    {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент в стек\n";
        std::cout << "2. Удалить элемент из стека\n";
        std::cout << "3. Вывести элементы стека\n";
        std::cout << "4. Очистить стек\n";
        std::cout << "0. Выйти\n";
        std::cout << "Введите ваш выбор: ";

        //FIX_ME: добавляем проверку корректности ввода

        /*
        cin >> choice;
        */

        std::cin >> InputChoice;

        if (!IsNumber(InputChoice))
        {
            std::cout << "Ошибка: необходимо ввести число.\n";
            continue;
        }

        Choice = std::stoi(InputChoice);

        switch (Choice)
        {
        case 1:

            std::cout << "Введите число для добавления в стек: ";

            //FIX_ME: переписываем ввод числа с проверкой

            /*
            cin >> value;
            */

            std::cin >> InputValue;

            if (!IsNumber(InputValue))
            {
                std::cout << "Ошибка: необходимо ввести число.\n";
                break;
            }

            Value = std::stoi(InputValue);

            AddElementAndPrintAddress(StackObject, Value);

            break;

        case 2:
            //stack.pop();

            StackObject.Pop();

            break;

        case 3:
            //stack.print();

            StackObject.Print();

            break;

        case 4:
            //stack.clearStack();

            StackObject.ClearStack();

            break;

        case 0:

            std::cout << "Выход из программы." << std::endl;
            return 0;

        default:

            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
}