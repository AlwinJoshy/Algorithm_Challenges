#include <iostream>
#include <stdlib.h>
#include <time.h>

constexpr auto ARRAY_LENGTH = 10;

int randomArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

void ArrayRandomizer()
{
	srand(time(NULL));
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		int tempPos = rand() % 10;
		int tempVal = randomArray[tempPos];
		randomArray[tempPos] = randomArray[i];
		randomArray[i] = tempVal;
	}
}

void DisplayArray()
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		std::cout << randomArray[i];
	}
	std::cout << "\n";
}

int main()
{
	ArrayRandomizer();
	DisplayArray();

	for (int i = 1; i < ARRAY_LENGTH; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (randomArray[j] > randomArray[j - 1])
			{
				int temp = randomArray[j - 1];
				randomArray[j - 1] = randomArray[j];
				randomArray[j] = temp;
			}
		}
		DisplayArray();
	}


}