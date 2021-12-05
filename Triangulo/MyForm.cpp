#include "MyForm.h"

using namespace System;
using namespace Windows::Forms;
using namespace S9Ejercicio2;

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew S9Ejercicio2::MyForm);
}
