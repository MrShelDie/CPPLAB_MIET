#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	CSVReader csv("db.csv");
	if (csv.isOpen())
		employees = csv.readAll();
	if (!csv.isOpen() || employees.empty())
	{
		if (!csv.isOpen())
			ui->textBrowser->append("Database access error");
		else
			ui->textBrowser->append("Database parse error");
		ui->searchLine->setEnabled(false);
		ui->searchButton->setEnabled(false);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::sFindEmployee()
{
	const auto name_to_serch = ui->searchLine->text().toStdString();
	bool was_found = false;

	for (const auto &e : employees)
	{
		if (e.getFullName() == name_to_serch)
		{
			const auto text_to_print = QString::fromStdString
			(
				"Id: " + std::to_string(e.getId()) + '\n' +
				"Full name: " + e.getFullName() + '\n' +
				"Birth Year: " + std::to_string(e.getBirthYear()) + '\n' +
				"Sex: " + std::to_string(e.getSex()) + '\n'
			);
			ui->textBrowser->append(text_to_print);
			was_found = true;
		}
	}
	if (!was_found)
		ui->textBrowser->append("Employee not found\n");
}
