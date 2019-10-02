#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define START 1
#define MAXSIZE 50	//Максимальное число элементов 
void work_with_set(char *set[]);	//Функция работы со множествами
void main_menu();
int main(int argc, char const *argv[])
{
	int c, n, i;
	char *set1[MAXSIZE];	//Множество1
	char *set2[MAXSIZE]; 	//Множество2
	main_menu();
	while((c = getchar()) != EOF)
	{
		i = 0;
		while(c != '\n')
		{
			n = c;
			c = getchar();
			++i;
		}
		if (c == '\n' && i == 1 && isdigit(n) != 0)
		{
			switch(n-'0'){
				case 1:
					work_with_set(set1);
					break;
				case 2:
					work_with_set(set2);
					break;
				default:
					printf("Ошибка! Введите 1 или 2\n\n");
					break;
			}
		}
		else
		{
			printf("Ошибка! Для выбора необходимо ввести 1 или 2\n\n");
		}
		main_menu();
	}
	return 0;
}
void init_set(char *s_c[], int *pn); 		//Инициализация множества
void print_elements(char *s_c[], int *pn); 	//Вывод элементов 
void add_element(char *s_c[], int *pn); 	//Добавить элемент
void del_element(char *s_c[], int *pn); 	//Удалить элемент
void set_menu();
void work_with_set(char *set[])
{
	int a = 0, n = 0;
	int *pn = &n;
	int stdbin;						/*При использовании scanf() символ перевода строки идёт в stdin.
									Переменная 'stdbin' служит для забор '\n', т.е. очищения stdin*/
	set_menu();	
	while(a != 5 && n <= MAXSIZE)
	{
		scanf(" %d", &a);
		stdbin = getchar();
		switch(a){
			case 1:
				init_set(set, pn);
				printf("\n");
				set_menu();
				break;
			case 2:
				print_elements(set, pn);
				printf("\n");
				set_menu();
				break;
			case 3:
				add_element(set, pn);
				printf("\n");
				set_menu();
				break;
			case 4:
				del_element(set, pn);
				printf("\n");
				set_menu();
				break;
			case 5:
				break;
			default:
				printf("Введите число в соотвествии с меню\n");
				break;
		}
	}
	if (n > MAXSIZE)
	{
		printf("Слишком много элементов\n");
	}
	for (int i = 0; i < n; ++i)		//Цикл для очищения введеных элементов 
	{
		set[i] = 0;
	}
	return;
}
char *get_element();	//Получение элемента множества через ввод пользователя
void init_set(char *s_c[], int *pn)
{
	if (*pn != 0)
	{
		printf("Множество уже проинициализировано\n");
		return;
	}
	int c, stdbin;
	printf("Проинициализируем множество. Сколько элементов нужно?\n");
	scanf(" %d", &c);
	while (c > MAXSIZE)
	{
		printf("Слишком много элементов. Максимальное кол-во: 50\n");
		scanf(" %d", &c);
	}
	stdbin = getchar();
	printf("Начинаем инициализацию. Элементы вводятся через Enter\n");
	for (; *pn < c; ++(*pn))
	{
		s_c[*pn] = get_element();
	}
	return;
}
void print_elements(char *s_c[], int *pn)
{
	if (*pn == 0)
	{
		printf("Пустое множество\n");
		return;
	}

	printf("Сейчас элементы множества это:\n");
	for (int i = 0; i < *pn; ++i)
	{
		printf("%d) %s\n", i+1, s_c[i]);
	}
	return;
}
void add_element(char *s_c[], int *pn)
{
	if (*pn == 0)
	{
		printf("Пустое множество\n");
		return;
	}
	printf("Добавить новый элемент\n");
	s_c[(*pn)++] = get_element();
	return;
}
void del_element(char *s_c[], int *pn)
{
	if (*pn == 0)
	{
		printf("Пустое множество\n");
		return;
	}
	int i = 0, k = 0;
	int del, stdbin;
	char *unneccesary;			//Строка для удаления
	char *set_copy[MAXSIZE];	//Копия множества без данного элемента
	printf("Номер элемента, который вы хотите удалить: ");
	scanf(" %d", &del);
	stdbin = getchar();
	unneccesary = s_c[del - 1];
	for (; i < *pn; ++i)
	{
		if (s_c[i] != unneccesary)
		{
			(set_copy[k++] = s_c[i]);
		}
		s_c[i] = 0;
	}
	for (i = 0; i < k; ++i)		//Перезапись множества
	{
		s_c[i] = set_copy[i];
	}
	*pn = k;
	return;
}
char *get_element()
{
	int c;
	int len = 0;
	char *s = (char*) malloc(START * sizeof(int));	//Создание динамического массива для строки произвольной длины
	while((c = getchar()) != EOF && c != '\n')
	{
		if (isalnum(c) != 0)
		{
			s[len++] = c;
			s = (char*) realloc(s, (len+1) * sizeof(int));
		}
	}
	if (c == EOF)
	{
		free(s);
		exit(0);
	}
	++len;
	s[len] = '\0';

	return s;
}
void main_menu()
{
	printf("Выберите множество с которым хотите работать:\n");
	printf("1) Множество_1\n");
	printf("2) Множество_2\n");
	return;
}
void set_menu()
{
	printf("Выберите действие:\n");
	printf("1) Инициализировать\n");
	printf("2) Вывести значения\n");
	printf("3) Добавить элемент\n");
	printf("4) Удалить элемент\n");
	printf("5) Выйти\n");
	return;
}
