#include"MyForm.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
System::Void Project1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	inti = 0;
	intn[7] = { 1,2,4,10,20,40,100 };
this->chart1->Series[0]->Points->Clear();
while (i< 7) {
double t = multi(n[i] * 100);
		printf("time %lf , kolvo %d \n", t, n[i] * 100);
this->chart1->Series[0]->Points->AddXY(n[i] * 100, t);
i++;
    }
returnSystem::Void();
}

double Project1::MyForm::multi(int size)
{

	srand(time(NULL));
	clock_t start, end;
	int r = 0;
	inti = 0;
	int j = 0;
	int s = 0;
	doubleelem_c;
	int** a = (int**)malloc(sizeof(int*) * size);
	int** b = (int**)malloc(sizeof(int*) * size);
	int** c = (int**)malloc(sizeof(int*) * size);
	while (size >i) {
		j = 0;
		b[i] = (int*)malloc(sizeof(int) * size);
		a[i] = (int*)malloc(sizeof(int) * size);
		c[i] = (int*)malloc(sizeof(int) * size);
		while (size > j) {
			a[i][j] = rand() % 1000;
			b[i][j] = rand() % 1000;
			c[i][j] = rand() % 1000;
			j++;
		}
		i++;
	}
	start = clock();
	for (i = 0; i< size; i++)
	{
		for (j = 0; j < size; j++)
		{
			elem_c = 0;
			for (r = 0; r < size; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	free(a);
	free(b);
	free(c);
	while (size >i) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
		i++;
	}
	double diff = (end - start);
	double t = diff / CLOCKS_PER_SEC;
	return(t);


}
