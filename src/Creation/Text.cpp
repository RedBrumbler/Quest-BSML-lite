#include "Creation/Text.hpp"

#define protected public
#include "bsml/shared/BSML/Tags/TextTag.hpp"
#include "bsml/shared/BSML/Tags/ClickableTextTag.hpp"
#undef protected


#include "UnityEngine/RectTransform.hpp"

namespace BSML::Lite {
    HMUI::CurvedTextMeshPro* CreateText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta) {
        auto go = BSML::TextTag{}.CreateObject(parent);
        auto t = go->GetComponent<HMUI::CurvedTextMeshPro*>();
        t->set_text(text);
        t->set_fontStyle(fontStyle);
        t->set_fontSize(fontSize);

        auto rect = go->GetComponent<UnityEngine::RectTransform*>();
        rect->set_anchoredPosition(anchoredPosition);
        rect->set_sizeDelta(sizeDelta);

        go->AddComponent<UnityEngine::UI::LayoutElement*>();

        return t;
    }

    BSML::ClickableText* CreateClickableText(const TransformWrapper& parent, StringW text, TMPro::FontStyles fontStyle, float fontSize, std::function<void()> onClick, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta) {
        auto go = BSML::ClickableTextTag{}.CreateObject(parent);
        auto t = go->GetComponent<BSML::ClickableText*>();
        t->set_text(text);
        t->set_fontStyle(fontStyle);
        t->set_fontSize(fontSize);

        auto rect = go->GetComponent<UnityEngine::RectTransform*>();
        rect->set_anchoredPosition(anchoredPosition);
        rect->set_sizeDelta(sizeDelta);

        if (onClick) t->onClick += {onClick};

        go->AddComponent<UnityEngine::UI::LayoutElement*>();

        return t;
    }

}