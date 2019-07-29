#include "NumericBox.h"

NumericBox::NumericBox(short left, short top, int maxVal, int minVal, Border* border, Color textColor, Color backgroundColor) :
    Control(left, top, 16, 3, new SingleBorder(), textColor, backgroundColor),
    value(left + 7, top + 1, 1, new SingleBorder(), textColor, backgroundColor, "0"),
    add(left + 2, top + 1, 1, new SingleBorder(), textColor, backgroundColor, " +"),
    subtract(left + 12, top + 1, 1, new SingleBorder(), textColor, backgroundColor, " -"),
    maxVal(maxVal), minVal(minVal)
{
    int newWidth = 0, temp = 0;
    add.addListener(this);
    subtract.addListener(this);

    if(minVal < 0){
        temp = -minVal;
        if(temp < maxVal)
            temp = maxVal;
    }
    else temp = maxVal;

    while(temp){
        ++newWidth;
        temp /= 10;
    }

    value.setWidth(newWidth);
    subtract.setLeft(newWidth + left + 11);
    setWidth(getWidth() + newWidth -1);
}


void NumericBox::update(int x, int y, string s){
    if(s.compare(" +") == 0){
        addToVal();
        return;
    }

    if(s.compare(" -") == 0){
        subFromVal();
        return;
    }

    return;
}

void NumericBox::addToVal(){
    int numericVal = atoi(value.getValue().c_str());
    if(numericVal >= maxVal)
        return;

    ++numericVal;
    value.setValue(to_string(numericVal));
}

void NumericBox::subFromVal(){
    int numericVal = atoi(value.getValue().c_str());
    if(numericVal <= minVal)
        return;
    --numericVal;
    value.setValue(to_string(numericVal));
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
    add.mousePressed(x, y, isLeft);
    subtract.mousePressed(x, y, isLeft);
}

int NumericBox::setMin(int min){
    if(min > this->maxVal)
        return -1;

    this->minVal = min;
    return 0;
}

int NumericBox::setMax(int max){
    if(max < this->minVal)
        return -1;
        
    this->maxVal = max;
    return 0;
}

int NumericBox::getVal(){
    return atoi(value.getValue().c_str());
}

void NumericBox::setVal(int val) {
    if(val > maxVal) {
        val = maxVal;
    }
    if(val < minVal) {
        val = minVal;
    }
    value.setValue(to_string(val));
}

void NumericBox::draw(Graphics& g, int x, int y, size_t z){
    short relativeX, relativeY;
    if(z == 0){
        Control::draw(g, x, y, z);

        relativeX = value.getLeft();
        relativeY = value.getTop();
        value.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = add.getLeft();
        relativeY = add.getTop();
        add.draw(g, relativeX + 1, relativeY + 1, z);

        relativeX = subtract.getLeft();
        relativeY = subtract.getTop();
        subtract.draw(g, relativeX + 1, relativeY + 1, z);
    }
}