#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Personagem.h"
#include "Gerenciador_Grafico.h"
#include "ListaEntidades.h"

namespace Gerenciadores {
    class Gerenciador_Colisao// :public Entidades::Personagens::Inimigo     
    {
    private:
        Listas::Lista<Entidades::Entidade> LEs;

    public:
        Gerenciador_Colisao(/*Entidades::Personagens::Jogador* jogador, Entidades::Personagens::Inimigo* inimigo*/);
        ~Gerenciador_Colisao();
        static bool colidir(sf::Vector2f Inimigo, sf::Vector2f Jogador, sf::Vector2f tam);// coloque para chamar essa função quando iniciar o movimento do inimigo

        //bool operator==(const Gerenciador_Colisao& other) const;
    };
}