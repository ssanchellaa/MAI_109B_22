#include "../include/Table.hpp"
#include "../include/Node.hpp"
#include <cmath>
#include <climits>
bool Table::AddEntry(std::pair<int32_t, std::string> entry)
{
    entries.push_back(entry);
    return true;
}


 

void Table::TournamentSort() { 
    size_t log = static_cast<size_t>(ceil(log2(entries.size())));
    Vector<std::pair<int32_t, std::string>> supportVec;
    Vector<std::pair<int32_t, std::string>> sortedVec;
    for(size_t i = 0; i <= pow(2, log+1); ++i)
    {
        supportVec.push_back(std::pair<int32_t, std::string>(INT_MAX, "bla-bla"));
    }
    supportVec.push_back(std::pair<int32_t, std::string>(INT_MAX, "bla-bla"));
    for(size_t i = 0; i < entries.size(); ++i)
    {
        supportVec[i+1] = entries[i];
    }

    while(sortedVec.size() != entries.size())
    {
        size_t currentAddiition = pow(2,log);
        size_t offset = 0;
        
        while(currentAddiition > 1)
        {
            for(size_t i = 1; i <= currentAddiition/2; ++i)
            {
                if(supportVec[i+offset].first < supportVec[i+offset+currentAddiition/2].first)
                {
                    if(supportVec[i+offset].first != INT_MAX)
                    {
                        if(supportVec[i+offset].first < supportVec[currentAddiition + i + offset].first)
                        {
                            auto temp = supportVec[i+offset];
                            supportVec[i+offset] = supportVec[currentAddiition + i + offset];
                            supportVec[currentAddiition + i + offset] = temp;
                        }
                    }
                    else
                    {
                        if(supportVec[currentAddiition + i + offset] > supportVec[i+offset])
                            supportVec[currentAddiition + i + offset] = supportVec[i+offset];
                    }
                    
                }
                    
                else
                {
                    if(supportVec[i+offset+currentAddiition/2].first != INT_MAX)
                    {
                        if(supportVec[i+offset+currentAddiition/2].first < supportVec[currentAddiition + i + offset].first)
                        {
                            auto temp = supportVec[i+offset+currentAddiition/2];
                            supportVec[i+offset+currentAddiition/2] = supportVec[currentAddiition + i + offset];
                            supportVec[currentAddiition + i + offset] = temp;
                        }
                    }
                    else
                    {
                        if(supportVec[currentAddiition + i + offset] > supportVec[i+offset+currentAddiition/2])
                            supportVec[currentAddiition + i + offset] = supportVec[i+offset+currentAddiition/2];
                    }
                }
                if(currentAddiition == 2)
                {
                    supportVec[0] = supportVec[currentAddiition + i + offset];
                    supportVec[currentAddiition + i + offset].first = INT_MAX;
                }
            }
            offset += currentAddiition; 
            currentAddiition/=2;
        }
        sortedVec.push_back(supportVec[0]);
    }
    entries = sortedVec;
    
}

void Table::Swap(int32_t firstInd, int32_t secondInd)
{
    auto curr = entries[firstInd];
    entries[firstInd] = entries[secondInd];
    entries[secondInd] = curr;
}

std::pair<int32_t, std::string> Table::BinarySearch(int32_t key) const
{
    size_t leftBound = 0;
    size_t rightBound = entries.size();
    std::pair<int32_t, std::string> currentEntry(0,"oops");
    while(leftBound <= rightBound)
    {
        size_t currentIndex = leftBound + (rightBound - leftBound)/2;
        if(entries[currentIndex].first == key)
        {
            currentEntry = entries[currentIndex];
            return currentEntry;
        }
        if(entries[currentIndex].first < key)
            leftBound = currentIndex + 1;
        else
            rightBound = currentIndex - 1;
    }
    return currentEntry;
}
std::ostream& operator<<(std::ostream& os, Table& table)
{
    for(size_t i = 0; i < table.entries.size(); ++i)
    {
        std::cout << table.entries[i].first << " " << table.entries[i].second << std::endl;
    }
    return os;
}