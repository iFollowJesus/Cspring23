/*
* 
Cesar Reyna
COSC 2420
V. Vuckovic
Project 3
3/8/2023
=======================================================================
The program accepts double values for time of call and length of call
of format 00.00 for time and 00.00 for length. It will loop back and
ask for valid data if the time entered is not in range. It will then do
some calculations to give the cost of the call and discount applied as 
per the prompt. Please give any suggestions for improvment, thank you.
=======================================================================
*
*/



#include <stdio.h>
#include <math.h>
int main()
{
	float timeOfCall = 0.00, lengthOfCall=0.00, cost=0.00;
	int discount;
	int flag = 1;
	while (flag == 1)
	{
		printf("Please enter time of call and length of call in format 00.00 00.00 \n");
		scanf_s("%f %f", &timeOfCall, &lengthOfCall);
		if (timeOfCall > .01 && timeOfCall < 25.00)
		{
			printf("inside flag body\n");
			flag = 0;
			discount = "none";
		}
		else
			printf("invalid time please try again.\n");
		lengthOfCall = ceil(lengthOfCall);
		printf("Length of call = %5.2f \n", lengthOfCall);
	}
	if (lengthOfCall > 1)
	{
		if (timeOfCall > 7 && timeOfCall < 16)
		{
			printf("inside discount 0\n");
			cost = (lengthOfCall - 1) * .37 + .49;
			discount = 0;
		}
		else if (timeOfCall > 15 && timeOfCall < 22)
		{
			printf("inside discount 35\n");
			cost = ((lengthOfCall - 1) * .37) - ((lengthOfCall - 1) * .37 * .35) + .49;
			discount = 35;
		}

		else
		{
			printf("inside discount 65\n");
			cost = ((lengthOfCall - 1) * .37) - ((lengthOfCall - 1) * .37 * .65) + .49;
			discount = 65;
		}
	}
	else if (lengthOfCall = 1)
		cost = .49;

	printf("=====================================================================\n");
	printf("Time of Call     Length of call     Cost of Call     Discount applied\n");
	printf("=====================================================================\n");
	printf("%4.2f            %.0f Minuets       $%4.2f            %d percent\n", timeOfCall, lengthOfCall, cost, discount);


	
}