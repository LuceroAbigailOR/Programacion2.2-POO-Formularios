#include "MyForm.h"

using namespace System;
using namespace Windows::Forms;
using namespace Ejercicio2PC2;
void main() {
	//Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew Ejercicio2PC2::MyForm);
}
