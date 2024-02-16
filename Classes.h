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

class Student : public Person
{
public:
    bool signup()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool student_exists = check_user(name, password, "students.txt");
        if (student_exists)
        {
            cout << "Sorry, such student already exists!";
        }
        else
        {
            save_user(name, password, "students.txt");
            cout << "Student successfully created!" << endl;
        }

        return !student_exists;
    }

    bool login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool is_user_valid = check_user(name, password, "students.txt");

        if (is_user_valid)
        {
            set_name(name);
            set_password(password);
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            clear();
            cout << "* Invalid credentials! *" << endl;
        }

        return is_user_valid;
    }

    void showTests()
    {
        ifstream file("test.txt");
        ofstream answersFile("testAnswers.txt", ios::app);

        string line;
        string tests_found[10] = {};
        int tests_found_num = 0;
        while (getline(file, line))
        {
            string query = "Test name: ";
            if (line.find(query) != string::npos)
            {
                string test_name = line.substr(query.size());
                tests_found[tests_found_num] = test_name;
                tests_found_num += 1;
            }
        }

        file.clear();
        file.seekg(0);

        cout << "Choose a test: " << endl;
        int choosen_test_num;
        for (int i = 0; i < tests_found_num; i++)
        {
            cout << " " << i << ". " << tests_found[i] << endl;
        }
        cout << ">";
        cin >> choosen_test_num;
        string choosen_test_name = tests_found[choosen_test_num];
        int available_points = 0;
        int points = 0;

        while (getline(file, line))
        {
            string query = "Test name: ";
            if (line.find(query) != string::npos)
            {
                string test_name = line.substr(query.size());
                if (test_name == choosen_test_name)
                {
                    cout << test_name << endl
                         << choosen_test_name << endl;
                    string in_line;
                    string correct_answer;
                    string answer;
                    int answer_num = 0;
                    while (getline(file, in_line))
                    {
                        string correct_answer_query = "Correct Answer: ";
                        if (in_line.find(correct_answer_query) != string::npos)
                        {
                            correct_answer = in_line.substr(correct_answer_query.size());
                            cout << "Write your answer: ";
                            cin >> answer;
                            if (answer == correct_answer)
                            {
                                points += 1;
                            }
                            available_points += 1;

                            cout << "Answer recorded!" << endl;
                        }
                        else if (in_line.find("---") != string::npos)
                        {
                            break;
                        }
                        else
                        {
                            cout << in_line << endl;
                        }
                    }
                }
            }
        }

        answersFile << "Name: " << Person::get_name() << endl;
        answersFile << "Test name: " << choosen_test_name << endl;
        answersFile << "Points: " << points << "/" << available_points << endl
                    << "---" << endl;

        answersFile.close();
        file.close();
    }

    void showEssays()
    {
        ifstream essay_file("essay.txt");
        ofstream essay_answers_file("essayAnswers.txt", ios::app);

        string line;

        essay_file.clear();
        essay_file.seekg(0);

        string essays_found[5][5] = {};
        int essays_found_num = 0;

        while (getline(essay_file, line))
        {
            string question_query = "Essay question: ";
            string size_query = "Minimum size: ";

            if (line.find(question_query) != string::npos)
            {
                string question = line.substr(question_query.size());
                essays_found[essays_found_num][0] = question;
                essays_found_num += 1;
            }
            else if (line.find(size_query) != string::npos)
            {
                string size = line.substr(size_query.size());
                essays_found[essays_found_num - 1][1] = size;
            }
        }

        essay_file.clear();
        essay_file.seekg(0);

        cout << "Choose an essay: " << endl;
        int choosen_essay_num;
        for (int i = 0; i < sizeof(essays_found) / sizeof(essays_found[0]); i++)
        {
            cout << " " << i << ". " << essays_found[i][0] << endl;
        }
        cout << ">";
        cin >> choosen_essay_num;
        string choosen_essay[2];
        choosen_essay[0] = essays_found[choosen_essay_num][0];
        choosen_essay[1] = essays_found[choosen_essay_num][1];

    essay_start:
        string essay_text;
        string comment;
        cout << "Write an essay (At least " << stoi(choosen_essay[1]) << " characters): " << endl;
        cin.ignore();
        getline(cin, essay_text);
        cout << "Comments: ";
        cin.ignore();
        getline(cin, comment);
        if (essay_text.size() < stoi(choosen_essay[1]))
        {
            cout << "Essay myst be at least " << choosen_essay[1] << " characters!" << endl;
            goto essay_start;
        }
        else
        {
            essay_answers_file << "Name: " << Person::get_name() << endl;
            essay_answers_file << "Answer: " << essay_text << endl;
            essay_answers_file << "Comment: " << comment << endl
                               << "---" << endl;

            cout << "Answer recorded!" << endl;
        }

        essay_file.close();
        essay_answers_file.close();
    }

    void showSubjective()
    {
        ifstream subjective_file("subjective.txt");
        ofstream subjective_answers_file("subjectiveAnswers.txt", ios::app);

        string subjectives_found[5] = {};
        int subjectives_found_num = 0;

        string line;
        while (getline(subjective_file, line))
        {
            string question_query = "Question: ";

            if (line.find(question_query) != string::npos)
            {
                string question = line.substr(question_query.size());
                subjectives_found[subjectives_found_num] = question;
                subjectives_found_num += 1;
            }
        }

        subjective_file.clear();
        subjective_file.seekg(0);

        cout << "Choose a question: " << endl;
        int choosen_question_num;
        for (int i = 0; i < sizeof(subjectives_found) / sizeof(subjectives_found[0]); i++)
        {
            if (subjectives_found[i].size() == 0)
            {
                break;
            }
            cout << " " << i << ". " << subjectives_found[i] << endl;
        }
        cout << ">";
        cin >> choosen_question_num;

    question_start:
        string answer;
        cout << "Write an answer: ";
        cin.ignore();
        getline(cin, answer);
        if (answer.size() == 0)
        {
            cout << "Answer cannot be empty!" << endl;
            goto question_start;
        }
        else
        {
            subjective_answers_file << "Name: " << Person::get_name() << endl;
            subjective_answers_file << "Question: " << subjectives_found[choosen_question_num] << endl;
            subjective_answers_file << "Answer: " << answer << endl
                                    << "---" << endl;
            cout << "Answer recorded!" << endl;
        }

        subjective_file.close();
        subjective_answers_file.close();
    }
};