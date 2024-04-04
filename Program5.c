/* Author:    Cesar A Reyna
*  Professor: Vladan Vuckovic
*  Project 5 Due 10 April 2023
*  This program accepts input for 3 cars hours parked and prints the parking charges for each
*  if the car is parked longer than 24 hours the program returns
*  the charge for 24 hours, if a negative number is enterd the program loops and asks for new input.
*/




#include <stdio.h>

double calculateCharges(double);

int main() {
	float hours = 0.0, hours2 = 0.0, hours3 = 0.0;
	float charge = 0, charge2 = 0, charge3 = 0;
	int flag = 1;
	while (flag == 1) {
		printf("Enter hours for 3 cars: \n");
		scanf_s("%f %f %f", &hours, &hours2, &hours3);

		if (hours < 0 || hours2 < 0 || hours3 < 0)
			printf("Negative number entered please try again. \n");
		else
			flag = 2;

	}
		printf("hours\t%f\t%f\t%f\n", hours, hours2, hours3);

	charge = calculateCharges(hours);
	charge2 = calculateCharges(hours2);
	charge3 = calculateCharges(hours3);

	printf("Car \t Hours \t Charge \n");
	printf("1 \t %4.1f \t %4.2f \n", hours, charge);
	printf("2 \t %4.1f \t %4.2f \n", hours2, charge2);
	printf("3 \t %4.1f \t %4.2f \n", hours3, charge3);
	printf("Total \t %4.1f \t %4.2f", (hours + hours2 + hours3), (charge + charge2 + charge3));
	


}

double calculateCharges(double hours) {
	if (hours >= 24) {
		hours = 10.00;
		return hours;
	}
	else if (hours > 3) {
		hours = (((hours - 3) * 0.5) + 2.00);
		return hours;
	}
	else {
		hours = 2.00;
		return hours;
	}
	
}