#include <iostream>
#include <string>
using namespace std;

//\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\t\t
/*void displayGameIntro();*/
void basicConcepts();
void conditionals();
void controlFlow();
void arrays();
void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength, int *score);
void show_lectures(string lectures[][5], int l_length, int l_slength);
int score;
int main()
{
    char choice;

   /* displayGameIntro();*/

    cout<<"\n\n\t\t\t\t=======================================================\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   "<<" C++ CHALLENGE\n\n"<<endl;
    cout<<"\t\t\t\t=======================================================\n"<<endl;
    cout << "\t\t\t\t\t  "<<"WELCOME TO FUNDAMENTALS OF C++" << endl;
    cout<<"\n\n\t\tAVAILABLE TOPICS: BASIC CONCEPTS(1), CONDITIONALS(2), CONTROL FLOW(3), ARRAYS(4)";

    cout<<"\n\n\t\tEnter choice(1-4): ";
    cin>>choice;
        switch(choice){
        case '1': basicConcepts();
                break;
        case '2': conditionals();
                break;
        case '3': controlFlow();
                break;
        case '4': arrays();
                break;

        default: cout<<"\n\t\t\t\tINVALID CHOICE\n\n";


    }
    cout<<"\n\t\tYour Score is "<<score<<"/10\n\n";

    return 0;
}

    /*void displayGameIntro()
    {
        cout<<"\n\n\t\t\t\t=======================================================\n\n"<<endl;
        cout<<"\t\t\t\t\t\t   "<<" C++ CHALLENGE\n\n"<<endl;
        cout<<"\t\t\t\t=======================================================\n"<<endl;
        cout << "\t\t\t\t\t  "<<"WELCOME TO FUNDAMENTALS OF C++" << endl;
        cout<<"\n\n\t\tAVAILABLE TOPICS: BASIC CONCEPTS(1), CONDITIONALS(2), CONTROL FLOW(3), ARRAYS(4)";
    }*/


    void basicConcepts(){
        int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
            {"\n\n\t\tWELCOME TO C++\n\t\tC++ is one of the most popular programming languages.\n\t\tIt is used to build games, operating system, browsers, and much more.",
            "\n\t\tOutput\n\t\tCoders use output all the time to check the computer if its following the given instruction\n\t\tex: cout<<\"Welcome to c++\";\n",
            "\t\tStatements\n\t\tA line of code is called a statement\n\t\tA statement performs a specific task.\n\t\tex: cout<<\"Coding is an art\";\n\t\t#displays Coding is an art in the console\n",
            "\n\t\tSemicolon\n\t\tEach statements in c++ ends width a semicolon ;\n\t\tcout<<\"I love C++\" #returns an error due to no semicolon\n",
            "\n\t\tOutputting a text\n\t\tWhen printing text outputs you need to enclose the text in double qoutes\n\t\tcout<<\"C++ is super easy\";\n\n\t\tText VS Numbers\n\t\tComputers treat numbers and text differently.\n\t\tNumber dont need qoutes when you want to output them\n\t\tcout<<42; #displays 42 in the console\n"},

            {"\n\t\tC++ STRUCTURE\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\t\t}",
            "\n\t\t#include <iostream>\n\t\tA header file contains functions and commands\n\t\tWe need it to include in our program to use commands such as cin and cout  ",
            "\n\t\tNamespace\n\t\tusing namespace std;\n\t\tThis tells the program to use std namespace without prefixing each elememt with std::\n\n\t\tcout<<\"HELLO\";\n\n\t\tinstead of\n\n\t\tstd::cout<<\"HELLO\";\n",
            "\n\t\tMain function\n\n\t\tint main(){}\n\n\t\tEach c++ program has an entry point, which is a function called main",
            "\n\t\tCurly Brackets{}\n\n\t\tIndicates the beginning and end of the function, or so called the function's body.\n"},

            {"\n\t\tVARIABLES\n\t\tEvery Program works with values\n\t\tA variable lets you store a value by assigning it to a name or identifier\n",
            "\n\t\tVariable Types\n\t\tEach variable  has a type, which defines the type of the value it holds\n\t\tA variable can hold a text value, a number, decimal, character etc.\n\n\t\tex.\t string message; #This creates a variable called message of type string\n\t\t\t int age;\n",
            "\n\t\tDeclaration\n\t\tIt refers to the process of announcing the existence of a variable to a compiler without assigning a \n\t\tvalue to it\n\n\t\tex.string name;\n\t\tint age;\n",
            "\n\n\t\tInitialization\n\t\tIs the process of giving an initial value to variable using assignment operator(=)\n\n\t\tex.string name=\"JOHN\";\n\t\tint age=9;\n\t\t--or--\n\t\tstring surname;\n\t\tsurname=\"Stuoustruop\";\n",
            "\n\t\tNaming Variables\n\n\t\tCommon Conventions of naming variables are:\n\n\t\tCase-Sensitivity: This means that lowercase and uppercase are treated as distinct characters\n\t\tex. \"firstname\", \"firstName\" would be considered 2 different identifiers\n"},

            {"\n\t\tAllowed Characters: Identifiers can consist and must begin with (uppercase or lowercase)\n\t\tor camelCase convention, digits, and underscores\n\n\t\tfirstname, FIRSTNAME, Firstname, _firstName\n\t\tname1, name2\n\t\tname_1, name_2, _name3,\n",
            "\n\t\tInvalid Variable Names: Identifiers cannot CONTAIN with certain characters:\n\n\t\tSpecial Symbols: @, # ,$, %, ^,* etc.\n",
            "\n\t\tReserved Key Words: Identifiers cannot be the same as C++ keywords:\n\n\t\tC++ keywords: int, float, char, return etc.\n",
            "\n\t\tCan you find the error?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname;\n\t\t}\n",
            "\n\t\tCan you find the error?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname; //this line is the error due to wrong case, it should be cout<<firstName;\n\t\t}\n"},


            {"\n\t\tData Types\n\t\tC++ Supports many different data types for your variables based on their value.\n\t\tWe will discuss Basic Data Types\n\t\tIntegers, Characters, floats, and Boolean\n",
            "\n\t\tIntegers\n\t\t-Used to store numbers with out decimal points\n\t\tExamples: int, short, long, long long\n\n\t\tint myNum=100;\n\n\t\tcout<<myNum; //displays 100\n",
            "\n\t\tFloating-Points\n\t\t-Used to store numbers with decimal points\n\t\tExamples: float, double\n\n\t\tfloat myFloat=2.14f;\n\n\t\tcout<<myFloat //dispays 2.14\n",
            "\n\t\tCharacters\n\t\t-Used to store single characters\n\t\tExample: char\n\n\t\tchar myGrade='A';\n\n\t\tcout<<myGrade; //displays A\n",
            "\n\t\tBooleans\n\t\t-Used to store true(1)or false(0) values\n\t\tExample: bool\n\n\t\tbool am_I_handsome=true;\n\n\t\tcout<<am_I_handsome; //returns 1 which is true\n"},



            {"\n\t\tArithmetic Operators\n\t\t-Used to perform arithmetic operations on numerical values(Addition, Subtraction, \n\t\tMultiplication, Division or Modulus\n",
            "\n\t\tAddition(+)\n\t\t-Adds two values together\n\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 + num2; //displays 33\n",
            "\n\t\tSubtraction(-)\n\t\t-Subtracts the second value from the first\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 - num2; //displays 13\n",
            "\n\t\tMultiplication(*)\n\t\t-Multiplies two values together\n\n\t\tex.\n\t\tint num1=10;\n\t\tint num2=6;\n\n\t\tcout<<num1*num2; //displays 60\n",
            "\n\t\tDivision(/)\n\t\t-Divides the second value by the second\n\n\t\tex.\n\t\tint num1=50;\n\t\tint num2=5;\n\n\t\tcout<<num1/num2; //displays 10\n\n\t\tModulus(%)\n\t\t-Returns the remainder of the division of the first value by the second\n\n\t\ttex.\n\t\tint num1=53;\n\t\tint num2=5;\n\n\t\tcout<<num1%num2; //displays 3\n"},




           /* {"\n\t\tLesson Takeaways",
            "",
            "",
            "",
            ""}*/

            };

        string questionAns[][2]= {
                            {"\n\n\t\t1. Which statements are true about C++?:\n\n\t\tI.C++ is not a programming language\n\t\tII. C++ can be used to build games.\n\t\tIII.C++ is good for operating systems or browsers development\n\n\t\ta. I only\n\t\tb. I and II\n\t\tc. all of the statements: \n\t\t", "b"},
                            {"\n\n\t\t2. Find the missing structure\n\n\t\t#include <_____>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\n\t\treturn 0;\n\n\t\t}\n\n\t\ta.stdio.h\n\t\tb.iostrim\n\t\tc.iostream: \n\t\t", "b"},
                            {"\n\n\t\t3. C++ is programmming language use for kuanc?:\n\t\t a.yes  b.no  c.bawlang: ", "c"},
                            {"\n\n\t\t4. C++ is programmming language use for kuand?:\n\t\t a.yes  b.no  c.bawlang: ", "b"},
                            {"\n\n\t\t5. C++ is programmming language use for kuane?:\n\t\t a.yes  b.no  c.bawlang: ", "a"},
                            {"\n\n\t\t6. C++ is programmming language use for kuanf?:\n\t\t a.yes  b.no  c.bawlang: ", "c"},
                            {"\n\n\t\t7. C++ is programmming language use for kuang?:\n\t\t a.yes  b.no  c.bawlang: ", "c"},
                            {"\n\n\t\t8. C++ is programmming language use for kuanh?:\n\t\t a.yes  b.no  c.bawlang: ", "b"},
                            {"\n\n\t\t9. C++ is programmming language use for kuani?:\n\t\t a.yes  b.no  c.bawlang: ", "a"},
                            {"\n\n\t\t10. C++ is programmming language use for k1uanj?:\n\t\t a.yes  b.no  c.bawlang: ", "c"}
                          };
        //QA ROW LENGTH AND COLUMN LENGTH
        qa_length = sizeof(questionAns)/sizeof(questionAns[0]);
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        //INVOKE THE LECTURE FUNCTION
        show_lectures(lectures, l_length, l_slength);

        cout<<"\n\n\t\tProceed to test?: ";
        cin>>yes_no;

        //INVOKE THE QUIZ FUNCTION
        if(yes_no=="1"){
        question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
        }


    }



