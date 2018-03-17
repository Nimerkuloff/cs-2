//
// Created by nimerkuloff on 28-Feb-18.
//

/*
Функция создает текстовый файл (имя файла передается в переменной filename) из strCount строк.
Каждая строка содержит трехразрядное шестнадцатеричное число, сгенерированное случайным образом.
*/


#include "FirstFunction.h"

const int FIRST_VALUE = 0x100;
const int LAST_VALUE = 0xEFF;// 0xFFF-100
using namespace std;


void GenerateDataset(char *filename, int strCount) {
    //Создаем (перезаписываем) пустой файл
    ofstream makeFile(filename);

    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (makeFile.is_open() == 0) {
        cout << "Error" << endl;
        return;
    }

    int randomNumber;
    srand(time(0)); // автоматическая рандомизация

    for (int i = 0; i < strCount; i++) {
        randomNumber = FIRST_VALUE + rand() % LAST_VALUE;
        makeFile << hex << randomNumber << endl;
    }

    makeFile.close();
}
