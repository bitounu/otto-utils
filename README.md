# Otto-Utils

A collection of utilities useful for building OTTO modes.

## Display

Display handles a few things that make writing modes easier.

- Dims / sleeps the display after a timeout.
- Masks the display so nothing outside the circular portal is visible.
- Sets up the OpenVG transform correctly before you begin drawing.

### Usage

	#include "display.hpp"
	#include "timeline.hpp"

	static Display display = { { 96.0f, 96.0f } };

	STAK_EXPORT int update(float dt) {
		display.update([dt] {
				timeline.step(dt);
		});
		return 0;
	}

	STAK_EXPORT int draw() {
		display.draw([] {
			// Draw some things pre-transformed to the OTTO display
		});
		return 0;
	}

	STAK_EXPORT int shutter_button_pressed() {
		if (!display.wake()) { // Wake the display
			// If the display was not asleep, rect to the button press.
		}
		return 0;
	}

## Timeline

Timeline provides a static instance of a [Choreograph](https://github.com/sansumbrella/Choreograph) Timeline. Choreograph is used for all of the transitions in otto-menu and otto-gif-mode. It's usually not necessary to have more than one instance of Timeline, but definitely possible.

### Usage

	static Output<float> value = 0.0f;

	// Tween `value` to 1.0 over 2 seconds
	timeline.apply(&value).then<RampTo>(1.0f, 2.0f, EaseInOutQuad());
