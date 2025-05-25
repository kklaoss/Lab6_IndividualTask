#include <iostream>
#include "Factory.h"
#include "Triangle.h"
#include "Tetragon.h"

int main()
{
	Factory factory; // Создание фабрики
	int choice;
	std::string id, id1, id2;
	double x1, y1, x2, y2, x3, y3, x4, y4, dx, dy;

	do
	{
		// Меню для взаимодействия с пользователем
		std::cout << "\nMenu:\n"
			<< "1. Create Triangle\n"
			<< "2. Create Tetragon\n"
			<< "3. Delete by ID\n"
			<< "4. Show all\n"
			<< "5. Move object\n"
			<< "6. Compare objects\n"
			<< "0. Exit\n"
			<< "Enter choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1: // Создание треугольника
			std::cout << "Enter ID: ";
			std::cin >> id;
			std::cout << "Enter vertices (x1 y1 x2 y2 x3 y3): ";
			std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			factory.createTriangle(id, x1, y1, x2, y2, x3, y3);
			break;
		case 2: // Создание четырёхугольника
			std::cout << "Enter ID: ";
			std::cin >> id;
			std::cout << "Enter vertices (x1 y1 x2 y2 x3 y3 x4 y4): ";
			std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
			factory.createTetragon(id, x1, y1, x2, y2, x3, y3, x4, y4);
			break;
		case 3: // Удаление по ID
			std::cout << "Enter ID to delete: ";
			std::cin >> id;
			std::cout << (factory.deleteById(id) ? "Deleted." : "ID not found.") << "\n";
			break;
		case 4: // Вывод всех фигур
			factory.showAll();
			break;
		case 5: // Перемещение фигуры
			std::cout << "Enter ID and offset (dx dy): ";
			std::cin >> id >> dx >> dy;
			if (Shape* obj = factory.findById(id))
			{
				obj->move(dx, dy);
				std::cout << "Moved.\n";
			}
			else
			{
				std::cout << "ID not found.\n";
			}
			break;
		case 6: // Сравнение площадей
			std::cout << "Enter two IDs to compare: ";
			std::cin >> id1 >> id2;
			if (Shape* a = factory.findById(id1))
			{
				if (Shape* b = factory.findById(id2))
				{
					int result = Shape::compare(*a, *b);
					std::cout << "Result: ";
					if (result < 0) std::cout << id1 << " < " << id2 << "\n";
					else if (result > 0) std::cout << id1 << " > " << id2 << "\n";
					else std::cout << "Areas are equal.\n";
				}
				else std::cout << "Second ID not found.\n";
			}
			else std::cout << "First ID not found.\n";
			break;
		case 0: // Выход
			std::cout << "Exiting...\n";
			break;
		default: // Неверный ввод
			std::cout << "Invalid choice.\n";
		}
	} while (choice != 0);

	return 0;
}