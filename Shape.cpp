#include "Shape.h"

// ����������� �������� ������
Shape::Shape(const std::string& id) : id(id) {}

// ���������� ������������� ������
std::string Shape::getId() const
{
	return id;
}

// ��������� �������� ���� �����
int Shape::compare(const Shape& a, const Shape& b)
{
	double areaA = a.area();
	double areaB = b.area();
	if (areaA < areaB) return -1;
	if (areaA > areaB) return 1;
	return 0; // �����
}