/*
 * main.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: mduffy
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//#include <time.h>
//#include <stdlib.h>

using namespace std;

vector<vector<int> > parseInput(ifstream &in);
vector<float> setup(vector<vector<int> > f);

/*
 * Coefficients of Newton's polynomial algorithm
 * @param file of numbers to be evaluated
 * @return vector of analyzed newton coefficients
 */
int main(int argc, char** argv){

	/*
	 * create test files
	 */
//	ofstream os;
//	srand(time(NULL));
//	os.open("test.txt");
//	int interval = 1;
//	int counter = 0;
//	int h = 0;
//	for(int counter = 0; counter < 50; counter++){
//		int k = 0, j = 0;
//		interval = rand()%10 +1;
//		j = (h + interval);
//		os << j << ' ';
//		k = (j*j) - (6*j) + 10;
//		os << k << '\n';
//		h = j;
//	}
//	os.close();

	if(argc < 2)
	{
		cout << "usage: ./Algorithm3.2 <input file name> (Ex: ./Algorithm3.2 somefile.txt)"<< endl;
		return 1;
	}
	ifstream input(argv[1]);
	if(!input){
		cout << "Could not open the file";
		return 2;
	}


	vector<vector<int> > f_i;
	f_i = parseInput(input);

	vector<float> d_i;
	d_i = setup(f_i);
	int n = d_i.size();
//	for(auto it = d_i.begin(); it != d_i.end(); it++){
//		cerr<<*it<<endl;
//	}
	for(int k = 1; k <= n; k++){
		for(int i = 0; i < (n - k); i++){
			float temp = (d_i[i+1] - d_i[i]);
//			cerr<<"di[i]: "<<d_i[i]<<"di[i+1]: "<<d_i[i+1]<<endl;
//			cerr<<"temp: "<<temp<<endl;
			float temp2 = (f_i[i+k][0] - f_i[i][0]);
//			cerr<<"temp2: "<<temp2<<endl;
//			cerr<<"temp / temp2: "<<temp/temp2<<endl;
			d_i[i] =  (temp / temp2);
			cerr<<d_i[i]<<endl;
		}
		cerr<<"k: "<<k<<" d_i: ";
		for(int i = 0; i < n; i++){
			cerr<<d_i[i]<<" ";
		} cerr<<endl;
	}

//	for(auto it = d_i.begin(); it != d_i.end(); it++){
//		cerr<< *it << "\t\t\t";
//	}
	return 0;
}

/*
 * @param numbers to be turned into d_i
 * @return d_i in a vector
 */
vector<float> setup(vector<vector<int> > f){
	vector<float> to_return;
	for(int i = 0; i < f.size(); i++){
		//cerr<<"f[i][1]: "<<f[i][1]<<endl;
		to_return.push_back(f[i][1]);
	}
	return to_return;
}
/*
 * @param input stream of numbers
 * @return numbers in a vector of vector of ints
 */
vector<vector<int> > parseInput(ifstream &in){
	int x;
	string tempstring;
	vector<vector<int> > nums;

	while(getline(in, tempstring)){
		istringstream ss(tempstring);
		vector<int> tempVec;
		while(ss >> x){
			tempVec.push_back(x);
		}
		nums.push_back(tempVec);
	}
	return nums;
}
