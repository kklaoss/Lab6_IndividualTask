#pragma once
#include "Shape.h"

// Класс четырёхугольника. Наследует базовый класс Shape.
// Хранит координаты четырех вершин.
class Tetragon : public Shape
{
private:
	double x1, y1, x2, y2, x3, y3, x4, y4; // Координаты вершин
public:
	Tetragon(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3, double x4, double y4);
	void move(double dx, double dy) override; // Перемещение
	double area() const override;             // Вычисление площади
	void show() const override;               // Вывод информации
};