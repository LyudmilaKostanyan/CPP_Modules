#include <iostream>
#include <fstream>

int	read_from_file(std::string file_name, std::string *file_cont)
{
	std::ifstream	ifile;
	char			cont;

	ifile.open(file_name.c_str());
	if (!ifile.is_open())
	{
		std::cout << "Wrong file name" << std::endl;
		return (2);
	}
	while (ifile.get(cont))
		file_cont->push_back(cont);
	ifile.close();
	return (0);
}

void	replace(std::string file_name, std::string file_cont, std::string s1, std::string s2)
{
	std::ofstream	ofile;

	file_name.append(".replace");
	ofile.open(file_name.c_str(), std::ios::app);
	int	index = file_cont.find(s1);
	while (index != -1 && !s1.empty() && !s2.empty())
	{
		file_cont.erase(index, s1.length());
		file_cont.insert(index, s2);
		index = file_cont.find(s1, index);
	}
	ofile << file_cont;
	ofile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string		file_name = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		file_cont;
	if (read_from_file(file_name, &file_cont))
		return (2);
	std::cout << file_cont;
	replace(file_name, file_cont, s1, s2);
	return (0);
}