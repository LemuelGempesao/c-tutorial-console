#include <iostream>
#include <string>
using namespace std;


void displayGameIntro();
void basicConcepts();
void conditionalsAndLoops();
void arraysAndPointers();
void functions();

int main()
{
    char choice;

    displayGameIntro();


    cout<<"Enter choice: ";
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

        default: cout<<"\nINVALID CHOICE\n\n";




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
        int qa_length, qa_slength, l_length, l_slength, yAlength;
        string ans;
        string lectures[][2]= {
          /*c++ intro*/     {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };

        qa_length = sizeof(questionAns)/sizeof(questionAns[0]); //QA ROW LENGTH
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]); //QA COLUMN LENGTH

        l_length = sizeof(lectures)/sizeof(lectures[0]); //LECTURES ROW LENGTH
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]); //LECTURES COLUMN LENTGH

        //ANSWER CONTAINER
        string your_answers[]={"","","", "","","","","","",""};
        yAlength=sizeof(your_answers)/sizeof(your_answers[0]);

        //LECTURES







        //QUESTION AND ANSWERS
        for(int i =0; i<qa_length; i++)
        {
            cout<<questionAns[i][0]<<"\n"<<endl;
            do{
                cin>>ans;
                if(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"))
                {
                   cout<<"\n\t\t\t\tINVALID\n";
                }

            }while(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"));

            your_answers[i]=ans;
        }


        for(int i=0; i<yAlength; i++)
        {
            cout<<your_answers[i]<<endl;
        }


        //SCORING IMPLEMENTATION
    }



void conditionalsAndLoops(){

    cout<<"condiAndLoops"<<endl;
    int qa_length, qa_slength, l_length, l_slength, yAlength;
        string ans;
        string lectures[][2]= {
          /*c++ intro*/     {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };
  qa_length = sizeof(questionAns)/sizeof(questionAns[0]); //QA ROW LENGTH
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]); //QA COLUMN LENGTH

        l_length = sizeof(lectures)/sizeof(lectures[0]); //LECTURES ROW LENGTH
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]); //LECTURES COLUMN LENTGH

        //ANSWER CONTAINER
        string your_answers[]={"","","", "","","","","","",""};
        yAlength=sizeof(your_answers)/sizeof(your_answers[0]);

        //LECTURES







        //QUESTION AND ANSWERS
        for(int i =0; i<qa_length; i++)
        {
            cout<<questionAns[i][0]<<"\n"<<endl;
            do{
                cin>>ans;
                if(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"))
                {
                   cout<<"\n\t\t\t\tINVALID\n";
                }

            }while(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"));
            your_answers[i]=ans;
        }


        for(int i=0; i<yAlength; i++)
        {
            cout<<your_answers[i]<<endl;
        }


}



void arraysAndPointers(){



    cout<<"Arrays and Pointrs"<<endl;
    int qa_length, qa_slength, l_length, l_slength, yAlength;
        string ans;
        string lectures[][2]= {
          /*c++ intro*/     {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };

  qa_length = sizeof(questionAns)/sizeof(questionAns[0]); //QA ROW LENGTH
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]); //QA COLUMN LENGTH

        l_length = sizeof(lectures)/sizeof(lectures[0]); //LECTURES ROW LENGTH
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]); //LECTURES COLUMN LENTGH

        //ANSWER CONTAINER
        string your_answers[]={"","","", "","","","","","",""};
        yAlength=sizeof(your_answers)/sizeof(your_answers[0]);

        //LECTURES







        //QUESTION AND ANSWERS
        for(int i =0; i<qa_length; i++)
        {
            cout<<questionAns[i][0]<<"\n"<<endl;
            do{
                cin>>ans;
                if(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"))
                {
                   cout<<"\n\t\t\t\tINVALID\n";
                }

            }while(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"));
            your_answers[i]=ans;
        }


        for(int i=0; i<yAlength; i++)
        {
            cout<<your_answers[i]<<endl;
        }
        // SCORING IMPLEMENTATION


}

void functions(){
    cout<<"func"<<endl;
    int qa_length, qa_slength, l_length, l_slength, yAlength;
        string ans;
        string lectures[][5]= {
          /*c++ intro*/     {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n",
                            "afdfdfdfdfdfdfdfdfdfdfe", "efefefer","34344"},
                            {"\n C++ is programmming language use for kuanb?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanc?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuand?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuane?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanf?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuang?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuanh?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuani?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n\t\t\t\t C++ is programmming language use for kuana?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };
        string questionAns[][2]= {
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"},
                            {"\n C++ is programmming language use for kuan?:\n a.yes  b.no  c.bawlang\n", "a"}
                          };

  qa_length = sizeof(questionAns)/sizeof(questionAns[0]); //QA ROW LENGTH
        qa_slength=sizeof(questionAns[0])/ sizeof(questionAns[0][0]); //QA COLUMN LENGTH

        l_length = sizeof(lectures)/sizeof(lectures[0]); //LECTURES ROW LENGTH
        l_slength=sizeof(lectures[0])/ sizeof(lectures[0][0]); //LECTURES COLUMN LENTGH

        //ANSWER CONTAINER
        string your_answers[]={"","","", "","","","","","",""};
        yAlength=sizeof(your_answers)/sizeof(your_answers[0]);

        //LECTURES







        //QUESTION AND ANSWERS
        for(int i =0; i<qa_length; i++)
        {
            cout<<questionAns[i][0]<<"\n"<<endl;
            do{
                cin>>ans;
                if(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"))
                {
                   cout<<"\n\t\t\t\tINVALID\n";
                }

            }while(ans.length()!=1 ||(ans!="a" && ans!="b" && ans!="c"));
            your_answers[i]=ans;
        }


        for(int i=0; i<yAlength; i++)
        {
            cout<<your_answers[i]<<endl;
        }
}

