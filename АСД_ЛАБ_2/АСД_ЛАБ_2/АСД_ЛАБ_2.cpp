#include <iostream>

using namespace std;

void task1()
{
	int amount = 0;

	const int size = 1000;
	bool numbers[size];

	clock_t timeStart = clock();			//початок виміру

	for (int a = 0; a < 1000; a++)			//1000 разів
	{


		for (int i = 0; i < size; i++)
		{
			numbers[i] = true;
		}

		numbers[0] = false;
		numbers[1] = false;

		for (int u = 2; u < size; u++)			//решето
		{
			if (numbers[u])
			{
				for (int x = u * u; x < size; x += u)
				{
					numbers[x] = false;

				}

				if (u >= 100 && a == 0)	    //трицифрові числа 
				{
					cout << "Number " << u << " is prime" << endl;
					amount++;
				}
			}

		}
	}

	clock_t timeEnd = clock();				//кінець виміру

	double seconds = (double(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	cout << "The amount of all three-digit prime numbers: " << amount << endl;
	cout << "Runtime: " << seconds << " seconds." << endl;
}

int baseConvertion(int num, int inputSystem, int outputSystem)
{
	int result, rest, output = 0;

	for (int i = 0; num > 0; i++)
	{
		rest = (num % outputSystem) * pow(inputSystem, i);
		result = num / outputSystem;
		num = result;
		output += rest;
	}

	return output;
}


void task2()
{
	int number, baseResult, baseInput, result;

	cout << "Enter a number in n base: ";
	cin >> number;

	cout << "Enter a base of the entered number (2 - 10): ";
	cin >> baseInput;

	cout << "Enter a base, into which the number must be converted (2 - 10): ";
	cin >> baseResult;

	if (!(baseInput > 1 && baseInput <= 10 && baseResult > 1 && baseResult <= 10))		//системи від 2 до 10
	{
		cout << "Enter a valid base (2 - 10)" << endl;
	}
	else
	{
		if (baseInput == 10 || baseResult == 10)
		{
			result = baseConvertion(number, baseInput, baseResult);
		}
		else
		{
			int temp = baseConvertion(number, baseInput, 10);

			result = baseConvertion(temp, 10, baseResult);
		}

		cout << "The number " << number << " in a base" << baseResult << " equals: " << baseConvertion(number, baseInput, baseResult) << endl;
	}

}

int fibonacci(int n)			//розрахунок числа фібоначі
{

	if (n == 1)
	{
		return 0;
	}

	if (n == 2)
	{
		return 1;
	}

	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int product(int n)				//розрахунок добутка
{
	if (n == 1)
	{
		return 1;
	}

	return product(n - 1) * fibonacci(n);
}


void task3()
{
	int n;

	cout << "Enter the number of elements of the sequence whose product must be found: ";
	cin >> n;

	cout << "Product of the first " << n << " Fibonacci numbers is " << product(n) << endl;
}

int main()
{
	int task;

	while (true)
	{
		cout << "Choose the task or enter 0 to exit the program: " << endl;
		cin >> task;

		switch (task)
		{
		case 0:
			return 0;
			break;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		default:
			break;
		}
	}
}

