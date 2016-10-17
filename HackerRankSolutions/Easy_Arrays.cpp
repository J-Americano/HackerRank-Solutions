#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void arrays_ds();
void arrays_ds(int n, vector<int> arr);

void twod_arrays_ds();
void twod_arrays_ds(vector<vector<int>> arr);

void dynamic_array();
void dynamic_array();

int main(){
	arrays_ds();
	cout << endl;
	twod_arrays_ds();
	cout << endl;
	dynamic_array();
}

void arrays_ds(){
	cout << "Arrays-DS" << endl;
	arrays_ds(4, { 1, 3, 4, 2 });
}

void arrays_ds(int n, vector<int> arr){
	for (int arr_i = 0; arr_i < n; arr_i++){
		cout << arr[n - arr_i - 1] << " ";
	}
}

void twod_arrays_ds(){
	cout << endl << "2D Arrays-DS" << endl;
	vector<vector<int>> arr(6, vector<int>(6));
	string input = "111000010000111000002440000200001240";
	int i = 0;

	for (int arr_i = 0; arr_i < 6; arr_i++){
		for (int arr_j = 0; arr_j < 6; arr_j++){
			arr[arr_i][arr_j] = (int)input[i] - 48;
			i++;
		}
	}
	twod_arrays_ds(arr);
}

void twod_arrays_ds(vector<vector<int>> arr){
	int maxSum = -30000;

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (j + 2 < 6 && i + 2 < 6){
				int sum = arr[i][j] + arr[i][j + 1]
					+ arr[i][j + 2] + arr[i + 1][j + 1]
					+ arr[i + 2][j] + arr[i + 2][j + 1]
					+ arr[i + 2][j + 2];

				if (sum > maxSum)
					maxSum = sum;
			}
		}
	}

	cout << maxSum << endl;
}

void dynamic_array(){
	int numOfSeq = 2;
	int subLines = 5;

	vector<int> queries = { 1, 1, 1, 2, 2 };
	vector<int> xQueries = { 0, 1, 0, 1, 1 };
	vector<int> yQueries = { 5, 7, 3, 0, 1 };

	dynamic_array(numOfSeq, subLines, queries, xQueries, yQueries);
}

void dynamic_array(int numOfSeq, int subLines, vector<int> queries, vector<int> xQueries, vector<int> yQueries){
	int x, y, q, qType, lastAns, index, i;
	vector<int> seqList[numOfSeq];
	i = 0;
	while (i < subLines)
	{
		q = queries[i];
		x = xQueries[i];
		y = yQueries[i];
		index = (x^lastAns) % numOfSeq;
		switch (qType){
		case 1:
		{
				  if (seqList[index] == NULL)
				  {
					  vector<int>list(1, y);
					  seqList[index] = list;
				  }
		}
		}

		i++;
	}

	delete[] seqList;
}