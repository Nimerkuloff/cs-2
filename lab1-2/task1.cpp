/*
������� ������� ��������� ���� (��� ����� ���������� � ���������� filename) �� strCount �����.
������ ������ �������� ������������� ����������������� �����, ��������������� ��������� �������.
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
		
		//������� (��������������) ������ ����
		FILE *fp;
		fp = fopen(filename, "w");
		//���� �� ������ (�� ������) - ������������ � ����� ������ ������� 
		if (fp == NULL){
			cout << "Error" << endl;
			return;
		}
		//16-�� �������
		char hexDigits[] = { 'A','B','C','D','E','F','0','1','2','3','4','5','6','7','8','9' };
		//��������� - ������� ��� rand()
		const int  first_value = 0;
		const int  last_value = 15;//����� hexDigits-1
		int random_number;
		int j=0;
		srand(time(0)); // �������������� ������������
		//�������� ������ ��� ������ �����
		char **hexArr = new char *[strCount];
		for (int i = 0; i<strCount; i++) {
			hexArr[i] = new char[4];
			hexArr[i][3] = '\0';
			//���������� ����� �����������
			while (j < 3) {
				random_number = first_value + rand() % last_value;
				hexArr[i][j] = hexDigits[random_number];
				j++;
			}
			j = 0;
		fputs(hexArr[i], fp);
		fputc('\n',fp);
		}
		//������� ������
		delete[] hexArr;
		fclose(fp);

		return;
	
}