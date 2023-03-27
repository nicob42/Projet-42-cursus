#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cctype>

class PmergeMe
{
public:
    PmergeMe(int nb);

    ~PmergeMe();
    void mergeSortVector(std::vector<int>& vec);

    void mergeSortList(std::list<int>& lst);
	void mergeSortVector(std::vector<int>& vec, int left, int right);


	void displayV();
	void displayL();

private:
	std::vector<int> vec;
    std::list<int> lst;
	int _nb;
    void mergeVector(std::vector<int>& vec, int left, int middle, int right);
    void mergeList(std::list<int>& lst, std::list<int>& leftLst, std::list<int>& rightLst);
	double durationV;
	double durationL;
};

#endif
