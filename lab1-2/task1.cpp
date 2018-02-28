/*
Функция создает текстовый файл (имя файла передается в переменной filename) из strCount строк.
Каждая строка содержит трехразрядное шестнадцатеричное число, сгенерированное случайным образом.
*/
#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h"
#pragma once
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
#include <ctime>
using namespace std;
void GenerateDataset(char *filename, int strCount){
		
		//Создаем (перезаписываем) пустой файл
		FILE *fp;
		fp = fopen(filename, "w");
		//Файл не создан (не открыт) - возвращаемся в место вызова функции 
		if (fp == NULL){
			cout << "Error" << endl;
			return;
		}
		//16-ые символы
		char hexDigits[] = { 'A','B','C','D','E','F','0','1','2','3','4','5','6','7','8','9' };
		//Константы - границы для rand()
		const int  first_value = 0;
		const int  last_value = 15;//длина hexDigits-1
		int random_number;
		int j=0;
		srand(time(0)); // автоматическая рандомизация
		//Выделяем память под массив строк
		char **hexArr = new char *[strCount];
		for (int i = 0; i<strCount; i++) {
			hexArr[i] = new char[4];
			hexArr[i][3] = '\0';
			//Генерируем число посимвольно
			while (j < 3) {
				random_number = first_value + rand() % last_value;
				hexArr[i][j] = hexDigits[random_number];
				j++;
			}
			j = 0;
		fputs(hexArr[i], fp);
		fputc('\n',fp);
		}
		//Очищаем память
		delete[] hexArr;
		fclose(fp);

		return;
	
}
