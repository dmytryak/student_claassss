#include "cipher.h"

std::string encryptor(std::string text)
{
    std::vector<char> word(text.begin(), text.end());
    std::string alp = "-J2i6nIFS98RMyhA5uHNC#Pc_Gz =*%t+EBDXUQ3vb&dpxk$Y)s1j(LT7@r?wWg4OlV^qafZem!K0o";

    for (int i = 0; i < (int)text.length(); i++)
    {
        for (int j = 0; j < (int)alp.length(); j++)
        {
            if (word[i] == alp[j])
            {
                word[i] = alp[(j + 7) % alp.length()];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

std::string decrypt(std::string text)
{
    std::vector<char> word(text.begin(), text.end());
    std::string alp = "-J2i6nIFS98RMyhA5uHNC#Pc_Gz =*%t+EBDXUQ3vb&dpxk$Y)s1j(LT7@r?wWg4OlV^qafZem!K0o";

    for (int i = 0; i < (int)text.length(); i++)
    {
        for (int j = 0; j < (int)alp.length(); j++)
        {
            if (word[i] == alp[j])
            {
                word[i] = alp[(j - 7 + alp.length()) % alp.length()];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}
