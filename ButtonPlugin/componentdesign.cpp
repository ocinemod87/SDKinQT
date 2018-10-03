#include "componentdesign.h"

ComponentDesign::ComponentDesign()
{
    setBackgroundColor("#AA7939");
    //AA7939
    setTextColor("black");
    //294F6D
    setPressColor("blue");
    setHoverColor("#294F6D");
    setItemHeight(50);
    setItemWidth(200);
    setFontSize();
    setItemText("Text from Main Application");
    setFontSize(10);
}

QString ComponentDesign::getBackgroundColor()
{
    return backgroundColor;
}

QString ComponentDesign::getTextColor()
{
    return textColor;
}

QString ComponentDesign::getHoverColor()
{
    return hoverColor;
}

QString ComponentDesign::getPressColor()
{
    return pressColor;
}

int ComponentDesign::getItemHeight()
{
    return itemHeight;
}

int ComponentDesign::getItemWidth()
{
    return itemWidth;
}

QString ComponentDesign::getText()
{
    return text;
}

int ComponentDesign::getFontSize()
{
    return fontSize;
}

void ComponentDesign::setBackgroundColor(QString defineColor)
{
    backgroundColor = defineColor;
}

void ComponentDesign::setTextColor(QString defineColor)
{
    textColor = defineColor;
}

void ComponentDesign::setHoverColor(QString defineColor)
{
    hoverColor = defineColor;
}

void ComponentDesign::setPressColor(QString defineColor)
{
    pressColor = defineColor;
}

void ComponentDesign::setItemHeight(int defineHeight)
{
    itemHeight = defineHeight;
}

void ComponentDesign::setItemWidth(int defineWidth)
{
    itemWidth = defineWidth;
}

void ComponentDesign::setItemText(QString defineText)
{
    text = defineText;
}

void ComponentDesign::setFontSize(int defineFont)
{
    fontSize = defineFont;
}
