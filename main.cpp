#include <stdio.h>
#include <stdlib.h>

//���������� ����� ��������� ����� �� 0 �� 1
double new_rand()
{
	return ((double)rand()) / RAND_MAX;
}

//���������� ��������� ������ �����
void generated_rand_mas(double * mas, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		mas[i] = new_rand();
}

//������� �� ����� ������ �����
void print(double * mas, size_t size)
{
	for (size_t  i = 0; i < size; i++)
	{
		double pr = mas[i];
		printf("%f ", pr);
	}
	printf("\n");
}

//����� ���������
void swap(double &a, double &b)
{	
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//���������� �������
void selection_sort(double * mas, size_t  size) {
	for (size_t idx_i = 0; idx_i < size - 1; idx_i++) {
		size_t min_idx = idx_i;
		for (size_t idx_j = idx_i + 1; idx_j < size; idx_j++)
		{
			if (mas[idx_j] < mas[min_idx])
			    min_idx = idx_j;
		}

		if (min_idx != idx_i) {
			swap(mas[idx_i], mas[min_idx]);
			min_idx = idx_i;
		}
	}
}

//main
int main(int argc, char * argv[])
{
	if (argc < 2) {
		printf("Not found parameter\n");
		return 1;
	}

	const int size = atoi(argv[1]);
	double* mas = new double[size];

	generated_rand_mas(mas, size);
	
	print(mas, size);

	selection_sort(mas, size);

	print(mas, size);

	delete[] mas;

	return 0;
}
