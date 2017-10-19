/*File: FinalProject.cpp
Author: Wayne Nguyen
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Matrix {
public:
	Matrix(double const  &m): matrix(m) {}

	double element(int i, int j) {return matrix[i][j];}
	void change(int i, int j,double newValue) {matrix[i][j] =newValue;}
	
	double dtmnt(int dim, Matrix matrix) {
		double t[99][99];
		double dtmnt=0;
		if (dim==1)
			return m[0][0];
		else if  (dim==2)
			return mtx[0][0]*mtx[1][1])-mtx[0][1]*mtx[1][0];
		else {
			for( int i=0; i<dim;i++) {
				for(int j =1;j<dim;j++) {
					int j1=0;
					for (int k=0; k<n;k++) {
						if (k==c) 
							continue;
						t[j-1][j1]=m[j][k];
						j1++; 
					}
				}
			double c = 1;
			if ((i%2)==1)
				c=-1;
			dtmnt= dtmnt + c*m[0][i]*dtmnt(dim-1,t);
			}
		}
	}
	
private:
	int dim;
	double matrix[99][99]; 
};

int main()
{
	cout<<"Enter the dimension of the square matrix: " <<endl;
	int n;
	cin >> n;
	double m[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>m[i][j];
	}
	Matrix matrix(n,m[n][n]);
	return matrix.dtmnt;
}
		
