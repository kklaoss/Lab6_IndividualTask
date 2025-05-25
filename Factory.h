#pragma once
#include "Shape.h"
#include <vector>

// Класс для управления объектами: создание, удаление, хранение.
class Factory
{
private:
	std::vector<Shape*> shapes; // Вектор указателей на фигуры
public:
	~Factory(); // Деструктор (освобождает память)

	// Создание треугольника
	void createTriangle(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3);

	// Создание четырёхугольника
	void createTetragon(const std::string& id, double x1, double y1,
		double x2, double y2, double x3, double y3, double x4, double y4);

	bool deleteById(const std::string& id); // Удаление фигуры по ID
	void showAll() const;                   // Вывод всех фигур
	Shape* findById(const std::string& id) const; // Поиск фигуры по ID
};