#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, char** argv){
  bool run = true;
  while(run){
    string inFile = argv[1];
    string line;
    ifstream inFS(inFile);

    // variables!

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

    int totalLines = 0;
    int pairCount = 0;
    int lineLength = 0;

    string pair = "";
    string letter = "";

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

    if(inFS.is_open()){
      while(getline(inFS, line)){
        totalLines++;
        for(int i = 0; i < line.size() - 1; ++i){
          letter = line.substr(i,1);
          pair = line.substr(i,2);

          //cout << letter << endl;
          //cout << pair << endl;

          lineLength++;
          pairCount++;

          //count single nucleotides
          if(letter.compare("A") == 0){
            countA++;
          } else if(letter.compare("T") == 0){
            countT++;
          } else if(letter.compare("C") == 0){
            countC++;
          } else if(letter.compare("G") == 0){
            countG++;
          }

          //count bigrams
          if(pair.compare("AA") == 0){
            AA++;
            //cout << "AA = " << AA << endl;
          } else if(pair.compare("AC") == 0){
            AC++;
            //cout << "AC = " << AC << endl;
          } else if(pair.compare("AT") == 0){
            AT++;
            //cout << "AT = " << AT << endl;
          } else if(pair.compare("AG") == 0){
            AG++;
            //cout << "AG = " << AG << endl;
          } else if(pair.compare("CA") == 0){
            CA++;
            //cout << "CA = " << CA << endl;
          } else if(pair.compare("CC") == 0){
            CC++;
            //cout << "CC = " << CC << endl;
          } else if(pair.compare("CT") == 0){
            CT++;
            //cout << "CT = " << CT << endl;
          } else if(pair.compare("CG") == 0){
            CG++;
            //cout << "CG = " << CG << endl;
          } else if(pair.compare("TA") == 0){
            TA++;
            //cout << "TA = " << TA << endl;
          } else if(pair.compare("TC") == 0){
            TC++;
            //cout << "TC = " << TC << endl;
          } else if(pair.compare("TT") == 0){
            TT++;
            //cout << "TT = " << TT << endl;
          } else if(pair.compare("TG") == 0){
            TG++;
            //cout << "TG = " << TG << endl;
          } else if(pair.compare("GA") == 0){
            GA++;
            //cout << "GA = " << GA << endl;
          } else if(pair.compare("GA") == 0){
            GA++;
            //cout << "GA = " << GA << endl;
          } else if(pair.compare("GC") == 0){
            GC++;
            //cout << "GC = " << GC << endl;
          } else if(pair.compare("GT") == 0){
            GT++;
            //cout << "GT = " << GT << endl;
          } else if(pair.compare("GG") == 0){
            GG++;
            //cout << "GG = " << GG << endl;
          }

          pair = "";
        }
      }

      //open sbejerano file
      ofstream outFS;
      outFS.open("sbejeranoDNA.txt");

      outFS << "Sofia Bejerano \nID: 2317822 \nCPSC 350: Data Structures \nAssignment 1: DNA Sequence" << endl;
      outFS << " " << endl;

      // quick maths
      sum = countA + countT + countG + countC;
      outFS << "The sum of the length of the DNA strings is: " << sum << endl;

      mean = double(sum) / double(totalLines);
      outFS << "The mean of the length of the DNA strings is: " << mean << endl;

      variance = double(mean) / 10;
      outFS << "The variance of the length of the DNA strings is: " << variance << endl;

      stDev = sqrt(variance);
      outFS << "The standard deviation of the length of the DNA strings is: " << stDev << endl;

      outFS << " " << endl;

      //probability
      outFS << "Here is the relative probability of each nucleotide: " << endl;

      probA = (double)countA / (double)sum;
      outFS << "A: " << probA << endl;

      probC = (double)countC / (double)sum;
      outFS << "C: " << probC << endl;

      probT = (double)countT / (double)sum;
      outFS << "T: " << probT << endl;

      probG = (double)countG / (double)sum;
      outFS << "G: " << probG << endl;


      //bigram probability
      outFS << " " << endl;
      outFS << "Here is the relative probability of each nucleotide bigram: " << endl;

      probAA = (double)AA / double(pairCount);
      outFS << "AA: " << probAA << endl;

      probAC = (double)AC / double(pairCount);
      outFS << "AC: " << probAC << endl;

      probAT = (double)AT / double(pairCount);
      outFS << "AT: " << probAT << endl;

      probAG = (double)AG / double(pairCount);
      outFS << "AG: " << probAG << endl;

      probCA = (double)CA / double(pairCount);
      outFS << "CA: " << probCA << endl;

      probCC = (double)CC / double(pairCount);
      outFS << "CC: " << probCC << endl;

      probCT = (double)CT / double(pairCount);
      outFS << "CT: " << probCT << endl;

      probCG = (double)CG / double(pairCount);
      outFS << "CG: " << probCG << endl;

      probTA = (double)TA / double(pairCount);
      outFS << "TA: " << probTA << endl;

      probTC = (double)TC / double(pairCount);
      outFS << "TC: " << probTC << endl;

      probTT = (double)TT / double(pairCount);
      outFS << "TT: " << probTT << endl;

      probTG = (double)TG / double(pairCount);
      outFS << "TG: " << probTG << endl;

      probGA = (double)GA / double(pairCount);
      outFS << "GA: " << probGA << endl;

      probGC = (double)GC / double(pairCount);
      outFS << "GC: " << probGC << endl;

      probGT = (double)GT / double(pairCount);
      outFS << "GT: " << probGT << endl;

      probGG = (double)GG / double(pairCount);
      outFS << "GG: " << probGG << endl;

      // gaussian distribution

      outFS << " " << endl;
      outFS << "1000 random iterations:" << endl;

      int distributionG = 0;
      double r1 = 0.0;
      double r2 = 0.0;
      double r3 = 0.0;
      int lengthDNA = 0;

      //iterate 1000 times
      for(int i = 0; i < 1000; ++i){

        // rand function
        r1 = double(rand()) / double(RAND_MAX);
  			r2 = double(rand()) / double(RAND_MAX);

        // C: standard gaussian
        distributionG = sqrt((-2) * log(r1)) * cos(2 * M_PI * r2);

        // length
        lengthDNA = (stDev * distributionG) + mean;

  			// resets string
  			string dnaString = "";

        // loop to create the DNA
  			for(int j = 0; j < lengthDNA; ++j)
  			{
  				r3 = double(rand()) / double(RAND_MAX);

  				if(r3 < probA){
  					dnaString.push_back('A');
  				}else if(r3 < (probA + probC)){
  					dnaString.push_back('C');
  				} else if(r3 < (probA + probC + probT)){
  					dnaString.push_back('T');
  				}	else{
  					dnaString.push_back('G');
  				}
  			}

        outFS << dnaString << endl;
      }

      inFS.close();
      outFS.close();

      //exit loop
      cout << "Do you want to read another file? (y/n): " << endl;
      string choice;
      cin >> choice;

      if(choice.compare("n")){
        continue;
      } else {
        run = false;
        cout << "Exiting!" << endl;
        exit(1);
      }
    }
  }
}
