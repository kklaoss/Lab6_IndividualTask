#pragma once
#include <string>

// Базовый абстрактный класс для геометрических фигур.
// Содержит общие методы и идентификатор объекта.
class Shape
{
protected:
	std::string id; // Уникальный идентификатор фигуры
public:
	Shape(const std::string& id);
	virtual ~Shape() = default;

	// Перемещение фигуры на плоскости (dx, dy — смещения по осям X и Y)
	virtual void move(double dx, double dy) = 0;

	// Вычисление площади фигуры (должна быть реализована в потомках)
	virtual double area() const = 0;

	// Вывод информации о фигуре в консоль
	virtual void show() const = 0;

	// Получение идентификатора фигуры
	std::string getId() const;

	// Сравнение площадей двух фигур:
	// Возвращает -1, если площадь a < b; 1, если a > b; 0, если равны.
	static int compare(const Shape& a, const Shape& b);
};