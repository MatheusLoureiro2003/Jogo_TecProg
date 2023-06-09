#include "Gerenciador_Colisao.h"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>

Gerenciadores::Gerenciador_Colisao::Gerenciador_Colisao()
{
}

Gerenciadores::Gerenciador_Colisao::~Gerenciador_Colisao()
{
}

 bool Gerenciadores::Gerenciador_Colisao::colidir(sf::Vector2f posInimigo, sf::Vector2f posJogador, sf::Vector2f tam)
{
    bool x = 0;
    //float distancia = dynamic_cast<float> (tam);
    //sf::Vector2f tam
    if (posInimigo.y - posJogador.y == 10 || posInimigo.y - posJogador.y == -10)
    {
        //if (posInimigo.y - posJogador.y == 100 || posInimigo.y - posJogador.y == -50) {
        x = 1;
        //}
    }
    else x = 0;
    return x;
}

/*bool Gerenciadores::Gerenciador_Colisao::operator==(const Gerenciador_Colisao& other) const&
{
    return false;
}*/
