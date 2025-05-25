#pragma once
#include "Shape.h"

// ����� ������������. ��������� ������� ����� Shape.
// ������ ���������� ���� ������.
class Triangle : public Shape
{
private:
	double x1, y1, x2, y2, x3, y3; // ���������� ������
public:
	Triangle(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3);
	void move(double dx, double dy) override; // �����������
	double area() const override;             // ���������� �������
	void show() const override;               // ����� ����������
};