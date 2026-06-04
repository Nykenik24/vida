// clang-format off
#include <GL/glew.h>
// clang-format on
#include "vida/render/Renderer.hpp"
#include "vida/Color.hpp"
#include "vida/Vector.hpp"
#include <cstdlib>
#include <string>

namespace Vida {

// Converts pixel coords (origin top-left) to NDC (origin center, Y flipped).
static void PixelToNDC(float x, float y, float w, float h, float &nx,
                       float &ny) {
  nx = (x / w) * 2.0f - 1.0f;
  ny = -((y / h) * 2.0f - 1.0f);
}

static void SetColor(GLuint program, ColorRGBA color) {
  GLint loc = glGetUniformLocation(program, "uColor");
  glUniform4f(loc, color.r / 255.0f, color.g / 255.0f, color.b / 255.0f,
              color.a / 255.0f);
}

static const char *VERT_SRC = R"glsl(
  #version 330 core
  layout(location = 0) in vec2 pos;
  void main() {
    gl_Position = vec4(pos, 0.0, 1.0);
  }
)glsl";

static const char *FRAG_SRC = R"glsl(
  #version 330 core
  uniform vec4 uColor;
  out vec4 fragColor;
  void main() {
    fragColor = uColor;
  }
)glsl";

static GLuint CompileShader(GLenum type, const char *src) {
  GLuint s = glCreateShader(type);
  glShaderSource(s, 1, &src, nullptr);
  glCompileShader(s);
  GLint ok;
  glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
  if (!ok) {
    char log[512];
    glGetShaderInfoLog(s, 512, nullptr, log);
    fprintf(stderr, "Shader error: %s\n", log);
  }
  return s;
}

void Renderer::InitShaders() {
  GLuint vert = CompileShader(GL_VERTEX_SHADER, VERT_SRC);
  GLuint frag = CompileShader(GL_FRAGMENT_SHADER, FRAG_SRC);
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vert);
  glAttachShader(shaderProgram, frag);
  glLinkProgram(shaderProgram);
  glDeleteShader(vert);
  glDeleteShader(frag);

  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4, nullptr,
               GL_DYNAMIC_DRAW); // up to 2 verts
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);
}

Renderer::Renderer(std::string title, Vector2f size) : windowSize(size) {
  static bool initialized = false;
  if (!initialized) {
    int argc = 0;
    glutInit(&argc, nullptr);
    initialized = true;
  }
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(static_cast<int>(size.x), static_cast<int>(size.y));
  windowId = glutCreateWindow(title.c_str());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glutDisplayFunc([] {});
  glutCloseFunc([] { Renderer::shouldClose = true; });

  GLenum res = glewInit();
  if (res != GLEW_OK) {
    fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    exit(1);
  }

  InitShaders();
}

Renderer::~Renderer() {
  glDeleteProgram(shaderProgram);
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  if (windowId != 0)
    glutDestroyWindow(windowId);
}

void Renderer::BeginFrame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EndFrame() {
  glutSwapBuffers();
  glutMainLoopEvent();
}

void Renderer::DrawDot(Vector2f pos, ColorRGBA color, float size) {
  float nx, ny;
  PixelToNDC(pos.x, pos.y, windowSize.x, windowSize.y, nx, ny);

  float verts[] = {nx, ny};

  glUseProgram(shaderProgram);
  SetColor(shaderProgram, color);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);

  glPointSize(size);
  glDrawArrays(GL_POINTS, 0, 1);
  glBindVertexArray(0);
}

void Renderer::DrawLine(Vector2f a, Vector2f b, ColorRGBA color, float width) {
  float nx1, ny1, nx2, ny2;
  PixelToNDC(a.x, a.y, windowSize.x, windowSize.y, nx1, ny1);
  PixelToNDC(b.x, b.y, windowSize.x, windowSize.y, nx2, ny2);

  float verts[] = {nx1, ny1, nx2, ny2};

  glUseProgram(shaderProgram);
  SetColor(shaderProgram, color);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);

  glLineWidth(width);
  glDrawArrays(GL_LINES, 0, 2);
  glBindVertexArray(0);
}

} // namespace Vida
