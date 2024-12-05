#pragma once
#include <algorithm>
#include "DayClass.h"

class Day1 : public DayClass
{
public:
	Day1() : DayClass(1) {};

	void Constructor() override {
		FileReader reader("TextFiles/Day1.txt");

		auto lines = reader.ReadLine();
		for (auto& line : lines) {
			auto parts = FileReader::SplitString(line, ' ');
			nums1.push_back(std::stoi(parts[0]));
			nums2.push_back(std::stoi(parts[3]));
		}

		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
	};

	int Part1() override {
		int sum = 0;

		for (size_t i = 0; i < nums1.size(); i++) {
			sum += std::abs(nums1[i] - nums2[i]);
		}

		return sum;
	};

	int Part2() override {
		int sum = 0;
		
		std::pair<int, int> last = { -1, 0 };
		size_t count = 0;

		for (size_t i = 0; i < nums1.size(); i++) {
			if (nums1[i] == last.first)
				sum += nums1[i] * last.second;

			int j = 0;
			while (count < nums2.size() && nums2[count] <= nums1[i]) {
				if (nums2[count] == nums1[i])
					j++;
				count++;
			}

			last = { nums1[i], j };
			sum += nums1[i] * j;
		}

		return sum;
	};

private:
	std::vector<int> nums1;
	std::vector<int> nums2;
};
