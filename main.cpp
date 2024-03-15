#include <iostream>
#include <string>
using namespace std;

/*void displayGameIntro();*/
void basicConcepts();
void conditionals();
void controlFlow();
void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength, int *score);
void show_lectures(string lectures[][5], int l_length, int l_slength);
int score;
int main()
{   string choice;



    cout<<"\n\n\t\t\t\t=======================================================\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   "<<" C++ CHALLENGE\n\n"<<endl;
    cout<<"\t\t\t\t=======================================================\n"<<endl;
    cout << "\t\t\t\t\t  "<<"WELCOME TO FUNDAMENTALS OF C++" << endl;

    do{
        cout<<"\n\n\t\tAVAILABLE TOPICS: BASIC CONCEPTS(1), CONDITIONALS(2), CONTROL FLOW(3)";
        cout<<"\n\n\t\tEnter choice(1-3): ";
        cin>>choice;

        if(choice=="1"){
            basicConcepts();
        }

        else if(choice=="2"){
            conditionals();
        }

        else if(choice=="3"){
            controlFlow();
        }
        else {
            cout<<"\n\n\t\tInvalid Choice\n\n";

        }


    }while(choice.length()==1|| choice!="1" && choice!="2" && choice!="3");

    return 0;
}


    void basicConcepts(){
        int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
            {"\n\n\t\tWELCOME TO C++\n\t\tC++ is one of the most popular programming languages.\n\t\tIt is used to build games, operating system, browsers, and much more.",
            "\n\n\t\tOutput\n\t\tCoders use output all the time to check the computer if its following the given instruction\n\t\tex: cout<<\"Welcome to c++\";\n",
            "\n\n\t\tStatements\n\t\tA line of code is called a statement\n\t\tA statement performs a specific task.\n\t\tex: cout<<\"Coding is an art\";\n\t\t//displays Coding is an art in the console\n",
            "\n\n\t\tSemicolon\n\t\tEach statements in c++ ends width a semicolon ;\n\t\tcout<<\"I love C++\" //returns an error due to no semicolon\n",
            "\n\n\t\tOutputting a text\n\t\tWhen printing text outputs you need to enclose the text in double qoutes\n\t\tcout<<\"C++ is super easy\";\n\n\t\tText VS Numbers\n\t\tComputers treat numbers and text differently.\n\t\tNumber dont need qoutes when you want to output them\n\t\tcout<<42; #displays 42 in the console\n"},

            {"\n\n\t\tC++ STRUCTURE\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\t\t}",
            "\n\n\t\t#include <iostream>\n\t\tA header file contains functions and commands\n\t\tWe need it to include in our program to use commands such as cin and cout  ",
            "\n\n\t\tNamespace\n\t\tusing namespace std;\n\t\tThis tells the program to use std namespace without prefixing each elememt with std::\n\n\t\tcout<<\"HELLO\";\n\n\t\tinstead of\n\n\t\tstd::cout<<\"HELLO\";\n",
            "\n\n\t\tMain function\n\n\t\tint main(){}\n\n\t\tEach c++ program has an entry point, which is a function called main",
            "\n\n\t\tCurly Brackets{}\n\n\t\tIndicates the beginning and end of the function, or so called the function's body.\n"},

            {"\n\n\n\t\tVARIABLES\n\t\tEvery Program works with values\n\t\tA variable lets you store a value by assigning it to a name or identifier\n",
            "\n\n\t\tVariable Types\n\t\tEach variable  has a type, which defines the type of the value it holds\n\t\tA variable can hold a text value, a number, decimal, character etc.\n\n\t\tex.\t string message; #This creates a variable called message of type string\n\t\t\t int age;\n",
            "\n\n\t\tDeclaration\n\t\tIt refers to the process of announcing the existence of a variable to a compiler without assigning a \n\t\tvalue to it\n\n\t\tex.string name;\n\t\tint age;\n",
            "\n\n\t\tInitialization\n\t\tIs the process of giving an initial value to variable using assignment operator(=)\n\n\t\tex.string name=\"JOHN\";\n\t\tint age=9;\n\t\t--or--\n\t\tstring surname;\n\t\tsurname=\"Stuoustruop\";\n",
            "\n\n\t\tNaming Variables\n\n\t\tCommon Conventions of naming variables are:\n\n\t\tCase-Sensitivity: This means that lowercase and uppercase are treated as distinct characters\n\t\tex. \"firstname\", \"firstName\" would be considered 2 different identifiers\n"},

            {"\n\t\tAllowed Characters: Identifiers can consist and must begin with (uppercase or lowercase)\n\t\tor camelCase convention, digits, and underscores\n\n\t\tfirstname, FIRSTNAME, Firstname, _firstName\n\t\tname1, name2\n\t\tname_1, name_2, _name3,\n",
            "\n\t\tInvalid Variable Names: Identifiers cannot CONTAIN with certain characters:\n\n\t\tSpecial Symbols: @, # ,$, %, ^,* etc.\n",
            "\n\t\tReserved Key Words: Identifiers cannot be the same as C++ keywords:\n\n\t\tC++ keywords: int, float, char, return etc.\n",
            "\n\t\tCan you find the error?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname;\n\t\t}\n",
            "\n\t\tCan you find the error?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  string firstName;\n\n\t\t  cout<<firstname; //this line is the error due to wrong case, it should be cout<<firstName;\n\t\t}\n"},


            {"\n\n\n\t\tDATA TYPES\n\t\tC++ Supports many different data types for your variables based on their value.\n\t\tWe will discuss Basic Data Types\n\t\tIntegers, Characters, floats, and Boolean\n",
            "\n\n\t\tIntegers\n\t\t-Used to store numbers with out decimal points\n\t\tExamples: int, short, long, long long\n\n\t\tint myNum=100;\n\n\t\tcout<<myNum; //displays 100\n",
            "\n\n\t\tFloating-Points\n\t\t-Used to store numbers with decimal points\n\t\tExamples: float, double\n\n\t\tfloat myFloat=2.14f;\n\n\t\tcout<<myFloat //dispays 2.14\n",
            "\n\n\t\tCharacters\n\t\t-Used to store single characters\n\t\tExample: char\n\n\t\tchar myGrade='A';\n\n\t\tcout<<myGrade; //displays A\n",
            "\n\n\t\tBooleans\n\t\t-Used to store true(1)or false(0) values\n\t\tExample: bool\n\n\t\tbool am_I_handsome=true;\n\n\t\tcout<<am_I_handsome; //returns 1 which is true\n"},



            {"\n\n\n\t\tARITHMETIC OPERATORS\n\t\t-Used to perform arithmetic operations on numerical values(Addition, Subtraction, \n\t\tMultiplication, Division or Modulus\n",
            "\n\n\t\tAddition(+)\n\t\t-Adds two values together can be applied in integral, floats, and chars\n\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 + num2; //displays 33\n",
            "\n\n\t\tSubtraction(-)\n\t\t-Subtracts the second value from the first\n\t\tex.\n\t\tint num1=23;\n\t\tint num2=10;\n\n\t\tcout<<num1 - num2; //displays 13\n",
            "\n\n\t\tMultiplication(*)\n\t\t-Multiplies two values together\n\n\t\tex.\n\t\tint num1=10;\n\t\tint num2=6;\n\n\t\tcout<<num1*num2; //displays 60\n",
            "\n\n\t\tDivision(/)\n\t\t-Divides the first value by the second\n\n\t\tex.\n\t\tint num1=50;\n\t\tint num2=5;\n\n\t\tcout<<num1/num2; //displays 10\n\n\t\tModulus(%)\n\t\t-Returns the remainder of the division of the first value by the second\n\n\t\ttex.\n\t\tint num1=53;\n\t\tint num2=5;\n\n\t\tcout<<num1%num2; //displays 3\n"},

            {"\n\n\n\t\tOPERATOR PRECEDENCE\n\n\t\t-Determines the order in which arithmetic operators are evaluated within an arithmetic expression\n\n\t\t-The precedence of C++ follows PEMDAS Rule, which stands for Parenthesis, Exponent, \n\t\tMultiplication and Division and Addition and Subtraction\n",
            "\n\n\t\tMultiplication and Division\n\t\t-They have the same precedence from left to right\n\n\t\tex. int result=10+5*2\n\n\t\tcout<<result; //displays 20 (5 and 2 are evaluated first(5*2=10) then is added to 10,(10+10=20))\n\n\t\tint result=10+8/2\n\n\t\tcout<<result; //dsiplays 14 (8 and 2 are evaluated first(8/2=4) then added to 10, (10+4=14))\n",
            "\n\n\t\tModulus\n\t\t-This operator is also evaluated after multiplication and division\n\n\t\tex. int result=10+5%3\n\n\t\tcout<<result; //displays 12 (5 and 3 are evaluated first(5%3=2) then added to 10,(10+2=12))\n",
            "\n\n\t\tAddition and Subtraction\n\t\t-These Operators have the same precedence and are evaluated left to right\n\n\t\tex. int result=10+5-3\n\n\t\tcout<<result; //displays 12 (10+5=15, 15-3=(12))",
            "\n\n\t\tParenthesis\n\n\t\t-Used tp control the order of the operation.\n\t\tThey override the operator precedence rule.\n\t\tAllowing you to specify which parts should be evaluated together\n\n\t\tint result=(10+5)*2;\n\n\t\tcout<<result; //displays 30 (10+5=15) are evaluated first due to parenthesis, (15*2=30)\n\n\t\tint result=(10-5)*3;\n\n\t\tcout<<result; //displays 15 (10-5=5), (5*3=(15))\n"
            },

        };

        string questionAns[][2]= {
            {"\n\n\t\t1. Which statements are true about C++?:\n\n\t\tI.C++ is not a programming language\n\t\tII. C++ can be used to build games.\n\t\tIII.C++ is good for operating systems or browsers development\n\n\t\ta. I only\n\t\tb. II and III\n\t\tc. all of the statements: \n\t\t", "b"},
            {"\n\n\t\t2. Find the missing structure\n\n\t\t#include <_____>\n\t\tusing namespace std;\n\n\t\tint main(){\n\t\t  cout<<\"Hello World\";\n\n\t\treturn 0;\n\n\t\t}\n\n\t\ta.stdio.h\n\t\tb.iostrim\n\t\tc.iostream\n\t\t", "c"},
            {"\n\n\t\t3. This Program returns an error why?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\tstring programmingLanguage=\"C++\";\n\n\t\tcout<<programminglanguage;\n\n\t\t  return 0;\n\n\t\t}:\n\n\t\ta.Calling an incorrect Case of Identifier\n\t\tb.data type should be int\n\t\tc.No semicolon\n\t\t", "a"},
            {"\n\n\t\t4. Determine if its a valid or invalid identifier\n\n\t\tfirst name\n\n\t\ta.valid\n\t\tb.invalid\n\t\tc.hard to tell\n\t\t", "b"},
            {"\n\n\t\t5. Guess the output\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int myGrade=99;\n\n\t\t cout<<\"myGrade\";\n\n\t\t return 0;\n\n\t\t}\n\n\t\ta.99\n\t\tb.error\n\t\tc.myGrade\n\t\t", "c"},
            {"\n\n\t\t6. Determine data type suitable for this data.\n\n\t\tThe number of days in a year:\n\n\t\ta.int\n\t\tb.float\n\t\tc.string\n\t\t", "a"},
            {"\n\n\t\t7. (7-10)Determine the value of the following expression\n\n\t\t3+6*7\n\n\t\ta.46\n\t\tb.56\n\t\tc.45\n\t\t", "c"},
            {"\n\n\t\t8. 50%30\n\n\t\ta.20\n\t\tb.1\n\t\tc.50/30\n\t\t", "a"},
            {"\n\n\t\t9. 10*(2+3)\n\n\t\ta.23\n\t\tb.50\n\t\tc.15\n\t\t", "b"},
            {"\n\n\t\t10. 3*4/6+6\n\n\t\ta.1\n\t\tb.8\n\t\tc.6\n\t\t", "b"}
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


        do{
            cout<<"\n\n\t\tQuiz(1) or Lecture(2)?: ";
            cin>>yes_no;

            if(yes_no=="1"){
            system("cls");
            question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
            cout<<"\n\t\tYour Score is "<<score<<"/10\n\n";
            }

            else if(yes_no=="2"){
               show_lectures(lectures, l_length, l_slength);
            }

            else{
                cout<<"\n\n\t\tTry again\n\n";
            }
        }while(yes_no.length()!=1||(yes_no!="1"&&yes_no!="2"));


    }



