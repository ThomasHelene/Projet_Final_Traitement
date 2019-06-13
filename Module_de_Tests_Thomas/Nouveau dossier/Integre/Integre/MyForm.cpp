#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Integre::MyForm MyForm;
	System::Windows::Forms::Application::Run(%MyForm);
	




}
