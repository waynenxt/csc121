#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <memory>
#include <fstream>

using namespace std;

void pp(vector<vector<double>> matrix){
	int n = matrix.size();
	cout << n << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void pp2(vector<double> row) {
	int n = row.size();
	cout << "row vec ";
	for (int i = 0; i < n; i++)
		cout << row[i];
	cout << endl;
}

double dtmnt(vector<vector <double>> matrix) {
	int dim = matrix.size();
	double d = 0;
	if (dim == 1)
		return matrix[0][0];
	//else if (dim == 2)
	//	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else {
		for (int i = 0; i<dim; i++) {
			vector< vector<double> > t;
			for (int j = 1; j<dim; j++) {
				vector<double> row;
				for (int k = 0; k<dim; k++) {
					if (k != i) row.push_back(matrix[j][k]);
				}
				//pp2(row);
				t.push_back(row);
			}
			//cout << "column " << i << endl;
			//pp(t);
			if ((i % 2) == 0)
				d += matrix[0][i] * dtmnt(t);
			if ((i % 2) == 1)
				d -= matrix[0][i] * dtmnt(t);
		}
	}
	return d;
}

int main() {
	cout << "File (0) or cin (1) => ";
	int n;
	cin >> n;
	vector < vector<double> > m;
	if (n == 1) {
		cout << "Enter dimension: " << endl;
		cin >> n;
		for (int i = 0; i < n; i++){
			vector<double> row;
			for (int j = 0; j < n; j++){
				double k;
				cin >> k;
				row.push_back(k);
			}
			m.push_back(row);
		}
	}
	else {
		string a;
		cout << "file name => ";
		cin >> a;
		ifstream stream;
		stream.open(a);
		stream >> n;
		for (int i = 0; i < n; i++){
			vector<double> row;
			for (int j = 0; j < n; j++){
				double k;
				stream >> k;
				row.push_back(k);
			}
			m.push_back(row);
		}
	}
	pp(m);
	cout << dtmnt(m) << endl;
	cin >> n;
}
