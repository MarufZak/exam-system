#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"

using namespace std;
class Person
{
private:
    string name;
    string password;

public:
    bool check_user(string name, string password, string filename)
    {
        ifstream file(filename);

        string line;
        string name_query = "Name: ";
        string password_query = "Password: ";
        bool is_user_valid = false;
        while (getline(file, line))
        {
            if (line.find(name_query) != string::npos)
            {
                string found_name = line.substr(name_query.size());
                if (found_name == name)
                {
                    is_user_valid = true;
                }
            }
            else if (line.find(password_query) != string::npos && is_user_valid)
            {
                string found_password = line.substr(password_query.size());
                if (found_password == password)
                {
                    is_user_valid = true;
                    break;
                }
                else
                {
                    is_user_valid = false;
                }
            }
        }

        file.close();

        return is_user_valid;
    }

    void save_user(string name, string password, string filename)
    {
        ofstream file(filename, ios::app);
        file << "Name: " << name << endl;
        file << "Password: " << password << endl
             << "---" << endl;

        file.close();
    }

    string get_name()
    {
        return name;
    }
    string get_password()
    {
        return password;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_password(string password)
    {
        this->password = password;
    }
};
