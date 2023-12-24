//
// Created by OchiAnthropos on 23.12.2023.
//

#include "Ground.h"
#include "../Animations/GroundAnimation.h"

namespace Game::Objects {

    void Ground::AddToHolder() {holder.addObject("ground_animation", baseAnimation->GetEndFrameSprite());}

    void Ground::UpdateDrawObjects() { baseAnimation->DrawAnimation(); AddToHolder(); }

    Ground::Ground(sf::RenderWindow *windowContext, int x, int y) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = std::string ("GroundAnimation [x:" + std::to_string(x) + std::string(" y:") +  std::to_string(y) + std::string ("]"));
        baseAnimation = new GroundAnimation();
        baseAnimation->y = y;
        baseAnimation->x = x;
    }

    Ground::Ground(sf::RenderWindow *windowContext) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = "GroundAnimation";
        baseAnimation = new GroundAnimation();
    }
    Ground::Ground(sf::RenderWindow *windowContext, const sf::Sprite &sprite1, int _x, int _y) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = "GroundAnimation" + std::to_string(_x) + "_" +  std::to_string(_y);
        baseAnimation = new GroundAnimation();
        x_position = _x;
        y_position = _y;
    }
} // Objects
// Game