#include <iostream>
using namespace std;

//ОГОЛОШЕННЯ ФУНКЦІЙ

//Завдання 1: Proc1
void PowerA3(double A, double &B);   // B = A^3 (A - вхідний, B - вихідний)
bool in_Proc1(double &a1, double &a2, double &a3, double &a4, double &a5); // введення з перевіркою
void task_Proc1();                   // задача Proc1 цілком

//Завдання 1: Proc14
void ShiftRight3(double &A, double &B, double &C); // правий циклічний зсув
bool in_Proc14(double &a1, double &b1, double &c1,
               double &a2, double &b2, double &c2); // введення з перевіркою
void task_Proc14();                  // задача Proc14 цілком

//Завдання 2: Integer1
bool in_L(int &pL);                  // введення з перевіркою Integer1
int sm_to_m(int pL);                 // підрахунок Integer1
void out_res(int pr);                // виведення результату Integer1
void task_Int1();                    // задача Integer1 цілком

//Допоміжні
bool inRange(double x);              // перевірка діапазону [-100,100]
void clearInput();                   // очищення після помилки введення

//MAIN
int main()
{
    int choice;
    cout << "Menu:" << endl;
    cout << "1 - Proc1" << endl;
    cout << "2 - Proc14" << endl;
    cout << "3 - Integer1" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice)                  // вибір завдання
    {
    case 1: task_Proc1();  break;
    case 2: task_Proc14(); break;
    case 3: task_Int1();   break;
    default: cout << "Wrong number" << endl;
    }
    return 0;
}

//ВИЗНАЧЕННЯ ФУНКЦІЙ

// Перевірка належності числа діапазону [-100,100]
bool inRange(double x)
{
    return (x >= -100 && x <= 100);
}

// Очищення помилки cin і буфера
void clearInput()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

//Proc1
// Обчислює третій степінь A і повертає її в B
void PowerA3(double A, double &B)
{
    B = A * A * A;
}

// Введення п'яти чисел; true - дані некоректні
bool in_Proc1(double &a1, double &a2, double &a3, double &a4, double &a5)
{
    cout << "Proc1. Enter 5 numbers from [-100,100]: ";
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    if (cin.fail())                  // помилка введення (не число)
    {
        clearInput();
        return true;
    }
    // перевірка діапазону без циклу
    if (!(inRange(a1) && inRange(a2) && inRange(a3) &&
          inRange(a4) && inRange(a5)))
        return true;
    return false;
}

void task_Proc1()
{
    double a1, a2, a3, a4, a5;       // вхідні числа
    double b1, b2, b3, b4, b5;       // їх треті степені

    if (in_Proc1(a1, a2, a3, a4, a5))
        cout << "Incorrect input data!" << endl;
    else
    {
        PowerA3(a1, b1);
        PowerA3(a2, b2);
        PowerA3(a3, b3);
        PowerA3(a4, b4);
        PowerA3(a5, b5);
        cout << "Cubes: " << b1 << " " << b2 << " " << b3 << " "
             << b4 << " " << b5 << endl;
    }
}

//Proc14
// Правий циклічний зсув: A -> B, B -> C, C -> A
void ShiftRight3(double &A, double &B, double &C)
{
    double tmp = C;                  // запам'ятовуємо C
    C = B;
    B = A;
    A = tmp;
}

// Введення двох наборів по три числа
bool in_Proc14(double &a1, double &b1, double &c1,
               double &a2, double &b2, double &c2)
{
    cout << "Proc14. Enter set 1 (A1 B1 C1) and set 2 (A2 B2 C2), "
            "numbers from [-100,100]: ";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (cin.fail())
    {
        clearInput();
        return true;
    }
    if (!(inRange(a1) && inRange(b1) && inRange(c1) &&
          inRange(a2) && inRange(b2) && inRange(c2)))
        return true;
    return false;
}

void task_Proc14()
{
    double a1, b1, c1, a2, b2, c2;

    if (in_Proc14(a1, b1, c1, a2, b2, c2))
        cout << "Incorrect input data!" << endl;
    else
    {
        ShiftRight3(a1, b1, c1);     // зсув першого набору
        ShiftRight3(a2, b2, c2);     // зсув другого набору
        cout << "Set 1: " << a1 << " " << b1 << " " << c1 << endl;
        cout << "Set 2: " << a2 << " " << b2 << " " << c2 << endl;
    }
}

//Integer1
// Введення L  з перевіркою;
bool in_L(int &pL)
{
    cout << "Integer1." << endl;
    cout << "L (sm) = ";
    cin >> pL;
    if (cin.fail())                  // перевірка помилок консольного введення
    {
        clearInput();
        return true;
    }
    if (pL < 0)                      // відстань не може бути від'ємною
        pL = -pL;
    return false;
}

// Кількість повних метрів 
int sm_to_m(int pL)
{
    return pL / 100;
}

// Виведення результату
void out_res(int pr)
{
    cout << "L (m) = " << pr << endl;
}

void task_Int1()
{
    int L;                           // відстань у сантиметрах
    if (in_L(L))                     // некоректні дані
        cout << "L must be integer!" << endl;
    else
        out_res(sm_to_m(L));         // підрахунок і виведення
}
