#include "lgs.h"
#include <math.h>
#include <iostream>

void outputMatrix4x4(double matrix[4][4])
{
	int size = 4;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n\n";
}

void outputVector(double vector[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << vector[i] << "\t";
	}
	std::cout << "\n---------------------------------------------\n\n";
}

void lrEliminate()
{
	int const size = 4;
	int k = 1;	//Eliminationsschritt
	double matrix[size][size];
	double leftMatrix[size][size];

	double helper;

	matrix[0][0] = -1;		matrix[0][1] = 1;		matrix[0][2] = -1;	matrix[0][3] = 1;
	matrix[1][0] = 1;		matrix[1][1] = 0;		matrix[1][2] = -1;	matrix[1][3] = 1;
	matrix[2][0] = 2;		matrix[2][1] = 2;		matrix[2][2] = 1;	matrix[2][3] = -1;
	matrix[3][0] = -2;		matrix[3][1] = -1;		matrix[3][2] = 1;	matrix[3][3] = 1;

	double b[4] = {1,2,3,4};

	// build up left matrix
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(i == j)
			{
				leftMatrix[i][j] = 1;
			}
			else if(i < j)
			{
				leftMatrix[i][j] = 0;
			}
			else
			{
				leftMatrix[i][j] = matrix[i][j];
			}
		}
	}

	// calculate left and right matrix
	// round
	for(int k = 1; k < size; k++)
	{
		// row
		for(int i = k; i < size; i++){
			helper = matrix[i][k - 1] / matrix[k - 1][k - 1];
			leftMatrix[i][k - 1] = helper;
			// coloumn
			for(int j = 0; j < size; j++)
			{
				matrix[i][j] -= matrix[k - 1][j] * helper;
			}
		}
	}
	// output every round
	std::cout << "leftMatrix:" << k << "\n";
	outputMatrix4x4(leftMatrix);

	std::cout << "matrix:" << k << "\n";
	outputMatrix4x4(matrix);

	// calculate y and x
	double y[size];
	double x[size] = {0,0,0,0};
	double sum = 0;

	y[0] = b[0];
	// row
	for(int i = 1; i < size; i++)
	{
		y[i] = b[i];
		// coloumn
		for(int j = 0; j < i; j++)
		{
			y[i] -= leftMatrix[i][j] * y[j];
		}
	}

	// row
	for(int i = 3; i >= 0; i--)
	{
		// coloumn
		for(int j = 3; j > i; j--)
		{
			x[i] += matrix[i][j] * x[j];
		}
		x[i] = (y[i] - x[i]) / matrix[i][i];
	}


	std::cout << "x:" << "\n";
	outputVector(x,size);

	std::cout << "y:" << "\n";
	outputVector(y,size);
}


void jacobi()
{
	int const size = 3;
	double matrix[size][size] = {{  3, 1, 0},
								  { 1, 3, 1},
								  { 0, 1, 3}};

	double helper;

	double b[size] = {1,5,7};
	double x[size] = {0,0,0};
	double xNew[size] = {0,0,0};
	double sum = 0;
	bool isWhile = true;
	double abbruch[size];
	// calculate matrix
	// round
	do
	{
		// row
		for(int i = 0; i < size; i++)
		{
			sum = 0;
			// coloumn
			for(int j = 0; j < size; j++)
			{
				if(j != i)
					sum += matrix[i][j] * x[j];
			}
			xNew[i] = (1 / matrix[i][i]) * (b[i] - sum);


			abbruch[i] = x[i] - xNew[i];
		}
		isWhile = sqrt(abbruch[0] * abbruch[0] + abbruch[1] * abbruch[1] + abbruch[2] * abbruch[2]) > 0.001;
		
		x[0] = xNew[0];
		x[1] = xNew[1];
		x[2] = xNew[2];

	} while(isWhile);

	std::cout << "x:" << "\n";
	outputVector(x, size);
}

void gaussSeidel()
{
	int const size = 3;

	double matrix[size][size] = {{  3, 1, 0},
								  { 1, 3, 1},
								  { 0, 1, 3}};
	double b[size] = {1,5,7};

	double x[size] = {0,0,0};
	double xNew;
	int test = 0;
	double sum = 0;
	double sumOldX = 0;
	double sumNewX = 0;
	bool isWhile = true;
	double abbruch[size];
	// calculate matrix
	// round
	do
	{
		// row
		for(int i = 0; i < size; i++)
		{
			sum = 0;
			// coloumn
			for(int j = 0; j < size; j++)
			{
				if(j != i)
					sum += matrix[i][j] * x[j];
			}
			xNew = (1 / matrix[i][i]) * (b[i] - sum);
			
			abbruch[i] = x[i] - xNew;

			x[i] = xNew;
		}
		isWhile = sqrt(abbruch[0] * abbruch[0] + abbruch[1] * abbruch[1] + abbruch[2] * abbruch[2]) > 0.001;	
	} while(isWhile);

	std::cout << "x:" << "\n";
	outputVector(x, size);
}