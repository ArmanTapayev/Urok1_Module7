#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include "Header.h"

// Задание 4
int primeNumber(int *number)
{
	int flag = 1;
	for (int i = 2; i <= *number / 2; ++i)
	{
		if (*number%i==0)
		{
			flag=0;
			break;
		}		
		
	}
		return flag;
}

//Задание 5
void LineSearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);

	for (int i = 0; i < *len; i++) // просматриваем все элементы в цикле
	{
		if (arr[i] == *key)      // если находим элемент со значением key,
		{
			printf("\nЭлемент A[%d]=%d найдем за %d проходов.\n", i, arr[i], i); 
			break;
		}
					
	}
	
}

//Задание 6

void BinarySearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);
	int left = 0; // задаем левую и правую границы поиска
	int right = *len-1;
	int search = -1; // найденный индекс элемента равен -1 (элемент не найден)
	int count = 0;

	while (left <= right) // пока левая граница не "перескочит" правую
	{
		count++;
		int mid = (left + right) / 2; // ищем середину отрезка

									  // если ключевое поле равно искомому
									  // мы нашли требуемый элемент, выходим из цикла
		if (*key == arr[mid])
		{
			search = mid;
			break;
		}


		if (*key < arr[mid])     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}

	if (search == -1)     // если индекс элемента по-прежнему -1, элемент не найден
		printf("\nЭлемент не найден!");

	else          // иначе выводим элемент, его ключ и значение
		printf("\nЭлемент A[%d]=%d найдем за %d проходов.\n", search, arr[search], count);

}

void BubleSort(int *arr, int *len)
{  
	printf("\nМассив после сортировки:\n");

	for (int i = 0; i < *len; i++)
	{
		for (int j = (*len - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (arr[j - 1] > arr[j]) // если текущий элемент меньше предыдущего
			{
				int temp = arr[j - 1]; // меняем их местами
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
		
		printf("A[%d]=%d ", i, arr[i]);
	}
}

// Задание 7
void fillArrayBullsAndCows(int *mas, int *len, int *min, int *max)
{
	int i=0, flag =0;
	
		while (i < 4) 
		{
			mas[i] = mas[i] = rand() * (*max - *min) / RAND_MAX + *min;

				for (int j = 0; j < i; j++)
				{
					if (mas[i] == mas[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)		
					i++;
		
			flag = 0;
		}

}

void printArrayBullsAndCows(int * mas, int len)
{
	static int i = 4;

		if (i > 0)
		{
			printf("%d", mas[len-i]);
			i--;
			printArrayBullsAndCows(mas, len);
		}

}

int bulls(int *arr1, int *arr2, int *len)
{
	int bullsCount = 0;
	for (int i = 0; i < *len; i++)
	{	
		if (*(arr1+i) == *(arr2+i))
			{
				bullsCount++;			
			}		
	}
	//printf("Быков: %d\n", bullsCount);
	return bullsCount;
}

int cows(int *arr1, int *arr2, int *len)
{
	int cowsCount = 0;
	for (int i = 0; i < *len; i++)
	{
		for (int j = 0; j < *len; j++)
		{
			if ((*(arr1+i) == *(arr2+j))&& (i!=j))
			{
				cowsCount++;
			}
		}
	}
	//printf("Коров: %d\n", cowsCount);
	return cowsCount;
}

void getNumber(int *arr1, int len, int number)
{
		if(len>=0 && number>0)
		{
			arr1[len-1] = number % 10;
			number /= 10;
			getNumber(arr1, len - 1, number);
		}

}

void BullsAndCowsResult(int *number, int *arr2, int *len)
{
	int arr1[4];
	int lenNumber = *len;
	int numberNumber = *number;
	getNumber(arr1, lenNumber, numberNumber);
	
	int bull, cow;

	bull = bulls(arr1, arr2, len);
	cow = cows(arr1, arr2, len);

	printf("Быков: %d, Коров: %d\n", bull, cow);

	if (bull == 4)
		printf("Вы победили!\n");

}


void fillArrayInteger(int * mas, int len, int *min, int *max)
{
	for (int i = 0; i < len; i++)
		mas[i] = rand() * (*max - *min) / RAND_MAX + *min;
}

void printArray(int * mas, int len)
{
	printf("\nИсходный массив:\n");
	for (int i = 0; i < len; i++)
		printf("A[%d]=%d ", i, mas[i]);
	printf("\n");
}

