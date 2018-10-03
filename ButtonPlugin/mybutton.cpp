#include "mybutton.h"

MyButton::MyButton(QQuickItem *parent):
    QQuickItem(parent)
{
}

MyButton::~MyButton()
{
}

void MyButton::onButtonClicked()
{
    qDebug()<<"Action triggered NOW from the button";
}


