#include <iostream>
#include <string> //for strings
#include <sstream> //for stringstream
#include <fstream> //for files

using namespace std;

int main() {
	int count = 0; //a int variable to be used as a counter
	double *arrPtr = new double[19], sum = 0, average = 0; //a dynamic memory allocating array pointer and 2 double variables
	string str; //necessary string variable
	stringstream stdd; //a stringstream variable
	ifstream iFile; //a ifstream variable, the file
	iFile.open("dataFile.txt", fstream::in); //opens the file to be read

	if (iFile) { //runs if the file is abundant
		while (getline(iFile, str)) { //a while loop that retrieves each line from the file using getline()
			stdd << str; //adds the line into the stdd file
			stdd >> arrPtr[count]; //sets the element in the "arrPtr" array to the line in the stdd file
			stdd.clear(); //clears the stdd file
			count++; //counter
		}
	}

	iFile.close(); //closes the file

	for (int i = 0; i < 19; i++) { //a for loop that runs 19 times
		sum += arrPtr[i]; //adds up all of the elements from the "arrPtr" array into the "sum" variable
	}

	average = sum / 19; //divides the "sum" variable by 19 to make the value of the "average" variable

	//below outputs the sum and average
	cout << "The sum is " << sum << endl;
	cout << "The average is " << average << endl;

	delete[] arrPtr; //deletes the memory allocated for the pointer variable
	arrPtr = NULL; //sets the array pointer to NULL
	return 0;
}