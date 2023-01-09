#include "SetPlayer.h"

using namespace HW04;

[STAThreadAttribute]
int main(array<System::String^ >^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew SetPlayer());
	return 0;
}