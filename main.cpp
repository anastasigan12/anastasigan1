#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void geo22(); //Декларування функції типу void(задача geo17)

void task19();//Декларування функції типу void(задача Solve24)
double factorial(int temp);

void task27();//Декларування функції типу void(задача Solve32)

int main()
{
	setlocale(LC_ALL, "ukrainian");

		int choice = 0; //Декларування змінної задля choice

		while (true && choice !=4){
			setlocale(LC_ALL, "ukrainian");
			cout.clear();
			cout << "Виберiть яку з цих задач будете вирiшувати: "
				"\n1. Геометрія22"
				"\n2. Задача19"
				"\n3. Задача27"
				"\n4. Вийти з програми" << endl;

			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					// Geo17
					geo22();
					break;
				}
				case 2:
				{
					// Solve24
					task19();
					break;
				}
				case 3:
				{
					// Solve32
					task27();
					break;
				}
				case 4:
				{
					cout << "Програма завершена";
					break;
				}
				default:
				{
					cout << "Такого варiанту немає\n";
					break;
				}
			}
		}
}

void geo22() { // Функція типу void, що не повертає значень
	float x, y, r; // Декларування змінних типу float
	bool ar1, ar2; // Декларування змінних типу bool
	int n, counter = 0;

	cout << "Кількість разів: ";
	cin >> n;

		cout << "Уведiть радiус кола: ";
		std::cin >> r;

		for (int i = 1; i <= n; i++)
		{

			if (r > 0)
			{
				cout << "Уведiть точку за кординатою х : ";
				cin >> x;
				cout << "Уведiть точку за кординатою y : ";
				cin >> y;


				ar1 = pow(x, 2) + pow(y, 2) > pow(r, 2) && x > 0 && y > 0 && y < x && x < 2 * r; //Рівняння першої фігури(верхньої)
				ar2 = pow(x, 2) + pow(y, 2) > pow(r, 2) && x<0 && y<0 && y>x && x>-2 * r; //Рівняння другої фігури(нижньої)

				if (ar1 || ar2) {
					counter++;
				}
			}
			else {
				cout << "Радіус не може бути від'ємним" << endl;
			}
		}
		cout << "Кількість вдалих спроб: " << counter;
}

void task19()
{
	int k = 0,n; 
	const double pi = 3.14;
	double x;

	cout << "Введіть х: ";
	cin >> x;

	cout << "Обмеження n: ";
	cin >> n; 

	
	long double sum = 0;	
	cout.precision(15);
	if (!cin || n < 0)
	{
		cout << "Неправильне введення даних" << endl;
	}
	else 
	{
		for (k; k <= n; k++)
		{
			int temp = 1 + (2 * k);
			int count = 0;

			double part1 = pow(-1,k)*pow((-1*pi/2.0+x),temp);
			double part2 = factorial(temp);

			double temps = part1 / part2;

			sum += temps;
			temps = 0;

			count = k % 4;

			if (count == 3) {
				cout << "Сума ряду: " << sum << endl;
			}
		}
	}
}

double factorial(int temp)
{
	int eq = 1;
	for (int i = 1; i <= temp; i++)
	{
		eq *= i;
	}
	return eq;
}

void task27()
{
	int k = 0, n;
	const double pi = 3.14, e = 1;
	double x, g = 1E+5;


	cout << "Введіть х: ";
	cin >> x;

	cout << "Діапазон суми ряду: ";
	cin >> g;

	double sum = 0;

	do
	{
		k++;
			int count = 0;

			double part1 = pow(-1, k) * pow(x, (k - 1)) * sqrt((3 * k + 1));
			double part2 = factorial(k);

			double solving = part1 / part2;

			sum += solving;
			solving = 0;

			count = k % 4;

			if (count == 3) {
				cout << "Сума ряду: " << sum << endl;
			}
	} while (sum < g);
}