/*
    Author: ~Michael Perry~
    Description: implementation of editor header class
*/
#include "Editor.h"

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}


int Editor::loop()
{

    string command;
    while(true)
    {
        getline(cin,command);
        if(isNumber(command) == true)
            dc->jump_to(command);
        else if(command.at(0)=='+' && isNumber(command.substr(1)))
            dc->move_forward(command.substr(1));
        else if(command.at(0)=='-' && isNumber(command.substr(1)))
            dc->move_backward(command.substr(1));
        else if(command.compare("$")==0)
            dc->move_forward_last_line();
        else if(command.compare("a")==0)
            dc->add_lines_after();
        else if(command.compare("i")==0)
            dc->add_lines_before();
        else if(command.compare("c")==0)
            dc->replace_current_line();
        else if(command.compare("d")==0)
            dc->delete_current_line();
        else if(command.at(0)=='/')
            {
                size_t end = command.find('/',1);
                if(end == string::npos)
                    {
                        cout<<"?"<<endl;
                        break;
                    }//if
                dc->find_text(command.substr(1,end-1));
            }//else if
        else if(command.at(0)=='s')
            {
                size_t end1 = command.find('/',2);
                if(end1 == string::npos)
                    {
                        cout<<"?"<<endl;
                    }//if
                string old_str = command.substr(2,end1-2);
                size_t end2 = command.find('/',end1+1);
                if(end2 == string::npos)
                    {
                        cout<<"?"<<endl;
                    }//if
                string new_str = command.substr(end1+1,end2-end1-1);
                dc->replace_current_old_with_new(old_str,new_str);
            }//else if
        else if(command.compare("j")==0)
            dc->add_following_lines();
        else if(command[0]=='w')
        {
            if(command[1]!=' ')
            {
                cout<<"?"<<endl;
            }//if
            string file_name = command.substr(2);
            dc->save_to_file(file_name);
        }//else if
        else if(command.compare("q")==0)
        {
            break;
        }//else if
    }//while

    
}//loop