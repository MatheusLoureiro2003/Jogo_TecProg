#include "Observer.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Eventos* Observadores::Observer::pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
Gerenciadores::Gerenciador_Estados* Observadores::Observer::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

namespace Observadores {


	Observer::Observer() :
		activate(true)
	{
		pEve->addObserver(this);
	}

	Observer::~Observer()
	{
		removeObserver();
	}

	void Observer::changeStateActivate()
	{
		activate = (activate) ? false : true;
	}

	const bool Observer::getActivate() const
	{
		return activate;
	}

	void Observer::removeObserver()
	{
		pEve->removeObserver(this);
	}

	void Observer::moveMouse(const sf::Vector2f posMouse)
	{
	}

	void Observer::buttonLooseMouse(const sf::Mouse::Button botaoMouse)
	{
	}
}