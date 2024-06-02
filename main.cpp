#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

struct Player {
    string name;
    int score;
    bool l1_finished;
    bool l2_finished;
    bool l3_finished;
};

const int MAX_PLAYERS = 100;
int numPlayers = 0;
Player players[MAX_PLAYERS];

//Game Flow Functions
void gameName();
string chooseLesson(Player *currentPlayer);
void basicConcepts(Player* currentPlayer );
void conditionals(Player* currentPlayer );
void loopings(Player* currentPlayer );
void lecture_or_quiz(string lectures[][5], int lectureRowLen, int lectureColLen, string questionAns[0][2], string your_answers[], int qa_Row_Len, int anslength, Player* currentPlayer ,string lessonName);
void question_And_Answer(string questionAns[][2], string your_answers[], int qa_Row_Len, int anslength, Player* currentPlayer );
void show_lectures(string lectures[][5], int lectureRowLen, int lectureColLen,string lessonName);
void initializeGame(Player* currentPlayer);
void shuffle_array(string arr[10][2], int n);

//File and Data Handling Functions
void loadPlayersFromFile();
void addNewPlayer();
void savePlayersToFile();
Player* findPlayerByName(const string& playerName);



int main() {

    string action;
    string playerName;
    string res;
    loadPlayersFromFile();


    do {
        gameName();
        while(1){
            cout << "\n\n\t\t\t   \033[34mADD NEW PLAYER(1)\033[0m,";
            cout << " \033[31mPLAY GAME(2)\033[0m,";
            cout << " \033[35mSAVE AND EXIT(3)\033[0m\n\n";
            cout << "\t\t\t   \033[32mEnter your choice(1, 2, 3)\033[0m: ";
            getline(cin, action);
            action.erase(remove(action.begin(), action.end(), ' '), action.end());

            if (action == "1") {
                addNewPlayer();
                savePlayersToFile();
                do{
                    cout << "\n\t\t\t   \033[32mPress 1 to exit: \033[0m";
                    getline(cin, res);
                    res.erase(remove(res.begin(), res.end(), ' '), res.end());

                }while(res!="1");
                break;

            }

            else if (action == "2") {
                cout << "\t\t\t   \033[32mEnter player name\033[0m: ";
                getline(cin, playerName);
                playerName.erase(remove(playerName.begin(), playerName.end(), ' '), playerName.end());
                Player* currentPlayer = findPlayerByName(playerName);
                if (currentPlayer) {
                   initializeGame(currentPlayer);
                    break;
                }
                do{
                    cout << "\n\t\t\t   \033[32mPress 1 to exit: \033[0m";
                    getline(cin, res);
                    res.erase(remove(res.begin(), res.end(), ' '), res.end());
                }while(res!="1");
                break;
            }




            else if (action == "3") {
                savePlayersToFile();
                cout << "\n\t\t\t  \033[36m Player data saved. Exiting\033[0m ...\n";
                break;
            }

            else {
                cout << "\n\t\t\t  \033[31m Invalid choice\033[0m \n";
                    do{
                    cout << "\n\t\t\t   \033[32mPress 1 to exit: \033[0m";
                    getline(cin, res);
                    res.erase(remove(res.begin(), res.end(), ' '), res.end());
                }while(res!="1");
                break;
            }
        }

    } while (action != "3");

    return 0;
}





