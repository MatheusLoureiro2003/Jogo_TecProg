#include "Botao.h"

Botao::Botao(const std::string info, const sf::Vector2f tam, const sf::Vector2f pos, const IDs ID, const sf::Color corlorSelected):
Ente(ID),
selected(false), pos(pos), tam(tam), Clock(), text(pGG->loadFont(CAMINHO_FONTE), info),
timeChangeColor(TEMPO_TROCAR_COR),time(0.0f),colorSelected(corlorSelected)
{
	TextBox.setPosition(pos);
	TextBox.setSize(tam);
	sf::Vector2f textSize = this->text.getTam();
	sf::Vector2f textPos = sf::Vector2f(
		pos.x + tam.y / 3.0f - textSize.x / 2.05f,
		pos.y + tam.y / 2.0f - textSize.y * 1.2f
	);
}

Botao::~Botao()
{
}

void Botao::draw()
{
	updateText();
	pGG->draw(text.getText());
}

void Botao::updateText()
{
    const float dt = Clock.getElapsedTime().asSeconds();
    Clock.restart();
    time += dt;
    if (selected) {
        if (time > timeChangeColor) {
            int transparente = text.getTransparent();
            if (text.getLightening()) {
                //texto clareando
                transparente += 5;
                if (transparente > 255) {
                    transparente = 255;
                    text.changeLightening();
                }
            }
            else {
                //texto escurecendo
                transparente -= 5;
                if (transparente < 0) {
                    transparente = 0;
                    text.changeLightening();
                }
            }
            text.setTransparent(transparente);
            time = 0.0f;
        }
    }
    else {
        time = 0.0f;
    }
}

void Botao::setSelecionado(const bool selecionado)
{
}

const bool Botao::getSelecionado() const
{
	return selected;
}

void Botao::updatePosition(const sf::Vector2f pos)
{
	this->pos = pos;
	TextBox.setPosition(pos);
	sf::Vector2f textSize = this->text.getTam();
	sf::Vector2f textPos = sf::Vector2f(
		pos.x + tam.x / 2.0f - textSize.x / 2.05f,
		pos.y + tam.y / 2.0f - textSize.y * 1.2f
	);
	this->text.setPos(textPos);
}

const sf::Vector2f Botao::getPos() const
{
	return TextBox.getPosition();
}
const sf::Vector2f Botao::getTextSize() const
{
    return sf::Vector2f(text.getText().getGlobalBounds().width, text.getText().getGlobalBounds().height);
}

