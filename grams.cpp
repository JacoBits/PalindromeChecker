#include<iostream>

const int ALPHABET = 26;

bool IsHeterogram(int* counters){
    for(int i = 0; i < ALPHABET; i++){
        if(counters[i] > 1)
            return false;
    }

    return true;
}

bool IsIsogram(int* counters){
    int last_letter_index = 0;

    for(int i = 0; i < ALPHABET; i++){
        if(counters[i] > 0 && counters[last_letter_index] > 0 && counters[i] != counters[last_letter_index]){
                return false;
        }
        if(counters[i] > 0)
            last_letter_index = i;

    }
    return true;
}

bool IsPangram(int* counters){
    for(int i = 0; i < ALPHABET; i++){
        if(counters[i] == 0)
            return false;
    }

    return true;
}



int main()
{

    int counter[ALPHABET] = {0};


    std::cout << "Input a sentence\n";
    std::string sentence;
    getline(std::cin, sentence);

    for(int i = 0; i < sentence.length(); i++)
    {
        if(isalpha(sentence.at(i)))
            counter[tolower(sentence.at(i)) - 'a']++;
            
    }

    /*for(int i = 0; i < ALPHABET; i++){
        std::cout << counter[i] << std::endl;
    }*/

    std::cout << "The sentence is ";

    if(!IsHeterogram(counter))
        std::cout << "not ";
    
    std::cout << "a heterogram, ";

    if(!IsIsogram(counter))
        std::cout << "not ";
    
    std::cout << "an isogram, and ";

    if(!IsPangram(counter))
        std::cout << "not ";
    
    std::cout << "a pangram.\n";

    return 0;

}