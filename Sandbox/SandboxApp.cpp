#include<Pip.h>


class Sandbox : public Pip::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};


Pip::Application* Pip::CreateApplication()
{
	return new Sandbox(); 
}