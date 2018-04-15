
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>

using namespace std;
struct dates
{
	int dd;
	int mm;
	int yy;
};

struct dd
{
	dates *date;
};

void generateDate(dates *date)
{
	date->dd = 1 + rand() % 30;
	date->mm = 1 + rand() % 11;
	date->yy = 1980 + rand() % 20;
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	FILE *fp = NULL, *fp1 = NULL, *fp2 = NULL;
	int n;
	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*1.	Имеется текстовый файл. Переписать его строки в другой файл. Порядок строк во втором файле должен:
			a.	совпадать с порядком строк в заданном файле;
			b.	быть обратным по отношению к порядку строк в заданном файле.
			*/
		case 1: {
			char mas_s[5][100];
			int count = 0;
			if ((fp = fopen("case1.txt", "r")) != NULL)
			{
				for (int i = 0; i < 5; i++)
				{
					fgets(mas_s[i], 100, fp);
					printf("%s", mas_s[i]);
					count++;
				}

			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp);

			if ((fp1 = fopen("case1_1.txt", "w")) != NULL)
			{
				for (int i = 0; i < 5; i++)
				{
					fprintf(fp1, "%s", mas_s[i]);
				}
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp1);

			if ((fp2 = fopen("case1_2.txt", "w")) != NULL)
			{
				for (int i = count - 1; i >= 0; i--)
				{
					fprintf(fp1, "%s", mas_s[i]);
				}
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp1);
		}break;

			/*2.	Имеется текстовый файл. Переписать его строки в обратном порядке (справа налево) в другой файл. Порядок строк во втором файле должен:
a.	совпадать с порядком строк в заданном файле;
b.	быть обратным по отношению к порядку строк в заданном файле.
*/
		case 2: {

			if ((fp = fopen("case1.txt", "r")) == NULL || (fp1 = fopen("case2_1.txt", "w")) == NULL ||
				(fp2 = fopen("case2_2.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int count = 0;
				while (!feof(fp))
				{
					getc(fp);
					count++;
				}
				rewind(fp);

				int b = 0;
				char c[600];

				for (int i = 0; i < count; i++)
				{
					fscanf(fp, "%c", &c[i]);
					if (c[i] == '\n')
					{
						int d = b;
						for (int j = i - 2; j >= d; j--)
						{
							fprintf(fp1, "%c", c[j]);
							b++;
						}
						if (d == 0)
							fprintf(fp1, "\n");
					}
				}
				rewind(fp);
				int j = 0;

				for (int i = count - 2; i >= 0; i--)
				{
					fscanf(fp, "%c", &c[i]);
				}
				for (int j = 0; j < count - 1; j++)
				{
					fprintf(fp2, "%c", c[j]);
				}
			}
			fclose(fp);
			fclose(fp1);
			fclose(fp2);
		}break;

			/*3.	Имеется текстовый файл. Получить текст, в котором в конце каждой строки из заданного файла добавлен восклицательный знак.*/
		case 3: {
		}break;

			/*4.	Дан файл, содержащий различные даты. Каждая дата - это число, месяц и год. Найти самую позднюю дату.*/
		case 4: {
			int count = 5 + rand() % 5;
			dd *date = NULL;
			date = (dd*)malloc(count * sizeof(dd));
			if (date != 0)
			{
				for (int i = 0; i < count; i++)
				{
					(date + i)->date = (dates*)malloc(10 * sizeof(dates));
					generateDate((date + i)->date);

					printf("%2d.%2d.%4d\n", (date + i)->date->dd, (date + i)->date->mm, (date + i)->date->yy);
				}

				if ((fp = fopen("case4.txt", "w")) != NULL)
				{
					for (int i = 0; i < count; i++)
						fprintf(fp, "%2d\n%2d\n%4d\n", (date + i)->date->dd, (date + i)->date->mm, (date + i)->date->yy);
				}
				fclose(fp);
				printf("------------------------------------------------------------------------------\n");
				if ((fp = fopen("case4.txt", "r")) != NULL)
				{
					while (!feof(fp))
					{
						fscanf(fp, "%d", &date->date->dd);
						fscanf(fp, "%d", &date->date->mm);
						fscanf(fp, "%d", &date->date->yy);
						printf("%d.%d.%d\n", date->date->dd, date->date->mm, date->date->yy);
					}					
				}
				else
				{
					printf("error\n");
					EXIT_FAILURE;
				}
				int minY = 1980, minM = 1, minD = 1;
				for (int i = 0; i < count; i++)
				{
					if (date[i].date->yy > minY)
					{
						minY = date[i].date->yy;
					}
				}
				/*printf("Last year: %4d\n", minY);*/
				for (int i = 0; i < count; i++)
				{
					if ((date[i].date->yy == minY) && (date[i].date->mm > minM))
					{
						minM = date[i].date->mm;
					}
				}
				/*printf("Last year: %d.%4d\n", minM,minY);*/
				for (int i = 0; i < count; i++)
				{
					if (date[i].date->yy == minY&&date[i].date->mm == minM&&date[i].date->dd > minD)
					{
						minD = date[i].date->dd;
					}
				}
				printf("самая поздняя дата:%2d.%2d.%4d\n", minD, minM, minY);
			}
			}break;

			/*5.	Записать в файл g все чётные числа файла f, а в файл h все нечётные. Порядок следования чисел сохраняется*/
		case 5: {
			int mas[10];
			for (int i = 0; i < 10; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if (((fp = fopen("case5_g.txt", "w")) != NULL) && (fp1 = fopen("case5_h.txt", "w")))
			{
				printf("Файлы открыты\n");

				for (int i = 0; i < 10; i++)
				{
					if (mas[i] % 2 == 0)
						fprintf(fp, "%d\t", mas[i]);
					else
						fprintf(fp1, "%d\t", mas[i]);
				}
			}
			fclose(fp);
			fclose(fp1);
		}break;

			/*6.	В первом файле хранится k матриц из n строк и n+1 столбцов каждая (последний столбец - столбец свободных членов). Во втором файле хранится k векторов - результатов решений соответствующих систем ЛАУ с матрицами из первого файла. Вывести на экран покомпонентно исходную систему уравнений и результат, проверив его предварительно; добавить в файлы новые данные; удалить ненужную информацию.*/
		case 6: {
		}break;

			/*7.	Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
a.	 Наименование товара;
b.	 Стоимость единицы товара;
c.	 Количество каждого товара.
d.	Определить общую стоимость товара, предложенного для реализации, и его среднюю цену
*/
		case 7: {
		}break;

			/*8.	Создать бинарный файл с информацией о наличии компьютеров для продажи:
a.	 название компьютера;
b.	 частота процессора;
c.	 объем оперативной памяти;
d.	 объем жесткого диска;
e.	 цена.
f.	Определить общую стоимость предложенных к продаже компьютеров, у которых частота процессора более 2 ГГц/сек фирмы «Asus» и напечатать информацию о них.
*/
		case 8: {
		}break;
		}
		} while (n > 0);
	}