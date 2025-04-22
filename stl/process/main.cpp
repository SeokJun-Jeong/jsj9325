#include "data_process.hpp"
#include <iostream>

using namespace std;

int main()
{
    vector<string> words = {"apple", "ant", "banana", "bear", "cat"};
    DataProcessor processor(words);

    auto sorted = processor.sort_by_length();
    cout << "Original sequence : " << endl;     //작성순서
    for (const auto& word : processor.data_)
    {
        cout << word << endl;
    }
    
    cout << "Sorted by length : " << endl;      //길이순
    for (const auto& word : sorted)
    {
        cout << word << endl;
    }
    
    cout << "Filtered by prefix : " << endl;
    auto filtered = processor.filter_by_prefix("b");        //b시작 문자표시
    for (const auto &word : filtered)
    {
        cout << word << endl;
    }
    
    //capture mutable사용
    int min_length = 4;
    auto count_long = [=]() mutable
    {
        int count = 0;
        for (const auto &word : words)
        {
            if (word.length() >= min_length)
            {
                count++;
            }
            
        }
        min_length++;
        cout << "min_length : " << min_length << endl;
        return count;
    };
    cout << "Words with length >= 4\t " << count_long() << endl;
    cout << "After mutable change, min_length : " << min_length << endl;
    return 0;
}