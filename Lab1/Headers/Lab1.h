/*
 * Author:	Ivchenko Nikolay
 * Group:	IVT-21
 * Date:	07.02.2022
 * Variant:	2
 *
 * The program receives two arguments as input - the name of the file to read and the file to write.
 * This implementation assumes that the entries in the CSV file are separated
 * by the ";" symbol. It is also assumed that the entries in the file are in
 * the same order in which they were presented in the task.
 * Function calls are not protected by the try-catch block.
*/

#ifndef LAB1_H
#define LAB1_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define ERROR -1
#define SUCCESS 0

enum e_sex
{
	MALE,
	FEMALE
};

struct s_employee
{
	unsigned int	nb;
	unsigned int	birth_year;
	std::string		full_name;
	e_sex			sex;
};

/* Opens files for reading and writing.
 * In case of invalid parameters, writes an error message and terminates the program */
void open_files(int argc, char **argv, std::ifstream &in, std::ofstream &out);

std::vector<std::string> split(const std::string &str, char delim);

/* Reads data from a file and writes it to a vector of employee structures.
 * In case of an error, returns -1 */
int parse_file(std::ifstream &file, std::vector<s_employee> &employees);

/* To STDOUT */
void print_vector(const std::vector<s_employee> &employees);

/* To file */
void write_vector(const std::vector<s_employee> &employees, std::ofstream &file);

#endif // LAB1_H
