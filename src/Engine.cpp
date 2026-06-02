#include "vida/Engine.hpp"
#include "vida/Event.hpp"
#include <chrono>

namespace Vida {
bool Engine::Update() {
  auto now = std::chrono::high_resolution_clock::now();
  dt = std::chrono::duration<float>(now - prev).count();
  prev = now;

  if (first_loop) {
    first_loop = false;
    game->Handle(Event(EventType::LoopFirstEnter));
  }
  game->Handle(Event(EventType::LoopEnter));
  if (!game->Loop(dt)) {
    Quit();
    return false;
  }
  game->Handle(Event(EventType::LoopExit));

  if (first_draw) {
    first_draw = false;
    game->Handle(Event(EventType::DrawFirstEnter, &renderer));
  }
  if (!renderer.ShouldClose()) {
    game->Handle(Event(EventType::DrawEnter, &renderer));
    renderer.BeginFrame();
    if (!game->Draw(&renderer)) {
      Quit();
      return false;
    }
    renderer.EndFrame();
    game->Handle(Event(EventType::DrawExit, &renderer));
  } else {
    Quit();
  }

  return true;
}

void Engine::Quit() { running = false; }
} // namespace Vida
