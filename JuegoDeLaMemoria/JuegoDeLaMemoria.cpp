#include <iostream>
#include <SFML/Graphics.hpp>
#include "Carta.h"
#include <vector>
#include "Seleccionado.h"
#include <chrono>
#include <thread>

struct Punto {
    sf::Vector2f punto;
};

int main()
{
    using namespace std::this_thread;
    using namespace std::chrono;

    // crea la ventana
    sf::RenderWindow window(sf::VideoMode(780, 620), "Juego de la Memoria");
    window.setFramerateLimit(60);

    // carga el fondo
    sf::Texture back;

    if (!back.loadFromFile("C:/Users/Franco/Documents/Proyectos Net/JuegoDeLaMemoria/background.png")) {
        std::cout << "Error";
    }

    // fondo
    sf::Sprite sprite;
    sprite.setTexture(back);
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
    sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    sprite.setScale(sf::Vector2f(1.f, 1.5));

    // carga las posiciones
    std::vector<Punto> puntos;

    // 1ra fila
    Punto punto;
    punto.punto = sf::Vector2f(80.f, 100.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(280.f, 100.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(480.f, 100.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(680.f, 100.f);
    puntos.push_back(punto);

    //2da fila
    punto.punto = sf::Vector2f(80.f, 300.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(280.f, 300.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(480.f, 300.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(680.f, 300.f);
    puntos.push_back(punto);


    // 3ra fila
    punto.punto = sf::Vector2f(80.f, 500.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(280.f, 500.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(480.f, 500.f);
    puntos.push_back(punto);

    punto.punto = sf::Vector2f(680.f, 500.f);
    puntos.push_back(punto);


    // carga de las cartas
    std::vector<Carta> cartas;

    Carta carta1 = Carta("C:/Users/Franco/Documents/Proyectos Net/JuegoDeLaMemoria/_1.png", 1);
    Carta carta2 = Carta("C:/Users/Franco/Documents/Proyectos Net/JuegoDeLaMemoria/_2.png", 2);
    Carta carta3 = Carta("C:/Users/Franco/Documents/Proyectos Net/JuegoDeLaMemoria/_3.png", 3);

    cartas.push_back(carta1);
    cartas.push_back(carta2);
    cartas.push_back(carta3);

    cartas.push_back(carta1);
    cartas.push_back(carta2);
    cartas.push_back(carta3);

    cartas.push_back(carta1);
    cartas.push_back(carta2);
    cartas.push_back(carta3);

    cartas.push_back(carta1);
    cartas.push_back(carta2);
    cartas.push_back(carta3);


    for (int i = 0; i < cartas.size(); i++)
    {
        cartas[i].setPos(puntos[i].punto);
    }
    bool pintado = false;

    std::vector<Seleccionado> seleccionados;

    int click = 0;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                int i;
                for (i = 0; i < cartas.size(); i++)
                {
                    if (cartas[i].getCarta().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && !cartas[i].isVolteado()) {
                        cartas[i].voltear();
                        seleccionados.push_back(Seleccionado(cartas[i].getValor(), i));
                        break;
                    }                 
                }
            }
            if (!seleccionados.empty() && seleccionados.size() == 2 && pintado) {
                sleep_for(nanoseconds(10));
                sleep_until(system_clock::now() + seconds(1));
                if (seleccionados[0].getValor() == seleccionados[1].getValor()) {

                    if (seleccionados[0].getIndex() > seleccionados[1].getIndex()) {

                        for (int j = seleccionados[0].getIndex(); j < cartas.size() - 1; j++)
                        {
                            cartas[j] = cartas[j + 1];
                        }
                        cartas.pop_back();

                        for (int j = seleccionados[1].getIndex(); j < cartas.size() - 1; j++)
                        {
                            cartas[j] = cartas[j + 1];
                        }
                        cartas.pop_back();
                    }
                    else {
                        for (int j = seleccionados[1].getIndex(); j < cartas.size() - 1; j++)
                        {
                            cartas[j] = cartas[j + 1];
                        }
                        cartas.pop_back();

                        for (int j = seleccionados[0].getIndex(); j < cartas.size() - 1; j++)
                        {
                            cartas[j] = cartas[j + 1];
                        }
                        cartas.pop_back();
                    }

                    seleccionados.clear();
                }
                else {
                    cartas[seleccionados[0].getIndex()].voltear();
                    cartas[seleccionados[1].getIndex()].voltear();
                    for (int i = 0; i < seleccionados.size(); i++)
                    {
                        std::cout << seleccionados[i].getValor();
                    }
                    seleccionados.clear();
                }

                pintado = false;
            }
            else {
                if (seleccionados.size() == 2)
                    pintado = true;
            }

        }

        if (cartas.size() == 0) {
            window.close();
        }
        window.clear();
        window.draw(sprite);
        for (int i = 0; i < cartas.size(); i++)
        {
            window.draw(cartas[i].getCarta());
        }
        window.display();
    }
}


