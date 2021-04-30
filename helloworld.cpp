#include <iostream>
using std::string;

class AbstractEmployee//建立抽象化類型
{  
  virtual void AskForPromotion() = 0;//讓開發者可以調用該函式做自由設定行為；毋需理解其他程式內容，也可以任意調用
};

class Employee : AbstractEmployee //Employee繼承AbstractEmployee，使可以進入結構中。
{
  private://private access modifier 不允許外部修改；protected access modifier between private and public
    string Company;
    int Age;
  protected:
    string Name;
  public://public access modifier 公開可允許所有修改
    void setName(string name){//setter
      Name = name;
    }
    string getName(){//getter
      return Name;
    }
    void setCompany(string company){//setter
      Company = company;
    }
    string getCompany(){//getter
      return Company;
    }
    void setAge(int age){//setter
      if(age>=18)
        Age = age;
    }
    int getAge(){//getter
      return Age;
    }

    void IntroduceYourSelf()
    {
      std::cout << "Name - " << Name << std::endl;
      std::cout << "Company - " << Company << std::endl;
      std::cout << "Age - " << Age << "\n" << std::endl;
    };
    Employee(string name, string company, int age)
    {
      Name = name;
      Company = company;
      Age = age;
    };
    
    void AskForPromotion()//為提供AbstractEmployee虛擬類型進入結構的實現方法
    {
      if (Age>=30)
        std::cout << Name << " got promoted!" << std::endl;
      else
        std::cout << Name << ", sorry NO promotion for you!" << std::endl;
    }

};

class Developer : public Employee
{
  public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
      :Employee(name, company, age)
    {
      FavProgrammingLanguage = favProgrammingLanguage;
    }
    void favProgrammingLanguage()
    {
      std::cout << Name << " favorite programming language is " << FavProgrammingLanguage << std::endl;
    }
};

class Teacher : public Employee
{
  public:
    string Subject;
    Teacher(string name, string company, int age, string subject)
      :Employee(name, company, age)
    {
      Subject = subject;
    }
    void PrepareLesson()
    {
      std::cout << Name << " is preparing " << Subject << std::endl;
    }
};

int main()
{
  Employee employee1 = Employee("Emma Watson", "WB company", 30);
  Employee employee2 = Employee("RAKU", "DELTA", 28);

  employee1.AskForPromotion();//以類似觸控按鈕形式測試功能，使用者毋需知道程式內容即可產生結果
  employee2.AskForPromotion();

  Developer d = Developer("Emma Watson", "WB company", 30, "Python");
  Teacher t = Teacher("RAKU", "MY company", 28, "History");
  
  d.favProgrammingLanguage();
  d.AskForPromotion();
  t.PrepareLesson();
  t.AskForPromotion();
}