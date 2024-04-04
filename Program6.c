/*
COSC2420 - 001
Program 6 Spring 2023
Cesar A. Reyna
19 April 2023
This progam asks the user to enter 1 for first class and 2 for second class then assigns a seat based on their selection.
*/



#include<stdio.h>

#define Size 5
void print(int array[]);
void fillFirst();
void fillSecond();
int killFlag = 0;
int array1Full = 0;
int array2Full = 0;
int firstClass[Size] = { 0 };
int economyClass[Size] = { 0 };

int main() {

	int flag = 1;
	int userInput = 0;

	while (flag==1) {
		printf("Please type 1 for first class, 2 for  economy: \n");
		scanf_s("%d", &userInput);
		if (userInput == 1 && array1Full==0) {
			fillFirst();
		}
		else if (userInput == 2 && array2Full==0) {
			fillSecond();
		}
		else if (array1Full == 1 && array2Full == 1) {
			printf("Flight full next flight in 3 hours\n");
			exit(0);
		}
		else if (userInput ==1 && array1Full==1) {
			printf("First class is full next flight in 3 hours thank you good bye. \n");
			print(firstClass);
			flag = 0;
		}
		else if (userInput == 2 && array2Full == 1) {
			printf("Economy class is full next flight in 3 hours thank you good bye. \n");
			print(economyClass);
			flag = 0;
		}
		else {
			printf("bad input try again \n");
		}
			
	}

}

void print(int array[])
{
	printf("[");
	for (int i = 0; i < Size; i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}

void fillFirst() {
	int userInput = 0;
	int flag = 0;
	for (int i = 0; i < Size; i++) {
			if (i == 4 && firstClass[i] != 0 && array1Full==0) //special case first class full
			{
				while (flag == 0)
				{
					if (killFlag == 0)
					{
						printf("First is full would you like to switch to economy 1 for yes 2 for no: \n");
						scanf_s("%d", &userInput);
						if (userInput == 1) {
							array1Full = 1;
							i = 5;
							flag = 1;
						}
						else if (userInput == 2) {
							printf("Thank you next flight is in 3 hours ending program: \n");
							exit(0);
						}
						else {
							printf("Invalid input please try again: \n");
						}
					}
					else if (killFlag == 1) {
						printf("Thank you (in first) next flight is in 3 hours ending program: \n");
						exit(0);
					}
					else if (array1Full == 1 && array2Full == 1) {
						printf("Flight full next flight in 3 hours\n");
						exit(0);
					}
				}
			}
			else if (firstClass[i] == 0) {
				firstClass[i] = 1;
				printf("======================================================\n");
				printf("-- Seat assigned in first class seat number %d --\n", i + 1);
				print(firstClass);
				printf("======================================================\n");
				i = 5;
			}
			else if (array1Full == 1) {

			}
	}

}

void fillSecond()
{
	int userInput = 0;
	int flag = 0;
	for (int i = 0; i < Size; i++) {
		if (i == 4 && economyClass[i] != 0) //special case first class full
		{
			while (flag == 0)
			{
				if (killFlag == 0)
				{
					printf("Economy is full would you like to switch to First 1 for yes 2 for no: \n");
					scanf_s("%d", &userInput);
					if (userInput == 1) {
						array2Full = 1;
						i = 5;
						flag = 1;
					}
					else if (userInput == 2) {
						printf("Thank you next flight is in 3 hours ending program: \n");
						exit(0);
					}
					else {
						printf("Invalid input please try again: \n");
					}
				}
				else if (killFlag == 1) {
					printf("Thank you next (in second) flight is in 3 hours ending program: \n");
					exit(0);
				}
				else if (array1Full == 1 && array2Full == 1) {
					printf("Flight full next flight in 3 hours\n");
					exit(0);
				}
			}
		}
		else if (economyClass[i] == 0) {
			economyClass[i] = 1;
			printf("======================================================\n");
			printf("-- Seat assigned in economy class seat number %d --\n", i + 6);
			print(economyClass);
			printf("======================================================\n");
			i = 5;
		}
	}
}
