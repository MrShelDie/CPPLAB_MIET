#include "colored_qtextbrowser.h"

ColoredQTextBrowser::ColoredQTextBrowser()
{

}

void ColoredQTextBrowser::appendRed(const QString& text)
{
	setStyleSheet("color: rgb(255, 0, 0);");
	append(text);
}
