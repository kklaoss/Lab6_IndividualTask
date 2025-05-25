#include "Tetragon.h"
#include <cmath>
#include <iostream>

// Конструктор четырёхугольника
Tetragon::Tetragon(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3, double x4, double y4)
	: Shape(id), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
}

// Перемещение: добавляет смещение (dx, dy) ко всем вершинам
void Tetragon::move(double dx, double dy)
{
	x1 += dx; y1 += dy;
	x2 += dx; y2 += dy;
	x3 += dx; y3 += dy;
	x4 += dx; y4 += dy;
}

// Площадь четырёхугольника вычисляется как сумма площадей двух треугольников
double Tetragon::area() const
{
	double area1 = std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	double area2 = std::abs((x1 * (y3 - y4) + x3 * (y4 - y1) + x4 * (y1 - y3)) / 2.0);
	return area1 + area2;
}

// Вывод информации о четырёхугольнике
void Tetragon::show() const
{
	std::cout << "Tetragon ID: " << id << "\n"
		<< "Vertices: (" << x1 << ", " << y1 << "), ("
		<< x2 << ", " << y2 << "), (" << x3 << ", " << y3
		<< "), (" << x4 << ", " << y4 << ")\n"
		<< "Area: " << area() << "\n";
}