#pragma once
#include "Shape.h"

// ����� ���������������. ��������� ������� ����� Shape.
// ������ ���������� ������� ������.
class Tetragon : public Shape
{
private:
	double x1, y1, x2, y2, x3, y3, x4, y4; // ���������� ������
public:
	Tetragon(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3, double x4, double y4);
	void move(double dx, double dy) override; // �����������
	double area() const override;             // ���������� �������
	void show() const override;               // ����� ����������
};