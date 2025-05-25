#include "Factory.h"
#include "Triangle.h"
#include "Tetragon.h"
#include <algorithm>
#include <iostream>

// ����������: ������� ��� ������� �� �������
Factory::~Factory()
{
	for (auto shape : shapes) delete shape;
}

// �������� ������������ � ���������� � ������
void Factory::createTriangle(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3)
{
	shapes.push_back(new Triangle(id, x1, y1, x2, y2, x3, y3));
}

// �������� ��������������� � ���������� � ������
void Factory::createTetragon(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3, double x4, double y4)
{
	shapes.push_back(new Tetragon(id, x1, y1, x2, y2, x3, y3, x4, y4));
}

// �������� ������ �� ID. ���������� true, ���� �������� �������.
bool Factory::deleteById(const std::string& id)
{
	auto it = std::remove_if(shapes.begin(), shapes.end(),
		[&id](Shape* s) { return s->getId() == id; });
	if (it != shapes.end())
	{
		delete* it;
		shapes.erase(it, shapes.end());
		return true;
	}
	return false;
}

// ����� ���������� � ���� �������
void Factory::showAll() const
{
	for (const auto& shape : shapes)
	{
		shape->show();
		std::cout << "------------------------\n";
	}
}

// ����� ������ �� ID. ���������� nullptr, ���� �� �������.
Shape* Factory::findById(const std::string& id) const
{
	auto it = std::find_if(shapes.begin(), shapes.end(),
		[&id](const Shape* s) { return s->getId() == id; });
	return (it != shapes.end()) ? *it : nullptr;
}