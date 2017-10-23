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
double dtmnt(int dim, vector<vector <double>> matrix) {
                vector< vector<double> > t;
                double d=0;
                if (dim==1)
                        return matrix[0][0];
                else if  (dim==2)
                        return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
                else {
                        for( int i=0;i<dim;i++) {
                                for(int j =1;j<dim;j++) {
                                        vector<double> row;
                                        for (int k=0; k<dim ;k++) {
                                                if (k==i)
                                                        continue;
                                                row.push_back(matrix[j][k]);
                                        }
                                        t.push_back(row);
                                }
                	if ((i%2)==0)
                	d  += matrix[0][i]*dtmnt(dim-1, t);
                	if ((i%2)==1)
                	d -= matrix[0][i]*dtmnt(dim-1, t);
                       }
                }
	        return d;
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
	cout << dtmnt(n,m)<<endl;
}
	
