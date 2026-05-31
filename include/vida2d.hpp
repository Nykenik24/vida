#pragma once

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "vida2d/color.hpp"
#include "vida2d/int_types.hpp"
#include <mutex>
#include <stdexcept>
#include <string>
#include <sys/types.h>

namespace Vida2D {
class Context {
public:
  Context(const Context &) = delete;
  Context(Context &&) = delete;
  Context &operator=(const Context &) = delete;
  Context &operator=(Context &&) = delete;

  ~Context();

  static Context &GetInstance();

  static void Init(std::string window_title, unsigned width, unsigned height);

  int IsRunning() const;
  void SetRunning(bool running);

  void Quit();

  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;

  Color clear_color = Black;

  TTF_Font *current_font = nullptr;
  TTF_TextEngine *text_engine;

  double dt = 0;
  uint64 last_time;

private:
  Context(std::string window_title, unsigned width, unsigned height);

  static Context *instance;
  static std::mutex mtx;
};

inline void Context::Init(std::string window_title, unsigned width,
                          unsigned height) {
  std::lock_guard<std::mutex> lock(mtx);
  if (!instance) {
    instance = new Context(std::move(window_title), width, height);
  }
}

inline Context &Context::GetInstance() {
  std::lock_guard<std::mutex> lock(mtx);
  if (!instance) {
    throw std::runtime_error("Context not initialized — call Init() first");
  }
  return *instance;
}

inline Context::Context(std::string window_title, unsigned width,
                        unsigned height)
    : running(true) {
  window = SDL_CreateWindow(window_title.c_str(), width, height, 0);
  renderer = SDL_CreateRenderer(window, NULL);
  TTF_Init();
  text_engine = TTF_CreateRendererTextEngine(renderer);
}

inline Context::~Context() { Quit(); }

inline void Context::Quit() {
  if (text_engine) {
    TTF_DestroyRendererTextEngine(text_engine);
    text_engine = nullptr;
  }
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  TTF_Quit();
  SDL_Quit();
}

bool ClearScreen();
void PollEvents();

inline bool Running() { return Context::GetInstance().running; }

bool Update();
} // namespace Vida2D
