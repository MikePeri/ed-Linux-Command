/*
    Author: ~Michael Perry~
    Description: Editor is user interface class
*/
#pragma once
#include <iostream>
#include <string>
#include "Document.h"
using namespace std;
class Editor
{
private:
    Document* dc;
public:
    Editor()
        {
            cout<<"Editor constructor.\n"<<endl;
            dc = new Document();
        };//Constructor
    Editor(string filename)
        {
            cout<<"Editor constructor.\n"<<endl;
            dc = new Document(filename);
        };//Constructor
    ~Editor()
    {
        cout<<"Editor distructor.\n"<<endl;
        delete(dc);
    };//Distructor
    int loop();
};


