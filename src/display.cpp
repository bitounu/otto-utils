#include "display.hpp"

using namespace choreograph;

namespace otto {

void Display::sleep() {
  timeline.apply(&brightness)
      .then<RampTo>(0.5f, 2.0f, EaseInOutQuad())
      .then<Hold>(0.5f, sleepDelay - daydreamDelay)
      .then<RampTo>(0.0f, 2.0f, EaseInQuad())
      .finishFn([this](ch::Motion<float> &m) { isSleeping = true; });
}

bool Display::wake() {
  if (sleepTimeout) {
    sleepTimeout->cancel();
    sleepTimeout.reset();
  }

  timeline.apply(&brightness).then<RampTo>(1.0f, 0.25f, EaseOutQuad());
  sleepTimeout = timeline.cue([this] { sleep(); }, daydreamDelay).getControl();

  auto wasSleeping = isSleeping;
  isSleeping = false;

  return wasSleeping;
}

void Display::update(const std::function<void()> userUpdate) {
  if (!isSleeping) userUpdate();
}

void Display::draw(const std::function<void()> userDraw) const {
  static const mat3 defaultMatrix = { 0.0, -1.0, 0.0, 1.0, -0.0, 0.0, 0.0, bounds.size.y, 1.0 };

  if (isSleeping) return;

  clearColor(vec3(0.0f));
  clear(bounds);

  setTransform(defaultMatrix);

  // NOTE(ryan): Apply a circular mask to simulate a round display. We may want to move this to
  // stak-sdk so that the mask is enforced.
  fillMask(bounds);
  beginPath();
  circle(48.0f, 48.0f, 48.0f);
  beginMask();
  fill();
  endMask();
  enableMask();

  enableColorTransform();
  setColorTransform(vec4(vec3(brightness()), 1.0f), vec4(0.0f));

  ScopedMask mask(bounds.size);
  userDraw();
}

} // otto
