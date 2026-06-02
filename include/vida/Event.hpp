#pragma once

#include "vida/render/Renderer.hpp"
namespace Vida {
enum class EventType {
  LoopFirstEnter,
  LoopEnter,
  LoopExit,
  DrawFirstEnter,
  DrawEnter,
  DrawExit,
};

struct Event {
  EventType type;
  Renderer *render = nullptr;

  Event(EventType type) : type(type) {}
  Event(EventType type, Renderer *render) : type(type), render(render) {}
};
} // namespace Vida
