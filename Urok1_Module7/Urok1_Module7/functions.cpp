#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include "Header.h"

// ������� 4
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

//������� 5
void LineSearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);

	for (int i = 0; i < *len; i++) // ������������� ��� �������� � �����
	{
		if (arr[i] == *key)      // ���� ������� ������� �� ��������� key,
		{
			printf("\n������� A[%d]=%d ������ �� %d ��������.\n", i, arr[i], i); 
			break;
		}
					
	}
	
}

//������� 6

void BinarySearch(int *arr, int *len, int *key)
{
	BubleSort(arr, len);
	int left = 0; // ������ ����� � ������ ������� ������
	int right = *len-1;
	int search = -1; // ��������� ������ �������� ����� -1 (������� �� ������)
	int count = 0;

	while (left <= right) // ���� ����� ������� �� "����������" ������
	{
		count++;
		int mid = (left + right) / 2; // ���� �������� �������

									  // ���� �������� ���� ����� ��������
									  // �� ����� ��������� �������, ������� �� �����
		if (*key == arr[mid])
		{
			search = mid;
			break;
		}


		if (*key < arr[mid])     // ���� ������� �������� ���� ������ ��������� ��������
			right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
		else
			left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
	}

	if (search == -1)     // ���� ������ �������� ��-�������� -1, ������� �� ������
		printf("\n������� �� ������!");

	else          // ����� ������� �������, ��� ���� � ��������
		printf("\n������� A[%d]=%d ������ �� %d ��������.\n", search, arr[search], count);

}

void BubleSort(int *arr, int *len)
{  
	printf("\n������ ����� ����������:\n");

	for (int i = 0; i < *len; i++)
	{
		for (int j = (*len - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			if (arr[j - 1] > arr[j]) // ���� ������� ������� ������ �����������
			{
				int temp = arr[j - 1]; // ������ �� �������
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
		
		printf("A[%d]=%d ", i, arr[i]);
	}
}

// ������� 7
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
	//printf("�����: %d\n", bullsCount);
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
	//printf("�����: %d\n", cowsCount);
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

	printf("�����: %d, �����: %d\n", bull, cow);

	if (bull == 4)
		printf("�� ��������!\n");

}


void fillArrayInteger(int * mas, int len, int *min, int *max)
{
	for (int i = 0; i < len; i++)
		mas[i] = rand() * (*max - *min) / RAND_MAX + *min;
}

void printArray(int * mas, int len)
{
	printf("\n�������� ������:\n");
	for (int i = 0; i < len; i++)
		printf("A[%d]=%d ", i, mas[i]);
	printf("\n");
}

