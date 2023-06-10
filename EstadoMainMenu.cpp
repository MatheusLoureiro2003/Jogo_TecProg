#include "EstadoMainMenu.h"

EstadoMainMenu::EstadoMainMenu():
	Estado(IDs::estado_menu_principal), mainMenu()
{
}

EstadoMainMenu::~EstadoMainMenu()
{
}

void EstadoMainMenu::changeObserverState()
{
	mainMenu.changeObserverState();
}

void EstadoMainMenu::executar()
{
	mainMenu.executar();
}
