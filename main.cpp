#include <iostream>
#include "Factory.h"
#include "Triangle.h"
#include "Tetragon.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	Factory factory; // Создание фабрики
	int choice;
	std::string id, id1, id2;
	double x1, y1, x2, y2, x3, y3, x4, y4, dx, dy;

	do
	{
		// Меню для взаимодействия с пользователем
		std::cout << "\nМеню:\n"
			<< "1. Создать треугольник\n"
			<< "2. Создать четырёхугольник\n"
			<< "3. Удалить по ID\n"
			<< "4. Показать все фигуры\n"
			<< "5. Переместить фигуру\n"
			<< "6. Сравнить фигуры\n"
			<< "0. Выход\n"
			<< "Выберите действие: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1: // Создание треугольника
			std::cout << "Введите ID: ";
			std::cin >> id;
			std::cout << "Введите координаты вершин (x1 y1 x2 y2 x3 y3): ";
			std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			factory.createTriangle(id, x1, y1, x2, y2, x3, y3);
			break;
		case 2: // Создание четырёхугольника
			std::cout << "Введите ID: ";
			std::cin >> id;
			std::cout << "Введите координаты вершин (x1 y1 x2 y2 x3 y3 x4 y4): ";
			std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
			factory.createTetragon(id, x1, y1, x2, y2, x3, y3, x4, y4);
			break;
		case 3: // Удаление по ID
			std::cout << "Введите ID для удаления: ";
			std::cin >> id;
			std::cout << (factory.deleteById(id) ? "Фигура удалена." : "Фигура с таким ID не найдена.") << "\n";
			break;
		case 4: // Вывод всех фигур
			factory.showAll();
			break;
		case 5: // Перемещение фигуры
			std::cout << "Введите ID и смещение (dx dy): ";
			std::cin >> id >> dx >> dy;
			if (Shape* obj = factory.findById(id))
			{
				obj->move(dx, dy);
				std::cout << "Фигура перемещена.\n";
			}
			else
			{
				std::cout << "Фигура с таким ID не найдена.\n";
			}
			break;
		case 6: // Сравнение площадей
			std::cout << "Введите два ID для сравнения: ";
			std::cin >> id1 >> id2;
			if (Shape* a = factory.findById(id1))
			{
				if (Shape* b = factory.findById(id2))
				{
					int result = Shape::compare(*a, *b);
					std::cout << "Результат: ";
					if (result < 0) std::cout << id1 << " < " << id2 << "\n";
					else if (result > 0) std::cout << id1 << " > " << id2 << "\n";
					else std::cout << "Площади равны.\n";
				}
				else std::cout << "Вторая фигура не найдена.\n";
			}
			else std::cout << "Первая фигура не найдена.\n";
			break;
		case 0: // Выход
			std::cout << "Завершение работы...\n";
			break;
		default: // Неверный ввод
			std::cout << "Неверный выбор.\n";
		}
	} while (choice != 0);
}