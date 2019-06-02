#include <iostream>
using namespace std;
class UniversityStaff {
   public:
    UniversityStaff();
    UniversityStaff(string);
    UniversityStaff(const UniversityStaff&);

    string getName() const { return this->name; };
    UniversityStaff& operator=(const UniversityStaff&);
    friend istream& operator>>(istream&, UniversityStaff&);
    friend ostream& operator<<(ostream&, const UniversityStaff&);

   private:
    string name;
};

class Student {
   public:
    Student();
    Student(string, string, string);
    Student(string, string, UniversityStaff&);
    Student(const Student&);

    void setRegistrationNumber(string theRegistrationNumber) { this->registrationNumber = theRegistrationNumber; }
    void setUniversityName(string theUntversityname) { this->universityName = theUntversityname; }
    void setProctor(const UniversityStaff& source) { this->proctor = UniversityStaff(source); }
    string getRegistrationNumber() const { return this->registrationNumber; }
    string getUniversityName() const { return this->universityName; }
    UniversityStaff getProctor() const { return this->proctor; }

    Student& operator=(const Student&);
    friend ostream& operator<<(ostream&, const Student&);

   private:
    string registrationNumber;
    string universityName;
    UniversityStaff proctor;
};

class ScienceStudent : public Student {
   public:
    ScienceStudent();
    ScienceStudent(string, string, string, string, string);
    ScienceStudent(string, string, const Student&);
    ScienceStudent(const ScienceStudent&);

    void setStudentType(string thetype) { this->studentType = thetype; }
    void setDiscipline(string theDiscipline) { this->discipline = theDiscipline; }
    string getStudentType() const { return this->studentType; }
    string getDiscipline() const { return this->discipline; }

    ScienceStudent& operator=(const ScienceStudent&);
    friend ostream& operator<<(ostream&, const ScienceStudent&);

   private:
    string studentType;  //undergraduate or postgraduate course
    string discipline;   //additional properties science discipline
};

int main() {
    Student Test1("B123012345", "NSYSU", "John"), Test2;
    cout << "Student Test1(constructed) Data: " << Test1 << endl;

    Test2 = Test1;
    cout << "Student Test2(assigned) Data: " << Test2 << endl;

    Student Test3 = Test1;
    cout << "Student Test3(copy constructed) Data: " << Test3 << endl;

    ScienceStudent sciTest1("Curry", "NTU", "C222012345", "undergraduate", "Math"), sciTest2;
    cout << "ScienceStudent Test1(constructed) Data: " << sciTest1 << endl;

    sciTest2 = sciTest1;
    cout << "ScienceStudent Test2(assigned) Data: " << sciTest2 << endl;

    ScienceStudent sciTest3 = sciTest1;
    cout << "ScienceStudent Test3(copy constructed) Data: " << sciTest3 << endl;
    return 0;
}

UniversityStaff::UniversityStaff() { this->name = ""; }
UniversityStaff::UniversityStaff(string theName) : name(theName) {}
UniversityStaff::UniversityStaff(const UniversityStaff& source) : name(source.name) {}

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& source) {
    if (this != &source)
        this->name = source.getName();
    return *this;
}
istream& operator>>(istream& instream, UniversityStaff& destination) {
    instream >> destination.name;
    return instream;
}
ostream& operator<<(ostream& outstream, const UniversityStaff& source) {
    outstream << source.getName();
    return outstream;
}

Student::Student() : registrationNumber(""), universityName("") { this->proctor = UniversityStaff(); }
Student::Student(string registration, string theUniversityName, string theStudentName)
    : registrationNumber(registration), universityName(theUniversityName) { proctor = UniversityStaff(theStudentName); }
Student::Student(string registration, string theUniversityName, UniversityStaff& source) {
    this->registrationNumber = registration;
    this->universityName = theUniversityName;
    this->proctor = source;
}
Student::Student(const Student& source) {
    this->registrationNumber = source.registrationNumber;
    this->universityName = source.universityName;
    this->proctor = UniversityStaff(source.proctor);
}

Student& Student::operator=(const Student& source) {
    if (this != &source) {
        this->registrationNumber = source.registrationNumber;
        this->universityName = source.universityName;
        this->proctor = UniversityStaff(source.proctor);
    }
    return *this;
}
ostream& operator<<(ostream& outstream, const Student& source) {
    outstream << endl
              << source.getUniversityName() << endl
              << source.getRegistrationNumber() << endl
              << source.getProctor() << endl;
    return outstream;
}

ScienceStudent::ScienceStudent() : discipline(""), studentType(""), Student() {}
ScienceStudent::ScienceStudent(string theStudentName, string theUniversityName, string theRegistrationNumber, string theStudentType, string theDiscipline)
    : Student(theRegistrationNumber, theUniversityName, theStudentName) {
    this->studentType = theStudentType;
    this->discipline = theDiscipline;
}
ScienceStudent::ScienceStudent(string theStudentType, string theDiscipline, const Student& obj) {
    this->setUniversityName(obj.getUniversityName());
    this->setRegistrationNumber(obj.getRegistrationNumber());
    this->studentType = theStudentType;
    this->discipline = theDiscipline;
    this->setProctor(obj.getProctor());
}
ScienceStudent::ScienceStudent(const ScienceStudent& source) {
    this->setUniversityName(source.getUniversityName());
    this->setRegistrationNumber(source.getRegistrationNumber());
    this->setStudentType(source.getStudentType());
    this->setDiscipline(source.getDiscipline());
    this->setProctor(source.getProctor());
}
ScienceStudent& ScienceStudent::operator=(const ScienceStudent& source) {
    if (this != &source) {
        this->setUniversityName(source.getUniversityName());
        this->setRegistrationNumber(source.getRegistrationNumber());
        this->setStudentType(source.getStudentType());
        this->setDiscipline(source.getDiscipline());
        this->setProctor(source.getProctor());
    }
    return *this;
}
ostream& operator<<(ostream& outstream, const ScienceStudent& source) {
    outstream << endl
              << source.getUniversityName() << endl
              << source.getRegistrationNumber() << endl
              << source.getProctor() << endl
              << source.getDiscipline() << endl
              << source.getStudentType() << endl;
    return outstream;
}