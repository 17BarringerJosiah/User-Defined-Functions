
// <Project5> -- Programming: User-Defined Functions
// CSIS111-<B01>


// iostream for input/output, fstream for input/output of file(s), iomanip for manipulating output of C++ programs, string for using string class and functions, cmath for ceil and other mathematics
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;


// Two functions outside of the main program 

//First function takes one parameter, name, and prints it once called in the while loop later in the program
void printName(string name) {
    cout << setw(20) << left << name;
}

//Second function takes two parameters and calculates Percentage and Decimal
void computeAndPrint(double Score, double Total) {
    double Percentage = ceil(Score / Total * 100);
    double Decimal = Score / Total;


//Prints the Percentage and Decimal values previously calculated with width paddings and fixed-notation inseted
    cout << setw(20) << left << fixed << setprecision(0) << Percentage << setw(20) << left << fixed << setprecision(5) << Decimal;

//Prints message to the student based on their Percentage performace
if (Percentage >= 90) {
    cout << setw(20) << left << "Excellent";
}
else if (Percentage >= 80) {
    cout << setw(20) << left << "Well Done";
}
else if (Percentage >= 70) {
    cout << setw(20) << left << "Good";
}
else if (Percentage >= 60) {
    cout << setw(20) << left << "Need Improvement";
}
else {
    cout << setw(20) << left << "Fail";
}

cout << endl;
}


//main program
int main()
{
    cout << "Josiah Barringer -- CSIS111_B01" << endl << endl;

    //inputs students text file, initializes two variables: string Name and doubles Score, Total
    ifstream inputFile("students.txt");
    string Name;
    double Score, Total;

    //if statement to make sure I'm not going crazy and my file is actually opening
    if (!inputFile) {
        cerr << "Error opening input file: students.txt" << endl;
        return 1;
    }

    //Print headers for each column
    cout << setw(20) << left << "Name" << setw(20) << left << "Percentage" << setw(20) << left << "Decimal" << setw(20) << left << "Message" << endl;

    //while loop that calls both functions outside of the main program
    while (inputFile >> Name >> Score >> Total) {
      
        printName(Name);
        computeAndPrint(Score, Total);

    }

    //close students text file
        inputFile.close();

    //we out!
        return 0;

    }




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
