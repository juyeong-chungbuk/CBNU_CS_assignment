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

	printf("[-----[신주영] [2019038044]-----]\n");
	printf("행렬의 행(row)과 열(column)의 값을 입력하세요: ");
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

int** create_matrix(int **matrix, int row, int col) //행렬을 동적메모리 할당 방식으로 생성
{
	if (row <= 0 || col <= 0) {
		printf("행과 열의 값을 확인하세요.\n");
		return NULL;
	}
	else {
		matrix = (int **)malloc(row * sizeof(int));
		for (int i = 0; i < col; i++)
			matrix[i] = (int*)malloc(col * sizeof(int));
	}
	return (int**)matrix;
}

int  fill_data(int  **matrix, int  row, int  col) //행렬의 성분을 랜덤으로 생성한다
{
	srand((unsigned)time(NULL));
	matrix[row][col] = rand() % 20; //0~19 숫자를 랜덤으로 행렬의 성분을 채움
	return matrix[row][col]; //row, col번째 성분을 리턴
}

int  free_matrix(int **matrix, int  row, int  col)
{ //메모리 해제
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix); //2차원 배열이므로 두번 해제가 필요함

	return 0;
}

void  print_matrix(int  **matrix_a, int **matrix_b, int  row, int  col)
{ //결과값 출력

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_sum2[i][j]); //A+B 출력
		printf("\n");
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_sub2[i][j]); //A-B 출력
		printf("\n");
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%5d", matrix_axt2[i][j]); //AxT 출력
		printf("\n");
	}

}

int  transpose_matrix(int  **matrix_a, int  **matrix_t, int  row, int  col)
{ //행렬 A의 전치행렬 T를 구현

	matrix_t2[row][col] = matrix_a2[row][col];
	return matrix_t2[row][col];

}

int  addition_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sum, int  row, int  col)
{ //행렬 A+B를 구현

	matrix_sum2[row][col] = (matrix_a2[row][col] + matrix_b2[row][col]);
	return matrix_sum2[row][col];
}

int  subtraction_matrix(int  **matrix_a, int  **matrix_b, int  **matrix_sub, int  row, int  col)
{ //행렬 A-B를 구현

	matrix_sub2[row][col] = matrix_a2[row][col] - matrix_b2[row][col];
	return matrix_sub2[row][col];
}

int  multiply_matrix(int  **matrix_a, int  **matrix_t, int  **matrix_axt, int  row, int  col, int e)
{ //행렬 A x T를 구현

	matrix_axt2[row][col] = matrix_a2[row][e] * matrix_t2[e][col];

	return matrix_axt2[row][col];
}