#include "MainMenu.h"

MainMenu::MainMenu() : Menu(IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "CaçadorEspacial", 180),
leave(false), fundo(IDs::fundo_normal)
{
    MenuName.setPos(sf::Vector2f(WindowSize.x / 2.0f - MenuName.getTam().x / 2.0f, 25.0f));
    MenuName.setColorText(sf::Color{0, 200, 0});
    createBackground();
    createButton();
}

MainMenu::~MainMenu()
{
}

void MainMenu::setLeave(const bool leave)
{
    this->leave = leave;
}

const bool MainMenu::getLeave() const
{
    return leave;
}

void MainMenu::executar()
{
    //conteúdo do efeito Parallax
    BackPosition = sf::Vector2f(BackPosition.x + 0.05f, BackPosition.y);
    pGG->centerView(sf::Vector2f(BackPosition.x + WindowSize.x / 2.0f, BackPosition.y + WindowSize.y / 2.0f));
    fundo.executar();
    pGG->resetWindow();

    //desenha todo o conteúdo do menu principal na tela
    draw();
    pGG->draw(MenuName.getText());
}

void MainMenu::createButton()
{
    const float posBotaoX = WindowSize.x / 2.0f - ButtonSize.x / 2.0f;
    addButton("Novo Jogo", sf::Vector2f(posBotaoX, WindowSize.y / 2.0f), IDs::botao_novoJogo, sf::Color{0, 255, 0});
    addButton("Carregar Jogo", sf::Vector2f(posBotaoX, WindowSize.y / 2.0f + ButtonSize.y * 1.2f), IDs::botao_carregarJogo, sf::Color{0, 255, 0});
    addButton("Colocacao", sf::Vector2f(posBotaoX, WindowSize.y / 2.0f + ButtonSize.y * 2.4f), IDs::botao_colocacao, sf::Color{0, 255, 0});
    addButton("Opcao", sf::Vector2f(posBotaoX, WindowSize.y / 2.0f + ButtonSize.y * 3.6f), IDs::botao_opcao, sf::Color{0, 255, 0});
    addButton("Sair", sf::Vector2f(posBotaoX, WindowSize.y / 2.0f + ButtonSize.y * 4.8f), IDs::botao_sair, sf::Color{0, 255, 0});
    it = ButtonList.begin();
    (*it)->setSelecionado(true);
}

void MainMenu::createBackground()
{
}
