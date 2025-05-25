#include "Triangle.h"
#include <cmath>
#include <iostream>

// ����������� ������������
Triangle::Triangle(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3)
	: Shape(id), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3){
}

// �����������: ��������� �������� (dx, dy) �� ���� ��������
void Triangle::move(double dx, double dy)
{
	x1 += dx; y1 += dy;
	x2 += dx; y2 += dy;
	x3 += dx; y3 += dy;
}

// ������� ������������ �� ������� ������
double Triangle::area() const
{
	return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// ����� ���������� � ������������
void Triangle::show() const
{
	std::cout << "Triangle ID: " << id << "\n"
		<< "Vertices: (" << x1 << ", " << y1 << "), ("
		<< x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")\n"
		<< "Area: " << area() << "\n";
}