#include "bF.hpp"


// The plugin-wide instance of the Plugin class
Plugin *plugin;

using namespace bF;

void init(rack::Plugin *p) {
    plugin = p;

#ifdef SLUG
    plugin->slug = TOSTRING(SLUG);
#else
    plugin->slug = "bitFetcher";
#endif

#ifdef VERSION
    plugin->version = TOSTRING(VERSION);
#endif

    plugin->website = "https://github.com/bitfetcher/bF";
    plugin->manual = "https://github.com/bitfetcher/bF/blob/master/README.md";

    // For each module, specify the ModuleWidget subclass, manufacturer slug (for saving in patches), manufacturer human-readable name, module slug, and module name
    p->addModel(createModel<OscWidget>(plugin->slug, "Oscillator", "Oscillator", OSCILLATOR_TAG));

    p->addModel(createModel<MultWidget>(plugin->slug, "Multiple", "Multiple", MULTIPLE_TAG, UTILITY_TAG));

    p->addModel(createModel<QuadWidget>(plugin->slug, "Quadrature", "Quadrature", OSCILLATOR_TAG, LFO_TAG, QUAD_TAG));
//    p->addModel(createModel<beeWidget>(plugin->slug, "beeSting", "beeSting", OSCILLATOR_TAG, LFO_TAG,
//                                       AMPLIFIER_TAG, ATTENUATOR_TAG, CLOCK_TAG,DELAY_TAG,
//                                       DISTORTION_TAG, EFFECT_TAG, ENVELOPE_FOLLOWER_TAG,LFO_TAG,
//                                       NOISE_TAG,OSCILLATOR_TAG, QUANTIZER_TAG,RING_MODULATOR_TAG,
//                                       SAMPLE_AND_HOLD_TAG,SLEW_LIMITER_TAG, UTILITY_TAG,WAVESHAPER_TAG));

    // Any other plugin initialization may go here.
    // As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
