#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "csvreader.h"
#include "jsonreader.h"
#include "csvwriter.h"
#include "csv_parse_error_exeption.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->textBrowser->append("Please open the file\n");
    setEnabledAllElements(false);
}

MainWindow::~MainWindow()
{
	if (!employees.empty())
	{
		QString db_to_save;
		if (db_name.endsWith(".json"))
			db_to_save = db_name.left(db_name.length() - 5) + ".csv";
		else
			db_to_save = db_name;
		CSVWriter csv(db_to_save);
		if (csv.isOpen())
			csv.write(employees);
	}
	delete ui;
}

void MainWindow::setEnabledAllElements(bool is_enabled)
{
    ui->searchLine->setEnabled(is_enabled);
    ui->searchButton->setEnabled(is_enabled);
    ui->id_input->setEnabled(is_enabled);
    ui->name_input->setEnabled(is_enabled);
    ui->year_input->setEnabled(is_enabled);
    ui->sex_input->setEnabled(is_enabled);
    ui->add_employee_btn->setEnabled(is_enabled);
}

void MainWindow::readFile(AbstractReader& reader)
{
	employees = reader.readAll();
	setEnabledAllElements(true);
}

void MainWindow::sFindEmployee()
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
            ui->textBrowser->appendGreen(text_to_print);
			was_found = true;
		}
	}
	if (!was_found)
        ui->textBrowser->appendRed("Employee not found\n");
}

void MainWindow::sAddEmployee()
{
	if (
		ui->id_input->text().isEmpty() ||
		ui->year_input->text().isEmpty() ||
		ui->name_input->text().isEmpty()
	)
	{
        ui->textBrowser->appendRed("Invalid input\n");
		return ;
	}

	const int			id = ui->id_input->text().toInt();
	const int			birth_year = ui->year_input->text().toInt();
	const std::string	full_name = ui->name_input->text().toStdString();
	const e_sex			sex = static_cast<e_sex>(ui->sex_input->currentIndex());

	if (id < 0)
	{
		ui->textBrowser->appendRed("Invalid ID\n");
		return;
	}
	else if (birth_year < 0)
	{
		ui->textBrowser->appendRed("Too much age\n");
		return;
	}

	UniversityMan employee(id, birth_year, full_name, sex);
	employees.push_back(employee);
}

void MainWindow::sSearchFile()
{
    try
    {
        db_name = QFileDialog::getOpenFileName(this, "Open file", "../../Data", "(*.csv *.json)");
        if (db_name.endsWith(".csv"))
        {
            CSVReader csv(db_name);
            readFile(csv);
        }
        else if (db_name.endsWith(".json"))
        {
            JSONReader json(db_name);
            readFile(json);
        }
        else
            ui->textBrowser->appendRed("Invalid file format");
    }
	catch (std::ifstream::failure &e)
	{
		ui->textBrowser->appendRed("Error: can not open/read/close file");
	}
    catch (std::exception &e)
    {
        ui->textBrowser->appendRed(e.what());
    }
}
