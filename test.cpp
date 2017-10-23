#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <memory>

using namespace std;

//Function used to calculate determinant
double dtmnt(int dim, vector<vector <double>> matrix) {
                double d=0;     								 //determinant
                if (dim==1)									 //If dimension = 1
                        return matrix[0][0];
                else if  (dim==2)								 //If dimension = 2
                        return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
                else { 										 //dimension >=3 
                        for( int i=0;i<dim;i++) {
                                        vector< vector<double> > t; 				 //Submatrix
				        for(int j =1;j<dim;j++) {
                                        vector<double> row;      
                                        for (int k=0; k<dim ;k++) {
                                                if (k==i)
                                                        continue;
                                                row.push_back(matrix[j][k]);
                                        }
                                        t.push_back(row);					 //Input submatrix
                                }
                           if ((i%2)==0)							 //Calculate determinant
                           d  += matrix[0][i]*dtmnt(dim-1, t);
                           if ((i%2)==1)
                                 d -= matrix[0][i]*dtmnt(dim-1, t);

                       }
                }
                        return d;								 //Output determinant

        }


int main()
{
	cout <<"Enter dimension: " <<endl;
	int n;
	cin>>n;
	vector < vector<double> > m;
	for(int i=0;i<n;i++){
		vector<double> row;
		for(int j=0;j<n;j++){
			double k;
			cin >>k;
			row.push_back(k);
		}
		m.push_back(row);	
	}
//	double d=0;
/*	vector< vector<double> > t;
	                for( int i=0;i<(n);i++) {
                                for(int j =1;j<n;j++) {
                                        vector<double> row;
                                        for (int k=0; k<n;k++) {
                                                if (k==i)
                                                        continue;
                                                row.push_back(m[j][k]);
                                        }
                                        t.push_back(row);
                                }
				cout << dtmnt(n-1,t) <<endl;
                                if ((i%2)==0)
                                d  += m[0][i]*dtmnt(n-1, t);
                                if ((i%2)==1)
                                 d -= m[0][i]*dtmnt(n-1, t);

                     }
                      cout<< d<<endl; */
		cout <<dtmnt(n,m) <<endl;	

}
	
