
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include <iostream>
#include <bitset>
#include <string>

void transform(sf::Image& img, FibLFSR* seed){
    sf::Vector2u size = img.getSize();

    for (unsigned int i = 0; i < size.x; i++){
        for (unsigned int j = 0; j < size.y; j++){
            sf::Color pixel;
            pixel = img.getPixel(i,j);

            int xorRed = pixel.r ^ seed->generate(25);
            pixel.r = xorRed;

            int xorBlue = pixel.b ^ seed->generate(25);
            pixel.b = xorBlue;

            int xorGreen = pixel.g ^ seed->generate(25);
            pixel.g = xorGreen;
            img.setPixel(i,j,pixel);
        }
    }
}


int main(int argc, char *argv[])
{
	sf::Image image;

    std::string inputFile = argv[1];
    image.loadFromFile(inputFile);
    std::string seed = argv[3];
    FibLFSR mainSeed(seed);

    
    sf::RenderWindow window1(sf::VideoMode(image.getSize().x, image.getSize().y), "Input File");
    sf::RenderWindow window2(sf::VideoMode(image.getSize().x, image.getSize().y), "Encrypted Image");

    sf::Texture texture1;
    texture1.loadFromImage(image);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);

    transform(image, &mainSeed);

    sf::Texture texture2;
    sf::Sprite sprite2;
    texture2.loadFromImage(image);
    sprite2.setTexture(texture2);

    image.saveToFile(argv[2]);

    while (window1.isOpen() && window2.isOpen()){
        sf:: Event event;
        while (window1.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window1.close();
            }
        }
        while (window2.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window2.close();
            }
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();

    }

    return 0;
}