/*
1. Написать функцию со следующим прототипом: void GenerateDataset (char *filename, int num).
Функция создает текстовый файл (имя файла передается в переменной filename)из strCount строк. 
Каждая строка содержит трехразрядное шестнадцатеричное число, сгенерированное случайным образом.

2. Написать функцию со следующим прототипом: int SortDataset (char *filename). 
Функция читает содержимое файла в массив, сортирует массив по возрастанию его элементов, 
записывает упорядоченный массив в новый файл (один элемент - одна строка). 
	* Алгоритм сортировки: пирамидальная сортировка. 
	* Тип данных в файле: см. условие задачи 1. 
	* Имя нового файла формируется путем добавления к имени предыдущего файла метки .sort (например,
	  filename.txt -> filename.sort.txt). 
	* Функция возвращает целое число, равное общему количеству сравнений элементов массива в процессе сортировки.
*/

#include "FirstFunction.h"
#include "SecondFunction.h"


using namespace std;

int main() {
    char filename[256];
    int strCount;

    cout << "Input file name" << endl;
    cin >> filename;
    cout << "Input qty of strings" << endl;
    cin >> strCount;

    GenerateDataset(filename, strCount);
    cout<<"Qty of comparisons"<<endl<<SortDataset(filename);
    return 0;
}

