#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "csvreader.h"
#include "csvwriter.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	CSVReader csv(db_name);
	if (csv.isOpen())
		employees = csv.readAll();
	if (!csv.isOpen())
	{
		ui->textBrowser->append("Database access error");
		disableAllElements();
	}
	if (csv.isParseError())
	{
		ui->textBrowser->append("Database parse error");
		disableAllElements();
	}
}

MainWindow::~MainWindow()
{
	if (!employees.empty())
	{
		CSVWriter csv(db_name);
		if (csv.isOpen())
			csv.write(employees);
	}
	delete ui;
}

void MainWindow::disableAllElements()
{
	ui->searchLine->setEnabled(false);
	ui->searchButton->setEnabled(false);
	ui->id_input->setEnabled(false);
	ui->name_input->setEnabled(false);
	ui->year_input->setEnabled(false);
	ui->sex_input->setEnabled(false);
	ui->add_employee_btn->setEnabled(false);
}

void MainWindow::findEmployee()
{
	const std::string	name_to_serch = ui->searchLine->text().toStdString();
	bool				was_found = false;

	for (const auto &e : employees)
	{
		if (e.getFullName() == name_to_serch)
		{
			const auto text_to_print = QString::fromStdString
			(
				"Id: " + std::to_string(e.getId()) + '\n' +
				"Full name: " + e.getFullName() + '\n' +
				"Birth Year: " + std::to_string(e.getBirthYear()) + '\n' +
				"Sex: " + (e.getSex() == e_sex::MALE ? "male" : "female") + '\n'
			);
			ui->textBrowser->append(text_to_print);
			was_found = true;
		}
	}
	if (!was_found)
		ui->textBrowser->append("Employee not found\n");
}

void MainWindow::addEmployee()
{
	if (
		ui->id_input->text().isEmpty() ||
		ui->year_input->text().isEmpty() ||
		ui->name_input->text().isEmpty()
	)
	{
		ui->textBrowser->append("Invalid input\n");
		return ;
	}

	const int			id = ui->id_input->text().toInt();
	const int			birth_year = ui->year_input->text().toInt();
	const std::string	full_name = ui->name_input->text().toStdString();
	const e_sex			sex = static_cast<e_sex>(ui->sex_input->currentIndex());

	if (id < 0 || birth_year < 0)
	{
		ui->textBrowser->append("Invalid input\n");
		return ;
	}

	UniversityMan employee(id, birth_year, full_name, sex);
	employees.push_back(employee);
}
