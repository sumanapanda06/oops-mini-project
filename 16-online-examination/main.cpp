#include <iostream>
#include <string>
#include <vector>

#include "../student_info.h"

using namespace std;

// Abstract base class
class Question
{
protected:
    string questionText;
    int marks;

public:
    Question(string q, int m)
    {
        questionText = q;
        marks = m;
    }

    virtual int evaluate(string answer) = 0;

    void displayQuestion()
    {
        cout << questionText << endl;
    }

    int getMarks()
    {
        return marks;
    }
};

// Multiple Choice Question
class MCQ : public Question
{
private:
    string correctAnswer;

public:
    MCQ(string q, int m, string ans)
        : Question(q, m)
    {
        correctAnswer = ans;
    }

    int evaluate(string answer)
    {
        if (answer == correctAnswer)
            return marks;
        else
            return 0;
    }
};

// True/False Question
class TrueFalse : public Question
{
private:
    string correctAnswer;

public:
    TrueFalse(string q, int m, string ans)
        : Question(q, m)
    {
        correctAnswer = ans;
    }

    int evaluate(string answer)
    {
        if (answer == correctAnswer)
            return marks;
        else
            return 0;
    }
};

// Descriptive Question
class Descriptive : public Question
{
private:
    string keyword;

public:
    Descriptive(string q, int m, string k)
        : Question(q, m)
    {
        keyword = k;
    }

    int evaluate(string answer)
    {
        if (answer == keyword)
            return marks;
        else
            return marks / 2;
    }
};

// Programming Question
class Programming : public Question
{
private:
    string expectedOutput;

public:
    Programming(string q, int m, string output)
        : Question(q, m)
    {
        expectedOutput = output;
    }

    int evaluate(string answer)
    {
        if (answer == expectedOutput)
            return marks;
        else
            return 0;
    }
};

// Template function
template <class T>
void displayScore(T score)
{
    cout << "Final Score : " << score << endl;
};

// Exam class
class Exam
{
private:
    vector<Question*> questions;

public:
    Exam(int size)
    {
        questions.resize(size);
    }

    void addQuestion(int index, Question* q)
    {
        questions[index] = q;
    }

    Question* getQuestion(int index)
    {
        return questions[index];
    }

    int getNumberOfQuestions()
    {
        return questions.size();
    }
};

// Student class
class Student
{
private:
    string name;
    int totalMarks;

public:
    Student(string n)
    {
        name = n;
        totalMarks = 0;
    }

    void attemptExam(Exam &exam)
    {
        string answer;

        cout << "\n========== EXAM ==========\n";

        for (int i = 0; i < exam.getNumberOfQuestions(); i++)
        {
            cout << "\nQuestion " << i + 1 << ":\n";

            exam.getQuestion(i)->displayQuestion();

            cout << "Enter Answer: ";
            cin >> answer;

            totalMarks = totalMarks +
                         exam.getQuestion(i)->evaluate(answer);
        }
    }

    void displayResult()
    {
        cout << "\n========== RESULT ==========\n";
        cout << "Student Name : " << name << endl;

        displayScore(totalMarks);
    }
};

int main()
{
    cout << "ONLINE EXAMINATION SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    // Creating different question objects
    MCQ q1(
        "Which language is used for OOP? (C++/HTML)",
        2,
        "C++"
    );

    TrueFalse q2(
        "C++ supports inheritance. (True/False)",
        2,
        "True"
    );

    Descriptive q3(
        "Write the main OOP concept used for hiding data:",
        3,
        "Encapsulation"
    );

    Programming q4(
        "What is the output of 5 + 5?",
        3,
        "10"
    );

    // Creating exam
    Exam exam(4);

    exam.addQuestion(0, &q1);
    exam.addQuestion(1, &q2);
    exam.addQuestion(2, &q3);
    exam.addQuestion(3, &q4);

    // Registering student
    Student student("Sikhsha");

    // Student attempts exam
    student.attemptExam(exam);

    // Generate result
    student.displayResult();

    return 0;
}