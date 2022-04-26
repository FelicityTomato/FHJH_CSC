
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true, int color=0);
void PrintHint(int guess[], int hint[]);

void generateAnswer(int ans[])  {
    // set ans[0] ~ ans[3]
    // YOUR CODE HERE!!

    for (int i=0; i<4; i++) ans[i]=i+1; 
}
bool validateTry(string tryAnswer, int guess[]) {
    // if tryAnswer is not allowed, return false
    // ex:  tryAnswer.length() != 4;
    // YOUR CODE HERE!!


    for(int i=0; i<4; i++) {
        guess[i] = tryAnswer[i]-48;
    }
    return true;
}

bool checkGuess(int guess[], int ans[], int hint[])  {
    // Your Code here!! 
    hint[0]=1;
    hint[1]=2;
    return hint[0] == 4 ? true: false;
}

int main()
{
    srand(time(0)); // set rand seed
    string tryAnswer;
    int guess[4];
    int answer[4];
    int hint[2] = {0,0};
    bool win = false;

    // init  
    system("clear"); //replace this line with system("clear"); if you run Linux or MacOS
    PrintMessage("1 A 2 B", true, true, 44);
    PrintMessage("GUESS", false, true, 34);
    PrintMessage("", false, true);
    generateAnswer(answer);

    int times;
    for(times=10; times > 0; times--) {
        cout <<  times << " > " ; 
        cin >> tryAnswer;
        if (! validateTry(tryAnswer, guess) ) {
            // Do Something!
        }
        win = checkGuess(guess, answer, hint);
        //win = true;
        PrintHint(guess, hint);
        if (win) {
            break;
        }
        
    }
    if (win)
        PrintMessage("YOU WON!", false, true, 31);
    else {
        cout << ("\033[1A\r"); // move cursor up 1 line and return to left
        PrintMessage("Anser is :", true, true, 33);
        PrintMessage( to_string(answer[0])  + to_string(answer[1]) + to_string(answer[2]) + to_string(answer[3])
        , false, true, 33);
        PrintMessage("GAME OVER", false, true, 33);
    }
    if (win && times >= 5) {
        // https://www.asciiart.eu/movies/ice-age
        cout << "                             ,--.\"\"\n";
        cout << "                      __,----( o ))\n";
        cout << "                    ,'--.      , (\n";
        cout << "             -\"\",:-(    o ),-'/  ;\n";
        cout << "               ( o) `o  _,'\\ / ;(\n";
        cout << "                `-;_-<'\\_|-'/ '  )\n";
        cout << "   Good JOB!!        `.`-.__/ '   |\n";
        cout << "                       `. .__,   ;\n";
        cout << "                       \\`       |\n";   
    }
}
/*
+-------------------------+
|        1 A 2 B          |
+-------------------------+            
|         Guess           |
+-------------------------+
|     0123       1A2B     |
|     0123       1A2B     |
|                         |
+-------------------------+
|        YOU WON!         |
+-------------------------+
*/


void PrintMessage(string message, bool printTop = true, bool printBottom = true, int color=0)
{
    if (printTop) cout << "+-------------------------+" << endl;

    cout << "|";
    
    bool front = true;
    for (int i = message.length(); i < 25; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << "\033[" << color << "m" <<  message.c_str()  << "\033[m";
 
    cout << "|" << endl;

    if (printBottom) cout << "+-------------------------+" << endl;
    
}


void PrintHint(int guess[], int hint[])
{
    cout << ("\033[3A\r"); // move cursor up 3 line and return to left
    cout << "|     " << guess[0] << guess[1] << guess[2] << guess[3]
         << "       " << hint[0] << 'A' << hint[1] << 'B'
        << "     |" << endl;
    PrintMessage("", false, true);

}
