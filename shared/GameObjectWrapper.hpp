#pragma once

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Component.hpp"
#include "UnityEngine/Transform.hpp"

namespace BSML::Lite {
    /// @brief A wrapper for transforms, components and gameobjects to automatically be converted into a gameObject
    struct GameObjectWrapper {
        GameObjectWrapper(UnityEngine::GameObject* gameObject) noexcept : gameObject(gameObject) {}
        GameObjectWrapper(UnityEngine::Component* comp) : GameObjectWrapper(comp->get_gameObject()) {}
        GameObjectWrapper(UnityEngine::Transform* transform) : GameObjectWrapper(transform->get_gameObject()) {}

        UnityEngine::GameObject* operator->() const noexcept { return gameObject; }
        operator UnityEngine::GameObject*() const noexcept { return gameObject; }
        UnityEngine::GameObject* gameObject;
    };
}

template<>
struct ::il2cpp_utils::il2cpp_type_check::il2cpp_no_arg_class<BSML::Lite::GameObjectWrapper> {
    static inline Il2CppClass* get() {
        return classof(UnityEngine::GameObject*);
    }
};
static_assert(sizeof(BSML::Lite::GameObjectWrapper) == sizeof(UnityEngine::GameObject*));
