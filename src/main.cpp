#include "BSML.hpp"
#include "logging.hpp"

Logger& getLogger() {
    static Logger* logger = new Logger({MOD_ID, VERSION}, LoggerOptions(false, true));
    return *logger;
}

void ViewController_DidActivate(HMUI::ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    if (!firstActivation) return;
    DEBUG("ViewController_DidActivate({}, {}, {}, {})", fmt::ptr(self), firstActivation, addedToHierarchy, screenSystemEnabling);
    using namespace BSML::Lite;
    auto layout = CreateVerticalLayoutGroup(self);
    CreateText(layout, "Hi!");
    CreateText(layout, "Hi again!");
    CreateText(layout, "Bit longwinded innit?");

    //auto bar = CreateProgressBar({0, 3, 3}, "yomama", "t1", "t2");
    //bar->ShowMessage("yomama", 10.0f);
}

extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
}

void gameplaySetup(UnityEngine::GameObject* self, bool firstActivation) {
    DEBUG("gameplay setup({}, {})", fmt::ptr(self), firstActivation);
    if (!firstActivation) return;
    using namespace BSML::Lite;
    auto layout = CreateVerticalLayoutGroup(self);
    CreateText(layout, "Hi!");
    CreateText(layout, "Hi again!");
    CreateText(layout, "Bit longwinded innit?");
}

extern "C" void load() {
    il2cpp_functions::Init();
    BSML::Init();
    custom_types::Register::AutoRegister();
}