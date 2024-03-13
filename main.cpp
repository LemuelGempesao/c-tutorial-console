#include <iostream>
#include <string>
using namespace std;


void displayGameIntro();
void basicConcepts();
void conditionalsAndLoops();
void arraysAndPointers();
void functions();
void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength);
void show_lectures(string lectures[][2], int l_length, int l_slength);

int main()
{
    char choice;

    displayGameIntro();

    cout<<"\n\n\t\tTOPICS: BASIC CONCEPTS(1), CONDITIONALS AND LOOPS(2), ARRAYS AND POINTERS(3), FUNCTIONS(4)";
    cout<<"\n\n\t\tEnter choice: ";
    cin>>choice;
        switch(choice){
        case '1': basicConcepts();
                break;
        case '2': conditionalsAndLoops();
                break;
        case '3': arraysAndPointers();
                break;
        case '4': functions();
                break;

        default: cout<<"\n\t\t\t\tINVALID CHOICE\n\n";




    }


    return 0;
}

    void displayGameIntro()
    {
        cout<<"\t\t\t\t=======================================================\n\n"<<endl;
        cout<<"\t\t\t\t\t\t   "<<" C++ CHALLENGE\n\n"<<endl;
        cout<<"\t\t\t\t=======================================================\n"<<endl;
        cout << "\t\t\t\t\t  "<<"WELCOME TO FUNDAMENTALS OF C++" << endl;
    }


    void basicConcepts(){
        int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][2]= {
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
        question_And_Answer(questionAns, your_answers, qa_length, anslength);
        //LECTURES
        }

        //SCORING IMPLEMENTATION

    }



void conditionalsAndLoops(){
   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][2]= {
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
        question_And_Answer(questionAns, your_answers, qa_length, anslength);
        //LECTURES
        }

        //SCORING IMPLEMENTATION

}



void arraysAndPointers(){



   int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][2]= {
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
        question_And_Answer(questionAns, your_answers, qa_length, anslength);
        //LECTURES
        }

        //SCORING IMPLEMENTATION

}

void functions(){
    int qa_length, qa_slength, l_length, l_slength, anslength;
        string yes_no;
        string ans;
        string lectures[][2]= {
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
        question_And_Answer(questionAns, your_answers, qa_length, anslength);
        //LECTURES
        }

        //SCORING IMPLEMENTATION
}


void question_And_Answer(string questionAns[][2], string your_answers[], int qa_length, int anslength) {
    for (int i = 0; i < qa_length; i++) {
        cout << questionAns[i][0];
        string ans;
        do {
            cin >> ans;
            if (ans.length() != 1 || ans==""|| (ans != "a" && ans != "b" && ans != "c")) {
                cout << "\n\t\t\t\tINVALID\n";
            }
        } while (ans.length() != 1 || ans==""|| (ans != "a" && ans != "b" && ans != "c"));

        your_answers[i] = ans;
    }
      for(int m=0; m<anslength; m++)
        {
            cout<<your_answers[m]<<" ";
        }
}


void show_lectures(string lectures[][2], int l_length, int l_slength){

    for(int i=0; i<l_length; i++){
        for(int j=0; j<l_slength; j++){
            cout<<lectures[i][j]<<endl;
            string ans;
            do{
            cout<<"\n\n\t\tPress 1 to proceed: ";
            cin>>ans;

            }while(ans!="1");
            }


    }
}


