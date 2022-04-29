#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

template<typename T>
T average(const std::vector<T> &v)
{
	if (v.size() == 0)
		throw std::runtime_error("Math error: Attempted to divide by Zero\n");

	T sum = 0;

	for (size_t i = 0; i < v.size(); i++)
		sum += v[i];

	return (sum / static_cast<float>(v.size()));
}

template <typename T>
struct Point
{
	T x, y;

	Point() : x(0), y(0) {};
	Point(T val) : x(val), y(val) {};
	Point(T _x, T _y) : x(_x), y(_y) {};


	Point<T> operator+=(const Point<T> &p)
	{
		x += p.x;
		y += p.y;
		return *this;
	}

	Point<T> operator/(float val)
	{
		return Point(x / val, y / val);
	}

	std::string toString()
	{
		return "(" +  std::to_string(x) + "; " + std::to_string(y) + ")";
	}
};

int main()
{
	std::vector<float> v1;
	v1.push_back(1.2);
	v1.push_back(1.3);
	v1.push_back(1.4);
	std::cout << average(v1) << std::endl;

	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	std::cout << average(v2) << std::endl;

	std::array<int, 10>			arr_i = {0, 1, 2, 3, 42, 5, 6, 73, 8, 9};
	std::array<float, 2>		arr_f = {42.73, 73.42};
	std::array<Point<int>, 2>	arr_pi;
	arr_pi[0] = {4, 2};
	arr_pi[1] = {7, 3};
	std::array<Point<float>, 2>	arr_pf;
	arr_pf[0] = {4, 2};
	arr_pf[1] = {7, 3};

	std::cout << average(std::vector<int>(arr_i.begin(), arr_i.end()))\
			  << std::endl;

	std::cout << average(std::vector<float>(arr_f.begin(), arr_f.end()))
			  << std::endl;

	std::cout << average(std::vector<Point<int>>(arr_pi.begin(), arr_pi.end())).toString()
			  << std::endl;

	std::cout << average(std::vector<Point<float>>(arr_pf.begin(), arr_pf.end())).toString()
			  << std::endl;

	return 0;
}
