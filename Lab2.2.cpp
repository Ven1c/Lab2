#define_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
voidqs(int* items, intleft, intright);
voidshell(int* items, intcount);
intcompare(constvoid* x1, constvoid* x2);
intmain() {
	srand(time(NULL));
	clock_t start, end;
	int* mas = (int*)malloc(sizeof(int) * 100000);
	for (inti = 0; i< 100000; i++) {
		mas[i] = i;
	}
	printf("/ \n");
	start = clock();
	shell(mas, 100000);
	end = clock();
	double shelltime1 = end - start;
	shelltime1 = shelltime1 / CLOCKS_PER_SEC;
	printf("shell %lf\n", shelltime1);

	start = clock();
	qs(mas, 0, 100000);
	end = clock();
	double qs1 = end - start;
	qs1 = qs1 / CLOCKS_PER_SEC;
	printf("qs %lf\n", qs1);

	start = clock();
	qsort(mas, 100000, sizeof(int), compare);
	end = clock();
	double qsort1 = end - start;
	qsort1 = qsort1 / CLOCKS_PER_SEC;
	printf("qsort %lf\n", qsort1);
	printf("\n");

	int j = 99999;
	for (inti = 0; i< 100000; i++) {
		mas[i] = j;
		j--;
	}
	printf("\\ \n");
	start = clock();
	shell(mas, 100000);
	end = clock();
	shelltime1 = end - start;
	shelltime1 = shelltime1 / CLOCKS_PER_SEC;
	printf("shell %lf\n", shelltime1);

	start = clock();
	qs(mas, 0, 100000);
	end = clock();
	qs1 = end - start;
	qs1 = qs1 / CLOCKS_PER_SEC;
	printf("qs %lf\n", qs1);

	start = clock();
	qsort(mas, 100000, sizeof(int), compare);
	end = clock();
	qsort1 = end - start;
	qsort1 = qsort1 / CLOCKS_PER_SEC;
	printf("qsort %lf\n", qsort1);
	printf("\n");
	j = 50000;
	for (inti = 0; i< 100000; i++) {
		if (i< 50000) {
			mas[i] = i;
		}
		else {
			mas[i] = j;
			j--;
		}
	}
	printf("/\\ \n");
	start = clock();
	shell(mas, 100000);
	end = clock();
	shelltime1 = end - start;
	shelltime1 = shelltime1 / CLOCKS_PER_SEC;
	printf("shell %lf\n", shelltime1);

	start = clock();
	qs(mas, 0, 100000);
	end = clock();
	qs1 = end - start;
	qs1 = qs1 / CLOCKS_PER_SEC;
	printf("qs %lf\n", qs1);

	start = clock();
	qsort(mas, 100000, sizeof(int), compare);
	end = clock();
	qsort1 = end - start;
	qsort1 = qsort1 / CLOCKS_PER_SEC;
	printf("qsort %lf\n", qsort1);
	printf("\n");

	for (inti = 0; i< 100000; i++) {
		mas[i] = rand() % 100000;
	}
	printf("rand \n");
	start = clock();
	shell(mas, 100000);
	end = clock();
	shelltime1 = end - start;
	shelltime1 = shelltime1 / CLOCKS_PER_SEC;
	printf("shell %lf\n", shelltime1);

	start = clock();
	qs(mas, 0, 100000);
	end = clock();
	qs1 = end - start;
	qs1 = qs1 / CLOCKS_PER_SEC;
	printf("qs %lf\n", qs1);

	start = clock();
	qsort(mas, 100000, sizeof(int), compare);
	end = clock();
	qsort1 = end - start;
	qsort1 = qsort1 / CLOCKS_PER_SEC;
	printf("qsort %lf\n", qsort1);

}


voidshell(int* items, intcount)
{
	inti, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i<count; ++i) {
			x = items[i];
			for (j = i - gap; (x <items[j]) && (j >= 0); j = j - gap) {
				items[j + gap] = items[j];
				items[j + gap] = x;
			}
		}
	}
}
voidqs(int* items, intleft, intright)
{
	inti, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i<right)) i++;
		while ((x <items[j]) && (j >left)) j--;
		if (i<= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i<= j);
	if (left< j) qs(items, left, j);
	if (i<right) qs(items, i, right);
}
intcompare(constvoid* x1, constvoid* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
