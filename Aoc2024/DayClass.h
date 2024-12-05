#pragma once
#include <chrono>
#include <iostream>

#include "FileReader.h"

class DayClass
{
public:
	DayClass(int d) : m_day(d) {};
	~DayClass() = default;
	DayClass(const DayClass&) = delete;
	DayClass& operator =(const DayClass&) = delete;

	void Run() {
		auto m_start = std::chrono::high_resolution_clock::now();

		Constructor();

		std::cout << "\nDay " << m_day << " Part1: " << Part1() << std::endl;
		std::cout << "Day " << m_day << " Part2: " << Part2() << std::endl;

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start);
		std::cout << "Day " << m_day << " took " << duration.count() << "ms" << std::endl;
	};


	virtual void Constructor() = 0;
	virtual int Part1() = 0;
	virtual int Part2() = 0;

private:
	int m_day;
};

