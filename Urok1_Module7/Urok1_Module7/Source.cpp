#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<cstring>
#include "Header.h"

int primeNumber(int *number); // ������� 4
void LineSearch(int *arr, int *len, int *key); // ������� 5
void BinarySearch(int *arr, int *len, int *key); // ������� 6
void BubleSort(int *arr, int *len); // ������� 6
void printArrayBullsAndCows(int * mas, int len); //������� 7
int bulls(int *arr1, int *arr2, int* len); //������� 7
int cows(int *arr1, int *arr2, int *len); //������� 7
void getNumber(int *arr1, int len, int number); //������� 7
void BullsAndCowsResult(int *number, int *arr2, int *len); //������� 7
void fillArrayBullsAndCows(int * mas, int *len, int *min, int *max); //������� 7

void printArray(int * mas, int len);
void fillArrayInteger(int * mas, int len, int *min, int *max);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n;
	do
	{
		printf("������ �������� 8 �������.\n");
		printf("��� ������ �������� 0.\n");
		printf("������� ����� �������: ");
		scanf("%d", &n);
		printf("\n");

		switch (n)
		{
		case 1:
		{
			/*1. �������� ��������� �� ����� �����, ���������� �������.*/
			int a = 100;

			int *p = &a;

			printf("a = %d, *p = %d", a, p);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 2:
		{
			/*2. ��������� �������� ������� 'W' ����������, �� ������� ��������� ��������� ���������.*/
			char W = 'W';

			char *p = &W;

			char w = *p;

			printf("W = %d, *p = %d, w = %d", W, p, w);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 3:
		{
			/*3. �������� ��������� �� ��������� ������ � ���������� �Hello�*/

			const char *str = "Hello";

			printf("Hello:  *str = %d", str);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 4:
		{
			/*4. �������� �������, ������� ���������, �������� �� ���������� �� 
			����� �������? ����� ���������� �������, ���� ��� ������� ���
			������� ������ �� ���� � �� �������.*/
			
			int number, flag;

			printf("������� ����� ��� �������� �������� �� ��� �������:");
			scanf("%d", &number);

			flag = primeNumber(&number);

			if (flag==1)
				printf("����� �������");
			else
				printf("����� �� �������� �������");

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 5:
		{
			/*5. �������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.*/
			
			int A[10], len = 10, min = 10, max = 100, key, count = 0;

			printf("***�������� �����***.\n");

			fillArrayInteger(A, len, &min, &max);
			printArray(A, len);

			printf("������� �������� ����� key:");
			scanf("%d", &key);

			LineSearch(A, &len, &key);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 6:
		{
			/*6. �������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.*/

			int A[10], len = 10, min = 10, max = 100, key, count=0;

			printf("***�������� �����***.\n");
			
			fillArrayInteger(A, len, &min, &max);
			printArray(A, len);

			printf("������� �������� ����� key:");
			scanf("%d", &key);			

			BinarySearch(A, &len, &key);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 7:
		{
			/*7. �������� ���� ����� � �������. ��������� "����������" ������������� ����� � �������� ������ ������� ���.
			����� ����� ������������� ����� ��������� ��������, ������� ���� ����� ������� (����) � ������� ���� ������� �
			����� �� ������ ����� (������). ����� ����������� ����� �� ����� ���������� ������� ���������� ��������� ������������� �������.
			� ��������� ���������� ������������ ��������.*/

			int number, A[4], B[4], len = 4, n, min = 1, max = 9, count = 0, C[4] = { 1,2,3,4 };
			
			printf("���� ***���� � ������***.\n");
			printf("\n����� � ���������� ����� �� �����������.\n");

			printf("\n���������� �����: ");
			fillArrayBullsAndCows(B, &len, &min, &max);
			printArrayBullsAndCows(B, len);
			printf("\n");

				do
				{
					printf("������� �������������� �����:");
					scanf("%d", &number);

					BullsAndCowsResult(&number, B, &len);

					count++;
					printf("���������� ������� %d\n", count);
					printf("��� ����������� �������� ����� �����, ��� ������ �������� 0\n");
					scanf("%d", &n);

				} while (n != 0);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 8:
		{
			/*8. ����� ��������� ���������� �������� ���������?*/

			int  count = 10, *temp, sum = 0;
			temp = &count;
			*temp = 20;
			temp = &sum;
			*temp = count;
			printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum);

			printf("\n");
			system("pause");
			system("cls");
		}break;
		}
	} while (n != 0);
}

