#pragma once
#include "Shape.h"

// Класс треугольника. Наследует базовый класс Shape.
// Хранит координаты трех вершин.
class Triangle : public Shape
{
private:
	double x1, y1, x2, y2, x3, y3; // Координаты вершин
public:
	Triangle(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3);
	void move(double dx, double dy) override; // Перемещение
	double area() const override;             // Вычисление площади
	void show() const override;               // Вывод информации
};