//---------------------------------FUNCTIONS-------------------------------------------------

    void basicConcepts(Player* currentPlayer ){
        string LessonName="\n\n\n\n\t\t\033[36mLESSON 1:\033[34m\n\n\t\t\033[34mBASIC CONCEPTS\033[0m\n";
        string lectures[][5]= {
            {"\n\n\t\t\033[34mWELCOME TO C++\033[0m \n\n\t\t-C++ is one of the most popular programming languages.\n\t\tIt is used to build \033[36mgames\033[0m, \033[36moperating system\033[0m, \033[36mbrowsers\033[0m, and much more.\n",
            "\n\n\t\t\033[34mOUTPUT\033[0m \n\n\t\t-Coders use output all the time to check the computer if its following the given instruction\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tcout << \"Welcome to c++\";\n",
            "\n\n\t\t\033[34mSTATEMENTS\033[0m \n\n\t\t-A line of code is called a statement\n\t\t-A statement performs a specific task.\n\n\t\t\033[34mExample:\033[0m\n\n\t\tcout << \"Coding is an art\"; \033[36m//displays Coding is an art in the console\033[0m\n",
            "\n\n\t\t\033[34mSEMICOLON\033[0m\n\n\t\t-Each statements in c++ ends width a semicolon \033[36m;\033[0m\n\n\t\tcout << \"I love C++\" \033[36m//returns an error due to no semicolon\033[0m\n",
            "\n\n\t\t\033[34mOUTPUTING A TEXT\033[0m \n\n\t\t-When printing text outputs you need to enclose the text in double qoutes\n\n\t\tcout << \033[36m\"\033[0mC++ is super easy\033[36m\"\033[0m;\n\n\n\t\t\033[34mText VS Numbers\033[0m\n\n\t\t-Computers treat numbers and text differently.\n\t\t-Number don't need quotes when you want to output them\n\n\t\tcout << 42; \033[36m//displays 42 in the console\033[0m\n"},

            {"\n\n\t\t\033[34mC++ STRUCTURE\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout << \"Hello World\";\n\t\t}",
            "\n\n\t\t\033[34m#include <iostream>\033[0m\n\n\t\t-A header file contains functions and commands\n\t\tWe need it to include in our program to use commands such as \033[36mcin\033[0m and \033[36mcout\033[0m\n",
            "\n\n\t\t\033[34mNAMESPACE\033[0m\033[0m\n\n\t\tusing namespace std;\n\t\t-This tells the program to use std namespace without prefixing each element with std::\n\n\t\tcout << \"HELLO\";\n\n\t\t\033[36minstead of\033[0m\n\n\t\tstd::cout << \"HELLO\";\n",
            "\n\n\t\t\033[34mMAIN FUNCTION\033[0m\033[0m\n\n\t\tint main(){}\n\n\t\tEach c++ program has an entry point, which is a function called main",
            "\n\n\t\t\033[34mCURLY BRACES{}\033[0m\033[0m\n\n\t\t-Indicates the beginning and end of the function, or so called the function's body.\n"},

            {"\n\n\t\t\033[34mVARIABLES\033[0m \n\n\t\t-Every Program works with values\n\t\t-A variable lets you store a value by assigning it to a name or identifier\n",
            "\n\n\t\t\033[34mVariable Types\033[0m\n\n\t\t-Each variable  has a type, which defines the type of the value it holds\n\t\tA variable can hold a text value, a \033[36mnumber\033[0m, \033[36mdecimal\033[0m, \033[36mcharacter\033[0m etc.\n\n\t\t\033[34mExample:\033[0m\n\n\t\tstring message; \033[36m//This creates a variable called message of type string\033[0m\n\n\t\tint age;   \033[36m//This creates a variable called age of type integer\033[0m\n\n",
            "\n\n\t\t\033[34mDECLARATION\033[0m \n\n\t\t-It refers to the process of announcing the existence of a variable to a compiler without assigning a \n\t\tvalue to it\n\n\t\t\033[34mExample:\033[0m\n\n\t\tstring name;\n\t\tint age;\n",
            "\n\n\t\t\033[34mINITIALIZATION\033[0m \n\n\t\t-Is the process of giving an initial value to variable using assignment operator(=)\n\n\t\t\033[34mExample:\n\n\t\t\033[0mstring name=\"JOHN\";\n\t\tint age=9;\n\n\t\t\033[36m--or--\033[0m\n\n\t\tstring surname;\n\t\tsurname=\"Stuoustruop\";\n",
            "\n\n\t\t\033[34mNAMING VARIABLES\033[0m \n\n\t\t-Common Conventions of naming variables are:\n\n\t\t\033[34mCase-Sensitivity:\033[0m\n\n\t\t-This means that lowercase and uppercase are treated as distinct characters\n\n\t\t\033[34mExample:\n\n\t\t\033[0m\"firstname\", \"firstName\" would be considered 2 different identifiers\n"},

            {"\n\n\t\t\033[34mAllowed Characters:\033[0m\n\n\t\t-Identifiers can consist and must begin with (uppercase or lowercase)\n\t\tor camelCase convention, digits, and underscores\n\n\t\t\033[34mExample:\033[0m\n\n\t\tfirstname, FIRSTNAME, Firstname, _firstName\n\t\tname1, name2\n\t\tname_1, name_2, _name3,\n",
            "\n\t\t\033[34mInvalid Variable Names:\033[0m\n\n\t\t-Identifiers \033[31mcannot contain\033[0m with certain characters:\n\n\t\t\033[34mSpecial Symbols:\033[0m\n\n\t\t\033[31m@\033[0m, \033[31m#\033[0m, \033[31m$\033[0m, \033[31m%\033[0m, \033[31m^\033[0m,\033[31m*\033[0m\033[0m etc.\n",
            "\n\t\t\033[34mReserved Key Words:\033[0m\n\n\t\t-Identifiers cannot be the same as C++ keywords:\n\n\t\t\033[34mC++ keywords:\033[0m\n\n\t\t\033[36mint\033[0m, \033[36mfloat\033[0m, \033[36mchar\033[0m, \033[36mreturn\033[0m etc.\n",
            "\n\t\t\033[34mCan you find the error?\033[0m \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout << firstname;\n\t\t}\n",
            "\n\t\t\033[34mCan you find the error?\033[0m \n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout << \033[31mfirstname\033[0m; \033[36m//this line is the error due to wrong case, it should be\033[0m \033[34mfirstName\033[0m\n\t\t}\n"},


            {"\n\n\t\t\033[34mDATA TYPES\033[0m \n\n\t\tC++ Supports many different data types for your variables based on their value.\n\t\tWe will discuss Basic Data Types\n\t\t\033[36mIntegers\033[0m, \033[36mCharacters\033[0m, \033[36mfloats\033[0m, and \033[36mBoolean\033[0m\n",
            "\n\n\t\t\033[34mINTEGERS\033[0m \n\n\t\t-Used to store numbers with out decimal points\n\t\tExamples: \033[36mint\033[0m, \033[36mshort\033[0m, \033[36mlong\033[0m, \033[36mlong long\033[0m\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint myNum = 100;\n\n\t\tcout << myNum; \033[36m//displays 100\033[0m\n",
            "\n\n\t\t\033[34mFLOATING-TYPES\033[0m \n\n\t\t-Used to store numbers with decimal points\n\t\tExamples: \033[36mfloat\033[0m, \033[36mdouble\033[0m\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tfloat myFloat = 2.14f;\n\n\t\tcout << myFloat; \033[36m//dispays 2.14\033[0m\n",
            "\n\n\t\t\033[34mCHARACTERS\033[0m \n\n\t\t-Used to store single characters\n\t\tExample: \033[36mchar\033[0m\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tchar myGrade = 'A';\n\n\t\tcout << myGrade; \033[36m//displays A\033[0m\n",
            "\n\n\t\t\033[34mBOOLEANS\033[0m \n\n\t\t-Used to store true(1)or false(0) values\n\t\tExample: \033[36mbool\033[0m\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tbool am_I_handsome = true;\n\n\t\tcout<<am_I_handsome; \033[36m//displays 1 which is true\033[0m\n"},


            {"\n\n\n\t\t\033[34mARITHMETIC OPERATORS\033[0m \n\n\t\t-Used to perform arithmetic operations on numerical values(\033[36mAddition\033[0m, \033[36mSubtraction\033[0m, \n\t\t\033[36mMultiplication\033[0m, \033[36mDivision\033[0m or \033[36mModulus\033[0m)\n",
            "\n\n\t\t\033[34mAddition(+)\033[0m \n\n\t\t-Adds two values together can be applied in integral, floats, and chars\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num1 = 23;\n\t\tint num2 = 10;\n\n\t\tcout << num1 + num2; \033[36m//displays 33\033[0m\n",
            "\n\n\t\t\033[34mSubtraction(-)\033[0m \n\n\t\t-Subtracts the second value from the first\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num1 = 23;\n\t\tint num2 = 10;\n\n\t\tcout << num1 - num2; \033[36m//displays 13\033[0m\n",
            "\n\n\t\t\033[34mMultiplication(*)\033[0m\033[0m \n\n\t\t-Multiplies two values together\n\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num1 = 10;\n\t\tint num2 = 6;\n\n\t\tcout << num1*num2; \033[36m//displays 60\n",
            "\n\n\t\t\033[34mDivision(/)\033[0m \n\n\t\t-Divides the first value by the second\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num1 = 50;\n\t\tint num2 = 5;\n\n\t\tcout << num1/num2; \033[36m//displays 10\033[0m\n\n\n\n\t\t\033[34mModulus(%)\033[0m\n\n\t\t-Returns the remainder of the division of the first value by the second\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num1 = 53;\n\t\tint num2 = 5;\n\n\t\tcout << num1%num2; \033[36m//displays 3\033[0m\n"},

            {"\n\n\n\t\t\033[34mOPERATOR PRECEDENCE\033[0m \n\n\t\t-Determines the order in which arithmetic operators are evaluated within an arithmetic expression\n\n\t\t-The precedence of C++ follows PEMDAS Rule, which stands for (\033[36mParenthesis\033[0m, \033[36mExponent\033[0m, \n\t\t\033[36mMultiplication and Division\033[0m,  and \033[36mAddition and Subtraction\033[0m)\n",
            "\n\n\t\t\033[34mMultiplication and Division\033[0m \n\n\t\t-They have the same precedence from left to right\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint result = 10+5*2;\n\n\t\tcout << result; \033[36m//displays 20\033[0m, (5 and 2 are evaluated first(5*2=10), then is added to 10,(10+10=(\033[36m20\033[0m))\n\n\n\t\tint result = 10+8/2\n\n\t\tcout << result; \033[36m//displays 14\033[0m, (8 and 2 are evaluated first(8/2=4), then added to 10, (10+4=(\033[36m14\033[0m))\n",
            "\n\n\t\t\033[34mModulus\033[0m\n\n\t\t-This operator is also evaluated after multiplication and division\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint result = 10+5%3;\n\n\t\tcout << result; \033[36m//displays 12\033[0m, (5 and 3 are evaluated first(5%3=2) then added to 10,(10+2=(\033[36m12\033[0m))\n",
            "\n\n\t\t\033[34mAddition and Subtraction\033[0m \n\n\t\t-These Operators have the same precedence and are evaluated left to right\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint result = 10+5-3;\n\n\t\tcout << result; \033[36m//displays 12\033[0m, (10+5=15, 15-3=(\033[36m12\033[0m))",
            "\n\n\t\t\033[34mParenthesis\033[0m \n\n\t\t-Used to control the order of the operation.\n\t\tThey override the operator precedence rule.\n\t\tAllowing you to specify which parts should be evaluated together\n\n\t\tint result = (10+5)*2;\n\n\t\tcout << result; \033[36m//displays 30\033[0m, (10+5=15) (15*2=(\033[36m30\033[0m))\n\n\n\t\tint result=(10-5)*3;\n\n\t\tcout << result; \033[36m//displays 15\033[0m, (10-5=5), (5*3=(\033[36m15\033[0m))\n"
            }

        };

        string questionAns[][2]= {
            {"\033[36mWhich statements are true about C++?\033[0m:\n\n\t\tI.C++ is not a programming language\n\t\tII. C++ can be used to build games.\n\t\tIII.C++ is good for operating systems or browsers development\n\n\t\ta. I only\n\t\tb. II and III\n\t\tc. all of the statements: \n\t\t", "b"},
            {"\033[36mFind the missing structure\033[0m\n\n\t\t#include <_____>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout << \"Hello World\";\n\n\t\t  return 0;\n\n\t\t}\n\n\t\ta.stdio.h\n\t\tb.iostrim\n\t\tc.iostream\n\t\t", "c"},
            {"\033[36mThis Program returns an error why?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t  string programmingLanguage = \"C++\";\n\n\t\t  cout << programminglanguage;\n\n\t\t  return 0;\n\n\t\t}:\n\n\t\ta.Calling an incorrect Case of Identifier\n\t\tb.data type should be int\n\t\tc.No semicolon\n\t\t", "a"},
            {"\033[36mDetermine if its a valid or invalid identifier\033[0m\n\n\t\tfirst name\n\n\t\ta.valid\n\t\tb.invalid\n\t\tc.hard to tell\n\t\t", "b"},
            {"\033[36mGuess the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int myGrade = 99;\n\n\t\t cout << \"myGrade\";\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta.99\n\t\tb.error\n\t\tc.myGrade\n\t\t", "c"},
            {"\033[36mDetermine data type suitable for this data.\033[0m\n\n\t\tThe number of days in a year:\n\n\t\ta.int\n\t\tb.float\n\t\tc.string\n\t\t", "a"},
            {"\033[36m(7-10)Determine the value of the following expression\033[0m\n\n\t\t3+6*7\n\n\t\ta.46\n\t\tb.56\n\t\tc.45\n\t\t", "c"},
            {"\033[36m50%30\033[0m\n\n\t\ta.20\n\t\tb.1\n\t\tc.50/30\n\t\t", "a"},
            {"\033[36m10*(2+3)\033[0m\n\n\t\ta.23\n\t\tb.50\n\t\tc.15\n\t\t", "b"},
            {"\033[36m3*4/6+6\033[0m\n\n\t\ta.1\n\t\tb.8\n\t\tc.6\n\t\t", "b"}
                };


        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER

        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength, currentPlayer, LessonName);


    }


    void conditionals(Player* currentPlayer ){

        string LessonName="\n\n\n\n\t\t\033[36mLESSON 2:\033[0m\n\n\t\t\033[31mCONDITIONALS\033[0m\n";
        string lectures[][5]= {
            {"\n\n\n\t\t\033[34mTAKING INPUTS\033[0m\n\n\t\t-Your program may take user input for an application to process and generate output\n\n\t\t-To take input, use \033[36mcin>>\033[0m command\n\n\t\t-We first declare the variable that will hold our input value, then we use cin>> command\n\n\t\tint age;\n\t\tcin >> age;\033[36m //for example you type 23\033[0m\n\t\tcout << age; \033[36m//displays 23\033[0m\n",
            "\n\n\t\t\033[34mAnother Example:\033[0m\n\n\t\tstring name;\n\t\tcout << \"Enter name \";\n\t\tcin >> name; \033[36m//lets assume you type Lemuel\033[0m\n\t\tcout << \"You entered: \"<<name; \033[36m//displays You entered Lemuel\033[0m\n",
            "\n\n\t\t\033[34mMultiple Inputs\033[0m\n\n\t\tYou can take multiple inputs throughout your program\n\n\t\tint a, b;\n\t\tcin >> a; \033[36m//assume you type 3\033[0m\n\t\tcin >> b; \033[36m//assume you type 10\033[0m\n\n\t\tcout << a+b; \033[36m//displays 13\033[0m\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t  string name;\n\t\t  int age;\n\n\t\t  cout <<\"Enter name: \";\n\t\t  cin >> name; \033[36m//assume you type Guko\033[0m\n\n\t\t  cout <<\"Enter age: \";\n\t\t  cin >> age; \033[36m//assume you type 34\033[0m\n\n\t\t  cout << \"You are \"<<name<<\" \"<< age <<\" years old\";\n\n\t\t  return 0;\n\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t  string name;\n\t\t  int age;\n\n\t\t  cout <<\"Enter name: \";\n\t\t  cin >> name; \033[36m//assume you type Guko\033[0m\n\n\t\t  cout <<\"Enter age: \";\n\t\t  cin >> age; \033[36m//assume you type 34\033[0m\n\n\t\t  cout << \"You are \"<<name<<\" \"<< age <<\" years old\";\033[36m //displays \"You are Guko 34 years old\"\033[0m\n\n\t\t  return 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\t\033[34mCONDITIONAL STATEMENTS\033[0m\n\n\t\t-Are used to perform different actions based on different conditions\n\n\t\t",
            "\n\n\t\t\033[34mIF STATEMENT\033[0m\n\n\t\t-The if statements allows you to run a specified code if a given condition is true\n\n\t\tHere is the syntax\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}",
            "\n\n\t\t\033[34mCOMPARISON OPERATORS\033[0m\n\n\t\t-The following are comparison operators may be used to form the conditions\n\n\t\t\033[36m<\033[0m -less than\n\n\t\t\033[36m>\033[0m -greater than\n\n\t\t\033[36m!=\033[0m -not equal to\n\n\t\t\033[36m==\033[0m -equal to\n\n\t\t\033[36m<=\033[0m -less than or equal to\n\n\t\t\033[36m>=\033[0m -greater than or equal to\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint grade=80;\n\t\tif(grade > 75){\n\n\t\t  cout<<\"You pass\"; \033[36m//displays \"You pass\", since the condition is true, 80 is greater than 75\033[0m\n\n\t\t}",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t   cout<<\"Sunday\";\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t   cout<<\"Sunday\"; \033[36m//displays \"Sunday\" since day is equals to 7\033[0m\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\t\033[34mELSE STATEMENT\033[0m\n\n\t\t-You can use the else statement after an if statement\n\t\tIf you want to run a code in case the condition is false\n\n\t\tSyntax:\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}\n\n\t\telse{\n\t\t//code to run\n\t\t}\n",
            "\n\n\t\t\033[34mExample:\033[0m\n\n\t\tstring gender = \"male\";\n\n\t\tif(gender==\"male\"){\n\t\t  cout<<\"You are a male\";\n\n\t\t}\n\n\t\telse{\n\t\t  cout<<\"You are a female\"; \033[36m//displays \"You are a female\" since if statement returns false\033[0m\n\t\t}\n\t\t",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\tint grade = 60;\n\t\tif(grade >= 75){\n\t\t cout<<\"You passed\";\n\t\t}\n\n\t\telse{\n\t\t  cout<<\"You failed \";\n\t\t}",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\tint grade = 60;\n\t\tif(grade >= 75){\n\t\t cout<<\"You passed\";\n\t\t}\n\n\t\telse{\n\t\t  cout<<\"You failed \"; \033[36m//displays \"You failed\" since grade(52) is not greater than or equal to 75\033[0m\n\t\t}",
            "\n\n\t\t\033[34mNESTED IF STATEMENTS\033[0m\n\n\t\t-You can use one if-else statements inside another if or else statement.\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint age = 24;\n\n\t\tif(age>=65){\n\t\t  cout<<\"SENIOR\";\n\t\t}\n\n\t\telse{\n\t\t  if(age>=18){\n\t\t    cout<<\"ADULT\"; \033[36m//displays \"ADULT\" since age (24) is greater than or equal to 18\033[0m\n\t\t  }\n\t\t  else{\n\t\t    cout<<\"CHILD\";\n\t\t  }\n\t\t}"
            },

            {"\n\n\n\t\t\033[34mELSE IF STATEMENT\033[0m\n\n\t\t-Nested if-else statements become hard to read and maintain. \n\t\tThis is why C++ provides the else if statement.\n\n\t\tSyntax:\n\n\t\tif (condition) {\n\t\t  //some code\n\t\t}\n\t\telse if (condition){\n\t\t  //some code\n\t\t}\n\t\telse {\n\t\t  //some other code\n\t\t}\n",
            "\n\n\t\t\033[34mHere's our previous example, written using else if:\033[0m\n\n\t\tint age=24;\n\n\t\tif(age >= 65) {\n\t\t  cout<<\"SENIOR\";\n\t\t}\n\t\telse if (age >= 18){\n\t\t  cout<<\"ADULT\";\n\t\t}\n\t\telse{\n\t\t  cout<<\"CHILD\";\n\t\t}\n\t\t",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\t\t\033[36mAssume user enters 'B'\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int points;\n\t\t  char category;\n\n\t\t  cout<<\"Enter Category(A, B, C)\";\n\t\t  cin>>category;\n\n\t\t  if (category == 'A'){\n\t\t    points=100;\n\t\t  }\n\n\t\t  else if(category =='B'){\n\t\t    points=70;\n\n\t\t  }\n\n\t\t  else {\n\t\t    points=50;\n\t\t  }\n\n\t\t  cout<<points;\n\n\t\t  return 0;\n\n\t\t}\n\t\t",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\t\t\033[36mAssume user enters 'B'\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int points;\n\t\t  char category;\n\n\t\t  cout<<\"Enter Category(A, B, C)\";\n\t\t  cin>>category;\n\n\t\t  if (category == 'A'){\n\t\t    points=100;\n\t\t  }\n\n\t\t  else if(category =='B'){\n\t\t    points=70;\n\n\t\t  }\n\n\t\t  else {\n\t\t    points=50;\n\t\t  }\n\n\t\t  cout<<points; \033[36m//Displays 70\033[0m\n\n\t\t  return 0;\n\n\t\t}\n\t\t",
            "\n\n\t\t\033[34mLESSON TAKEAWAYS\033[0m\n\n\t\t-Decision making is easy right?\n\t\tYou can check for a condition using the if statement.\n\t\tIn case the condition of if statement is false, the code in an else if statement can be executed to test \n\t\tfor another condition.\n\n\t\tAnd if the all the conditions are false, else statement is executed\n\n\t\t"
            },

             {"\n\n\n\t\t\033[34mSWITCH STATEMENT\033[0m\n\n\t\t-The switch statement can be used to check for equality against a list of (int and char) values, \n\t\tinstead of multiple else if statements.\n\n\t\tSyntax:\n\n\t\tswitch (expression or variable) {\n\n\t\t  case constant1:\n\t\t    //some code\n\t\t    break;\n\t\t  case constant2:\n\t\t    //some code\n\t\t    break;\n\t\t  //more cases as needed\n\t\t  default:\n\t\t    //some code\n\t\t    break;\n\t\t}\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint choice=2;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\"; \033[36m//displays \"Tea\" since choice matches with this case(2)\033[0m\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t    default:\n\t\t      cout << \"Empty\";\n\t\t  }\n\t\t",
            "\n\n\t\t\033[34mBREAK\033[0m\n\n\t\t-The break statement is used to terminate the switch, when the case is matched.\n\t\t-If you forget to to add a break statement after each case,\n\t\tthe program will execute the code in the next case statement even if the value does not match\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint choice=2;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\";\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t}\n\n\t\t\033[36m//Displays \"TeaWater\"\033[0m\n\t\t",
            "\n\n\t\t\033[34mDEFAULT\033[0m\n\n\t\t-You might notice that there is a default case at the end of the switch statement.\n\t\tIt is used to run code, when none of the cases match, just like how else statement does\n\n\t\t\033[34mExample:\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  int choice=4;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Coffee\";\n\t\t    case 2:\n\t\t      cout << \"Tea\";\n\t\t    case 3:\n\t\t      cout <<\"Water\";\n\t\t    default:\n\t\t      cout << \"Empty\"; \033[36m//displays \"Empty\" since choice(4) have no matching cases\033[0m\n\t\t  }\n\t\t}\n",
            "\n\n\t\t\033[34mCan You guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  char grade = 'C';\n\n\t\t  switch(choice) {\n\t\t    case 'A':\n\t\t      cout << \"Excelent\";\n\t\t    case 'B':\n\t\t      cout << \"Good Job\";\n\t\t    case 'C':\n\t\t      cout << \"Not Bad\";\n\t\t    default:\n\t\t      cout << \"Invalid\";\n\t\t  }\n\t\t}\n",
            "\n\n\t\t\033[34mCan You guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  char grade = 'C';\n\n\t\t  switch(choice) {\n\t\t    case 'A':\n\t\t      cout << \"Excelent\";\n\t\t    case 'B':\n\t\t      cout << \"Good Job\";\n\t\t    case 'C':\n\t\t      cout << \"Not Bad\"; \033[36m//displays \"Not Bad\" since grade matches this case ('C')\033[0m\n\t\t    default:\n\t\t      cout << \"Invalid\";\n\t\t  }\n\t\t}\n",
            },

             {"\n\n\n\t\t\033[34mMULTIPLE CONDITIONS\033[0m\n\n\t\t-In some scenarios we need to combine multiple conditions.\n\t\t-In C++, you can use logical operators such as '&&' (logical AND), '||' (logical OR), \n\t\tand '!' (logical NOT)to create multiple conditions in if statements, loops, and other structures\n\n\t\tAND OPERATOR (&&)\n\n\t\t-Used to combine Multiple conditions in such a way that all conditions must be true\n\t\tfor overall expression to be true\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint age=19;\n\n\t\tif (age>=18 && age <=50){\n\t\tcout <<\"Eligible to Work; \033[36m//displays \"Eligible to Work\" since 19 is within the range of 18 and 50\033[0m\n\t\t}",
            "\n\n\t\t\033[34mOR OPERATOR(||)\033[0m\n\n\t\t-The logical OR operator combines conditions and check if any one of them is true\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint level = 5;\n\t\tint points = 300;\n\n\t\tif (level >=5 || points>=400){\n\t\t  cout << \"You are Allowed to enter this Area\"; \033[36m//displays this line since one of the condition is true level(5) is >= 5\033[0m\n\t\t}",
            "\n\n\t\t\033[34mNOT OPERATOR (!)\033[0m\n\n\t\t-The logical NOT operator reverse the condition: in case the condition is true,\n\t\tthen not operator will make it false, and vice-e-versa\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint height = 200;\n\n\t\tif(!(height <150)){\n\t\t  cout << \"Welcome\"; \033[36m//displays \"Welcome\" since the condition is inversed from false to true\033[0m\n\t\t}\n\n\t\t",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; \033[36m//assume user enters 4\033[0m\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted\";\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; \033[36m//assume user enters 4\033[0m\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted\"; \033[36m//displays \"Discounted\" since 4 is within the range of this condition\033[0m\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n"

            }
        };

        string questionAns[][2]= {
            {"\033[36mIn C++ what command use to take input from the user?\033[0m\n\n\t\ta. cout\n\t\tb. scanf \n\t\tc. cin\n\t\t", "c"},
            {"\033[36mDetermine the output\033[0m\n\n\t\tstring name;\n\n\t\tcout<<\"Enter name \";\n\t\tcin>>name; //lets assume you type BJARNE\n\n\t\tcout<<\"Your name is: \"<<name;\n\n\t\ta. You entered: BJARNE\n\t\tb. Your name is: BJARNE\n\t\tc. You are BJARNE", "b"},
            {"\033[36mSupply the missing code\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t __(day==7){\n\t\t cout<<\"Sunday\"; //displays \"Sunday\"\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta. if\n\t\tb. else\n\t\tc. else if", "a"},
            {"\033[36mDetermine the Output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int num=8;\n\n\t\t  if(num%2==0){\n\t\t   cout << \"EVEN\";\n\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"ODD\";\n\n\t\t  }\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta. EVEN\n\t\tb. ODD\n\t\tc. 0", "a"},
            {"\033[36mWhich of the following statements is true about nested if-else statements\033[0m\n\n\t\ta. They cannot be used in c++\n\t\tb. They can have one if statement and multiple else statement\n\t\tc. They can have multiple if and else statement with each other", "c"},
            {"\033[36mWhat data type is commonly used in switch cases?\033[0m\n\n\t\ta. int\n\t\tb. floats\n\t\tc. string\n\t\t", "a"},
            {"\033[36mDetermine the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\t\t  int order = 4;\n\n\t\t  switch(choice) {\n\t\t    case 1:\n\t\t      cout << \"Rice with egg\";\n\t\t    case 2:\n\t\t      cout << \"Rice with ham\";\n\t\t    case 3:\n\t\t      cout << \"Rice with pork\";\n\t\t    default:\n\t\t      cout << \"Water\"\n\t\t  }\n\t\t}\n\n\t\ta. Rice with egg\n\t\tb. Water\n\t\tc. Rice with ham", "b"},
            {"\033[36mIn C++ what symbol is used for logical OR operator?\033[0m\n\n\t\ta. &&\n\t\tb. or\n\t\tc. ||", "c"},
            {"\033[36mComplete the missing code to run the program\033[0m\n\n\t\tint day=13;\n\n\t\tif (day>=1 __ day<=12){\n\t\t  cout <<\"Valid Month;\n\n\t\telse{\n\t\t  cout << \"Invalid month\"; //displays \"Invalid month\";\n\t\t}\n\n\t\ta. ||\n\t\tb. !\n\t\tc. &&\n", "c"},
            {"\033[36mguess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int age;\n\t\t  cin >> age; //assume user enters 5\n\n\t\t  if(age >0 && age <=3){ \n\t\t    cout << \"Free Meal\";\n\t\t  }\n\n\t\t  else if (age >= 4 && age <=6) {\n\t\t    cout << \"Discounted Meal\";\n\t\t  }\n\n\t\t  else{\n\t\t    cout << \"Normal\";\n\t\t  }\n\t\t}\n\n\t\ta. Free Meal\n\t\tb. Discounted Meal\n\t\tc. Normal\n", "b"}
            };

        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);


        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength,currentPlayer , LessonName);

}


void loopings(Player* currentPlayer){

        string LessonName="\n\n\n\n\t\t\033[36mLESSON 3:\033[0m\n\n\t\t\033[35mLOOPINGS\033[0m\n";
        string lectures[][5]={
            {"\n\n\n\t\t\033[34mLOOPS\033[0m\n\n\t\t-A loop allows you to repeat a block of code multiple times.\n\t\tFor example, a game can use a loop through all items in the warehouse and perform calculations\n\n\t\t",
            "\n\n\t\t\033[34mWHLE LOOPS\033[0m\n\n\t\t-The while loop takes a condition and repeats its statements\n\t\twhile the condition is true.\n\n\t\tSyntax:\n\n\t\twhile(condition) {\n\t\t  //code to be executed repeatedly\n\t\t  //as long as the condition is true\n\t\t}\n",
            "\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num=1;\n\n\t\twhile(num<5) {\n\t\t cout << num; \033[36m//displays 1234\033[0m\n\t\t num=num+1;\n\t\t}\n\n\t\tThe statement \033[36mnum=num+1\033[0m increases the value of num by 1\n\t\teach time the loop runs.\n\n\t\tThis is important as without it the loop would run forever\n\n\t\t",
            "\n\n\t\t\033[34mINCREMENT AND DECREMENT\033[0m\n\n\t\t-As it's common to increment and decrement a value by 1 in loops.\n\t\tC++ provides a special increment and decrement operators.\n\n\t\t\033[36mvar--\033[0m :decreases value of num by 1\n\t\t\033[36mvar++\033[0m :increases value of num by 1\n\n\t\tExample: (num = num+1 can \033[36mbe num++\033[0m) or (num = num-1 can be \033[36mnum--\033[0m)\n\t\t",
            "\n\n\t\t\033[34mSHORTHAND OPERATORS\033[0m\n\n\t\t-Sometimes you might need to increase or decrease the value of a variable\n\t\tby a different value than 1.\n\t\tFor these cases C++ provides shorthand operators too!\n\n\t\t\033[34mExample:\033[0m\n\n\t\tint num = 0;\n\n\t\twhile(num <= 10) {\n\t\t  cout << num << endl;\n\t\t  num+=2;    \033[36m//shorthand of num = num+2\033[0m\n\t\t}\n\n\t\t\033[36m//displays\n\t\t0\n\t\t2\n\t\t4\n\t\t6\n\t\t8\n\t\t10\033[0m\n\n\t\tSimilarly you can use shorthand for other math operators (\033[36m*=\033[0m, \033[36m/=\033[0m, \033[36m%=\033[0m )\n"
            },


            {"\n\n\t\t\033[34mCan You guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  while(number >= 0) {\n\n\t\t    cout << number << endl;\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n",
            "\n\n\t\t\033[34mCan You guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  while(number >= 0) {\n\n\t\t    cout << number << endl;\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n\n\t\t\033[36m//displays\n\t\t5\n\t\t4\n\t\t3\n\t\t2\n\t\t1\n\t\t0\033[0m\n",
            "\n\n\t\t\033[34mDO WHILE\033[0m\033[0m\n\n\t\t-Another variation of the while loop is do-while.\n\t\tThe difference with a while loop is that the condition is checked after the code,\n\t\tmeaning the code in the do is executed at least once even if the condition\n\t\tis false\n\n\t\tSyntax:\n\n\t\tdo {\n\n\t\t  //code to be executed\n\t\t  //this code block will execute at least once\n\n\t\t} while (condition);\n\n\t\t\033[36mExample:\033[0m\n\n\t\tint  num = 0;\n\n\t\tdo{\n\n\t\t  cout << \"Hello \"; \033[36m//displays Hello Hello Hello\033[0m\n\t\t  num++;\n\n\t\t} while(num<3);",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \";\n\t\t    num += 2;\n\t\t  }while(num <=5);\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \"; \033[36m//dipslays 0 2 4\033[0m\n\t\t    num += 2;\n\t\t  }while(num <=5);\n\t\t}\n"
            },


            {"\n\n\t\t\033[34mFOR LOOPS\033[0m\n\n\t\t-A for loop is a control flow statement used to execute a block of code repeatedly\n\t\tbased on a specific condition.\n\n\t\tSyntax:\n\n\t\tfor (initialization; condition; increment/decrement) {\n\t\t  //code to be executed\n\t\t}\n",
            "\n\n\t\t\033[34mFOR LOOP HEADER\033[0m\n\n\t\t-The loop header contains 3 components,\n\t\teach serves a specific purpose in controlling the behavior of the loop\n\n\t\t\033[36mInitialization\033[0m-Used to initialize a loop control variable, executed only once the loop starts ex. (int i = 0;)\n\n\t\t\033[36mCondition\033[0m - A boolean expression that's evaluated before each iteration, if condition is true,\n\t\tloop keeps executing, otherwise, the loop terminates (ex. i < 5;)\n\n\t\t\033[36mIncrement/Decrement\033[0m - Used to modify the loop control variable after each iteration. \n\t\tIt's optional and used to update loop control variable ex. (i++, i--, etc)",
            "\n\n\t\t\033[34mExample:\033[0m\n\n\t\tfor (int i = 1; i<= 5; i++){\n\t\t  cout << i << \" \"; \033[36m//displays 1 2 3 4 5\033[0m\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; x--){\n\n\t\t    cout << x <<\" \";\n\n\t\t  }\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; x--){\n\n\t\t    cout << x <<\" \"; \033[36m//displays 10 9 8 7 6 5 4 3 2 1\033[0m\n\n\t\t  }\n\t\t}\n"
            },

            {"\n\n\t\t\033[34mBREAK\033[0m\n\n\t\t-Remember break; statement that was used in switch to stop when a case\n\t\twas matched? It can also be used to stop a loop\n\n\t\t\033[34mExample:\033[0m\n\n\t\tfor(int i=0; i<10; i++){\n\t\t  if(i==5) {\n\t\t    break;\n\t\t  }\n\t\t  cout << i <<\" \"; \033[36m//displays 0 1 2 3 4 5 since break executed when i equals to 5, then the loop terminates\033[0m\n\t\t}\n",
            "\n\n\t\t\033[34mCONTINUE\033[0m\n\n\t\t-The continue statement skips the current loop iteration\n\t\tand continues with the next one\n\n\t\t\033[34mExample:\033[0m\n\n\t\tfor(int i=0; i<5; i++){\n\t\t  if(i==3) {\n\t\t  cout <<\"Skipping \"<<i<<endl;\n\t\t    continue;\n\t\t  }\n\t\t  cout << i <<endl;\n\n\t\t}\n\n\t\t\033[36m//displays\n\t\t0\n\t\t1\n\t\t2\n\t\tSkipping 3\n\t\t4\033[0m\n",
            "\n\n\t\t\033[34mBREAK AND CONTINUE IN ACTION\033[0m\n\n\t\tfor(int i=10; i>=0; i--){\n\n\t\t  if(i==7) {\n\t\t    cout <<\"Skipping \"<<i<<endl;\n\t\t    continue;\n\t\t  }\n\n\t\t  if(i==6) {\n\t\t    break;\n\t\t  }\n\n\t\t cout << i <<endl;\n\n\t\t}\n\n\t\t\033[36m//displays\n\t\t10\n\t\t9\n\t\t8\n\t\tSkipping 7\033[0m\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=12; x+=2){\n\n\t\t    if(x == 4) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==10) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<endl;\n\n\t\t  }\n\t\t}\n",
            "\n\n\t\t\033[34mCan you guess the output?\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=12; x+=2){\n\n\t\t    if(x == 4) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==10) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<endl;\n\n\t\t  }\n\t\t}\n\n\t\t\033[36m//displays\n\t\t0\n\t\t2\n\t\tskip\n\t\t6\n\t\t8\033[0m\n"
            }
        };
        string questionAns[][2]= {
                            {"\033[36mIt is a C++ construct that allows you to repeat a block of code multiple times?\033[0m\n\n\t\ta. loop\n\t\tb. conditionals\n\t\tc. variable\n", "a"},
                            {"\033[36mSupply the missing code\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int number;\n\t\t  cin >> number; //assume you input 5\n\n\t\t  ____(number >= 0) {\n\n\t\t    cout << number <<\" \"; //displays 5 4 3 2 1 0\n\t\t    number--;\n\n\t\t  }\n\n\t\t}\n\n\t\ta. for\n\t\tb. while\n\t\tc. do\n", "b"},
                            {"\033[36mWhat loop construct in C++ guarantees that the loop body is executed at least once,\n\t\teven if the condition is false initially?\033[0m\n\n\t\ta. while loop\n\t\tb. for loop\n\t\tc. do while\n", "c"},
                            {"\033[36mDetermine the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  int num = 0;\n\n\t\t  do{\n\t\t    cout << num <<\" \";\n\t\t    num += 3;\n\t\t  }while(num <=12);\n\t\t}\n\n\t\ta. 0,3,6,9,12\n\t\tb. 0 3 6 9 12\n\t\tc. 036912\n", "b"},
                            {"\033[36mWhat loop that contains header loop component (initialization; condition; update)?\033[0m\n\n\t\ta. for loop\n\t\tb. do while\n\t\tc. while\n", "a"},
                            {"\033[36mDetermine the output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=12; x>0; x-=4){\n\n\t\t    cout << x <<\" \";\n\n\t\t  }\n\t\t}\n\n\t\ta. 4 8 12\n\t\tb. 8 4\n\t\tc. 12 8 4\n", "c"},
                            {"\033[36mWhat statement that can be used to stop a loop\033[0m\n\n\t\ta. break;\n\t\tb. stop;\n\t\tc. endl;\n", "a"},
                            {"\033[36mWhat statement that skips the current loop iteration and continues with the next one\033[0m\n\n\t\ta. skip;\n\t\tb. continue;\n\t\tc. next;\n", "b"},
                            {"\033[36mSupply the missing code\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=10; x>0; ___){\n\n\t\t    cout << x <<\" \"; //displays 10 9 8 7 6 5 4 3 2 1\n\n\t\t  }\n\t\t}\n\t\ta. x+=2\n\t\tb. x++\n\t\tc. x--\n", "c"},
                            {"\033[36mDetermine the Output\033[0m\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main() {\n\n\t\t  for(int x=0; x<=20; x+=4){\n\n\t\t    if(x == 12) {\n\t\t      cout << \"skip\"<<endl;\n\t\t      continue;\n\t\t    }\n\n\t\t    if(x ==16) {\n\t\t    break;\n\t\t    }\n\n\t\t  cout << x <<\" \";\n\n\t\t  }\n\t\t}\n\n\t\ta. 0 4 8 skip\n\t\tb. 0 4 8 12 skip\n\t\tc. 0 4 8 12 16 20\n", "a"}

            };


        //QA ROW LENGTH AND COLUMN LENGTH
        int qa_Row_Len = sizeof(questionAns)/sizeof(questionAns[0]);
        int qa_Col_Len=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        int lectureRowLen = sizeof(lectures)/sizeof(lectures[0]);
        int lectureColLen=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        int anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        //INVOKE LECTURE OR QUIZ FUNCTION
        lecture_or_quiz(lectures,  lectureRowLen,  lectureColLen, questionAns, your_answers, qa_Row_Len, anslength, currentPlayer , LessonName);

}


void lecture_or_quiz(string lectures[][5], int lectureRowLen, int lectureColLen, string questionAns[0][2], string your_answers[], int qa_Row_Len, int anslength, Player* currentPlayer , string lessonName){

string yes_no;

 do{
            cout<<"\n\n\t\t\033[32mLecture(1) or Quiz(2)?:\033[0m ";
            getline(cin, yes_no);
            yes_no.erase(remove(yes_no.begin(), yes_no.end(), ' '), yes_no.end());

            if(yes_no=="1"){
                system("cls");
                show_lectures(lectures, lectureRowLen, lectureColLen, lessonName);

            }

            else if(yes_no=="2"){
                system("cls");
                question_And_Answer(questionAns, your_answers, qa_Row_Len, anslength, currentPlayer );
            }

            else{
                cout<<"\n\n\t\t\033[31mTry again\033[0m\n\n";
            }
        }while(yes_no.length()!=1||(yes_no!="1"&&yes_no!="2"));

}

void question_And_Answer(string questionAns[][2], string your_answers[], int qa_Row_Len, int anslength, Player* currentPlayer) {
    string res;
    int functionScore=0;
    string reset;
    string next;

    shuffle_array(questionAns, qa_Row_Len);

    for (int i = 0; i < qa_Row_Len; i++) {
        system("cls");
        if(i==0){
            cout<<"\n\n\t\t\033[36mMULTIPLE CHOICE\033[0m: \033[33mAttain a perfect score to unlock next lessons\033[0m \n";
        }
        cout <<"\n\n\t\t"<< i+1 <<". "<<questionAns[i][0];
        string ans;
        do {
            cout<<"\n\n\t\t\033[36mEnter Answer (a, b, or c):\033[0m ";
            getline(cin, ans);
            ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());
            ans[0]=tolower(ans[0]);
            if (ans==""|| (ans != "a" && ans != "b" && ans != "c" )) {
                cout << "\n\t\t\033[31mINVALID\033[0m\t\t";
            }
        } while (ans==""|| (ans != "a" && ans != "b" && ans != "c" ));


        your_answers[i] = ans;


        if (your_answers[i]==questionAns[i][1]){
            functionScore++;
            }

        do{
            cout<<"\n\n\n\n\t\t\033[32mPress 1 to proceed\033[0m\n\t\t";
            getline(cin, next);
            next.erase(remove(next.begin(), next.end(), ' '), next.end());
            if(next!="1"){
                cout<<"\n\t\t\033[31mTry Again\033[0m\t\t";
            }
        }while(next!="1");
    }

    system("cls");

    cout<<"\n\t\t\033[36mRESULTS: \033[0m\n";
    for(int i = 0; i<10; i++){
        if (your_answers[i]==questionAns[i][1]){
        cout<<"\n\t\t" << i+1 << ". \033[32mCORRECT\033[0m\n";

        }

        else{
            cout<<"\n\t\t" << i+1 << ". \033[31mWRONG\033[0m\n";
        }

    }


    cout<<"\n\n\n\n\t\t\033[36mYour Score is: \033[0m"<<"\033[36m"<<functionScore<<"\033[0m"<<"\033[36m/10\033[0m\n\n";
    if(functionScore==10 || currentPlayer->l1_finished == 0){



        if(currentPlayer->score==10 && currentPlayer->l1_finished == 0){
            cout << "\n\t\t\033[33mYou Unlock Lesson 2\033[0m\n";
            currentPlayer->l1_finished=true;
            currentPlayer->score+=functionScore;
        }


        savePlayersToFile();
    }


    else if(functionScore==10 && currentPlayer->l2_finished == 0){


        if(currentPlayer->score==20 && currentPlayer->l2_finished == 0){
            cout << "\n\t\t\033[33mYou Unlock Lesson 3\033[0m\n";
            currentPlayer->l2_finished=true;
            currentPlayer->score+=functionScore;

        }

        savePlayersToFile();
    }

    else if(functionScore==10 && currentPlayer->l3_finished == 0){


        if(currentPlayer->score==30 && currentPlayer->l3_finished == 1){
            currentPlayer->l3_finished=true;
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\033[33mYOU HAVE COMPLETED THIS COURSE\033[0m\n\n\t\t      \033[36mCONGRATS!!!!\033[0m\n";

            savePlayersToFile();
        }
    }

    do{
        cout<<"\n\n\t\t\033[32mPress 1 to exit\033[0m\n\n\t\t";
        getline(cin, reset);
        reset.erase(remove(reset.begin(), reset.end(), ' '), reset.end());

        if(reset!="1"){
            cout<<"\n\n\t\t\033[31mTry again\033[0m\n\n\t\t";
        }

        else{
            system("cls");
        }

    }while(reset!="1");

}



void show_lectures(string lectures[][5], int lectureRowLen, int lectureColLen, string lessonName){
    string ans, begins, exits;

    do{cout<<lessonName;
    cout <<"\n\n\n\n\t\t\033[32mPress any key to begin lesson:\033[0m ";
    getline(cin, begins);
    begins.erase(remove(begins.begin(), begins.end(), ' '), begins.end());

    break;
    }while(1);

    for(int i=0; i<lectureRowLen; i++){
        for(int j=0; j<lectureColLen; j++){
            system("cls");
            cout<<lectures[i][j]<<endl;

            do{
                cout<<"\n\n\t\t\033[32mPress (1)Proceed or (2)Exit\n\t\t>\033[0m ";
                getline(cin, ans);
                ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());

                if(ans!="1" && ans!="2"){
                    cout<<"\n\t\t\033[31mtry again\033[0m\n";
                }

            }while(ans!="1" && ans!="2");

            if(ans=="2"){
                break;
            }
        }
        if (ans=="2"){
            break;
        }
    }


      do{
        system("cls");
        if (ans=="2"){
            break;
        }
        cout<<"\n\n\t\t\033[34mEND OF THE LESSON\033[0m\n\n";
        cout <<"\n\n\n\n\t\t\033[32mPress any key to exit:\033[0m ";
        cin>>exits;
        break;
    }while(1);

}




void gameName(){
    system("cls");
    cout<<"\n\n\t\t\033[36m_____________________________________________________________________\033[0m\n\n"<<endl;
    cout <<"\n\n\t\t\t\t\033[36;46m* * * *\033[0m\t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m     \t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m \t    \033[36;46m* * * * * \033[0m\t    \033[36;46m* * * * * \033[0m\033[30m+\033[0m"<<endl;
    cout <<"    \t\t\t\t\033[36;46m**\033[0m     \t\t\033[36;46m**\033[0m \t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;
    cout <<"\t\t\t\t\033[36;46m* * * *\033[0m\t\t\033[36;46m**\033[0m\t        \033[36;46m**\033[0m\033[30m+\033[0m"<<endl;;
    cout<<"\n\n\t\t\t\t\t\033[36mM  O  N  T  A  G  E\033[0m";
    cout<<"\n\n\t\t\033[36m____________________________________________________________________\033[0m\n"<<endl;
    cout << "\n\t\t\t\t  "<<"\033[36mWELCOME TO THE FUNDAMENTALS OF C++\033[0m\n" << endl;

    }



 string chooseLesson(Player *currentPlayer){
    string choice;
    cout<<"\n\n\t\t\033[32mAVAILABLE TOPICS\033[0m: \033[34mBASIC CONCEPTS(1)\033[0m, \033[31mCONDITIONALS(2)\033[0m, \033[35mCONTROL FLOW(3)\033[0m, \033[36mEXIT(4)\033[0m";
    cout<<"\n\n\t\t\033[32mCURRENT PLAYER\033[0m: "<<"\033[36m" << currentPlayer->name<<"\033[0m";
    cout<<" \033[32mSCORE\033[0m: " <<"\033[36m"<< currentPlayer->score<<"\033[0m";
    cout<<"\n\n\t\t\033[32mEnter choice(1-4)\033[0m: ";
    getline(cin, choice);
    choice.erase(remove(choice.begin(), choice.end(), ' '), choice.end());

    return choice;

    }

void addNewPlayer() {
    string res;
    string name;
    if (numPlayers >= MAX_PLAYERS) {
        cout << "\t\t\t   \033[31mMaximum number of players reached\033[0m." << endl;
        return;
    }
    do{
        cout << "\t\t\t   \033[32mEnter player name\033[0m: ";
        getline(cin, name);
        name.erase(remove(name.begin(), name.end(), ' '), name.end());


        if(name.length()<4){
            cout << "\n\t\t\t   \033[33mYour chosen name is too short\033[0m\n" <<endl;
        }

        else if(name.length() > 10){
            cout << "\n\t\t\t   \033[33mYour chosen name exceeds  the required length(10) \033[0m\n" <<endl;
        }


    }while(name.length()<4 || name.length() >10);

    for(int i = 0; i < numPlayers; i++){
        if(name==players[i].name){
            cout << "\n\t\t\t   \033[33mThe name is already taken\033[0m" <<endl;
            return;
            }
    }


    players[numPlayers].name = name;
    players[numPlayers].score = 0;
    players[numPlayers].l1_finished = false;
    players[numPlayers].l2_finished = false;
    players[numPlayers].l3_finished = false;
    numPlayers++;
    cout << "\n\t\t\t   \033[36mPlayer Successfully Added\033[0m\n";



}

void savePlayersToFile() {
    ofstream outputFile("player_datas.txt");
    if (!outputFile) {
        cerr << "\t\t\t   \033[31mError: Unable to open file for writing\033[0m." << endl;
        return;
    }

    for (int i = 0; i < numPlayers; i++) {
        outputFile << players[i].name << " " << players[i].score << " "
                   << players[i].l1_finished << " " << players[i].l2_finished << " "
                   << players[i].l3_finished << endl;
    }

    outputFile.close();
}



void loadPlayersFromFile() {
    numPlayers = 0;

    ifstream inputFile("player_datas.txt");
    if (!inputFile) {
        cerr << "\t\t\t   \033[33mNo existing player data found. Starting with empty player list\033[0m." << endl;
        return;
    }

    while (numPlayers < MAX_PLAYERS &&
           inputFile >> players[numPlayers].name >> players[numPlayers].score
                     >> players[numPlayers].l1_finished >> players[numPlayers].l2_finished
                     >> players[numPlayers].l3_finished) {
        numPlayers++;
    }
    inputFile.close();
}


Player* findPlayerByName(const string& playerName) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].name == playerName) {
            return &players[i];
        }
    }
    cout << "\n\t\t\t   \033[33mPlayer not found. Add player to PLAY\033[0m" << endl;
    return 0;
    }



void initializeGame(Player* currentPlayer ){
    string choice, res;
    do {
       gameName();
       while(1){
       choice = chooseLesson(currentPlayer);
            if (choice == "1") {
                basicConcepts(currentPlayer);
                break;
            }

            else if (choice == "2") {
                if (currentPlayer->score >= 10 && currentPlayer->l1_finished) {
                    conditionals(currentPlayer);
                    break;
                }

                else {
                    cout << "\n\n\t\t\033[33mAttain a perfect score in lesson 1 to access this lesson\033[0m\n\n\t\t";
                    do{
                        cout << "\n\t\t\033[32mPress 1 to exit: \033[0m";
                        getline(cin, res);
                        res.erase(remove(res.begin(), res.end(), ' '), res.end());
                }while(res!="1");
                break;
                }
            }

            else if (choice == "3") {
                if (currentPlayer->score >= 20 && currentPlayer->l2_finished) {
                    loopings(currentPlayer);
                    break;
                }

                else {
                    cout << "\n\n\t\t\033[33mAttain a perfect score in lesson 2 to access this lesson\033[0m\n\n\t\t";
                    do{
                        cout << "\n\t\t\033[32mPress 1 to exit: \033[0m";
                        getline(cin, res);
                        res.erase(remove(res.begin(), res.end(), ' '), res.end());
                }while(res!="1");
                break;
                }
            }

            else if (choice == "4") {
                break;

            }

            else {
                cout << "\n\t\t\033[31mInvalid Choice\033[0m";
                    do{
                    cout << "\n\t\t\033[32mPress 1 to exit: \033[0m";
                    getline(cin, res);
                    res.erase(remove(res.begin(), res.end(), ' '), res.end());
                }while(res!="1");
                break;
            }
        }
    } while (choice != "4");

}


void shuffle_array(string arr[10][2], int n) {
    // Use the current time as the seed for the random number generator
    unsigned seed = static_cast<unsigned>(std::time(nullptr));

    // Shuffling the array
    shuffle(arr, arr + n, default_random_engine(seed));

}

