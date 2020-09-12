#include <stdio.h>
#include <math.h>

int Digit(int num);
void Data_Save(int* Array, int num, int digit);

int main()
{
	//Making Pyramid
	int i, z, line, digit;
	printf("How many line do you want to make? : ");
	scanf_s("%d", &line);
	digit = Digit(line);
	int* Array;
	Array = (int*)malloc(sizeof(int) * digit);
	for (i = 0; i < line; i++){
		for (z = 0; z < line - (i + 1); z++)
			printf(" ");
		for (z = 0; z < 2 * (i + 1) - 1; z++){
			digit = Digit(i + 1);
			Data_Save(Array, i + 1, digit);
			printf("%d", Array[z % digit]);
		}
		printf("\n");
	}
	free(Array);
	printf("\n");
	//other version
	for (i = 0; i < line; i++){
		for (z = 0; z < line - (i + 1); z++)
			printf(" ");
		for (z = 0; z < 2 * (i + 1) - 1; z++)
			printf("%d", i + 1);
		printf("\n");
	}
	printf("\n");
	//Making Rhombus
	for (i = 0; i < line; i++){
		for (z = 0; z < line - (i + 1); z++)
			printf(" ");
		for (z = 0; z < 2 * (i + 1) - 1; z++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i < line - 1; i++){
		for (z = 0; z < i + 1; z++) printf(" ");
		for (z = 0; z < 2 * (line - i) - 3; z++)
			printf("*");
		printf("\n");
	}
	return 0;
}

int Digit(int num){
	int count = 0;
	do{
		num = num / 10;
		count++;
	} while (num > 0);
	return count;
}

void Data_Save(int* Array, int num, int digit){
	int i;
	for (i = 0; i < digit; i++){
		Array[i] = num / (int)pow(10, digit - i - 1);
		num = num % (int)pow(10, digit - i - 1);
	}
}