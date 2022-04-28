#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "abstract_reader.h"
#include "university_man.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

    void setEnabledAllElements(bool is_enabled);

public slots:
    void sFindEmployee();
    void sAddEmployee();
    void sSearchFile();

private:
	Ui::MainWindow *ui;
    QString db_name;
	std::vector<UniversityMan> employees;

private:
    void readFile(AbstractReader& reader);
};
#endif // MAINWINDOW_H
