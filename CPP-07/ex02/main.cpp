#include "Array.hpp"

int main()
{
    //test int array
    std::cout << "=== TEST INT ARRAY ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "--------- OG INT ARRAY ---------" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << "\n--- MODIFIED INT ARRAY (*10) ---" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
        std::cout << "Modified intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼" << std::endl;

    //test string array
    std::cout << "\n=== TEST STRING ARRAY ===" << std::endl;
    Array<std::string> strArray(5);
    strArray[0] = "𓇢𓆸 NIHAO";
    strArray[1] = "⋆˚ 𝜗𝜚˚⋆ BONJOUR";
    strArray[2] = "🃁 BIEN OU BIEN";
    strArray[3] = "🍪";
    strArray[4] = "💇";
    strArray[4] = "💅";
    
    std::cout << "------ OG STR ARRAY ------" << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
        std::cout << "strArray[" << i << "] " << strArray[i] << std::endl;
    std::cout << "\n--- MODIFIED STR ARRAY ---" << std::endl;
    for (size_t i = 0; i < strArray.size(); i++)
    {
        strArray[i] += " ⛧°𓃵 ♫⋆｡♪ ₊˚♬";
        std::cout << "Modified strArray[" << i << "] " << strArray[i] << std::endl;
    }
    return 0;
}