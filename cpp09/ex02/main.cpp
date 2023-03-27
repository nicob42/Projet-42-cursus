#include "PmergeMe.hpp"

void printSequence(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printSequence(const std::list<int>& lst)
{
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
	{
        std::cout << "Usage: " << argv[0] << " <sequence>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;
    for (int i = 1; i < argc; i++)
	{
        const char* arg = argv[i];
        bool is_digit = true;
        for (int j = 0; arg[j] != '\0'; j++)
		{
            if (!std::isdigit(arg[j]))
			{
                is_digit = false;
                break;
            }
        }
        if (!is_digit)
		{
            std::cerr << "Error: Invalid argument '" << arg << "' (not an integer)" << std::endl;
            return 1;
        }
        int val = std::atoi(argv[i]);
		if (val < 0)
		{
        std::cerr << "Error: Negative value detected !" << std::endl;
        return 1;
    	}
			vec.push_back(val);
        	lst.push_back(val);
    }


	PmergeMe pm(argc);

    std::cout << "Before :"  << std::endl;
    printSequence(vec);

    pm.mergeSortVector(vec, 0, vec.size() - 1);
    pm.mergeSortList(lst);

    std::cout << "After :"  << std::endl;
    printSequence(vec);
	pm.displayL();
	pm.displayV();
    return 0;
}
