#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool *Printed;
vector<int> *data;

vector<int> printData(vector<int> out);

int main(){

	while(!cin.eof()){


		char line[15];
		vector<string> input;


		//getting n and setting up array
		cin.getline(line, 15);
		int n = stoi(line);
		data = new vector<int>[n];
		Printed = new bool[n];

		//getting input from stdin
		cin.getline(line, 15);
		while (*line){
			input.push_back(line);
			
			cin.getline(line, 15);
		}

		// check if none
		if(input.capacity() == 0){
			cout << "NONE" << endl << endl;
			continue;
		}

		//testing input
		for (string i : input){

			//split string and convert to int
			int a = stoi(strtok((char *)i.c_str(), " "));
			int b = stoi(strtok(nullptr, " "));

			//you can't be friends with yourself
			if (a != b){
				data[(a-1)].push_back(b);
				data[(b-1)].push_back(a);
			}
		}


		//output
		for(int i = 1; i <= n; i++){
			if(!Printed[(i-1)] && data[(i-1)].capacity() != 0){
				
				vector<int> out = {i};
				Printed[(i-1)] = true;

				vector<int> iData = printData(data[(i-1)]);
				out.insert(out.end(), iData.begin(), iData.end());

				sort(out.begin(), out.end());

				for(int k: out){
					cout << k << ' ';
				}
				cout << endl;

			}
		}

		delete[] Printed;
		delete[] data;

		cout << endl;
	}


}

//recursive function
vector<int> printData(vector<int> out){
	vector<int> returnVal;
	for(int i: out){
		if(!Printed[(i-1)]){
			returnVal.push_back(i);
			Printed[(i-1)] = true;
			vector<int> iData = printData(data[(i-1)]);

			returnVal.insert(returnVal.end(), iData.begin(), iData.end());
		}
	}

	return returnVal;
}