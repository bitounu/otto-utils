#pragma once

#include "gfx.hpp"
#include "timeline.hpp"

#include <functional>

namespace otto {

struct Display {
  Display(const vec2 &size) : bounds{ vec2(0.0f), size } {}

  float daydreamDelay = 15.0f;
  float sleepDelay = 30.0f;

  ch::Output<float> brightness = 1.0f;

  ch::TimelineItemControlRef sleepTimeout;
  bool isSleeping = false;

  Rect bounds;

  void sleep();
  bool wake();

  void update(const std::function<void()> userUpdate);
  void draw(const std::function<void()> userDraw) const;
};

} // otto
