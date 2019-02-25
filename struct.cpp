#include <stdio.h>

int Add(int a, int b) 
{
	return a + b;
}

int Substract(int a, int b) 
{
	return a - b;	
}

typedef struct Mate 
{
	int a;
	int b;
	Mate() 
	{
		a = b = 0;
	}
	Mate(int a, int b) 
	{
		this->a = a;
		this->b = b;	
	}
	void Set_A(int a) 
	{
		this->a = a;
	}
	void Set_B(int b) 
	{
		this->b = b;
	}
	int Get_A() 
	{
		return a;
	}
	int Get_B() 
	{
		return b;
	}
	int Add() 
	{
		return this->a + this->b;
	}
	int Substract()
	{
		return a - b;	
	}
} MatDas;



int main()
{
	int a = 10, b = 2; 
	
	printf("A = %d\n", a);
	printf("B = %d\n", b);
	
	printf("A + B = %d + %d = %d\n", a, b, Add(a, b));
	printf("A - B = %d - %d = %d\n", a, b, Substract(a, b));
	
	MatDas m;
	
	m.Set_A(20);
	m.Set_B(5);
	
	printf("A = %d\n", m.Get_A());
	printf("B = %d\n", m.Get_B());
	
	printf("A + B = %d + %d = %d\n", m.Get_A(), m.Get_B(), m.Add());
	printf("A - B = %d - %d = %d\n", m.Get_A(), m.Get_B(), m.Substract());
	
	MatDas *m2 = new MatDas(100, 10);
	
	printf("A = %d\n", m2->Get_A());
	printf("B = %d\n", m2->Get_B());
	
	printf("A + B = %d + %d = %d\n", m2->Get_A(), m2->Get_B(), m2->Add());
	printf("A - B = %d - %d = %d\n", m2->Get_A(), m2->Get_B(), m2->Substract());
	
	return 0;
}
