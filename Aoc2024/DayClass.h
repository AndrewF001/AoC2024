#pragma once
#include <chrono>
#include <iostream>
class DayClass
{
public:
	DayClass(int d) : m_day(d) {};
	~DayClass() = default;
	DayClass(const DayClass&) = delete;
	DayClass& operator =(const DayClass&) = delete;

	void Run() const {
		auto m_start = std::chrono::high_resolution_clock::now();

		Part1();
		Part2();

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start);
		std::cout << "Day " << m_day << " took " << duration.count() << "ms" << std::endl;
	};

	virtual void Part1() const = 0;
	virtual void Part2() const = 0;

private:
	int m_day;
};

