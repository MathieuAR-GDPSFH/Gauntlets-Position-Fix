#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include <Geode/modify/GauntletSelectLayer.hpp>//why u guys move this on top ever? - user95401
class $modify(GauntletSelectLayerFix, GauntletSelectLayer) {
    $override void setupGauntlets() {
        GauntletSelectLayer::setupGauntlets();
        findFirstChildRecursive<ExtendedLayer>(this,
            [](ExtendedLayer* gauntlet_pages) {
                if (gauntlet_pages->getChildrenCount() > 1) return false;
                gauntlet_pages->setAnchorPoint(CCPointMake(1.f, 0.f));
                gauntlet_pages->ignoreAnchorPointForPosition(false);
                return true;
            }
        );
    };
};
