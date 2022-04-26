#include "coloredqtextbrowser.h"

ColoredQTextBrowser::ColoredQTextBrowser(QWidget* parent)
    : QTextBrowser(parent)
{

}

void ColoredQTextBrowser::appendRed(const QString& text)
{
    auto color = textColor();
    setTextColor(Qt::red);
	append(text);
    setTextColor(color);
}

void ColoredQTextBrowser::appendGreen(const QString& text)
{
    auto color = textColor();
    setTextColor(Qt::green);
    append(text);
    setTextColor(color);
}
