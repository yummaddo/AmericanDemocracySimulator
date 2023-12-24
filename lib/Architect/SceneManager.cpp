//
// Created by OchiAnthropos on 21.12.2023.
//
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "SceneManager.h"
#include "Scene.h"
#include "../Debugger/Debugger.h"

namespace Game {
    Scene *SceneManager::createScene() { return new Scene(); }
    Scene *SceneManager::createScene(std::string name) { return new Scene(std::move(name)); }
    Scene *SceneManager::createScene(std::string name, const std::string& contextName) { return new Scene(std::move(name)); }

    void SceneManager::AddScene(){}

    void SceneManager::AddScene(SceneHolder *sceneHolder){ scenes[sceneHolder->scene->ContextName] = sceneHolder; }
    void SceneManager::AddScene(SceneHolder sceneHolder){ AddScene(&sceneHolder); }
    void SceneManager::setActiveScene(SceneHolder *sceneHolder) { activeScene = sceneHolder; }
    void SceneManager::setActiveScene(SceneHolder sceneHolder) { activeScene = &sceneHolder; }

    void SceneManager::SwitchScene(const std::string& sceneName)
    {
        auto it = SceneManager::GetInstance()->scenes.find(sceneName);
        if (it != SceneManager::GetInstance()->scenes.end()) {
            SceneManager::GetInstance()->setActiveScene(it->second );
            Debugger::Log("Switched to scene: " + sceneName, Debugger::Color::GREEN);
        } else {
            Debugger::Log("Scene not found: " + sceneName, Debugger::Color::RED);
        }
    }
    void SceneManager::PrintScenes() {
        Debugger::Log("Available scenes:", Debugger::Color::YELLOW);
        for (const auto& pair : SceneManager::GetInstance()->scenes) {
            Debugger::Log(pair.first, Debugger::Color::GREEN);
        }
    }

    SceneManager *SceneManager::GetInstance() {
        if(singleton_==nullptr){
            singleton_ = new SceneManager();
        }
        return singleton_;
    }
}