void conditionals(){
   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
          /*c++ intro*/     {"\n\t\tC++ is programmming language use for kuana?:\n\n\t\t\ta.yes  b.no  c.bawlang\n"},
                            {"\n\t\tC++ is programmming language use for kuanb?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanc?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuand?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuane?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanf?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuang?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanh?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuani?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\t\t\tC++ is programmming language use for kuana?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang  ", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanj?:\n a.yes  b.no  c.bawlang ", "a"}
                          };
        //QA ROW LENGTH AND COLUMN LENGTH
        qa_length = sizeof(questionAns)/sizeof(questionAns[0]);
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENTGH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);
        show_lectures(lectures, l_length, l_slength);

        cout<<"\n\n\t\tPROCEED TO THE QUIZ?: ";
        cin>>yes_no;

        //CALLOUT
        if(yes_no=="1"){
        question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
        //LECTURES
        }



}



void controlFlow(){



   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
          /*c++ intro*/     {"\n\t\tC++ is programmming language use for kuana?:\n\n\t\t\ta.yes  b.no  c.bawlang\n"},
                            {"\n\t\tC++ is programmming language use for kuanb?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanc?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuand?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuane?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanf?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuang?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanh?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuani?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\t\t\tC++ is programmming language use for kuana?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang  ", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanj?:\n a.yes  b.no  c.bawlang ", "a"}
                          };
        //QA ROW LENGTH AND COLUMN LENGTH
        qa_length = sizeof(questionAns)/sizeof(questionAns[0]);
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENTGH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);
        show_lectures(lectures, l_length, l_slength);

        cout<<"\n\n\t\t\tProceed to test?: ";
        cin>>yes_no;

        //CALLOUT
        if(yes_no=="1"){
        question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
        //LECTURES
        }

        //SCORING IMPLEMENTATION

}

