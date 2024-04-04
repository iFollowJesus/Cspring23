// *********************************************************************
// COSC 2420-001
// Programing Assignment 2 - Spring 2023
// Author: Cesar Reyna
// Due: 2/20/2023
// Program Description: This program satisfies the request of the assignment. 
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 1: 
// Accept user input of date and bday
// accounts for a user inputing a bday that is in the future
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 2:
// Calculate age
// calculate mhr
// calculate thr range
// ____________________________________________________________________
// ____________________________________________________________________
// Problem 3:
// print results
// ____________________________________________________________________
// ____________________________________________________________________ 
// 
// 
//




#include <stdio.h>

int main() {


	//problem 1 integers xyz for bday and integers abc for todays day

	int x, y, z, a, b, c, age1, mhr, donothing;
	double thr1, thr2;
	int doitdoit = 1;

	while (doitdoit == 1) {
		printf("Enter Birthdate seperated by spaces in format mm dd yyyy \n");
		scanf_s("%d %d %d", &x, &y, &z);
		printf("Enter Todays date seperated by spaces in format mm dd yyyy \n");
		scanf_s("%d %d %d", &a, &b, &c);
		donothing = c - z;
		if (donothing < 0)
			printf("Please explain how you where born in the future? Please enter a valid birthdate. \n");
		else
			doitdoit = 0;
	}


	//problem 2 calculations donothing used as a statment to prevent an error.
	// used to debug printf("x = %d y = %d z = %d a = %d b = %d c = %d \n\n\n", x, y, z, a, b, c);
	donothing = 0;
	age1 = 0;

	age1 = c - z;

	if (a >= x)
	{
		++donothing;
		if (b >= y) 
		{
			++donothing;
		}	
		else if (a>x)
		{
			++donothing;
		}
		else
		{
			--age1;
		}		
	}
	else
	{
		--age1;
	}
		

	mhr = 220 - age1;
	thr1 = mhr * .5;
	thr2 = mhr * .85;

	//problem 3 print results
	printf("========================================== \n");
	printf("D.O.B. : %d/%d/%d \n", x, y, z);
	printf("Age    : %d \n", age1);
	printf("MHR    : %d \n", mhr);
	printf("THR    : %5.2f - %5.2f \n", thr1, thr2);
	printf("========================================== \n");
	printf("========================================== \n");
	printf("End of Project 2: \n\n");

	return 0;
}
