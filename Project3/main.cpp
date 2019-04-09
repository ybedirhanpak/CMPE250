#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
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
    //Get the first line to read number of piggy banks
    getline(infile,nextLine);
    vector<string> tokens1;
    split(nextLine,tokens1);
    int N = stoi(tokens1[0]);
    cout << "N: " << N <<endl;

    //Construct graph
    Graph piggyBanksGraph(N);

    //Build Graph
    for(int i=0;i<N;i++){
        Node* source = piggyBanksGraph.headNodes[i];
        //Get the next line
        getline(infile,nextLine);
        //Add tokens to the vector
        vector<string> tokens;
        split(nextLine,tokens);
        //There are m keys in each piggy bank
        int m = stoi(tokens[0]);
        for(int j=0;j<m;j++){
            //Add the edges to the head from source to destination.
            int destinationVertex = stoi(tokens[j+1]);
            Node* destination = piggyBanksGraph.headNodes[destinationVertex-1];
            piggyBanksGraph.addEdge(*source,*destination);
        }
    }
    //Builds SCC
    piggyBanksGraph.buildSCC();

    //Calculates and the piggy banks to break
    piggyBanksGraph.calculatePiggyBanksToBreak();

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream outputFile;
    outputFile.open (argv[2]);

    //If there is a cycle between SCCs
    if(piggyBanksGraph.numToBreak == 0){
        piggyBanksGraph.numToBreak = 1;
        piggyBanksGraph.piggyBanksToBreak.push(piggyBanksGraph.SCCList.front().root);
        outputFile << piggyBanksGraph.numToBreak << " " << piggyBanksGraph.piggyBanksToBreak.top();
    }else{
        outputFile << piggyBanksGraph.numToBreak;
        while(!piggyBanksGraph.piggyBanksToBreak.empty()){
            outputFile << " " << piggyBanksGraph.piggyBanksToBreak.top();
            piggyBanksGraph.piggyBanksToBreak.pop();
        }
        outputFile << endl;
    }
	
	outputFile.close();


    return 0;
}

