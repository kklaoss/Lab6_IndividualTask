#pragma once
#include "Shape.h"
#include <vector>

// ����� ��� ���������� ���������: ��������, ��������, ��������.
class Factory
{
private:
	std::vector<Shape*> shapes; // ������ ���������� �� ������
public:
	~Factory(); // ���������� (����������� ������)

	// �������� ������������
	void createTriangle(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3);

	// �������� ���������������
	void createTetragon(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3, double x4, double y4);

	bool deleteById(const std::string& id); // �������� ������ �� ID
	void showAll() const;                   // ����� ���� �����
	Shape* findById(const std::string& id) const; // ����� ������ �� ID
};