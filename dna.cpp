#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

int main(int argc, char** argv){

  // boolean for while loop
  bool run = true;

  while(run = true){
    //command line argument
    string inFile = argv[1];
    string line;
    ifstream inFS (inFile);

    // declare and initialize all variables

    //nucleotides
    int countA = 0;
    int countT = 0;
    int countC = 0;
    int countG = 0;

    //bigrams
    int AA = 0;
    int AT = 0;
    int AC = 0;
    int AG = 0;

    int TA = 0;
    int TT = 0;
    int TC = 0;
    int TG = 0;

    int CA = 0;
    int CT = 0;
    int CC = 0;
    int CG = 0;

    int GA = 0;
    int GT = 0;
    int GC = 0;
    int GG = 0;

    // etc
    int countLines = 0;
    int countPairs = 0;

    //quick maths
    int sum = 0;
    double mean = 0.0;
    double variance = 0.0;
    double stDev = 0.0;

    // probability
    double probA = 0.0;
    double probT = 0.0;
    double probC = 0.0;
    double probG = 0.0;

    double probAA = 0.0;
    double probAT = 0.0;
    double probAG = 0.0;
    double probAC = 0.0;

    double probCA = 0.0;
    double probCC = 0.0;
    double probCT = 0.0;
    double probCG = 0.0;

    double probTA = 0.0;
    double probTC = 0.0;
    double probTT = 0.0;
    double probTG = 0.0;

    double probGA = 0.0;
    double probGC = 0.0;
    double probGT = 0.0;
    double probGG = 0.0;

    // create + open file to write to
    ofstream outFS;
    outFS.open("sbejeranoDNA.txt");
    outFS << "Sofia Bejerano \nID: 2317822 \nCPSC 350: Data Structures \nAssignment 1: DNA Sequence" << endl;
    outFS << " " << endl;

    if(inFS.is_open()){
      // checks lines in file/while there are lines to read
      while(getline(inFS,line)){
        // line count ASK!!
        countLines++;
        countLines++;
        countLines++;
        countLines++;
        countLines++;
        cout << countLines << endl;

        //goes through lines
        for(int i = 0; i < line.length() - 1; ++i){
          string pair = line.substr(i, 1 + i);

          //transform(pair.begin(), pair.end(), pair.begin(), ::tolower);

          // pair total +
          countPairs++;

          //count A
          if(pair.find("AA")){
            countA++;
            countA++;
            AA++;
          }
          if(pair.find("AC")){
            countA++;
            countA++;
            AC++;
          }
          if(pair.find("AT")){
            countA++;
            countA++;
            AT++;
          }
          if(pair.find("AG")){
            countA++;
            countA++;
            AG++;
          }

          //count C
          if(pair.find("CC")){
            countC++;
            countC++;
            CC++;
          }
          if(pair.find("CA")){
            countC++;
            countC++;
            CA++;
          }
          if(pair.find("CT")){
            countC++;
            countC++;
            CT++;
          }
          if(pair.find("CG")){
            countC++;
            countC++;
            CG++;
          }

          //count T
          if(pair.find("TT")){
            countT++;
            countT++;
            TT++;
          }
          if(pair.find("TA")){
            countT++;
            countT++;
            TA++;
          }
          if(pair.find("TC")){
            countT++;
            countT++;
            TC++;
          }
          if(pair.find("TG")){
            countT++;
            countT++;
            TG++;
          }

          // count G
          if(pair.find("GG")){
            countG++;
            countG++;
            GG++;
          }
          if(pair.find("GA")){
            countG++;
            countG++;
            GA++;
          }
          if(pair.find("GC")){
            countG++;
            countG++;
            GC++;
          }
          if(pair.find("GT")){
            countG++;
            countG++;
            GT++;
          }
          //count pairs of DNA


          //calculate and print sum
          sum = countA + countC + countT + countG;
          outFS << "The sum of nucleotides for this file is: " << sum << endl;

          //calculate and print mean
          mean = (double)sum / (double)countLines;
          outFS << "The mean of the nucleotides for this file is: " << mean << endl;

          //calculate and print variance
          variance = (double)mean / 10;
          outFS << "The variance of the nucleotides for this file is: " << variance << endl;

          //calculate and print standard deviation
          stDev = sqrt(variance);
          outFS << "The standard deviation of the nucleotides for this file is: " << stDev << endl;

          //new line space
          outFS << " " << endl;

          // probability

          outFS << "Here is the relative probability of each nucleotide:" << endl;

          //single nucleotides
          probA = double(countA) / double(sum);
          outFS << "A: " << probA << endl;

          probC = double(countC) / double(sum);
          outFS << "C: " << probC << endl;

          probT = double(countT) / double(sum);
          outFS << "T: " << probT << endl;

          probG = double(countG) / double(sum);
          outFS << "G: " << probG << endl;

          outFS << " " << endl;
          outFS << "Here is the relative probability of each nucleotide bigram: " << endl;

          cout << AA << endl;
          cout << AC << endl;

          cout << GC << endl;
          cout << GT << endl;
          cout << GG << endl;

          //bigram probability
          probAA = double(AA) / double(sum);
          outFS << "AA: " << probAA << endl;

          //ASK!! why this isn't counting all the AC's
          probAC = double(AC) / double(sum) * 2;
          outFS << "AC: " << probAC << endl;

          probAT = double(AT) / double(sum);
          outFS << "AT: " << probAT << endl;

          probAG = double(AG) / double(sum);
          outFS << "AG: " << probAG << endl;

          // C_ bigrams
          probCA = double(CA) / double(sum);
          outFS << "CA: " << probCA << endl;

          probCC = double(CC) / double(sum);
          outFS << "CC: " << probCC << endl;

          probCT = double(CT) / double(sum);
          outFS << "CT: " << probCT << endl;

          probCG = double(CG) / double(sum);
          outFS << "CG: " << probCG << endl;

          // T_ bigrams
          probTA = double(TA) / double(sum);
          outFS << "TA: " << probTA << endl;

          probTC = double(TC) / double(sum);
          outFS << "TC: " << probTC << endl;

          probTT = double(TT) / double(sum);
          outFS << "TT: " << probTT << endl;

          probTG = double(TG) / double(sum);
          outFS << "TG: " << probTG << endl;

          // G_ bigrams
          probGA = double(GA) / double(sum);
          outFS << "GA: " << probGA << endl;

          probGC = double(GC) / double(sum);
          outFS << "GC: " << probGC << endl;

          probGT = double(GT) / double(sum);
          outFS << "GT: " << probGT << endl;

          probGG = double(GG) / double(sum);
          outFS << "GG: " << probGG << endl;

          //ask to reloop
          cout << "Do you want to read another file? (y/n): " << endl;
          string choice;
          cin >> choice;

          // exiting loop check
          if(choice.compare("n")){
            run = false;
            cout << "Exiting the program now!" << endl;
            exit(1);
          } else {
            continue;
          }
        }
      }

    }
  }
}
