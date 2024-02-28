#include <iostream>
#include <fstream>

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
	std::ifstream	ifile;
	std::ofstream	ofile;
	std::string		file_cont;
	char			cont;
	ifile.open(file_name.c_str());
	if (!ifile.is_open())
	{
		std::cout << "Wrong file name" << std::endl;
		return (2);
	}
	while (ifile.get(cont))
		file_cont.push_back(cont);
	ifile.close();
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
	return (0);
}