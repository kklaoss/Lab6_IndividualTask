#include "Triangle.h"
#include <cmath>
#include <iostream>

// Конструктор треугольника
Triangle::Triangle(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3)
	: Shape(id), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
}

// Перемещение: добавляет смещение (dx, dy) ко всем вершинам
void Triangle::move(double dx, double dy)
{
	x1 += dx; y1 += dy;
	x2 += dx; y2 += dy;
	x3 += dx; y3 += dy;
}

// Площадь треугольника по формуле Гаусса
double Triangle::area() const
{
	return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Вывод информации о треугольнике
void Triangle::show() const
{
	std::cout << "Треугольник ID: " << id << "\n"
		<< "Вершины: (" << x1 << ", " << y1 << "), ("
		<< x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")\n"
		<< "Площадь: " << area() << "\n";
}