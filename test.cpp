#include <climits>
#include <iostream>
#include <vector>
#include <sstream>

int main() {
	std::string line;
	int value;
	std::vector<int> inputValues;
	
	std::cout << "Enter integers separated by spaces:\n";
	std::getline(std::cin, line);
	std::istringstream stream(line);
	while (stream >> value)
		inputValues.push_back(value);
	if (inputValues.size() < 3) {
		std::cout << "Enter 3 or more numbers.";
		return 0;
	}
	
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;
	for (int i = 0; i < inputValues.size(); i++) {
		if (inputValues[i] <= min1) {
			min2 = min1;
			min1 = inputValues[i];
		} else if (inputValues[i] <= min2) {
			min2 = inputValues[i];
		}
		if (inputValues[i] >= max1) {
			max3 = max2;
			max2 = max1;
			max1 = inputValues[i];
		} else if (inputValues[i] >= max2) {
			max3 = max2;
			max2 = inputValues[i];
		} else if (inputValues[i] >= max3) {
			max3 = inputValues[i];
		}
	}
	
	std::cout << "Maximum product of 3 numbers: " << max1 * max2 * max3;
	return 0;
}
