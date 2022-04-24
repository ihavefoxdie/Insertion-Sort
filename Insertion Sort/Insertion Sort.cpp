#include <string>
#include <iostream>

bool check(std::string number)
{
	std::string nums = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-' };
	bool match = false;
	for (int i = 0; i < number.length(); i++)
	{
		for (int j = 0; j < 11; j++) {
			if (number[i] == nums[j]) {
				match = true;
				break;
			}
			match = false;
		}
		if (!match)
			throw number;
	}
	return 1;
}

void output(int* arr, int size)
{
	if (size != 0) {
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "Empty\n";
}

int* input(int& size)													//code below is simply making sure user input consists of numbers only. it's rather primitive and work in progress
{
	int* arr = new int[1];	std::string input;
	int pos = 0;

	while (true) {
		std::cout << "To stop, type \"C\" character or simply press enter.\nInput: ";
		getline(std::cin, input);
		if (input[0] == 'c' || input[0] == 'C' || input[0] == NULL || (input[0] == '-' && input.length() == 1)) {
			if (size == 0)
			{
				std::cout << "The array is empty. Deleting.\n";
				delete[] arr;
				return NULL;
			}
			break;
		}
		try
		{
			check(input);
		}
		catch (std::string number)
		{
			system("cls");
			std::cout << "Not a number!\n";
			continue;
		}
		size++;
		int* arr1 = new int[size];
		if (pos != 0)
			for (int i = 0; i < size - 1; i++)
				arr1[i] = arr[i];
		arr1[size - 1] = std::stoi(input);
		delete[] arr;
		arr = arr1;
		pos++;
		system("cls");
	}
	return arr;
}

void insertion(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
				std::swap(arr[i], arr[j]);
		}
	}
}

int main()
{
	int size = 0;

	std::cout << "Fill the array.\n";
	int* arr = input(size);
	output(arr, size);

	insertion(arr, size);
	output(arr, size);

	return 0;
}