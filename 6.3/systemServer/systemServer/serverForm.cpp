#include "serverForm.h"
#include<iostream>
using namespace systemServer;
using namespace std;

[STAThread]



int main(array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::Run(gcnew serverForm());
	cout << "hello world" << endl;
	system("pause");
	return 0;
}