// *********************************************************************
// COSC 2420-001
// Programing Assignment 1 - Spring 2023
// Author: Cesar Reyna
// Due: 2/1/2023
// Program Description: This program satisfies the request of the assignment. 
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 1: 
// receives two integers from terminal operator, and displays to the screen
// their sum, diffrence, product and quotient.
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 2:
// Constructs an algorithm that will receive an integer from the screen, add 5 to it, 
// double it, subtract 7 from it, and display the final number to the screen.
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 3:
// A program is required to prompt the terminal operator for the maximum and minimum 
// temperature readings on a particular day, accept those readings as integer, and calculateand
// display to the screen the simple average temperature, calculated by(maximum temperature +
// minimum temperature) / 2. I noticed that there is a possiblility to truncate giving a poor
// aproximation of the simple average, so I decided to cast my integers as double and display 
// my result as double.
// ____________________________________________________________________
// ____________________________________________________________________ 
// Each problems end is displayed on the screen and a blank line seperates each section.
// 
//




#include <stdio.h>

int main() {


	//problem 1

	int x, y;
	printf("Enter two integers \n");
	scanf_s("%d %d", &x,&y);
	printf("%d + %d = %d \n",x,y,x+y);
	printf("%d - %d = %d \n", x, y, x - y);
	printf("%d * %d = %d\n", x, y, x * y);
	printf("%d / %d = %d\n", x, y, x / y);
	printf("End of Problem 1: \n\n");
	

	//problem 2 Construct an algorithm that will receive an integer from the screen, add 5 to it, 
	//double it, subtract 7 from it, and display the final number to the screen

	int x2,x22;
	printf("Enter an integers \n");
	scanf_s("%d", &x2);
	x22 = (x2 + 5) * 2 - 7;
	printf("((%d + 5)2)-7 = %d \n", x2 ,x22);
	printf("End of Problem 2: \n\n");
	
	//A program is required to prompt the terminal operator for the maximum and minimum 
	//temperature readings on a particular day, accept those readings as integer, and calculateand
	//	display to the screen the simple average temperature, calculated by(maximum temperature +
	//		minimum temperature) / 2.

	int t1, t2;
	double t3;
	printf("Enter max and min temperatures as integers \n");
	scanf_s("%d %d", &t1, &t2);
	t3 = (t1 + t2) / 2.0;
	printf("The simple average temperature is: %5.2f \n\n", t3);
	printf("End of Problem 3 and Programing assignment 1: \n");

	return 0;
}