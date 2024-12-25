
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//variables
int teamID;
int playerID;
int totalPlayerScore;
int totalTeam1Score = 0;
int totalTeam2Score = 0;
int totalTeam3Score = 0;
const int maxPlayer = 12;
const int maxEvent = 7;
int marks[maxPlayer][maxEvent];
int totalScores[maxPlayer];

//functions prototype
void displayLine();
int findIndWinner(int bestPlayerID, int bestPlayerTeamID);
int findTeamWinner(int bestTeam, int bestTeamScore);

int main(){
    
    ofstream outFile;

    outFile.open("input.txt");

    if (outFile.is_open()){
        outFile << "1 1001 10 5 8 10 6\n";
        outFile << "1 1002 8 7 10 7 9\n";
        outFile << "1 1003 7 10 10 6 10\n";
        outFile << "1 1004 10 10 8 7 7\n";
        outFile << "2 2001 7 8 10 9 10\n";
        outFile << "2 2002 10 8 7 8 10\n";
        outFile << "2 2003 8 6 8 8 10\n";
        outFile << "2 2004 7 8 8 8 8\n";
        outFile << "3 3001 10 9 10 10 10\n";
        outFile << "3 3002 8 7 8 8 8\n";
        outFile << "3 3003 7 8 9 10 6\n";
        outFile << "3 3004 8 6 8 7 7\n";

        outFile.close();
        cout << "\nFile 'input.txt' created successfully!" << endl;
    }
    else {
        cout << "\nSorry, input file does not exist!" << endl;
        cout << "Press any key to continue . . ." << endl;

        return 1;
    }
    
    ifstream inFile("input.txt");
    if (!inFile.is_open()){
        cout << "\nSorry, input file does not exist!" << endl;
        return 1;
    }

    for (int i = 0; i < maxPlayer; i++){
        for (int j = 0; j < maxEvent; j++){
            if (!(inFile >> marks[i][j])){
                cout << "Error reading data" << endl;
                return 1;
            }
        }
    }

    inFile.close();

    // calculate total score for team 1
    for (int i = 0; i < 4; i++){
        for ( int j = 2; j < maxEvent; j++){
            totalTeam1Score = marks[i][j] + totalTeam1Score;
        }
    }

    //calculate total score for team 2
    for (int i = 4; i < 8; i++){
        for ( int j = 2; j < maxEvent; j++){
            totalTeam2Score = marks[i][j] + totalTeam2Score;
        }
    }

    //calculate total score for team 3
    for (int i = 8; i <= 11; i++){
        for ( int j = 2; j < maxEvent; j++){
            totalTeam3Score = marks[i][j] + totalTeam3Score;
        }
    }

    //calculate total score of each player
    for (int i = 0; i < maxPlayer; i++){ ;
        for (int j = 2; j < maxEvent; j++){
            totalScores[i] += marks[i][j];
        }
    }

    //output fr
    displayLine();
    cout << "Id      E1      E2      E3      E4      E5      Total";
    displayLine();

    //team 1
    cout << "TEAM " << marks[0][0] << endl;
    for (int i = 0; i < 4; i++){
        cout << right;
        cout << marks[i][1] << setw(6) << marks[i][2] << setw(8) << marks[i][3];
        cout << setw(8) << marks[i][4] << setw(8) << marks[i][5] << setw(8) << marks[i][6];
        cout << setw(8) << totalScores[i] << endl;
    }
    cout << "TOTAL" << setw(46) << totalTeam1Score;
    displayLine();

    //team 2 
    cout << "TEAM " << marks[4][0] << endl;
    for (int i = 4; i < 8; i++){
        cout << right;
        cout << marks[i][1] << setw(6) << marks[i][2] << setw(8) << marks[i][3];
        cout << setw(8) << marks[i][4] << setw(8) << marks[i][5] << setw(8) << marks[i][6];
        cout << setw(8) << totalScores[i] << endl;
    }
    cout << "TOTAL" << setw(46) << totalTeam2Score;
    displayLine();

    //team 3
    cout << "TEAM " << marks[8][0] << endl;
    for (int i = 8; i < 12; i++){
        cout << right;
        cout << marks[i][1] << setw(6) << marks[i][2] << setw(8) << marks[i][3];
        cout << setw(8) << marks[i][4] << setw(8) << marks[i][5] << setw(8) << marks[i][6];
        cout << setw(8) << totalScores[i] << endl;
    }
    cout << "TOTAL" << setw(46) << totalTeam3Score;
    displayLine();

    int bestPlayerID, bestPlayerTeamID;
    findIndWinner(bestPlayerID, bestPlayerTeamID);

    int bestTeam, bestTeamScore;
    findTeamWinner(bestTeam, bestTeamScore);

    cout << "\nPress any key to continue . . .\n"; 

    return 0;
}

void displayLine(){
    cout << "\n-----------------------------------------------------\n";
}

//function for best player, refer ln 100 for total score each player
int findIndWinner(int bestPlayerID, int bestPlayerTeamID){
    int bestScore = 0;
    for (int i = 0; i < maxPlayer; i++){
        if (totalScores[i] >= bestScore){
            bestScore = totalScores[i];
            bestPlayerID = marks[i][1];
            bestPlayerTeamID = marks[i][0];
        }
    }
    cout << "\nWinner for Individual Category: ";
    cout << bestPlayerID << " (Team " << bestPlayerTeamID << ")\n";
    return bestScore, bestPlayerID, bestPlayerTeamID;
}

//function for best team
int findTeamWinner(int bestTeam, int bestTeamScore){
    bestTeam = 0;
    bestTeamScore = 0;

    if (totalTeam1Score > totalTeam2Score && totalTeam1Score > totalTeam3Score){
        bestTeam = marks[0][0];
        bestTeamScore = totalTeam1Score;
    }
        
    else if (totalTeam2Score > totalTeam1Score && totalTeam2Score > totalTeam3Score){
        bestTeam = marks[4][0];
        bestTeamScore = totalTeam2Score;
    }

    else{
        bestTeam = marks[8][0];
        bestTeamScore = totalTeam3Score;
    }

    cout << "Winner for Group Category: Team " << bestTeam;
    cout << " (Score = " << bestTeamScore << ")\n";

    return bestTeam, bestTeamScore;
}