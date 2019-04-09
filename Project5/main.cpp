#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;
#define BASE 1000000007

int doesContain(string* arr,int arrSize,string word){
    for(int i=0;i<arrSize;i++){
        if(arr[i] == word)
            return 1;
    }
    return 0;
}

long long int canBeDivided(string str,int i,int j,string* wordsArray,int wordArrSize,long long int** dynArr){
    //If calculated before, get value from memo
    if(dynArr[i][j] != 0){
        return dynArr[i][j];
    }

    long long int result=0;
    for(int k=i;k<=j;k++){
        string firstPart = str.substr(i,k+1-i);
        if(doesContain(wordsArray,wordArrSize,firstPart)){
            if(j>k){
                result += canBeDivided(str,k+1,j,wordsArray,wordArrSize,dynArr) % BASE;
            }
            else{
                result = (result + 1) % BASE;
            }
        }
    }
    return dynArr[i][j] = result;
}

int main(int argc, char* argv[]) {

    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project5 [input_file] [output_file]" << endl;
        return 1;
    }

    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    ifstream inputFile(argv[1]);

    //The sentence to be examined
    string sentence;
    //Number of words to look for
    int numWords;

    //Get the sentence
    inputFile >> sentence;

    //Get the number of words
    inputFile >> numWords;

    string* words = new string[numWords];

    for(int i=0;i<numWords;i++){
        inputFile >> words[i];
    }

    int length = (int) sentence.length();

    long long int** dynArr = new long long int*[length+1];
    for(int i=0;i<length;i++)
        dynArr[i] = new long long int[length+1];

    long long int result = canBeDivided(sentence,0,length-1,words,numWords,dynArr) % BASE;

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream outputFile;
    outputFile.open (argv[2]);
    outputFile << result << endl;

    return 0;
}

