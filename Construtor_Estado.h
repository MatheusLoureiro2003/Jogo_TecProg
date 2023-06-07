#pragma once
#include "EstadoPlay.h"
#include "EstadoMainMenu.h"
#include "EstadoMenuPause.h"
#include "EstadoMenuMainOption.h"
#include "ConstrutorFase.h"

namespace Construtor {
	class Construtor_Estado
	{
    private:
        Estado* createPlayState(const IDs ID);
        Estado* createMainMenu();
        Estado* createMenuPause();
       // Estado* createMenuMainOption();
    public:
        Construtor_Estado();
        ~Construtor_Estado();
        Estado* createState(const IDs ID);
	};
}
