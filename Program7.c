/*
COSC2420-001
Project 7 Spring 2023
Cesar A. Reyna
4 May 2023
The programs purpose is to do baisc inventory managment based on 5 options provided by the assignment.
*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)



struct items{
	char Month[20];
	char Name[20];
	int idNumber;
	int quantity;
	float price;
	float sales;

};

struct months {
	char currentMonth[20];
	struct items;
};

void AddItem(struct items theStore[]);
void ItemSale(struct items theStore[]);
void UpdateQuantity(struct items theStore[]);
void DailyReport(struct items theStore[]);
void MonthlyReoprt(struct items theStore[]);
void initialize(struct items theStore[]);
void print(struct items theStore[]);
int itemsFull(struct items theStore[], char month[]);
void removeNewLine(char string[]);
int itemSearch(struct items theStore[], int idSearch);
void monthSearch(struct items theStore[], char month[]);

int main()
{
	struct items inventory[5];
	struct months calendar[12];
	int userInput = NULL;
	initialize(inventory);
	while (1) {
		printf("=================================\n");
		printf("0. Exit \n");
		printf("1. Add item \n");
		printf("2. Item Sale \n");
		printf("3. Update Quantity \n");
		printf("4. Daily Report \n");
		printf("5. Monthly Report \n");
		printf("=================================\n");
		scanf_s("%d", &userInput);
		if (userInput == 0) {
			printf("=================================\n");
			printf("You have selected option 0 \n");
			printf("Exiting program \n");
			printf("=================================\n");
			exit(0);
		}
		else if(userInput == 1)
		{
			AddItem(inventory);
		}
		else if (userInput == 2)
		{
			ItemSale(inventory);
		}
		else if (userInput == 3)
		{
			UpdateQuantity(inventory);
		}
		else if (userInput == 4)
		{
			DailyReport(inventory);
		}
		else if (userInput == 5)
		{
			MonthlyReoprt(inventory);
		}
		else 
		{
			printf("=================================\n");
			printf("Invalid option \n");
			printf("Please try again \n");
			printf("=================================\n");

		}
	}
	
}

void AddItem(struct items theStore[])
{
	printf("=================================\n");
	printf("You have selected 1\n");
	printf("=================================\n");
	printf("\n"); printf("\n"); printf("\n"); printf("\n");
	printf("=================================\n");
	printf("=========Inventory===============\n");
	print(theStore);
	int i = itemsFull(theStore,"Default");
	getchar();
	printf("Please enter the current month\n");
	fgets(theStore[i].Month, sizeof(theStore[i].Month), stdin);
	removeNewLine(theStore[i].Month);
	printf("Please enter new item name\n");
	fgets(theStore[i].Name, sizeof(theStore[i].Name), stdin);
	removeNewLine(theStore[i].Name);
	printf("Please enter new item identification number\n");
	scanf("%d", &theStore[i].idNumber);
	printf("Please enter new item quantity\n");
	scanf("%d", &theStore[i].quantity);
	printf("Please enter new item price\n");
	scanf("%f", &theStore[i].price);

}

void ItemSale(struct items theStore[])
{
	int ID = 0;
	int Quantity = 0;
	int i;
	printf("=================================\n");
	printf("You have selected 2 \n");
	printf("=================================\n");
	print(theStore);
	printf("Please enter the ID number of the sold item\n");
	scanf("%d", &ID);
	printf("Please enter the qunatity sold\n");
	scanf("%d", &Quantity);
	i = itemSearch(theStore, ID);
	theStore[i].sales = theStore[i].sales + (Quantity * theStore[i].price);
	theStore[i].quantity = theStore[i].quantity - Quantity;
	printf("===Changes applied+++++\n");
	print(theStore);


}

void UpdateQuantity(struct items theStore[])
{
	int ID = 0;
	int Quantity = 0;
	int i;
	printf("=================================\n");
	printf("You have selected 3 \n");
	printf("=================================\n");
	print(theStore);
	printf("Please enter the ID number of the item\n");
	scanf("%d", &ID);
	printf("Please enter the current qunatity\n");
	scanf("%d", &Quantity);
	i = itemSearch(theStore, ID);
	theStore[i].quantity = Quantity;
	printf("===Changes applied+++++\n");
	print(theStore);
}

void DailyReport(struct items theStore[])
{
	printf("=================================\n");
	printf("You have selected 4 \n");
	printf("=================================\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++Daily Report+++++++++++++++++++++++++++++\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	print(theStore);

}

void MonthlyReoprt(struct items theStore[])
{
	char month[20];
	printf("=================================\n");
	printf("You have selected 5 \n");
	printf("=================================\n");
	printf("=================================\n");
	printf("Please enter the month \n");
	getchar();
	fgets(month, sizeof(month), stdin);
	removeNewLine(month);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++Monthly Report+++++++++++++++++++++++++++\n");
	printf("++++++++Month+++Item++++ID Num++Stock+++Price+++Sales++++++++++++++\n");
	monthSearch(theStore, month);
	
}

void initialize(struct items theStore[])
{
	for (int i = 0; i < 5; i++)
	{
		strcpy(theStore[i].Month, "Default");
		strcpy(theStore[i].Name, "Default");
		theStore[i].idNumber = 0;
		theStore[i].quantity = 0;
		theStore[i].price = 0;
		theStore[i].sales = 0;
	}
}

void print(struct items theStore[])
{
	printf("========Month===Item====ID Num==Stock===Price===Sales==============\n");
	for (int i = 0; i < 5; i++)
	{
		printf("\t%s\t%s\t%05d\t%05d\t%06.2f\t%06.2f\n", theStore[i].Month,theStore[i].Name, theStore[i].idNumber, theStore[i].quantity, theStore[i].price, theStore[i].sales);

	}
	printf("===================================================================\n");

}

int itemsFull(struct items theStore[], char month[])
{
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(theStore[i].Month, month) == 0)
		{
			return i;
		}
		else
			continue;

	}
}

//removes a new line charachter from a string
void removeNewLine(char string[])
{
	char* ptr = NULL;
	ptr = strchr(string, '\n');
	if (ptr != NULL)
	{
		*ptr = '\0';
	}
}

int itemSearch(struct items theStore[], int idSearch)
{
	
	for (int i = 0; i < 5; i++)
	{
		if (theStore[i].idNumber = idSearch)
		{
			return i;
		}
		
	}
	return 0;
}

void monthSearch(struct items theStore[], char month[])
{
	for (int i=0; i < 5; i++)
	{

		if (strcmp(theStore[i].Month, month) == 0)
		{
			printf("\t%s\t%s\t%05d\t%05d\t%06.2f\t%06.2f\n", theStore[i].Month, theStore[i].Name, theStore[i].idNumber, theStore[i].quantity, theStore[i].price, theStore[i].sales);
		}
		else if (i == 4) {
			break;
		}
		else
			continue;	
	}
	printf("*****************************************************************\n");
	printf("*****************************************************************\n");
	printf("*****************************************************************\n");
}


