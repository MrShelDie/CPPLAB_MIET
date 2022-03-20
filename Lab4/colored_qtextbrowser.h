#ifndef COLOREDQTEXTBROWSER_H
#define COLOREDQTEXTBROWSER_H

#include <QTextBrowser>

class ColoredQTextBrowser : public QTextBrowser
{
public:
	ColoredQTextBrowser();

	void appendRed(const QString& text);
	//void appendGreen(const QString& text);
};

#endif // COLOREDQTEXTBROWSER_H
