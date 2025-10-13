#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

using std::cout, std::endl, std::ifstream, std::string, std::vector;

class Student {
private:
    string id;
    float studyHours, sleepHours, attendanceP, fScore;
    int preScore;


public:
    bool operator<(const Student& obj) const {
        return (this->getstudyHours() < obj.getstudyHours());
    }

    bool operator>(const Student& obj) const {
        return (this->getstudyHours() > obj.getstudyHours());
    }

    bool operator<=(const Student& obj) const {
        return (this->getstudyHours() <= obj.getstudyHours());
    }

    bool operator>=(const Student& obj) const {
        return (this->getstudyHours() >= obj.getstudyHours());
    }

    bool operator==(const Student& obj) const {
        return (this->getstudyHours() == obj.getstudyHours());
    }

    //Constructors
    Student() {
        id = " ";
        sleepHours = 0.0;
        attendanceP = 0.0;
        preScore = 0;
        fScore = 0.0;
    }

    Student(string id, float studyHours,
        float sleepHours, float attendanceP,
        int preScore, float fScore) {
        this->id = id;
        this->studyHours = studyHours;
        this->sleepHours = sleepHours;
        this->attendanceP = attendanceP;
        this->preScore = preScore;
        this->fScore = fScore;
    }

    std::string getID() const {
        return id;
    }

    void setID(string id) {
        this->id = id;
    }

    float getstudyHours() const {
        return studyHours;
    }

    void setstudyHours(float studyHours) {
        this->studyHours = studyHours;
    }

    float getsleepHours() const {
        return sleepHours;
    }

    void setsleepHours(float sleepHours) {
        this->sleepHours = sleepHours;
    }

    float getAttendance() const {
        return attendanceP;
    }

    void setAttendance(float attendanceP) {
        this->attendanceP = attendanceP;
    }

    int getpreScore() const {
        return preScore;
    }

    void setpreScore(int preScore) {
        this->preScore = preScore;
    }

    float getfScore() const {
        return fScore;
    }

    void setfScore(float fScore) {
        this->fScore = fScore;
    }
};

bool getDataFromFile(vector<Student>& students) {
    ifstream fileIn;
    fileIn.open("../student_scores_extended.csv");
    if (fileIn) {
        // Declare vars to be read in
        string header, id;
        float studyHours, sleepHours,
        attendanceP, fScore;
        int preScore;
        char comma;

        // Read in header line
        getline(fileIn, header);
        // cout << header << endl;
        while (fileIn && fileIn.peek() != EOF) {

            getline(fileIn, id, ',');
            // cout << id << endl;

            fileIn >> studyHours;
            fileIn >> comma;
            // cout << studyHours << endl;

            fileIn >> sleepHours;
            fileIn >> comma;
            // cout << sleepHours << endl;

            fileIn >> attendanceP;
            fileIn >> comma;
            // cout << attendanceP << endl;

            fileIn >> preScore;
            fileIn >> comma;
            // cout << preScore << endl;

            fileIn >> fScore;
            // cout << fScore << endl;

            students.push_back(Student(id, studyHours, sleepHours, attendanceP, preScore, fScore));
        }

        // cout << students[0].getID() << endl;
        // cout << students.size();
        fileIn.close();
    return true;
    } else {
        return false;
    }

}

float bestStudyHours(vector<Student>& students)
{
    float bStudyHours = 0.0;

    if (students.empty()) {
        cout << "No students loaded!" << endl;
        return 0.0f;
    }

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getstudyHours() > bStudyHours)
            bStudyHours = students[i].getstudyHours();
    }

    return bStudyHours;
}

float totalstudyHours(vector<Student>& students) {
    float totalHours = 0.0;

    for (int i = 0; i < students.size(); i++)
        totalHours += students[i].getstudyHours();

    return totalHours;
}

float avgstudyHours(vector<Student>& students) {
    float totalHours = 0.0;

    for (int i = 0; i < students.size(); i++)
        totalHours += students[i].getstudyHours();
    return totalHours / students.size();
}

float minstudyHours(vector<Student>& students) {
    float minstudyHours = 1000.0;

    for (int i = 0; i < students.size(); i++)
        if (students[i].getstudyHours() < minstudyHours)
            minstudyHours = students[i].getstudyHours();
    return minstudyHours;
}



#endif //LECTURER_H
