#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int* mass = new int[10];
short This = -1;
bool IsEmpty = true;


void PUSH()
{
	int i;

	if (This < 10)
	{
		IsEmpty = false;
		printf("Введите значение:\n");
		scanf_s("%d", &i);
		mass[This] = i;
		printf("Добавлен элемент: %d\n", mass[This]);
	}
	else
	{
		This--;
		printf("Стек переполнен.\n");
	}

}

void POP()
{
	if (This >= 0)
	{
		printf("Удалён элемент: %d\n", mass[This]);
		This--;
		if (This == -1)
		{
			IsEmpty = true;
		}
	}
	else
	{
		IsEmpty = true;
		printf("Стек пуст.\n");
	}

}

void PEEK()
{
	if (!IsEmpty)
	{
		printf("Верхний элемент: %d\n", mass[This]);
	}
	else
		printf("Стек пуст.\n");

}

void Clear()
{
	delete[] mass;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int l_Key;
	do
	{
		printf("Выберите пункт меню:\n");
		printf("------------\n");
		printf("| 1 - PUSH |\n");
		printf("------------\n");
		printf("| 2 - POP  |\n");
		printf("------------\n");
		printf("| 3 - PEEK |\n");
		printf("------------\n");
		printf(" \n");
		printf("---\n");
		scanf_s("%d", &l_Key);
		printf("---\n");
		switch (l_Key)
		{
		case 1:
			This++;
			PUSH();
			break;
		case 2:
			POP();
			break;
		case 3:
			PEEK();
			break;
		}

	} while (l_Key != 0);
	Clear();
	return 0;
}