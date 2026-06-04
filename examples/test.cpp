#include "vida/Color.hpp"
#include "vida/Engine.hpp"
#include "vida/Event.hpp"
#include "vida/Game.hpp"
#include "vida/Vector.hpp"
#include "vida/render/Renderer.hpp"
#include <iostream>

class MyGame : public Vida::Game {
public:
  bool Loop(float dt) override;
  bool Draw(Vida::Renderer *render) override;
  void Handle(Vida::Event ev) override;

private:
};

bool MyGame::Loop(float dt) { return true; }

bool MyGame::Draw(Vida::Renderer *render) {
  render->DrawDot(Vida::Vector2f(5.0f, 5.0f));
  render->DrawLine(Vida::Vector2f(10, 10), Vida::Vector2f(50, 20), Vida::Red);
  return true;
}

void MyGame::Handle(Vida::Event ev) {
  switch (ev.type) {
  case Vida::EventType::DrawFirstEnter:

    std::cout << "first draw!" << std::endl;
    break;
  default:
    return;
  }
}

int main(void) {
  auto engine = Vida::Engine::Create<MyGame>();
  engine.SetWindowTitle("My cool game");
  engine.SetWindowSize(Vida::Vector2f(1080, 720));

  while (engine.Running()) {
    engine.Update();
  }
  return 0;
}
