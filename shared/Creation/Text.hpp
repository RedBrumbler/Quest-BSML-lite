#pragma once

#include "../TransformWrapper.hpp"
#include "HMUI/CurvedTextMeshPro.hpp"
#include "TMPro/TextRenderFlags.hpp"
#include "UnityEngine/Transform.hpp"
#include "bsml/shared/BSML/Components/ClickableText.hpp"

namespace BSML::Lite {
    /// @brief Creates text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @return The created text
    HMUI::CurvedTextMeshPro* CreateText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, UnityEngine::Vector2 anchoredPosition = {}, UnityEngine::Vector2 sizeDelta = {});

    /// @brief Creates text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @return The created text
    static inline HMUI::CurvedTextMeshPro* CreateText(const TransformWrapper& parent, StringW text, float fontSize, UnityEngine::Vector2 anchoredPosition = {}, UnityEngine::Vector2 sizeDelta = {}) {
        return CreateText(parent, text, TMPro::FontStyles::Italic, fontSize, anchoredPosition, sizeDelta);
    }

    /// @brief Creates text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @return The created text
    static inline HMUI::CurvedTextMeshPro* CreateText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, UnityEngine::Vector2 anchoredPosition = {}, UnityEngine::Vector2 sizeDelta = {}) {
        return CreateText(parent, text, fontStyle, 4, anchoredPosition, sizeDelta);
    }

    /// @brief Creates text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @return The created text
    static inline HMUI::CurvedTextMeshPro* CreateText(const TransformWrapper& parent, StringW text, UnityEngine::Vector2 anchoredPosition = {}, UnityEngine::Vector2 sizeDelta = {}) {
        return CreateText(parent, text, TMPro::FontStyles::Italic, 4, anchoredPosition, sizeDelta);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick = nullptr);

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, fontStyle, 4, anchoredPosition, sizeDelta, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, float fontSize, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, fontSize, anchoredPosition, sizeDelta, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param sizeDelta how much smaller this thing is relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, 4, anchoredPosition, sizeDelta, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, fontStyle, fontSize, anchoredPosition, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, fontStyle, 4, anchoredPosition, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontSize size of the font
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, float fontSize, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, fontSize, anchoredPosition, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param anchoredPosition position of the anchor relative to the parent
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, UnityEngine::Vector2 anchoredPosition, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, 4, {}, anchoredPosition, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param fontSize size of the font
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, fontStyle, fontSize, {}, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontStyle the style of the font
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, fontStyle, 4, {}, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param fontSize size of the font
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, float fontSize, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, fontSize, {}, {}, onClick);
    }

    /// @brief Creates Clickable text which is parented to the passed parent
    /// @param parent parent transform to parent text to
    /// @param text the text to display
    /// @param onClick what gets ran when it is clicked
    /// @return The created text
    static inline BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, std::function<void()> onClick = nullptr) {
        return CreateClickableText(parent, text, TMPro::FontStyles::Italic, 4, {}, {}, onClick);
    }
}