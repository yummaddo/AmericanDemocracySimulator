//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENEHOLDER_H
#define AMERICANDEMOCRACYSIMULATOR_SCENEHOLDER_H
#include <iostream>
#include <map>
#include <SFML/System/Clock.hpp>
#include "Coroutine.h"
#include "../Scene.h"

namespace Game {

    class SceneHolder {
    private:
        float frameFixedDeltaTime = 0.00f;
        void AsyncRunState();
        void Main(){
            deltaTime = clock.restart().asSeconds();
            liveTime += deltaTime;
            updateRunStatus = true;

            if ( frameFixedDeltaTime <= fixedDeltaTime ){
                fixedUpdateRunStatus = true;
                frameFixedDeltaTime -= fixedDeltaTime;
            } else {
                frameFixedDeltaTime += deltaTime;
                fixedUpdateRunStatus = false;
            }
            AsyncRunState();
            for (auto Coroutine : void_stack) Coroutine.second->Continue(deltaTime);
        }

    protected:
        // fun, current time, border
        std::map<std::string, Game::Coroutine*> void_stack{};

        bool updateRunStatus = true;
        bool fixedUpdateRunStatus = false;

        sf::Clock clock;
        float liveTime = 0;
        float fixedDeltaTime = 0.02f;

        float deltaTime = 0;

    public:
        virtual void Update() {};
        virtual void FixedUpdate() {};
        virtual void Start() {};

        Scene *scene;
        void deleteCoroutineFunk(const std::string& name);

        virtual void Next() {
            Main();
        };

        void addCCoroutineFunk(const std::function<void()> &runtime, const std::string &name, float time);

        void addCCoroutineFunk(Coroutine *coroutine, const std::string &name);

        void addCCoroutineFunk(const std::string &name, Coroutine *coroutine);
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_SCENEHOLDER_H
