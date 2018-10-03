#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QQuickItem>

class MyButton : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MyButton)

public:
    MyButton(QQuickItem *parent = nullptr);
    ~MyButton();
    /*This function is triggered from the button
      it can be connected to a desired behaviour*/
    Q_INVOKABLE void onButtonClicked();
};

#endif // MYBUTTON_H
