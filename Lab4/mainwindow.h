#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "university_man.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	const std::string db_name = "db.csv";

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void disableAllElements();

public slots:
	void findEmployee();
	void addEmployee();

private:
	Ui::MainWindow *ui;
	std::vector<UniversityMan> employees;
};
#endif // MAINWINDOW_H
