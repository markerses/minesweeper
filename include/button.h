#ifndef M_BUTTON_H
#define M_BUTTON_H

class Button {

  public:
    Button(const int& x, const int& y, const int& w, const int& h);
    bool Clicked();
    void Draw();

  private:
    bool MouseIntersects();

    int x_;
    int y_;
    int w_;
    int h_;

};

#endif