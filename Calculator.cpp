/* version 1*/
#include <bits/stdc++.h>
using namespace std;

void process (string n1,string d1 , char symbol , string n2,string d2)
{
    int num1 = stoi (n1);
    int num2 = stoi (n2);
    int dum1 = stoi (d1);
    int dum2 = stoi (d2);
    int nom=0 , dom=0;
    if(symbol=='+')
    {
        nom = (num1*dum2)+(dum1*num2);
        dom=(dum2*dum1);
    }
    else if(symbol=='-')
    {
        nom = (num1 * dum2) - (num2 * dum1);
        dom = (dum1 * dum2);
    }
    else if(symbol=='*')
    {
        nom = (num1 * num2);
        dom = (dum1 * dum1);
    }
    else if(symbol=='/')
    {
        nom = (num1 * dum2);
        dom = (num2 * dum1);
    }
    if ((dum1 == 0 or dum2 == 0) or dom == 0)
    {
        cout<<"undefined"<<'\n';
        cout<<"Thank you for using rational number calculator \n";
        exit(1);
    }
    if(nom % dom ==0 )
    {
        cout<<nom/dom;
    }
    else{
        cout << nom <<'/'<<dom<<'\n';
    }
    cout<<"Thank you for using rational number calculator \n";
}
void calculator(string input)
{
    string n1 ="",n2="",d1="",d2="";
    int index=0;
    char symbol;
    auto iter =remove(input.begin(),input.end(),' ');
    input.erase(iter,input.end());
    int Size = input.size();
    for (int i=0;i<Size;i++)
    {
        if(isdigit(input[i]))
        {
            n1+=input[i];
        }
        else
        {
            index = i+1;
            break;
        }
    }
    for (int i=index;i<Size;i++)
    {
        if(isdigit(input[i]))
        {
            d1+=input[i];
        }
        else
        {
            symbol = input[i];
            index = i+1;
            break;
        }
    }
    for (int i=index;i<Size;i++)
    {
        if(isdigit(input[i]))
        {
            n2+=input[i];
        }
        else
        {
            index = i+1;
            break;
        }
    }
    for (int i=index;i<Size;i++)
    {
            d2+=input[i];
    }
    process(n1,d1,symbol,n2,d2);
}
int main() {
    while (true) {
        string input;
        cout << "Please, Enter the operation in form\n";
        cout << "\"numerator1/dominator1 \" operator \" numerator2 / dominator2 \" \n";
        cout << "or type exit.\n";
        getline(cin, input);
        if (input == "exit") {
            cout << "Thank you for using rational number calculator \n";
            exit(1);
        }
        calculator(input);
    }
}

