#include <iostream>
using std::string;

class AbstractEmployee//建立抽象化類型
{  
  virtual void AskForPromotion() = 0;//讓開發者可以調用該函式做自由設定行為；毋需理解其他程式內容，也可以任意調用
};

class Employee : AbstractEmployee //Employee繼承AbstractEmployee抽象化類型，使可以進入private結構中。
{
  private://private access modifier 不允許外部修改；protected access modifier between private and public
    string Company;
    int Age;
  protected://將Name設置在protected使AskForPromotion可invoke
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
    
    void AskForPromotion()//為提供AbstractEmployee抽象化類型進入結構的實現方法
    {
      if (Age>=30)
        std::cout << Name << " got promoted!" << std::endl;
      else
        std::cout << Name << ", sorry NO promotion for you!" << std::endl;
    }
    virtual void Work()//添加虛擬化Work function，當invoke subclass沒有Work function時將執行該function；若invoke subclass時subclass有Work function可供執行，則會執行subclass Work function
    {
      std::cout << Name << " is checking email..." << std::endl;
    }
};

class Developer : public Employee//Developer繼承Employee，並設為public，使Developer在main function中可以invoke AskForPromotion
{
  public://將Developer設為public access modifier
    string FavProgrammingLanguage;//設定變數FavProgrammingLanguage
    Developer(string name, string company, int age, string favProgrammingLanguage)//設定要繼承Employee class及Developer class中另加的參數
      :Employee(name, company, age)//表示要繼承部分的參數
    {
      FavProgrammingLanguage = favProgrammingLanguage;//Developer class中要自行添加的參數
    }
    void favProgrammingLanguage()//新增function favProgrammingLanguage以在main function中 invoke
    {
      std::cout << Name << " favorite programming language is " << FavProgrammingLanguage << "." << std::endl;
    }
    void Work()//添加多態性Work function
    {
      std::cout << Name << " is writing " << FavProgrammingLanguage << "." << std::endl;
    }
};

class Teacher : public Employee//Teacher繼承Employee，並設為public，使Teacher在main function中可以invoke AskForPromotion
{
  public://將Teacher設為public access modifier
    string Subject;//設定變數Subject
    Teacher(string name, string company, int age, string subject)//設定要繼承Employee class及Teacher class中另加的參數
      :Employee(name, company, age)//表示要繼承部分的參數
    {
      Subject = subject;//Teacher class中要自行添加的參數
    }
    void PrepareLesson()//新增function PrepareLesson以在main function中 invoke
    {
      std::cout << Name << " is preparing " << Subject << "." << std::endl;
    }
    void Work()//添加多態性Work function
    {
      std::cout << Name << " is teaching " << Subject << "." << std::endl;
    }
};

int main()//主程式
//The most common use of polymorphism is when a parent class reference is used to refer to a child class object
{
  Employee employee1 = Employee("Emma Watson", "WB company", 30);
  Employee employee2 = Employee("RAKU", "DELTA", 28);//初始功能，無繼承有抽象，並設定Employee參數

  Developer d = Developer("Emma Watson", "WB company", 30, "Python");//set Developer class argument
  Teacher t = Teacher("RAKU", "MY company", 28, "History");//set Teacher class argument

  Employee *e1 = &d;//pointer is going to hold and reference of Developer
  Employee *e2 = &t;//pointer is going to hold and reference of Teacher

  employee1.AskForPromotion();//employee1 invoke AskForPromotion function
  employee2.AskForPromotion();//employee2 invoke AskForPromotion function
  std::cout << "\n" << std::endl;
  d.favProgrammingLanguage();//d invoke favProgrammingLanguage function
  d.AskForPromotion();//d invoke AskForPromotion function
  std::cout << "\n" << std::endl;
  t.PrepareLesson();//t invoke PrepareLesson function
  t.AskForPromotion();//t invoke AskForPromotion function
  std::cout << "\n" << std::endl;
  e1->Work();//access member using a pointer to get it work
  e2->Work();
  std::cout << "\n" << std::endl;
}