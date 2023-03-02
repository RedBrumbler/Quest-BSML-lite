#include "Creation/Layout.hpp"

#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"

#include "bsml/shared/BSML/Components/ExternalComponents.hpp"
#define protected public
#include "bsml/shared/BSML/Tags/VerticalTag.hpp"
#include "bsml/shared/BSML/Tags/HorizontalTag.hpp"
#include "bsml/shared/BSML/Tags/GridLayoutTag.hpp"
#include "bsml/shared/BSML/Tags/StackLayoutTag.hpp"
#include "bsml/shared/BSML/Tags/SettingsContainerTag.hpp"
#include "bsml/shared/BSML/Tags/ScrollViewTag.hpp"
#include "bsml/shared/BSML/Tags/ModalTag.hpp"
#include "bsml/shared/BSML/Tags/ModifierContainerTag.hpp"
#undef protected

namespace BSML::Lite {
    UnityEngine::UI::VerticalLayoutGroup* CreateVerticalLayoutGroup(const TransformWrapper& parent) {
        return BSML::VerticalTag{}.CreateObject(parent)->GetComponent<UnityEngine::UI::VerticalLayoutGroup*>();
    }

    UnityEngine::UI::HorizontalLayoutGroup* CreateHorizontalLayoutGroup(const TransformWrapper& parent) {
        return BSML::HorizontalTag{}.CreateObject(parent)->GetComponent<UnityEngine::UI::HorizontalLayoutGroup*>();
    }

    UnityEngine::UI::GridLayoutGroup* CreateGridLayoutGroup(const TransformWrapper& parent) {
        return BSML::GridLayoutTag{}.CreateObject(parent)->GetComponent<UnityEngine::UI::GridLayoutGroup*>();
    }

    HMUI::StackLayoutGroup* CreateStackLayoutGroup(const TransformWrapper& parent) {
        return BSML::StackLayoutTag{}.CreateObject(parent)->GetComponent<HMUI::StackLayoutGroup*>();
    }

    UnityEngine::GameObject* CreateScrollableSettingsContainer(const TransformWrapper& parent) {
        auto go = BSML::SettingsContainerTag{}.CreateObject(parent);
        auto externalComponents = go->GetComponent<BSML::ExternalComponents*>();
        auto scrollTransform = externalComponents->Get<UnityEngine::RectTransform*>();
        scrollTransform->set_sizeDelta(UnityEngine::Vector2(0.0f, 0.0f));
        return go;
    }

    UnityEngine::GameObject* CreateScrollView(const TransformWrapper& parent) {
        return BSML::ScrollViewTag{}.CreateObject(parent);
    }

    BSML::ModalView* CreateModal(const TransformWrapper& parent, UnityEngine::Vector2 anchoredPosition, UnityEngine::Vector2 sizeDelta, std::function<void()> onBlockerClicked, bool dismissOnBlockerClicked) {
        auto go = BSML::ModalTag{}.CreateObject(parent);
        auto modalView = go->GetComponent<BSML::ModalView*>();
        auto rect = reinterpret_cast<UnityEngine::RectTransform*>(modalView->get_transform());
        rect->set_anchoredPosition(anchoredPosition);
        rect->set_sizeDelta(sizeDelta);

        modalView->dismissOnBlockerClicked = dismissOnBlockerClicked;
        modalView->onHide = onBlockerClicked;

        return modalView;
    }

    UnityEngine::GameObject* CreateScrollableModalContainer(BSML::ModalView* modal) {
        auto rect = reinterpret_cast<UnityEngine::RectTransform*>(modal->get_transform());
        auto sizeDelta = rect->get_sizeDelta();
        float width = sizeDelta.x;
        float height = sizeDelta.y;

        auto parent = modal->get_transform();
        auto content = CreateScrollView(parent);

        auto externalComponents = content->GetComponent<BSML::ExternalComponents*>();
        auto scrollTransform = externalComponents->Get<UnityEngine::RectTransform*>();

        scrollTransform->set_anchoredPosition({-2.5f, 0.0f});
        scrollTransform->set_sizeDelta({7.5f, 0.0f});

        auto layout = content->GetComponent<UnityEngine::UI::VerticalLayoutGroup*>();

        layout->set_childControlWidth(true);
        layout->set_childForceExpandWidth(true);

        auto layoutelem = content->AddComponent<UnityEngine::UI::LayoutElement*>();
        layoutelem->set_preferredWidth(width - 10.0f);

        static ConstString name("BSMLScrollableModalContainer");

        scrollTransform->get_gameObject()->set_name(name);
        return content;
    }

    UnityEngine::UI::VerticalLayoutGroup* CreateModifierContainer(const TransformWrapper& parent) {
        return BSML::ModifierContainerTag{}.CreateObject(parent)->GetComponent<UnityEngine::UI::VerticalLayoutGroup*>();
    }
}
