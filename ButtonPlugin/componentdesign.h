#ifndef COMPONENTDESIGN_H
#define COMPONENTDESIGN_H

#include <QString>
#include <QObject>

class ComponentDesign: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString getBackgroundColor READ getBackgroundColor CONSTANT)
    Q_PROPERTY(QString getTextColor READ getTextColor CONSTANT)
    Q_PROPERTY(QString getHoverColor READ getHoverColor CONSTANT)
    Q_PROPERTY(QString getPressColor READ getPressColor CONSTANT)
    Q_PROPERTY(int getItemHeight READ getItemHeight CONSTANT)
    Q_PROPERTY(int getItemWidth READ getItemWidth CONSTANT)
    Q_PROPERTY(QString getText READ getText CONSTANT)
    Q_PROPERTY(int getFontSize READ getFontSize CONSTANT)


public:
    ComponentDesign();
    QString getBackgroundColor();
    QString getTextColor();
    QString getHoverColor();
    QString getPressColor();
    int getItemHeight();
    int getItemWidth();
    QString getText();
    int getFontSize();
    void setBackgroundColor(QString defineColor = "white");
    void setTextColor(QString defineColor = "black");
    void setHoverColor(QString defineColor = "blue");
    void setPressColor(QString defineColor = "blue");
    void setItemHeight(int defineHeight = 250);
    void setItemWidth(int defineWidth = 100);
    void setItemText(QString defineText = "Button");
    void setFontSize(int defineFont = 20);
private:
    QString backgroundColor;
    QString textColor;
    QString hoverColor;
    QString pressColor;
    int itemHeight;
    int itemWidth;
    QString text;
    int fontSize;
};

#endif // COMPONENTDESIGN_H
