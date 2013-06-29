#include <iostream.h>

class Animal
{
public:
	Animal(int height, int wight)
	{
		cout<<"animal construct"<<endl;
	}
	~Animal()
	{
		cout<<"animal diconstruct"<<endl;
	}

	void eat()
	{
		cout<<"animal eat"<<endl;
	}
protected:
	void sleep()
	{
		cout<<"animal sleep"<<endl;
	}
private:
	void breathe()
	{
		cout<<"animal breathe"<<endl;
	}
};

class Fish : public Animal
{
public:
	Fish():Animal(400,30)
	{
		cout<<"Fish construct"<<endl;
	}
	~Fish()
	{
		cout<<"Fish diconstruct"<<endl;
	}
	void breathe()
	{
		cout<<"Fish bubble"<<endl;
	}
};

void main()
{
//	Animal am;
//	am.eat();
//	am.sleep();

	Fish fh;
	fh.breathe();
//	fh.eat();
}