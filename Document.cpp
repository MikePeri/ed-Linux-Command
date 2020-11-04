/*
    Author: Michael Perry
    Description: implementation of dovument header class
*/
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include "Document.h"

using namespace std;
/*
    Execute the command line: 'w <file_name>'
    Save to file 
*/
void Document::save_to_file(string file_name)
{
    ofstream output_file(file_name);
    ostream_iterator<std::string> output_iterator(output_file, "\n");
    copy(lines->begin(), lines->end(), output_iterator);
    output_file.close();
}//save_to_file
/*
    Execute the command line: 'j'
    Chaining current line with the following line 
*/
int Document::add_following_lines()
{
    if(current+1>lines->size())
    {
        cerr<<"There is no following line after the current one."<<endl;
        return 1;
    }//if
    else
    {
        string next = lines->at(current);
        lines->at(current-1)+=(" "+next);
        lines->erase(lines->begin()+current);
        return 0;
    }//else
}//add_following_lines
/*
    Execute the command line: 's/old/new'
    Find in the current line the old text and replace it with the new one
*/
int Document::replace_current_old_with_new(string old_text,string new_text)
{
    string line= lines->at(current-1);
    size_t start = line.find(old_text);
    if(start == string::npos)
    {
        cout<<"?"<<endl;
    }
    string line_new = line.substr(0,start)+new_text+line.substr(start+old_text.length(),line.size());
    cout<<"\n"<<line_new<<endl;
    lines->at(current-1) = line_new;
    return 0;
}//replace_current_old_with_new

/*
    Execute the command line: '/text/'
    Set the current pointer to the first line with the text inside
*/
int Document::find_text(string text)
{
    bool check = false;
    for(size_t i=current-1;i<lines->size();++i)
    {
        string s = lines->at(i);
        if(s.find(text) != string::npos)
        {
            current = i+1;
            //cout<<"\n"<<current<<endl;
            return 0;
        }//if
    }//for
    for(size_t i=0;i<current-1;++i)
    {
        string s = lines->at(i);
        if(s.find(text) != string::npos)
        {
            //cout<<"\n"<<current<<endl;
            current = i+1;
            return 0;
        }//if
    }//for
    return 1;
}//find_text
/*
    Execute the command line: 'd'
    Delete lines the current line.
*/
void Document::delete_current_line()
{
    lines->erase(lines->begin()+(current-1));
    //cout<<"\n"<<(current-2)<<endl;
}//delete_current_line
/*
    Execute the command line: 'c'
    Adding lines instead of the current line.
    Stop adding when user input '.'
*/
int Document::replace_current_line()
{
    string line="";
    int temp = current -1;
    while(true)
    {
        getline(cin,line);
        if(line.compare(".") == 0)
            return 0;
        else
        {
            if(temp == (current -1))//If it is the first input line
                lines->at(temp)=line;
            else
            {
                lines->insert(lines->begin()+temp,line);
                current++;
                temp++;
            }//else
        }//else
    }//while
    return 1;
}//replace_current_line
/*
    Execute the command line: 'i'
    Adding lines before the current line.
    Stop adding when user input '.'
*/
int Document::add_lines_before()
{
    int temp = current-1;
    string line;
    while(true)
    {
        getline(cin,line);
        if(line.compare(".")==0)
        {
            current--;
            return 0;
        }
        else
            {
               lines->insert(lines->begin()+temp,line);
               temp++;
               current++;
            }//else
    }//while
    
    return 1;
}//add_lines_before

/*
    Execute the command line: 'a'
    Adding lines after the current line.
    Stop adding when user input '.'
*/
int Document::add_lines_after()
{
    int temp;
    if(lines->size()==0)
        temp = 0;
    else
        temp = current;
    string line;
    while(true)
    {
        getline(cin,line);
        if(line.compare(".")==0)
        {
            //current--;
            //cout<<"\n"<<current<<endl;
            return 0;
        }//if
        else
            {
               lines->insert(lines->begin()+temp,line);
               temp++;
               current++;
            }//else
    }//while
    
    return 1;
}//add_lines_after
/*
    Execute the command line: '$'
    Jumping to the last line
*/
void Document::move_forward_last_line()
{
    current = lines->size();
    //cout<<"\n"<<current<<endl;
}//move_forward_last_line

/*
    Execute the command line: '-1'
    Subtracting to the current line pointer 1 line 
*/
void Document::move_backward(string steps)
{
    int temp;
    stringstream s(steps);
    s >> temp;
    if(0>current-temp)
    {
        cerr << "Cannot execute +2 command.\nThere is less then "<<current<<" lines."<<endl;
        exit(0); 
    }
    current-=temp;
    //cout<<"\n"<<current<<endl;
}//move_backward_1_line
/*
    Execute the command line: '3'
    Set the current line pointer to line number 3 
*/
void Document::jump_to(string steps)
{
    int temp;
    stringstream s(steps);
    s >> temp;
    if(lines->size()<temp)
    {
        cerr << "Cannot execute 3 command.\nThere is less then 3 lines."<<endl;
        exit(0);
    }
    current = temp;
}//jump_to_line_3
/*
    Execute the command line: '+2'
    Adding to the current line pointer 2 lines 
*/
void Document::move_forward(string steps)
{
    int temp;
    stringstream s(steps);
    s >> temp;
    if(lines->size()<current+temp)
    {
        cerr << "Cannot execute +2 command.\nThere is less then "<<current<<" lines."<<endl;
        exit(0); 
    }
    current+=temp;
    //cout<<"\n"<<current<<endl;
}//move_forward_2_lines
/*
    Helping us to debug the current vector state
*/
void Document::print_vector()
{
    cout<<"printing the lines vector...\n"<<endl;
   for (auto i =lines->begin();i!=lines->end();++i)
    {
        cout << *i << "\n"; 
    }
}//print_lines
