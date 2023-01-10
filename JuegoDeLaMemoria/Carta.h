#pragma once
#include <SFML/Graphics.hpp>

class Carta {
private:
    sf::Texture cartaTexture;
    sf::Texture dorsoTexture;
    sf::Sprite cartaSprite;

    bool volteado;

    int valor;

public:
    Carta(std::string url, int valor);

    sf::Sprite getCarta();

    void setPos(sf::Vector2f pos);

    void voltear();

    bool compararValores(Carta carta);

    int getValor();

    bool isVolteado();
};
