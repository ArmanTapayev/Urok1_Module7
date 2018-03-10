#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<cstring>
#include "Header.h"

int primeNumber(int *number); // Задание 4
void LineSearch(int *arr, int *len, int *key); // Задание 5
void BinarySearch(int *arr, int *len, int *key); // Задание 6
void BubleSort(int *arr, int *len); // Задание 6
void printArrayBullsAndCows(int * mas, int len); //Задание 7
int bulls(int *arr1, int *arr2, int* len); //Задание 7
int cows(int *arr1, int *arr2, int *len); //Задание 7
void getNumber(int *arr1, int len, int number); //Задание 7
void BullsAndCowsResult(int *number, int *arr2, int *len); //Задание 7
void fillArrayBullsAndCows(int * mas, int *len, int *min, int *max); //Задание 7

void printArray(int * mas, int len);
void fillArrayInteger(int * mas, int len, int *min, int *max);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n;
	do
	{
		printf("Работа содержит 8 заданий.\n");
		printf("Для выхода наберите 0.\n");
		printf("Введите номер задания: ");
		scanf("%d", &n);
		printf("\n");

		switch (n)
		{
		case 1:
		{
			/*1. Объявите указатель на целое число, называемое адресом.*/
			int a = 100;

			int *p = &a;

			printf("a = %d, *p = %d", a, p);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 2:
		{
			/*2. Назначьте значение символа 'W' переменной, на которую указывает буквенная указатель.*/
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
			/*3. Объявить указатель на текстовую строку с сообщением «Hello»*/

			const char *str = "Hello";

			printf("Hello:  *str = %d", str);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 4:
		{
			/*4. Написать функцию, которая проверяет, является ли переданное ей 
			число простым? Число называется простым, если оно делится без
			остатка только на себя и на единицу.*/
			
			int number, flag;

			printf("Введите число для проверки является ли оно простым:");
			scanf("%d", &number);

			flag = primeNumber(&number);

			if (flag==1)
				printf("Число простое");
			else
				printf("Число не является простым");

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 5:
		{
			/*5. Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.*/
			
			int A[10], len = 10, min = 10, max = 100, key, count = 0;

			printf("***Линейный поиск***.\n");

			fillArrayInteger(A, len, &min, &max);
			printArray(A, len);

			printf("Введите значение ключа key:");
			scanf("%d", &key);

			LineSearch(A, &len, &key);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 6:
		{
			/*6. Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.*/

			int A[10], len = 10, min = 10, max = 100, key, count=0;

			printf("***Бинарный поиск***.\n");
			
			fillArrayInteger(A, len, &min, &max);
			printArray(A, len);

			printf("Введите значение ключа key:");
			scanf("%d", &key);			

			BinarySearch(A, &len, &key);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 7:
		{
			/*7. Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его.
			После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и
			стоит на нужном месте (коровы). После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток.
			В программе необходимо использовать рекурсию.*/

			int number, A[4], B[4], len = 4, n, min = 1, max = 9, count = 0, C[4] = { 1,2,3,4 };
			
			printf("Игра ***Быки и коровы***.\n");
			printf("\nЦифры в загаданном числе не повторяются.\n");

			printf("\nЗагаданное число: ");
			fillArrayBullsAndCows(B, &len, &min, &max);
			printArrayBullsAndCows(B, len);
			printf("\n");

				do
				{
					printf("Введите четырехзначное число:");
					scanf("%d", &number);

					BullsAndCowsResult(&number, B, &len);

					count++;
					printf("Количество попыток %d\n", count);
					printf("Для продолжения наберите любое число, для выхода наберите 0\n");
					scanf("%d", &n);

				} while (n != 0);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 8:
		{
			/*8. Каков результат следующего сегмента программы?*/

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

