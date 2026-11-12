#ifndef M_BUTTON_H
#define M_BUTTON_H

#include "raylib.h"

#include <string>

class Button {

  public:
    Button(const int& x, const int& y, const int& w, const int& h, const Color& color);
    bool OnRelease(int button);
    bool OnClick(int button);
    bool Held(int button);
    void AddText(const std::string& text, int text_size);
    void Draw();

  private:
    bool MouseIntersects();

    int x_;
    int y_;
    int w_;
    int h_;
    Color color_ = WHITE;

    std::string text_;
    int text_size_;

};

#endif