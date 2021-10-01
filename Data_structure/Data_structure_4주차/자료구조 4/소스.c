#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** create_matrix(int **matrix, int row, int col);
int  free_matrix(int **matrix, int  row, int  col);
void  print_matrix(int **matrix_a, int **matrix_b, int  row, int  col);
int  fill_data(int  **matrix, int  row, int  col);
int  transpose_matrix(int  **matrix, int  **matrix_t, int  row, int  col);
int  addition_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sum, int  row, int  col);
int  subtraction_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sub, int  row, int  col);
int  multiply_matrix(int  **matrix_a, int  **matrix_t, int  **matrix_axt, int  row, int  col, int e);
int **matrix_a2=NULL;
int **matrix_b2=NULL;
int **matrix_t2=NULL;
int **matrix_sum2=NULL;
int **matrix_sub2=NULL;
int **matrix_axt2=NULL;

int main(void) {

	int row, col;

	printf("[-----[���ֿ�] [2019038044]-----]\n");
	printf("����� ��(row)�� ��(column)�� ���� �Է��ϼ���: ");
	scanf("%d%d", &row, &col);

	matrix_a2 = create_matrix(matrix_a2, row, col);
	matrix_b2 = create_matrix(matrix_b2, row, col);
	matrix_t2 = create_matrix(matrix_t2, row, col);
	matrix_sum2 = create_matrix(matrix_sum2, row, col);
	matrix_sub2 = create_matrix(matrix_sub2, row, col);
	matrix_axt2 = create_matrix(matrix_axt2, row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_a2[i][j] = fill_data(matrix_a2, i, j);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_b2[i][j] = fill_data(matrix_b2, i, j);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_sum2[i][j] = addition_matrix(matrix_a2, matrix_b2, matrix_sum2, i, j);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_sub2[i][j] = subtraction_matrix(matrix_a2, matrix_b2, matrix_sub2, i, j);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_t2[j][i] = transpose_matrix(matrix_a2, matrix_t2, i, j);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int e = 0; e < col; e++)
				matrix_axt2[i][j] = multiply_matrix(matrix_a2, matrix_t2, matrix_axt2, i, j, e);
		}
	}

	print_matrix(matrix_a2, matrix_b2, row, col);

	free_matrix(matrix_a2, row, col);
	free_matrix(matrix_b2, row, col);
}

int** create_matrix(int **matrix, int row, int col) //����� �����޸� �Ҵ� ������� ����
{
	if (row <= 0 || col <= 0) {
		printf("��� ���� ���� Ȯ���ϼ���.\n");
		return NULL;
	}
	else {
		matrix = (int **)malloc(row * sizeof(int));
		for (int i = 0; i < col; i++)
			matrix[i] = (int*)malloc(col * sizeof(int));
	}
	return (int**)matrix;
}

int  fill_data(int  **matrix, int  row, int  col) //����� ������ �������� �����Ѵ�
{
	srand((unsigned)time(NULL));
	matrix[row][col] = rand() % 20; //0~19 ���ڸ� �������� ����� ������ ä��
	return matrix[row][col]; //row, col��° ������ ����
}

int  free_matrix(int **matrix, int  row, int  col)
{ //�޸� ����
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix); //2���� �迭�̹Ƿ� �ι� ������ �ʿ���

	return 0;
}

void  print_matrix(int  **matrix_a, int **matrix_b, int  row, int  col)
{ //����� ���

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_sum2[i][j]); //A+B ���
		printf("\n");
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_sub2[i][j]); //A-B ���
		printf("\n");
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_axt2[i][j]); //AxT ���
		printf("\n");
	}

}

int  transpose_matrix(int  **matrix_a, int  **matrix_t, int  row, int  col)
{ //��� A�� ��ġ��� T�� ����

	matrix_t2[row][col] = matrix_a2[row][col];
	return matrix_t2[row][col];

}

int  addition_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sum, int  row, int  col)
{ //��� A+B�� ����

	matrix_sum2[row][col] = (matrix_a2[row][col] + matrix_b2[row][col]);
	return matrix_sum2[row][col];
}

int  subtraction_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sub, int  row, int  col)
{ //��� A-B�� ����

	matrix_sub2[row][col] = matrix_a2[row][col] - matrix_b2[row][col];
	return matrix_sub2[row][col];
}

int  multiply_matrix(int  **matrix_a, int  **matrix_t, int  **matrix_axt, int  row, int  col, int e)
{ //��� A x T�� ����

	matrix_axt2[row][col] = matrix_a2[row][e] * matrix_t2[e][col];

	return matrix_axt2[row][col];
}