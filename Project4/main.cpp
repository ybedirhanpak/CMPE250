#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <random>
#include "Graph.h"

using namespace std;

template <class Container>
void split(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {

    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project3 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;

    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    ifstream infile(argv[1]);

    //Next line of the input
    string nextLine;
    //Get the first line to read number rows and columns
    getline(infile,nextLine);
    vector<string> tokens1;
    split(nextLine,tokens1);

    const int ROWS = stoi(tokens1[0]);
    const int COLS = stoi(tokens1[1]);

    Graph myGraph(ROWS,COLS);

    for(int i=0;i<ROWS;i++){
        getline(infile,nextLine);
        istringstream iss(nextLine);
        string token;
        myGraph.createRows(i);
        for(int j=0;iss >> token;j++){
            int height = stoi(token);
            myGraph.addNode(i,j,height);
        }
    }
    //Get the number of queries
    getline(infile,nextLine);
    vector<string> tokens2;
    split(nextLine,tokens2);

    int Q = stoi(tokens2[0]);
    //For only one query
    Q = 1;

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream outputFile;
    outputFile.open (argv[2]);

    for(int p = 0;p < Q;p++){
        //cout << "----------------------" << endl;
        //Get the coordinates
        getline(infile,nextLine);
        vector<string> tokens3;
        split(nextLine,tokens3);
        int r1 = stoi(tokens3[0]);
        int c1 = stoi(tokens3[1]);
        int r2 = stoi(tokens3[2]);
        int c2 = stoi(tokens3[3]);
        //cout << "For query: " << p << " coordinates: (" << r1 << "," << c1 << ")" << " to (" << r2 << "," << c2 << ")" << endl;
        myGraph.calculateLadder(r1,c1,r2,c2);
        //cout << "Minimum ladder : " << myGraph.getLadder(r2,c2) << endl;
        outputFile << myGraph.getLadder(r2,c2) << endl;
        myGraph.resetLadder();
    }

    outputFile.close();

    return 0;
}