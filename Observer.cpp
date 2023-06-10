#include "Observer.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"

namespace Observadores {
	Gerenciadores::Gerenciador_Eventos* Observer::pEve = Gerenciadores::Gerenciador_Eventos::getInstance();
	Gerenciadores::Gerenciador_Estados* Observer::pGE = Gerenciadores::Gerenciador_Estados::getInstance();

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