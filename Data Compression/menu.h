#include "chcompress.h"
class opt
{
public:
    void magic()
    {
        int choice;
        cout<<"Welcome to Our attempt at Compression/Encryption\n\n";
        cout<<"Enter Your choice:\n";
        cout<<"1 to compress a file\n2 to extract a file\n";
        cin>>choice;
        switch(choice)
        {
            case 1: case1();
                    break;
            case 2: case2();
                    break;
            default:cout<<"Enter the correct choice\n";
                    break;
        }
    }
    void case1()
    {
       compress jj;
       jj.jadu();
    }
    void case2()
    {
        extract ji;
        ji.karnama();
    }
};