void arrays(){
    int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
          /*c++ intro*/     {"\n\t\tC++ is programmming language use for kuana?:\n\n\t\t\ta.yes  b.no  c.bawlang\n"},
                            {"\n\t\tC++ is programmming language use for kuanb?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanc?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuand?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuane?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanf?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuang?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuanh?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\tC++ is programmming language use for kuani?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"},
                            {"\n\t\t\t\tC++ is programmming language use for kuana?:\n\n\t\ta.yes  b.no  c.bawlang\n", "\t\ta"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang  ", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang ", "a"},
                            {"\n C++ is programmming language use for kuanj?:\n a.yes  b.no  c.bawlang ", "a"}
                          };
        //QA ROW LENGTH AND COLUMN LENGTH
        qa_length = sizeof(questionAns)/sizeof(questionAns[0]);
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]);

        //LECTURES ROW LENGTH AND COLUMN LENTGH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);
        show_lectures(lectures, l_length, l_slength);

        cout<<"\n\n\t\t\tProceed to test?: ";
        cin>>yes_no;

        //CALLOUT
        if(yes_no=="1"){
        question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
        //LECTURES
        }

        //SCORING IMPLEMENTATION
}


void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength, int *score) {
    *score=0;
    for (int i = 0; i < qa_length; i++) {
        cout << questionAns[i][0];
        string ans;
        do {
            cin >> ans;
            if (ans.length() != 1 || ans==""|| (ans != "a" && ans != "b" && ans != "c")) {
                cout << "\n\t\t\t\tINVALID\n\t\t";
            }
        } while (ans.length() != 1 || ans==""|| (ans != "a" && ans != "b" && ans != "c"));

        your_answers[i] = ans;
    }
      for(int m=0; m<anslength; m++)
        {
            if (your_answers[m]==questionAns[m][1]){
                (*score)++;
            }

        }

}


void show_lectures(string lectures[][5], int l_length, int l_slength){

    for(int i=5; i<l_length; i++){
        for(int j=0; j<l_slength; j++){
            cout<<lectures[i][j]<<endl;
            string ans;
            do{
            cout<<"\n\n\t\tPress 1 to proceed: ";
            cin>>ans;
            if(ans!="1"){
                cout<<"\n\t\ttry again\n";
            }
            }while(ans!="1");
            }


    }
}


