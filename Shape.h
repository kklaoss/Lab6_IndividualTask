#pragma once
#include <string>

// ������� ����������� ����� ��� �������������� �����.
// �������� ����� ������ � ������������� �������.
class Shape
{
protected:
	std::string id; // ���������� ������������� ������
public:
	Shape(const std::string& id);
	virtual ~Shape() = default;

	// ����������� ������ �� ��������� (dx, dy � �������� �� ���� X � Y)
	virtual void move(double dx, double dy) = 0;

	// ���������� ������� ������ (������ ���� ����������� � ��������)
	virtual double area() const = 0;

	// ����� ���������� � ������ � �������
	virtual void show() const = 0;

	// ��������� �������������� ������
	std::string getId() const;

	// ��������� �������� ���� �����:
	// ���������� -1, ���� ������� a < b; 1, ���� a > b; 0, ���� �����.
	static int compare(const Shape& a, const Shape& b);
};