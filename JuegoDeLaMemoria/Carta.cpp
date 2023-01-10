#include "Carta.h"

Carta::Carta(std::string url, int valor)
{
    dorsoTexture.loadFromFile("C:/Users/Franco/Documents/Proyectos Net/JuegoDeLaMemoria/back.png");
    cartaTexture.loadFromFile(url);
    cartaSprite.setTexture(dorsoTexture);
    cartaSprite.setOrigin(cartaSprite.getTexture()->getSize().x / 2, cartaSprite.getTexture()->getSize().y / 2);

    this->volteado = false;
    this->valor = valor;
}

sf::Sprite Carta::getCarta() 
{
    return this->cartaSprite;
}

int Carta::getValor() {
    return this->valor;
}

bool Carta::isVolteado()
{
    return this->volteado;
}

void Carta::setPos(sf::Vector2f pos) {
    this->cartaSprite.setPosition(pos);
}

void Carta::voltear() {

    if (!volteado) {
        cartaSprite.setTexture(cartaTexture);
        volteado = true;
    }
    else {
        cartaSprite.setTexture(dorsoTexture);
        volteado = false;
    }
}

bool Carta::compararValores(Carta carta) {
    return this->valor == carta.getValor();
}