void conditionals(){
   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]= {
            {"\n\n\n\t\tTAKING INPUTS\n\n\t\t-Your program may take user input for an application to process and generate output\n\n\t\t-To take input, use cin>> command\n\n\t\t-We first declare the variable that will hold our input value, then we use cin>>command\n\n\t\tint age;\n\t\tcin>>age; //for example you type 23\n\t\tcout<<age; /displays 23\n",
            "\n\n\t\tAnother Example:\n\n\t\tstring name;\n\t\tcout<<\"Enter name \";\n\t\tcin>>name; //lets assume you type Lemuel\n\t\tcout<<\"You entered: \"<<name; //displays You entered Lemuel\n",
            "\n\n\t\tMultiple Inputs\n\n\t\tYou can take multiple inputs throughout your program\n\n\t\tint a, b;\n\t\tcin>>a; //assume you type 3\n\t\tcin>>b; //assume you type 10;\n\t\tcout<< a+b; //displays 13\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\tstring name;\n\t\tint age;\n\n\t\tcout<<\"Enter name: \";// assume you type Guko\n\t\tcin>>name;\n\n\t\tcout<<\"Enter age: \"; // assume you type 34\n\n\t\tcout<<\"You are \"<<name<<\" \"<<age<<\" years old\";\n\n\t\treturn 0;\n\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\tstring name;\n\t\tint age;\n\n\t\tcout<<\"Enter name: \";// assume you type Guko\n\t\tcin>>name;\n\n\t\tcout<<\"Enter age: \"; // assume you type 34\n\n\t\tcout<<\"You are \"<<name<<\" \"<<age<<\" years old\"; //displays \"You are Guko 34 years old\"\n\n\t\treturn 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\tCONDITIONAL STATEMENTS\n\n\t\t-Are used to perform different actions based on different conditions\n\n\t\t",
            "\n\n\t\tIF STATEMENT\n\n\t\t-The if statements allows you to run a specified code if a given condition is true\n\n\t\tHere is the syntax\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}",
            "\n\n\t\tCOMPARISON OPERATORS\n\n\t\t-The following are comparison operators may be used to form the conditions\n\n\t\t< -less than\n\n\t\t> -greater than\n\n\t\t!= -not equal to\n\n\t\t== -equal to\n\n\t\t< -less than or equal to\n\n\t\t>= -greater than or equal to\n\n\t\tExamples\n\n\t\tint grade=80;\n\t\tif(grade > 75){\n\n\t\tcout<<\"You pass\"; //displays \"You pass\", since the condition is true, 80 is greater than 75\n\n\t\t}",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t cout<<\"Sunday\";\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n",
            "\n\n\t\tCan you guess the output?\n\n\t\t#include <iostream>\n\t\tusing namespace std;\n\n\t\tint main(){\n\n\t\t int day=7;\n\n\t\t if(day==7){\n\t\t cout<<\"Sunday\"; //displays \"Sunday\" since day is equals to 7\n\n\t\t}\n\n\t\t return 0;\n\n\t\t}\n"
            },


            {"\n\n\n\t\tELSE STATEMENT\n\n\t\t-You can use the else statement after an if statement\n\t\tIf you want to run a code in case the condition is false\n\n\t\tSyntax:\n\n\t\tif(condition){\n\t\t//code to run\n\t\t}\n\n\t\telse{\n\t\t//code to run\n\t\t}\n",
            "\n\n\t\tExample:\n\n\t\tint grade = 60\n\t\tif(age >= 75{\n\t\t cout<<\"You passed\";\n\t\t}\n\n\t\telse{\n\t\tcout<<\"You failed \"; //displays \"You failed\" since grade(52) is not greater than or equal to 75\n\t\t}",
            "",
            "",
            ""
            },

            {"\n\n\n\t\t",
            "",
            "",
            "",
            ""
            },

             {"\n\n\n\t\t",
            "",
            "",
            "",
            ""
            }
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

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        do{
            cout<<"\n\n\t\tQuiz(1) or Lecture(2)?: ";
            cin>>yes_no;

            if(yes_no=="1"){
            system("cls");
            question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
            cout<<"\n\t\tYour Score is "<<score<<"/10\n\n";
            }

            else if(yes_no=="2"){
               show_lectures(lectures, l_length, l_slength);
            }

            else{
                cout<<"\n\n\t\tTry again\n\n";
            }
        }while(yes_no.length()!=1||(yes_no!="1"&&yes_no!="2"));

}



