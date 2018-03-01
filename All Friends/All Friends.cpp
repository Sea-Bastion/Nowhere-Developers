#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool eof;

int main(){

	while(!eof){


		char line[15];
		vector<string> input;


		//getting n and setting up array
		cin.getline(line, 15);
		int n = stoi(line);
		vector<int> data[n];

		//getting input from stdin
		cin.getline(line, 15);
		while (*line){
			input.push_back(line);
			if(cin.eof())
				eof = true;
			
			else
				cin.getline(line, 15);
		}



		//testing input
		for (string i : input){

			//split string and convert to int
			int a = stoi(strtok((char *)i.c_str(), " "));
			int b = stoi(strtok(nullptr, " "));

			//you can't be friends with yourself
			if (a != b){
				data[a-1].push_back(b);
				data[b-1].push_back(a);
			}
		}

	}




	/*
	//output
	for(Friends testCase: allData){
		bool none = true;

		



		//print none if they all have friends
		if(none){
			cout << "NONE";
		}

		
		cout << endl;
		cout << endl;
	}
	*/

}