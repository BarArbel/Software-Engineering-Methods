#include "MessageBox.h"
#include "../Common/Border/SingleBorder.h"
#include "../Common/Border/NullBorder.h"

semMessageBox::semMessageBox(short left, short top, short width, Border* border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button* showButton) :
    Control(left, top, width, 7, border, textColor, backgroundColor),
    message(Label((width - message.size()) / 2, 0, message.size(), 1, new NullBorder, textColor, backgroundColor, message)),
    ok(Button(0, 4, ok.size(), 1, new SingleBorder, Color::White, Color::Green, ok)),
    cancel(Button(width - cancel.size() - 2, 4, cancel.size(), 1, new SingleBorder, Color::White, Color::Red, cancel)),
    showButton(showButton) {
        returnValue = "";
        show = false;
        this->ok.addListener(this);
        this->cancel.addListener(this);
        this->showButton->addListener(this);
}

string semMessageBox::getMessage() {
    return message.getValue();
}

void semMessageBox::setMessage(string message) {
    this->message.setValue(message);
}

void semMessageBox::draw(Graphics& g, int x, int y, size_t z) {
    int relativeX, relativeY;
    if(show == true && z == 0) {
        Control::draw(g, x, y, z);
        relativeX = message.getLeft();
        relativeY = message.getTop();
        message.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = ok.getLeft();
        relativeY = ok.getTop();
        ok.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = cancel.getLeft();
        relativeY = cancel.getTop();
        cancel.draw(g, x + relativeX + 1, y + relativeY + 1, z);
    }
}

void semMessageBox::mousePressed(int x, int y, bool isLeft) {
    if(show == true) {
        ok.mousePressed(x - getLeft() - 1, y - getTop() - 1, isLeft);
        cancel.mousePressed(x - getLeft() - 1, y - getTop() - 1, isLeft);
    }
}

void semMessageBox::update(int x, int y) {
    int okl = ok.getLeft(), okt = ok.getTop(), okw = ok.getWidth(), okh = ok.getHeight();
    int cal = cancel.getLeft(), cat = cancel.getTop(), caw = cancel.getWidth(), cah = cancel.getHeight();
    int shl = showButton->getLeft(), sht = showButton->getTop(), shw = showButton->getWidth(), shh = showButton->getHeight();
    if(x >= okl && x <= okl + okw && y >= okt && y <= okt + okh) {
        returnValue = "OK";
        show = false;
        Control::setMessageBoxLock(false);
    }
    else if(x >= cal && x <= cal + caw && y >= cat && y <= cat + cah) {
        returnValue = "CANCEL";
        show = false;
        Control::setMessageBoxLock(false);
    }
    else if(x >= shl && x <= shl + shw && y >= sht && y <= sht + shh){
        returnValue = "";
        show = true;
        Control::setFocus(*this);
        Control::setMessageBoxLock(true);
    }
}
