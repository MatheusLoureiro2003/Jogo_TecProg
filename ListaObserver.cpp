#include "ListaObserver.h"

namespace Listas {
	ListaObserver::ListaObserver() :
		objListaObservador()
	{
	}

	ListaObserver::~ListaObserver()
	{
		objListaObservador.limparLista();
	}

	void ListaObserver::addObserver(Observadores::Observer* observador)
	{
		objListaObservador.push(observador);
	}

	void ListaObserver::removeObserver(Observadores::Observer* observador)
	{
		objListaObservador.pop(observador);
	}

	void ListaObserver::removeObserver(int pos)
	{
		objListaObservador.removerElemento(pos);
	}

	int ListaObserver::getTam()
	{
		return objListaObservador.getLen();
	}

	Observadores::Observer* ListaObserver::operator[](int pos)
	{
		return objListaObservador.getItem(pos);
	}

	void ListaObserver::isKeyPressed(const sf::Keyboard::Key tecla)
	{
		for (int i = 0; i < objListaObservador.getLen(); i++) {
			Observadores::Observer* observador = objListaObservador.getItem(i);
			if (observador->getActivate()) {
				observador->IsKeyPressed(tecla);
			}
			observador = nullptr;
		}
		std::cout << objListaObservador.getLen() << std::endl;
	}

	void ListaObserver::isKeyLoose(const sf::Keyboard::Key tecla)
	{
		for (int i = 0; i < objListaObservador.getLen(); i++) {
			Observadores::Observer* observador = objListaObservador.getItem(i);
			if (observador->getActivate()) {
				observador->IsKeyLoose(tecla);
			}
			observador = nullptr;
		}
	}

	void ListaObserver::notifyMouseMovement(const sf::Event::MouseMoveEvent mouse)
	{
		sf::Vector2f posMouse = sf::Vector2f((float)mouse.x, (float)mouse.y);
		for (int i = 0; i < objListaObservador.getLen(); i++) {
			Observadores::Observer* observador = objListaObservador.getItem(i);
			if (observador->getActivate()) {
				observador->moveMouse(posMouse);
			}
			observador = nullptr;
		}
	}




	void ListaObserver::notifyMouseButtonRealeased(const sf::Mouse::Button botaoMouse)
	{
		for (int i = 0; i < objListaObservador.getLen(); i++) {
			Observadores::Observer* observador = objListaObservador.getItem(i);
			if (observador->getActivate()) {
				observador->buttonLooseMouse(botaoMouse);
			}
		}
	}
}