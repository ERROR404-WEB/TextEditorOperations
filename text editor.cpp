//SIMPLE TEXT EDITOR OPERATIONS-- using stacks
//PROJECT BY -- arjun
#include<stack>
#include <iostream>
#include <cstdlib>
using namespace std;
 stack<string>s,un,re,all;
 stack<char>unc,rec;
    
void enter()
{
   
    string st;
     getline(cin,st);
     string a;
     int i,j=0;
     int l=st.length();
     for(i=0;i<l;i++)
     {
         
       a+=st[i];
         if(st[i]==' '|| i==l-1)
         {
             s.push(a);
             a="";
          }

    }
                  
}
void display()
{
    int i;
    cout<<endl;  
    stack<string>dis;
    string str="";
    
   for(i=0;i<5;i++)
    cout<<"_______________________";
    cout<<endl<<endl;
    
     while(!s.empty()) {
                	string tt= s.top() ;
                	dis.push(tt);
                	str+=tt;
                	s.pop();
    }
    string ne="\\";
       if (dis.empty()) {
        cout << "You Have Cleared all the TEXT !! Please enter some TEXT to display!!\n";
    }
    while(!dis.empty())
    {
      
       string ne=dis.top();
        if(ne[0]=='@') cout<<endl;
        else
        cout<<ne<<" ";
        s.push(dis.top());
        dis.pop();
    }
    cout<<endl<<endl;
     for(i=0;i<5;i++)
    cout<<"_______________________";
    cout<<endl;
    cout<<endl;  
 
}
void displayt()
{
    int i;
    cout<<endl;  
    stack<string>dis;
    string str="";
    
   
    
    cout<<"--TEXT FORMAT ? :\n";
    
    cout<<"\t 1 - ITALIC \t\t 2 - BOLD \t\t 3 - UNDERLINE\n\n";
    cout<<"\nENTER CHOICE--";
    int ch;
    cin>>ch;
    
     cout<<"\e[0m";
   for(i=0;i<5;i++)
    cout<<"_______________________";
    cout<<endl<<endl<<endl;
    
    if(ch==2)
    {
        cout<<"\e[1m";//bold
    }
    else if(ch==1)
    {
        cout<<"\e[3m";//italic
    }
    else if(ch==3)
    {
        cout<<"\e[4m";//underline
    }
    else if(ch==12|| ch==21)
    {
        cout<<"\e[1m"<<"\e[3m";
    }
    else if(ch==13 || ch==31)
    {
         cout<<"\e[3m"<<"\e[4m";
    }
    else if(ch==23||ch==23)
    {
         cout<<"\e[1m"<<"\e[4m";
    }
    else if(ch==123||ch==321||ch==213)
    {
        cout<<"\e[1m"<<"\e[4m"<<"\e[3m";
    }
     while(!s.empty()) {
                	string tt= s.top() ;
                	dis.push(tt);
                	str+=tt;
                	s.pop();
    }
    string ne="\\";
       if (dis.empty()) {
        cout << "You Have Cleared all the TEXT !! Please enter some TEXT to display!!\n";
    }
    
    while(!dis.empty())
    {
      
       string ne=dis.top();
        if(ne[0]=='@') cout<<endl;
        else
        cout<<ne<<" ";
        s.push(dis.top());
        dis.pop();
    }
    cout<<endl<<endl;
    cout<<"\e[0m";
    for(i=0;i<5;i++)
    cout<<"_______________________";
    cout<<endl;
    cout<<endl;  
 
}
 void undo()
 {
    if (s.empty()) {
        cout << "\n!! You Have Cleared all the TEXT !! Please enter some TEXT to display !!\n";
    }
    else
    {
        cout<<"\nPERFORMING UNDO OPERATION!!\n";
     un.push(s.top());
     s.pop();
    }
 }
 void redo()
 {
     if(un.empty())
     {
         cout<<"\n!!INVALID OPERATION!!\n";
     }
     else
     {
         cout<<"\nPERFORMING REDO OPERATION!!\n";
     s.push(un.top());
     un.pop();
     }
 }
 
 void erase()
 {
     while(!s.empty())
    {
        s.pop();
    }
     while(!un.empty())
    {
        un.pop();
    }
    cout<<"\n !! TEXT CLEARED !!\n";
 }
 void undochar()
 {
     string und=s.top();
     int i=0;
    int ll=und.length();
    unc.push(und[ll-1]);
    
     string a;
     int l=und.length();
     for(i=0;i<l-1;i++)
     {
         a+=und[i];
     }
     s.pop();
     s.push(a);
     display();
     
 }
 void redochar()
 {
     if(unc.empty())
     {
         cout<<"\nINVALID OPERATION!!\n";
     }
     else
     {
     string a,st;
     st=s.top();
     a=st+unc.top();
     unc.pop();
     s.pop();
     s.push(a);
     }
     
 }
 void display0()
 {
       cout<<endl;
        for(int i=0;i<12;i++)
        {
            cout<<"----";
        }
        cout<<"|  "<<"\e[1m"<<"\e[4m"<<"SIMPLE TEXT EDITOR"<<"\e[0m"<<"  |";
       
         for(int i=0;i<11;i++)
        {
            cout<<"----";
        }
        cout<<endl<<endl;
        cout<<"                                  \t    >--CONTROL PANEL :\n\n";
    cout<<"                                    \t  E - ENTER TEXT    R - REDO CHAR\n";
    cout<<"                                    \t  Z - UNDO          U - UNDO CHAR\n";
    cout<<"                                    \t  Y - REDO          D - DISPLAY\n";
    cout<<"                                          N - ERASE ALL     C - CLEAR SCREEN\n";
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"-----------------------";
    }
    cout<<endl;
    
  
 }
int main()
{
        display0();
           while(1)
           {
               char ch;
                cout<<"\nENTER CHOICE: ";
                 cin>>ch;
                cin.ignore();
           switch(ch)
           {
               case 'e': cout<<"\nENTER TEXT: \n  NOTE: Enter @ For A New Line:\n\n";
                        enter();
                        break;
               case 'd' :
                        displayt();
                        break;
                case 'z' : 
                        undo();
                        break;
                case 'y' :redo();
                        break;
                case 'n': erase();
                        break;
                case 'u': undochar();
                        break;
                case 'r': redochar();
                        display();
                        break;
                case 'x' :cout<<"\n!! THANK YOU !!\n";
                        return 0;
                case 'c' : std::system("clear");
                          display0();
                        break;
                
                default: cout<<"\n!! INVALID CHOICE !!\n"; 
           }
                    
           }       

    return 0;
}


