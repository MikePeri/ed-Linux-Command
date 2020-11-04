/*
    Author: ~Michael Perry~
    Description: document class is responsible for the file we create and the editor functionality.
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Document
{
private:
   vector<string>* lines;
   string in_file_name;
   string out_file_name;
   int current;
public:
    Document():current(1)
    {
        cout<<"Document constructor.\n"<<endl;  
        lines = new vector<string>();
    };//constructor
    Document(string filename):current(1)
    {
        cout<<"Document constructor.\n"<<endl;
        lines = new vector<string>();
        in_file_name = filename;
        std::ifstream file(filename); 
        // Check if object is valid
        if(!file)
        {
            cerr << "Cannot open the File : "<<filename<<endl;
            exit(0);
        }
        string line="";
        while(getline(file,line))
        {
            if(line.size()>0)
                lines->push_back(line);
        }//while
        
    };//constructor
    ~Document()
    {
        cout<<"Documnent distructor.\n"<<endl;
        delete(lines);
    };//Distructor
    
    void jump_to(string);
    void move_forward(string);
    void move_backward(string);
    void move_forward_last_line();
    int add_lines_after();
    int add_lines_before();
    int replace_current_line();
    void delete_current_line();
    int find_text(string text);
    int replace_current_old_with_new(string old_text,string new_text);
    int add_following_lines();
    void save_to_file(string file_name);
    //DEBUG TOOLS:
    void print_vector();

};


