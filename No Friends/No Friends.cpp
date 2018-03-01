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


char line[15];
bool eof, none = true;
vector<Friends> allData;

int main(){

	while(!eof){
		vector<string> input;

		Friends testCase;

		//getting n and setting up array
		cin.getline(line, 15);
		testCase.n = stoi(line);
		testCase.HaveFriends = new bool[testCase.n];



		cin.getline(line, 15);
		//getting input
		while (*line && !eof){
			input.push_back(line);
			if(cin.eof())
				eof = true;
			
			else
				cin.getline(line, 15);
		}



		//testing input
		for (string i : input){
			int a = stoi(strtok((char *)i.c_str(), " "));
			int b = stoi(strtok(nullptr, " "));

			if (a != b){
				testCase.HaveFriends[a] = true;
				testCase.HaveFriends[b] = true;
			}
		}

		allData.push_back(testCase);
	}




	
	//output
	for(Friends testCase: allData){
		for(int i = 1; i <= testCase.n; i++){
			if(!testCase.HaveFriends[i]){
				cout << i << " ";
				if(none) none = false;
			}
		}

		if(none){
			cout << "NONE";
		}

		delete[] testCase.HaveFriends;
		cout << endl;
		cout << endl;
		none = true;
	}

}