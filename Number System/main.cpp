#include <iostream>
#include "numsys.h"

using namespace std;

int main()
{
    numsys ns;
    int ch;
while(true) {
    label : cout<<"\n\nEnter one of the following options\n1 for Decimal to Binary\n2 for Decimal to Octal\n3 for Decimal to Hexadecimal\n4for Binary to Decimal\n5for BInary to Octal\n6 for Binary to Hexadecimal\n7 for Octal to Decimal\n8 for Octal to Binary\n9 for Octal to Hexadecimal\n10 for Hexadecimal to Binary\n11 for Hexadecimal to Decimal\n12 for Hexadecimal to Octal\n";
    cin>>ch;
    switch (ch)
    {
        case 1 : ns.DB();
        break;
        case 2 : ns.DO();
        break;
        case 3 :ns.DH();
        break;
        case 4:ns.BD();
        break;
        case 5:ns.BO();
        break;
        case 6: ns.BH();
        break;
        case 7 : ns.OD();
        break;
        case 8 : ns.OB();
        break;
        case 9 : ns.OH();
        break;
        case 10 : ns.HB();
        break;
        case 11 : ns.HD();
        break;
        case 12 : ns.HO();
        break;
        default : {cout<<"Wrong input\n"; goto label;};
        break;
    }
}
    return 0;
}
