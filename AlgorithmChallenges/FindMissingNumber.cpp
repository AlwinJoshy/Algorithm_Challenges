#include<iostream>

void FindMissing(int array[], int length) 
{
	int lastReach = 1;
	int nextNo = 0;
	while (nextNo < length)
	{
		if (lastReach < array[nextNo])
		{
			
			std::cout << " - " << lastReach ;
			lastReach++;
			
		}
		
		else if (lastReach == array[nextNo])
		{
			nextNo++;
			lastReach++;
		}

	}
	std::cout << "\n";
}

int main()
{
	int arrayOne[8] = {1,2,3,4,7,8,9,10 };
	int arrayTwo[7] = { 1,3,4,7,8,9,10 };
	int arrayThree[6] = { 1,3,4,7,8,10};

	FindMissing(arrayOne, 8);
	FindMissing(arrayTwo, 7);
	FindMissing(arrayThree, 6);
	return 0;
}
