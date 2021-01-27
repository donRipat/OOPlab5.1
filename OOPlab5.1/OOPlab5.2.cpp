#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string sound;

public:
	Animal()
	{
		sound = "Unknown sound";
		cout << "Animal()\n";
	}

	virtual ~Animal()
	{
		cout << "~Animal()\n";
	}

	virtual string Sound()
	{
		return sound;
	}

	virtual string Class_name()
	{
		return "Animal";
	}

	//	overlapped method
	void Met1()
	{
		cout << "Animal::Met1()\n";
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		sound = "Mew";
		cout << "Cat()\n";
	}

	~Cat()
	{
		cout << "~Cat()\n";
	}

	string Sound()
	{
		return sound;
	}

	string Class_name()
	{
		return "Cat";
	}

	//	overlapping method
	void Met1()
	{
		cout << "Cat::Met1();\n";
	}

	void Catch()
	{
		cout << "Catch()\n";
	}
};

class Dog : public Animal
{
public:
	Dog()
	{
		sound = "Woof";
		cout << "Dog()\n";
	}

	~Dog()
	{
		cout << "~Dog\n";
	}

	string Sound()
	{
		return sound;
	}

	string Class_name()
	{
		return "Dog";
	}

	void Chase()
	{
		cout << "Chase()\n";
	}
};

class WildDog : public Dog
{
public:
	WildDog()
	{
		sound = "GRRR";
		cout << "WildDog()\n";
	}

	~WildDog()
	{
		cout << "~WildDog\n";
	}

	string Sound()
	{
		return sound;
	}

	string Class_name()
	{
		return "WildDog";
	}
};

int main()
{
	//	calling constructors and virtual methods
	const int n = 10;
	Animal *a[n];
	for (int i = 0; i < n; ++i)
	{
		cout << i << '\n';
		int r = rand() % 3;
		if (!r)
			a[i] = new Animal();
		else if (r == 1)
			a[i] = new Cat();
		else
			a[i] = new Dog();
		cout << a[i]->Sound() << '\n';
	}

	//	calling destructors
	for (int i = 0; i < n; ++i)
	{
		cout << i << '\n';
		delete a[i];
	}

	getchar();
	system("cls");

	//	calling overlapped and overlapping methods
	Animal *a0 = new Animal();
	a0->Met1();
	cout << '\n';

	Animal *a1 = new Cat();
	a1->Met1();
	cout << '\n';

	Cat *a2 = new Cat();
	a2->Met1();
	cout << '\n';

	getchar();
	system("cls");

	//	checking if object belongs to class
	for (int i = 0; i < n; ++i)
	{
		cout << i << '\n';
		int r = rand() % 4;
		if (!r)
			a[i] = new Animal();
		else if (r == 1)
			a[i] = new Cat();
		else if (r == 2)
			a[i] = new Dog();
		else
			a[i] = new WildDog();
	}
	cout << "\n\n";

	//	determining who is a[i]
	for (int i = 0; i < n; ++i)
	{
		if (a[i]->Class_name() == "Cat")
		{
			cout << "a[" << i << "] is a " << a[i]->Class_name()
				<< '\n';
		}
		else if (a[i]->Class_name() == "Dog")
		{
			cout << "a[" << i << "] is a " << a[i]->Class_name()
				<< '\n';
		}
		else if (a[i]->Class_name() == "WildDog")
		{
			cout << "a[" << i << "] is a " << a[i]->Class_name()
				<< '\n';
		}
		else
		{
			cout << "a[" << i << "] is an " << a[i]->Class_name()
				<< '\n';
		}
	}

	//	unsafe cast
	for (int i = 0; i < n; ++i)
	{
		((Cat*)a[i])->Catch();
	}
}
