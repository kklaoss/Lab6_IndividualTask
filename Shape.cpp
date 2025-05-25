#include "Shape.h"

// Конструктор базового класса
Shape::Shape(const std::string& id) : id(id) {}

// Возвращает идентификатор фигуры
std::string Shape::getId() const
{
	return id;
}

// Сравнение площадей двух фигур
int Shape::compare(const Shape& a, const Shape& b)
{
	double areaA = a.area();
	double areaB = b.area();
	if (areaA < areaB) return -1;
	if (areaA > areaB) return 1;
	return 0; // Равны
}