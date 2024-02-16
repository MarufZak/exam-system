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

class Teacher : public Person
{
public:
    bool signup()
    {
        string name;
        string password;
        string subject;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your subject: ";
        cin >> subject;

        bool user_exists = check_user(name, password, "teachers.txt");
        if (user_exists)
        {
            cout << "Sorry, user with this name already exists!" << endl;
        }
        else
        {
            save_user(name, password, "teachers.txt");
            cout << "Teacher successfully created!" << endl;
        }

        return !user_exists;
    }

    bool login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool is_user_valid = check_user(name, password, "teachers.txt");

        if (is_user_valid)
        {
            set_name(name);
            set_password(password);
            clear();
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            clear();
            cout << "* Invalid credentials! *" << endl;
        }

        return is_user_valid;
    }

    void create_test()
    {
        ofstream file("test.txt", ios::app);

        string test_name;
        int questions_number;
        cout << "Test name: ";
        cin.ignore();
        getline(cin, test_name, '\n');
        cout << "Questions number: ";
        cin >> questions_number;

        file << "Test name: " << test_name << endl;
        for (int i = 1; i <= questions_number; i++)
        {
            string question_name;
            string variant_a, variant_b, variant_c;
            string correct_variant;
            cout << "Question #" << i << ": ";
            cin.ignore();
            getline(cin, question_name);

            cout << " a. ";
            getline(cin, variant_a);

            cout << " b. ";
            getline(cin, variant_b);

            cout << " c. ";
            getline(cin, variant_c);

        start:
            cout << "Correct answer (write variant): ";
            cin >> correct_variant;
            if (correct_variant != "a" && correct_variant != "b" && correct_variant != "c")
            {
                cout << "You should write a, b or c! \n";
                goto start;
            }
            file << "Question" << i << ": " << question_name << endl
                 << "a) " << variant_a << endl
                 << "b) " << variant_b << endl
                 << "c) " << variant_c << endl
                 << "Correct Answer: " << correct_variant << endl;
        }

        file << "---" << endl;

        cout << "Test successfully created!\n";

        file.close();
    }

    void create_essay()
    {
        ofstream file("essay.txt", ios::app);

        string essay_question;
        int min_size = 0;
        cout << "Write essay question: ";
        cin.ignore();
        getline(cin, essay_question);
        cout << "Write minimum size of essay: ";
        cin >> min_size;

        file << "Essay question: " << essay_question << endl;
        file << "Minimum size: " << min_size << endl
             << "---" << endl;

        cout << "Essay successfully created!\n";

        file.close();
    }

    void create_subjective()
    {
        ofstream file("subjective.txt", ios::app);

        string question;
        cout << "Write subjective question: ";
        cin.ignore();
        getline(cin, question);

        file << "Question: " << question << endl
             << "---" << endl;

        file.close();
    }

    void show_test_answers()
    {
        ifstream file("testAnswers.txt");

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void show_essay_answers()
    {
        ifstream file("essayAnswers.txt");


        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void show_subjective_answers()
    {
        ifstream file("subjectiveAnswers.txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
};
