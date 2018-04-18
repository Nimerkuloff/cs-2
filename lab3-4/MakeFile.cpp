//
// Created by nimerkuloff on 14/04/18.
//
/*
Функция создает текстовый файл (имя файла передается в переменной filename) из strCount строк.
Каждая строка содержит трехразрядное шестнадцатеричное число, сгенерированное случайным образом.
*/

#include "MakeFile.h"




const int FIRST_VALUE = 0x100;
const int LAST_VALUE = 0xEFF;// 0xFFF-100
using namespace std;


void MakeFile(string filename, int strCount) {
    //Создаем (перезаписываем) пустой файл
    ofstream makeFile(filename);

    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (makeFile.is_open() == 0) {
        cout << "Error" << endl;
        return;
    }

    int randomNumber;
    srand(time(0)); // меняем случайные числа при каждом запуске

    for (int i = 0; i < strCount; i++) {
        randomNumber = FIRST_VALUE + rand() % LAST_VALUE;
        makeFile << hex << randomNumber << endl;
    }

    makeFile.close();
}
