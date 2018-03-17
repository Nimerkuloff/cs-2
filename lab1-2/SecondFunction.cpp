/*
Функция читает содержимое файла в массив, сортирует массив по возрастанию его элементов,
записывает упорядоченный массив в новый файл (один элемент - одна строка).
	* Алгоритм сортировки: пирамидальная сортировка.
	* Тип данных в файле: трехразрядное шестнадцатеричное число.
	* Имя нового файла формируется путем добавления к имени предыдущего файла метки .sort (например,
	  filename.txt -> filename.sort.txt).
	* Функция возвращает целое число, равное общему количеству сравнений элементов массива в процессе сортировки.
*/


#include "SecondFunction.h"
#include "HeapSort.h"

using namespace std;


int SortDataset(char *filename) {
    ifstream openFile;
    openFile.open(filename);
    string line;
    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (!openFile.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    int count = 0;
    while (getline(openFile, line))
        count++;
    //Just as a sidenote, In C++11, seekg clears the eofbit flag, if set before the call. – Zermingore
    openFile.clear();
    openFile.seekg(0,
                   ios::beg);
    int *numbers = new int[count];

    for (int i = 0; i < count; i++) {
        openFile >> hex >> numbers[i];
    }
    openFile.close();

    int comparisons= HeapSort(numbers, count);

    string old_filename(filename);
    string new_filename = old_filename + ".sort";
    ofstream makeFile(new_filename);
    if (makeFile.is_open() == 0) {
        cout << "Error opening .sort file" << endl;
        return 0;
    }
    
    for (int i = 0; i < count; i++) {
        makeFile <<hex<<numbers[i] << endl;
    }
    makeFile.close();
    return comparisons;
}


