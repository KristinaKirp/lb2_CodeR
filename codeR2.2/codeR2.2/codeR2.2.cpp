/* Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из
исходного набора с нечетными номерами (1, 3, …, 9), а вторая — с четными (2, 4, …, 10);
порядок чисел в каждой очереди должен совпадать с порядком чисел в исходном наборе.
Вывести указатели на начало и конец первой, а затем второй очереди.
Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.
*/

//FIX_ME: убираем using namespace std и подключаем собственный header
#include <iostream>
#include <windows.h>
#include <string>
#include "Header.h"

//using namespace std;

int main()
{
    std::setlocale(LC_ALL, "Russian");

    //FIX_ME: приводим названия переменных и классов к стандарту Epic Games (PascalCase).
    // В исходном коде названия написаны транслитом и не соответствуют код-стайлу.

    //Ochered Ochered1, Ochered2;

    Queue OddQueue;
    Queue EvenQueue;

    //Ochered1.Inicializaciya();
    //Ochered2.Inicializaciya();

    OddQueue.Initialize();
    EvenQueue.Initialize();

    std::cout << "Введите 10 чисел:\n";

    for (int i = 1; i <= 10; i++)
    {
        std::string Input;
        int Number;

        //FIX_ME: переписываем ввод с использованием строки и проверки корректности данных

        /*
        int Chislo;
        cout << "Число " << i << ": ";
        cin >> Chislo;

        if (cin.fail()) {
            cout << "Ошибка! Введите число!\n";
            return 0;
        }
        */

        std::cout << "Число " << i << ": ";
        std::cin >> Input;

        if (!IsNumber(Input))
        {
            std::cout << "Ошибка: необходимо ввести целое число.\n";
            return 1;
        }

        Number = std::stoi(Input);

        //FIX_ME: меняем имена методов в соответствии со стилем Epic Games

        //if (i % 2 != 0) Ochered1.DobavitElement(Chislo);
        //else Ochered2.DobavitElement(Chislo);

        if (i % 2 != 0)
        {
            OddQueue.AddElement(Number);
        }
        else
        {
            EvenQueue.AddElement(Number);
        }
    }

    std::cout << "\nНечетная очередь:\n";

    //Ochered1.VivodElementov();
    //Ochered1.VivodUkazatelei();

    OddQueue.PrintElements();
    OddQueue.PrintPointers();

    std::cout << "\nЧетная очередь:\n";

    //Ochered2.VivodElementov();
    //Ochered2.VivodUkazatelei();

    EvenQueue.PrintElements();
    EvenQueue.PrintPointers();

    return 0;
}