void controlFlow(){



   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][5]={
            {"\n\t\t,"
            "",
            "",
            "",
            ""
            },


            {"\n\t\t",
            "",
            "",
            "",
            ""
            },


            {"\n\t\t",
            "",
            "",
            "",
            ""
            },

            {"\n\t\t",
            "",
            "",
            "",
            ""
            }
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

        //LECTURES ROW LENGTH AND COLUMN LENGTH
        l_length = sizeof(lectures)/sizeof(lectures[0]);
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]);

        //ANSWER CONTAINER
        string your_answers[10];
        anslength=sizeof(your_answers)/sizeof(your_answers[0]);

        do{
            cout<<"\n\n\t\tQuiz(1) or Lecture(2)?: ";
            cin>>yes_no;

            if(yes_no=="1"){
            system("cls");
            question_And_Answer(questionAns, your_answers, qa_length, anslength, &score);
            cout<<"\n\t\tYour Score is "<<score<<"/10\n\n";
            }

            else if(yes_no=="2"){
               show_lectures(lectures, l_length, l_slength);
            }

            else{
                cout<<"\n\n\t\tTry again\n\n";
            }
        }while(yes_no.length()!=1||(yes_no!="1"&&yes_no!="2"));
}

void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength, int *score) {
    *score=0;
    for (int i = 0; i < qa_length; i++) {
        system("cls");
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

    for(int i=2; i<l_length; i++){

        for(int j=0; j<l_slength; j++){
            system("cls");
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


