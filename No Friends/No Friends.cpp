#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Friends{
	int n;
	bool *HaveFriends;
};


bool eof;
vector<Friends> allData;

int main(){

	while(!eof){


		char line[15];
		vector<string> input;
		Friends testCase;


		//getting n and setting up array
		cin.getline(line, 15);
		testCase.n = stoi(line);
		testCase.HaveFriends = new bool[testCase.n];



		//getting input from stdin
		cin.getline(line, 15);
		while (*line && !eof){
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
				testCase.HaveFriends[a] = true;
				testCase.HaveFriends[b] = true;
			}
		}

		allData.push_back(testCase);
	}




	
	//output
	for(Friends testCase: allData){
		bool none = true;

		//go though each testCase and check for friendless numbers
		for(int i = 1; i <= testCase.n; i++){
			if(!testCase.HaveFriends[i]){

				cout << i << " ";
				if(none) none = false;

			}
		}

		//print none if they all have friends
		if(none){
			cout << "NONE";
		}

		
		delete[] testCase.HaveFriends;
		cout << endl;
		cout << endl;
	}

}