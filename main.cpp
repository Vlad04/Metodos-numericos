#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
#define PI 3.14159265
#include <stdlib.h>


using namespace std;

int solveByGaussJordan(double **ab, int n, double *&x, double &det);
int solveByGaussJordan(double **ab, int n, double *&x, double &det)
{
	det = 1.;
	for (int i = 0; i < n; i++) {
		double pivote = ab[i][i];
		if (fabs(pivote) < 0.0001) {

			if (i == n - 1)
			{
				det = 0.;
				return 1;
			}

			for (int j = i + 1; j < n; j++)
			{

				if (fabs(ab[j][i]) > 0.0001) {
					double* temporal = ab[i];
					ab[i] = ab[j];
					ab[j] = temporal;
					pivote = ab[i][i];
				}

				if (j == n - 1)
				{
					det = 0.;
					return 1;
				}
			}
		}

		det *= pivote;
		for (int j = 0; j < n + 1; j++)
		{
			ab[i][j] *= pow(pivote, -1.);
		}


		for (int j = 0; j < n; j++)
		{
			if (j != i) {
				double* temporal = new double[n + 1];
				double *tmp2 = new double[n + 1];
				for (int k = 0; k < n + 1; k++)
				{
					temporal[k] = ab[i][k] * -ab[j][i];

				}

				for (int k = 0; k < n + 1; k++)
				{
					ab[j][k] += temporal[k];
				}

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		x[i] = ab[i][n];
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int weight=atoi(argv[1]);
	int angle_1=atoi(argv[2]);
	int angle_2=atoi(argv[3]);
	int steel_kind=atoi(argv[4]);
	/*
	int weight;
	int angle_1;
	int angle_2;
	int steel_kind;
	*/
	int i;
	
    std::string cmd;

	//validate angle
	if (angle_1 > 90 || angle_2 > 90) {
		std::cout << "Wrong angle , must me < 90 ";
		return -1;
	}

	double**ab = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		ab[i] = new double[3];
	}

	// sum F in x
	ab[0][0] = sin(angle_1*PI / 180);
	ab[0][1] = sin(angle_2*PI / 180);
	ab[0][2] = weight * -1;

	// sum F in y
	ab[1][0] = cos(angle_1*PI / 180);
	ab[1][1] = -1 * cos(angle_2*PI / 180);
	ab[1][2] = 0;

	//print matrix
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << ab[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//print result
	cout << "The result of the matrix is:" << endl;
	double*solucion = new double[2];
	double det;
	int code = solveByGaussJordan(ab, 2, solucion, det);
	for (int i = 0; i < 2; i++) {
		cout << "Force_" << i << ": " << solucion[i] << endl;
	}

    //plot vectors
    //TODO put this in a function please :) 

    double x_vector_1;
    double y_vector_1;
    double x_vector_2;
    double y_vector_2;

    x_vector_1 = cos(angle_1*PI/180);
    x_vector_2 = (-1) * cos(angle_2*PI/180);
    y_vector_1 = sin(angle_1*PI/180);
    y_vector_2 = sin(angle_2*PI/180);


    cmd = "Rscript plot.R ";
    cmd += std::to_string(x_vector_1)  + " ";
    cmd += std::to_string(y_vector_1)  + " ";
    cmd += std::to_string(x_vector_2)  + " ";
    cmd += std::to_string(y_vector_2)  + " ";

    cout << cmd << endl;

    i=system (cmd.c_str());

	return 0;
}

