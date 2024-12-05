#include <iostream>
#include <vector>

#include "DayClass.h"
#include "Day1.h"

const std::vector<std::shared_ptr<DayClass>> days = { 
	std::make_shared<Day1>()
};

int main() {

	std::cout << "Andrew F Advent of Code C++ Program\n\n";
	std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();

	for (const auto& day : days)
		day->Run();

	std::cout << "\nThe entire program took: ";
	std::chrono::high_resolution_clock::duration dur = std::chrono::high_resolution_clock::now() - Start;
	std::cout << dur.count() << " nanoseconds    :    " << (double)dur.count() / 1000000 << " milliseconds\n";

}

