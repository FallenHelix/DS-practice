#include<iostream>



void printArray(int * a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void ShellSort(int * a, int gap,int n)
{
	if (gap != 0)
	{
		std::cout << "Gap : " << gap << std::endl;
		for (int i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i-gap;
			while (j >= 0 && a[j] > temp)
			{
				a[j+gap] = a[j];
				j -= gap;
			}
			a[j+gap] = temp;
		}
		printArray(a, n);
		ShellSort(a, int((gap) / 2), n);
	}
	else
		return;	
}


int main()
{
	//int a[] = { 1,12,67,21,56,25,16,0,7,30 };
	//int a[] = { 77,62,14,9,30,21,80,25,70,55 };
	int a[] = { 12, 34, 54, 2, 3 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a,int( n/2),n);
	std::cout << "final Array: " << std::endl;
	printArray(a,n);
	std::cin.get();
}
