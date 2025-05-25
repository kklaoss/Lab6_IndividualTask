#include "Factory.h"
#include "Triangle.h"
#include "Tetragon.h"
#include <algorithm>
#include <iostream>

// Деструктор: удаляет все объекты из вектора
Factory::~Factory()
{
	for (auto shape : shapes) delete shape;
}

// Создание треугольника и добавление в вектор
void Factory::createTriangle(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3)
{
	shapes.push_back(new Triangle(id, x1, y1, x2, y2, x3, y3));
}

// Создание четырёхугольника и добавление в вектор
void Factory::createTetragon(const std::string& id, double x1, double y1,
	double x2, double y2, double x3, double y3, double x4, double y4)
{
	shapes.push_back(new Tetragon(id, x1, y1, x2, y2, x3, y3, x4, y4));
}

// Удаление фигуры по ID. Возвращает true, если удаление успешно.
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

// Вывод информации о всех фигурах
void Factory::showAll() const
{
	for (const auto& shape : shapes)
	{
		shape->show();
		std::cout << "------------------------\n";
	}
}

// Поиск фигуры по ID. Возвращает nullptr, если не найдена.
Shape* Factory::findById(const std::string& id) const
{
	auto it = std::find_if(shapes.begin(), shapes.end(),
		[&id](const Shape* s) { return s->getId() == id; });
	return (it != shapes.end()) ? *it : nullptr;
}