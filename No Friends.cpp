#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, pos = 0, size = 5;
char nStr[7];
vector<int> Friendless; 
bool loop = true;

int main(){
	char (*input)[15] = new char[size][15];
	
	cin.getline(nStr, 7);


	for(int i = 1; i <= n; i++){
		Friendless.push_back(i);
	}

	char line[15];
	cin.getline(line,15);
	while(*line){


		input[pos++] == line;


		if(pos >= size){
			char (*tmp)[15] = new char[size+1][15];
			copy(input, input + size, tmp);
			delete[] input;
			input = tmp;
		}


		cin.getline(line,15);
	}

	for(int i = 0; i < pos; i++){
		cout<<input[i]<<endl;
	}

}