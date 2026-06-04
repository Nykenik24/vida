#include "vida/Color.hpp"
#include "vida/Engine.hpp"
#include "vida/Event.hpp"
#include "vida/Game.hpp"
#include "vida/Vector.hpp"
#include "vida/render/Renderer.hpp"

class MyGame : public Vida::Game {
public:
  bool Loop(float dt) override;
  bool Draw(Vida::Renderer *render) override;
  void Handle(Vida::Event ev) override;

private:
};

bool MyGame::Loop(float dt) { return true; }

bool MyGame::Draw(Vida::Renderer *render) {
  render->DrawFillPolygon(
      {{50, 300}, {200, 100}, {350, 300}, {300, 300}, {200, 175}, {100, 300}},
      Vida::ColorRGBA(0, 255, 255));
  return true;
}

void MyGame::Handle(Vida::Event ev) {
  switch (ev.type) {
  case Vida::EventType::DrawFirstEnter:
  default:
    return;
  }
}

int main(void) {
  auto engine = Vida::Engine::Create<MyGame>();
  engine.SetWindowTitle("My cool game");
  engine.SetWindowSize(Vida::Vector2f(1080, 720));

  return engine.Run();
}
