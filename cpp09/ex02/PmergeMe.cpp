#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int nb) : _nb(nb - 1), durationV(0), durationL(0)
{

}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int middle, int right)
{
    std::vector<int> leftVec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> rightVec(vec.begin() + middle + 1, vec.begin() + right + 1);

    unsigned int i = 0, j = 0, k = left;
    while (i < leftVec.size() && j < rightVec.size())
	{
        if (leftVec[i] <= rightVec[j])
		{
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < leftVec.size())
	{
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < rightVec.size())
	{
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSortVector(std::vector<int>& vec, int left, int right)
{
    if (left >= right)
	{
        return;
    }

    int middle = left + (right - left) / 2;
	std::clock_t start = std::clock();
    mergeSortVector(vec, left, middle);
    mergeSortVector(vec, middle + 1, right);
    mergeVector(vec, left, middle, right);
	std::clock_t end = std::clock();
    durationV = (end - start) / (double) CLOCKS_PER_SEC * 1000;
}

void PmergeMe::mergeList(std::list<int>& lst, std::list<int>& leftLst, std::list<int>& rightLst)
{
    while (!leftLst.empty() && !rightLst.empty())
	{
        if (leftLst.front() <= rightLst.front())
		{
            lst.push_back(leftLst.front());
            leftLst.pop_front();
        } else
		{
            lst.push_back(rightLst.front());
            rightLst.pop_front();
        }
    }

    while (!leftLst.empty())
	{
        lst.push_back(leftLst.front());
        leftLst.pop_front();
    }

    while (!rightLst.empty())
	{
        lst.push_back(rightLst.front());
        rightLst.pop_front();
    }
}

void PmergeMe::mergeSortList(std::list<int>& lst)
{
    if (lst.size() <= 1)
	{
        return;
    }

    std::list<int> leftLst, rightLst;
    int middle = lst.size() / 2;
    std::list<int>::iterator it = lst.begin();
	std::clock_t start = std::clock();
    for (int i = 0; i < middle; i++)
	{
        leftLst.push_back(*it);
        ++it;
    }
    while (it != lst.end())
	{
        rightLst.push_back(*it);
        ++it;
    }

    mergeSortList(leftLst);
    mergeSortList(rightLst);
    mergeList(lst, leftLst, rightLst);
	std::clock_t end = std::clock();
	durationL = (end - start) / (double) CLOCKS_PER_SEC * 1000;
}

void PmergeMe::displayL()
{
	std::cout << "Time to process a range of " << _nb << " elements with std::list : " << durationL << " ms" <<  std::endl;
}

void PmergeMe::displayV()
{
	std::cout << "Time to process a range of " << _nb << " elements with std::vector : " << durationV << " ms" <<  std::endl;
}
