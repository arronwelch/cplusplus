// The test5.cpp Program

/* test5.cpp -- Inheritance */

#include <iostream>

using std::string;

class AbstractEmployee {
	virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{
private:// defualt
//	string Name;
	string Company;
	int Age;
protected:// derived class can access this member
	string Name;

public:
	void setName(string name)
	{
		Name = name;
	}
	string getName(void)
	{
		return Name;
	}
	void setCompany(string company)
	{
		Company = company;
	}
	string getCompany(void)
	{
		return Company;
	}
	void setAge(int age)
	{
		if ( age >= 18 )
		{
			Age = age;
		}
	}
	int getAge(void)
	{
		return Age;
	}
	
	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << "\n" << std::endl;
	}
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
	void AskForPromotion(void){
		if(Age > 30)
		{
			std::cout << Name << " got promoted!" << std::endl;
		}
		else
		{
			std::cout << Name << ", sorry No promotion for you!" << std::endl;
		}
	}
protected:
};

class Developer:public Employee {
private:
	string FavProgrammingLanguage;
public:
	Developer(string name, string company, int age, string favProgrammingLanguage)
	:Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	void FixBug(void) {
//		std::cout << getName() << " fixed bug using " << FavProgrammingLanguage << std::endl;
		std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
	}
};

class Teacher:public Employee {
public:
	string Subject;
	void PrepareLesson() {
		std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
	}
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age) 
	{
		Subject = subject;
	}
};

int main(void)
{
	Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");
	d.FixBug();
	d.AskForPromotion();

	Teacher t = Teacher("Jack", "Cool School", 35, "History");
	t.PrepareLesson();
	t.AskForPromotion();

	return 0;
}
