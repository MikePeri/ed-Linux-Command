/*
    Author: Michael Perry
*/
#include <vector>
#include <string>
#include <iostream>
#include "Editor.h"
#include "Document.h"
using namespace std;
int main(int argc,char* argv[])
{
    Editor* ed;
    switch (argc)
    {
    case 1://Execute cmd without arguments
        ed = new Editor();
        break;
    case 2://Execute cmd with text file argument
        ed = new Editor(argv[1]);
        break;
    default:
        ed = new Editor();
        break;
    }
    ed->loop();
    return 0;
}//main


