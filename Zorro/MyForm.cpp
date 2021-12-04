#include "MyForm.h"

using namespace System;
using namespace Windows::Forms;
using namespace SimulacroPC2;
void main() {
	//Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew SimulacroPC2::MyForm);
}
