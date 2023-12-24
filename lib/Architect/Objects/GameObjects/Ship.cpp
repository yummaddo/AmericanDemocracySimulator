//
// Created by OchiAnthropos on 23.12.2023.
//

#include "Ship.h"


namespace Game::Objects {
    void Ship::UpdateDrawObjects() {
        sprite.setPosition((float) x_position, (float) y_position);
        holder.addObject("ShipObject", sprite);
    }

    void Ship::AddToHolder() {}

    Ship::Ship( sf::RenderWindow *windowContext) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        x_position = 0;
        y_position = 0;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
    }

    Ship::Ship(sf::RenderWindow *windowContext, int x, int y)  {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        x_position = (float) x;
        y_position = (float) y;
    }

    Ship::Ship(sf::RenderWindow *windowContext, const sf::Sprite &sprite, int x, int y){
        this->sprite = sprite;
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        x_position = (float) x;
        y_position = (float) y;
    }

    void Ship::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
    }
    void Ship::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
    }

} // Objects
// Game