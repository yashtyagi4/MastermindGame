/* 
 * File:   main.cpp
 * Author: Yash Tyagi
 * Created on 10/08/20 11:10 PM
 * Purpose:  Mastermind Game
 * Version: 1
 * Version Highlight: Checking if the program is counting 
 *                    the correct complete and partial guesses.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


//Function Prototypes
char *strgen(int);                                  //Actual Hidden pattern generator
char *nodupli(char*, int, const char[], int);       //No-duplicate pattern generator
void rules();                                       //Rules of the game
//void count(const int);  //To count absolute right guesses and partial right guesses

//Main Execution
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));      //Random number seed
    
    //Variable Declaration
    int  len;          //Code Length
    char *ptrn;        //To store actual hidden pattern
    int  dupli;
    char RCWP, RCRP;   //RCWP: Right color, wrong position
                       //RCRP: Right color, right position
    bool check;
    
    rules();           //Printing the rules of the game
    
    //Code Length Input
    do{
        cout << endl << "Enter the code length (1-8): ";
        cin >> len;
    } while(len <=0 || len >8);

    //Finding the actual hidden pattern
    cout << "Enter the Pattern to hide: "; cin >> ptrn;
    
    //Declaration and Initialization of blockG (Block Guess) array to block 
    //all those position in Guess array which already had been matched.
    char blockG[len+1] = {'\0'};
    char blkGlen='\0';                               //blockG array length
    
    //Declaration and Initialization of blockP (Block Pattern) array to block 
    //all those position in actual Pattern array which already had been matched.
    char blockP[len+1] = {'\0'};
    char blkPlen='\0';
    
    //Initializing guess with 0   
    char guess[len+1] = {'\0'};
    RCWP = '\0'; RCRP = '\0';

    //Asking user for Guess
    cout << "MAKE YOUR GUESS: " << endl;
    cin >> guess;
    
    //Checking for all Right-Color-Right-Position(RCRP) guesses
    for(int i=0;i<len;i++)
    {
        if( ptrn[i] == guess[i])
        {
            RCRP = static_cast<char>(RCRP + 1);               //1+ RCRP
            blockP[static_cast<int>(blkPlen)] = static_cast<char>(i);
            blkPlen = static_cast<char>(blkPlen+1);
            blockG[static_cast<int>(blkGlen)] = static_cast<char>(i);
            blkGlen = static_cast<char>(blkGlen+1);
        }
    }
    
    //Checking for all Right-Color-Wrong-Position (RCWP) guesses
    for(int i=0;i<len;i++)
    {
       //Checking if a position for an element in actual pattern is blocked.
       for(int a =0;a<blkPlen;a++) {
           if( i == static_cast<int>(blockP[a]) )
                   check=true; }
       
       //Only proceed if the position (i) of an element 
       //in actual pattern is not blocked
       if(check == false){ 
           for(int j=0;j<len;j++) {
                check = false;
                
                //Checking if color matches
                if(ptrn[i] == guess[j]) {
                    
                    //Checking if the position of the
                    //matched element in Guess is blocked
                    for(int k=0;k < blkGlen;k++) {
                        if(blockG[k] == j)
                        { check = true; break; }}

                    //Only proceed if the position of the match element
                    //in Guess isn't blocked
                    if(check == false)
                    { RCWP = static_cast<char>(RCWP + 1);           //+1 RCWP

                        //Blocking the position of the matched guess array element 
                        blockG[static_cast<int>(blkGlen)] = static_cast<char>(j);
                        blkGlen = static_cast<char>(blkGlen+1);
                        break;
                    } 
                } 
           } 
       }
       check = false;
    }

    cout << static_cast<int>(RCRP) << "--" << static_cast<int>(RCWP);
    return 0;
}

//______________________________________________________________________________

char *strgen(int len)
{  
    //Domain of possible colors
    const char domain[] = {'R','G','B','P','O','W','Y','V'};    //R: RED
                                                                //G: GREEN
                                                                //B: BLACK
                                                                //P: PINK
                                                                //O: ORANGE
                                                                //W: WHITE
                                                                //Y: YELLOW
                                                                //V: VOILET
    const int dsize = 8;            //Domain size
    
    //Declaration of pattern array with user indicated code length
    char *chArr;                 
    chArr = new char[len+1];
    *(chArr+(len))='\0';            //Making extra index NULL
    bool check;
    
    for(int i=0; i < len; i++)
    {
            do{
            chArr[i]=domain[rand() % dsize];
            check = true;
            
            for(int j=i-1;j>=0;j--)
                if(chArr[i]==chArr[j])
                    check = false;
            
            if(check) break;   
            } while(true);  
    }
    return chArr;
}
//______________________________________________________________________________

void rules()
{
    cout << "HELLO, WELCOME TO MASTERMIND!" << endl
         << "Your mission is to crack the secret hidden color pattern by making guesses." << endl
         << "With each guess the game will tell you that in your guessed pattern, how many colors are in the actual pattern." << endl
         << "-If a guessed color is wrong, the game will show you: -" << endl
         << "-If a guessed color is right but is at wrong position, the game will show: X" << endl
         << "-If a guessed color is right and also at the correct position, the game will show: O" << endl
         << endl << "INSTRUCTIONS:" << endl << "1) You have maximum of 10 guesses to crack the pattern." << endl
         << "2) To input your guessed pattern, type the first letter of the colors all together in the order you guessed them." << endl
         << "For eg. If you want to guess RED-GREEN-YELLOW-ORANGE for a 4 code length pattern, type RGYO." << endl << endl
            
         << "Available colors to chose from:" << endl 
         << "| R : RED    | G: GREEN | B: BLACK  | P: PINK   |" << endl
         << "| O : ORANGE | W: WHITE | Y: YELLOW | V: VOILET |" << endl;
}

//______________________________________________________________________________
