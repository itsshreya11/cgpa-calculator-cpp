#include<iostream>
#include<vector>
using namespace std;
class subject{
  public:
  string subjectname;
  int credit;
  float gradepoint;

  subject(string name, int cr, float gr){
    subjectname=name;
    credit=cr;
    gradepoint=gr;

  }
};
class student{
    public:
    string name;
    vector<subject>subjects;

    student(string studentname){
        name= studentname; 
    }

  void addsubject(string subjectname, int credit, float gradepoint)
  {
    subject newsubject(subjectname,credit ,gradepoint);
    subjects.push_back(newsubject);
  }
  float calculatecgpa()
  {
    int totalcredit=0;
    float weightgradepoint=0;
    for(const subject & subject:subjects)
    {
      totalcredit+=subject.credit;
      weightgradepoint+=subject.credit*subject.gradepoint;
    }
    return (totalcredit>0)?(weightgradepoint/totalcredit):0;
  }
  void displaycgpa()
  {
    cout<<"student name :"<<name<<endl;
    float cgpa=calculatecgpa();
    cout<<"CGPA :"<<cgpa<<endl;
  }
  // void addsubject(string subjectname,int credit,float gradepoint);
};

int main(){
    string studentname;
    int numsub;

    cout<<"enter student's name:";
    getline(cin,studentname);

    cout<<"enter the number of subjects :";
    cin>>numsub;
    student student(studentname);

     for(int i=0; i<numsub; i++){
        string subjectname;
        int credit;
        float gradepoint;

        cout<<"enter the subject's name:";
        cin.ignore();
        getline(cin,subjectname);

        cout<<"enter the credit:";
        cin>>credit;

        cout<<"enter the gradepoint:";
        cin>>gradepoint;
        student.addsubject(subjectname, credit, gradepoint);
  
     }
     student.displaycgpa();
     return 0;
}