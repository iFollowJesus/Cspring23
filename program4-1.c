/*
* 
* Cesar Reyna
* COSC 2430
* V. Vuckovic
* Program 4
* 3/22/2023
*
*Write the C code that will solve the following programming problem :
*Write a program that prints the following diamond shape.You may use printf statements that print
*either a single asterisk(*) or a single blank.Maximize your use of iteration(with nested for
*statements) and minimize the number of printf statements.In addition, your program should read
*an odd number in the range of 1 to 19 to specify the number of rows in the diamond.Your program
*should then display a diamond of the appropriate size.
* PsedoCODE:
*
* 
* /////TOP HALF////////
* ask user for number 1-19
* check number is in range n>0 and N<20
* check number is odd n%2 = 0
* else ask for a number that meets criteria
* the diamond prints floor(n/2)-0 spaces then ceil(n/2) - floor(n/2)-0 + 0 star
* the diamond prints floor(n/2)-1 spaces then ceil(n/2) - floor(n/2)-1 + 1 star
* the diamond prints floor(n/2)-2 spaces then ceil(n/2) - floor(n/2)-2 + 2 star
* pattern is
*
* print floorVariable - counter spaces then (ceilVariable - (floorVariable - counter)) + counter stars
* until counter < ceilvariable
*
* ///BOTTOM HALF///
* print 0 space n asteriks
* print 1 space and n-2 asteriks
* print 2 space and n-4 asteriks
* print 3 space and n-6 asteriks
* 
* 
* 
* 
* 
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int userInput, count;
	double  floorVariable, ceilVariable;
	char space = ' ';
	int flag = 0;
	while (flag == 0)
	{
		printf("Please enter an odd number (valid entries 1-19): ");
		scanf_s("%d", &userInput);
		if (userInput > 0 && userInput < 20)
			if (userInput % 2 != 0)
				flag = 1;
			else
			{
				flag = 0;
				printf("Invalid input starting over. ");
			}
		else
		{
			flag = 0;
			printf("Invalid input starting over. ");
		}
	}

	floorVariable = floor((double)userInput / 2);
	ceilVariable = ceil((double)userInput / 2);

	/*printf("\n floor variable is %f", floorVariable);
	printf("\n ciel variable is %f", ceilVariable);
    */

	// Top Half of diamond

	for (count = 0; count < ceilVariable; count++)
	{
		for(int i = 1; i <= floorVariable-count; i++)
				{
					printf(" ");
				}
		for (int j = 0; j < (ceilVariable - (floorVariable - count)) + count; j++)
			printf("*");
		printf("\n");
	}

	//bottom half
	for (count = 1; count < ceilVariable; count++)
	{
		for (int i = floorVariable; i < floorVariable + count; i++)
			printf(" ");
		for (int j = 0; j < userInput - (2 * count); j++)
			printf("*");
		printf("\n");

	}

	
}