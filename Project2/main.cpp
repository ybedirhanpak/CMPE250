#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Passenger.h"
#include "Airport.h"

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
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;

    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    ifstream infile(argv[1]);
    string line;
    // process first line
    getline(infile, line);
    vector<string> tokens1;
    split(line,tokens1);
    int P = stoi(tokens1[0]);
    cout << "number of input lines: " << P << endl;

    int L = stoi(tokens1[1]);
    cout << "number of luggage counters: " << L << endl;

    int S = stoi(tokens1[2]);
    cout << "number of security counters: " << S << endl;

    //Create the 8 different cases
    Airport myAirport1(L,S,false,false,false);
    Airport myAirport2(L,S,true,false,false);
    Airport myAirport3(L,S,false,true,false);
    Airport myAirport4(L,S,true,true,false);
    Airport myAirport5(L,S,false,false,true);
    Airport myAirport6(L,S,true,false,true);
    Airport myAirport7(L,S,false,true,true);
    Airport myAirport8(L,S,true,true,true);

    //Add cases to the array
    vector<Airport> airports;
    airports.push_back(myAirport1);
    airports.push_back(myAirport2);
    airports.push_back(myAirport3);
    airports.push_back(myAirport4);
    airports.push_back(myAirport5);
    airports.push_back(myAirport6);
    airports.push_back(myAirport7);
    airports.push_back(myAirport8);

    for (int i=0; i<P; i++) {
        getline(infile, line);
        vector<string> tokens;
        split(line,tokens);
        int arrivalTime = stoi(tokens[0]);
        int boardTime = stoi(tokens[1]);
        int luggageTime= stoi(tokens[2]);
        int securityTime = stoi(tokens[3]);
        char VIP = tokens[4].at(0);
        char luggage = tokens[5].at(0);

        Passenger passenger(arrivalTime,boardTime,luggageTime,securityTime,VIP,luggage);
        for(int j=0;j<8;j++) {
            airports[j].addIncomingPassenger(passenger);
        }
    }

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    cout <<"Output: "<<endl;
    ofstream myfile;
    myfile.open (argv[2]);
    for(int i=0;i<8;i++){
        airports[i].start();
        myfile << airports[i].getAverageWaitingTime() << " " << airports[i].getPassengerMissedFlight() << endl;
        cout << airports[i].getAverageWaitingTime() << " " << airports[i].getPassengerMissedFlight() << endl;
    }

    myfile.close();

    return 0;
}