#include <iostream>
#include <string>
#include <fstream>
#include "Classes.h"

using namespace std;

int main()
{
    string app_state = "choosing_role";
    Teacher teacher;
    Student student;

    while (true)
    {
        if (app_state == "choosing_role")
        {
            int role;
            cout << "Choose a role: \n1. Teacher.\n2. Student.\n3. Exit\n>";
            cin >> role;
            switch (role)
            {
            case 1:
                app_state = "teacher_auth";
                clear();
                break;
            case 2:
                app_state = "student_auth";
                clear();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "* Invalid credentials! *" << endl;
                break;
            }
        }

        if (app_state == "teacher_auth")
        {
            int teacher_action;
            cout << "** Teacher **\nChoose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> teacher_action;
            switch (teacher_action)
            {
            case 1:
                if (teacher.signup() == 1)
                {
                    app_state = "teacher_action";
                    clear();
                }
                break;
            case 2:
                if (teacher.login() == 1)
                {
                    app_state = "teacher_action";
                    clear();
                }
                break;
            case 3:
                app_state = "choosing_role";
                clear();
                break;
            default:
                cout << "* Invalid credentials! *" << endl;
                break;
            }
        }

        if (app_state == "student_auth")
        {
            int student_action;
            cout << "** Student **\nChoose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> student_action;
            switch (student_action)
            {
            case 1:
                if (student.signup() == 1)
                {
                    app_state = "student_action";
                }
                break;
            case 2:
                if (student.login() == 1)
                {
                    app_state = "student_action";
                }
                break;
            case 3:
                app_state = "choosing_role";
                clear();
                break;
            default:
                cout << "* Invalid credentials! *" << endl;
                break;
            }
        }

        if (app_state == "teacher_action")
        {
            int teacher_action;
            cout << "** Teacher ** \nChoose option: \n1. Create multiple choice test.\n2. Create essay test.\n3. Create subjective question.\n4. Show essay answers.\n5. Show subjective questions answers.\n6. Show test answers.\n7. Logout\n>";
            cin >> teacher_action;
            switch (teacher_action)
            {
            case 1:
                teacher.create_test();
                clear();
                break;
            case 2:
                teacher.create_essay();
                clear();
                break;
            case 3:
                teacher.create_subjective();
                break;
            case 4:
                teacher.show_essay_answers();
                break;
            case 5:
                teacher.show_subjective_answers();
                break;
            case 6:
                teacher.show_test_answers();
                break;
            case 7:
                app_state = "choosing_role";
                break;
            default:
                cout << "* Invalid credentials! *" << endl;
                break;
            }
        }

        if (app_state == "student_action")
        {
            int student_action;
            cout << "** Student ** Choose option:\n1. Go to tests.\n2. Go to essays.\n3. Go to subjective questions.\n4. Logout.\n>";
            cin >> student_action;

            switch (student_action)
            {
            case 1:
                student.showTests();
                break;
            case 2:
                student.showEssays();
                break;
            case 3:
                student.showSubjective();
                break;
            case 4:
                app_state = "choosing_role";
                break;
            default:
                cout << "* Invalid credentials! *" << endl;
                break;
            }
        }
    }

    return 0;
}