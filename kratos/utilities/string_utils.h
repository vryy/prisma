/*
see kratos/LICENSE.txt
*/

/* *********************************************************
*
*   Last Modified by:    $Author: Giang Bui-Hoang $
*   Date:                $Date: 8 Apr 2025 $
*   Revision:            $Revision: 1.0 $
*
* ***********************************************************/

#if !defined(KRATOS_STRING_UTILS )
#define  KRATOS_STRING_UTILS

#include <vector>
#include <string>

namespace Kratos
{

class StringUtils
{
public:

    /// Get the string without quote if it starts and ends by quote
    /// The quote can be '\"' or '\'' or any single character
    static std::string StripQuote(const std::string& str, const char quote)
    {
        if (str.front() == quote && str.back() == quote)
        {
            return str.substr(1, str.size()-2);
        }
        else
            return str;
    }

    /// Split the string to words using a terminator
    static std::vector<std::string> Split(const std::string& input, const char terminator)
    {
        std::vector<std::string> parts;

        std::size_t start = 0;
        std::size_t end;

        while ((end = input.find(terminator, start)) != std::string::npos)
        {
            if (end > start)
            {
                parts.push_back(input.substr(start, end - start));
            }
            start = end + 1;
        }

        // Add the last part after the final underscore
        if (start < input.length())
        {
            parts.push_back(input.substr(start));
        }

        return std::move(parts);
    }

    /// Check if a string is a valid integer, then one can use std::atoi to convert
    static bool IsValidInteger(const std::string& str)
    {
        std::size_t i = 0;

        // Skip leading whitespaces
        while (i < str.length() && std::isspace(str[i])) ++i;

        // Optional + or - sign
        if (i < str.length() && (str[i] == '+' || str[i] == '-')) ++i;

        // At least one digit must follow
        if (i >= str.length() || !std::isdigit(str[i])) return false;

        // Check remaining characters
        for (; i < str.length(); ++i)
            if (!std::isdigit(str[i])) return false;

        return true;
    }
};

}  /* namespace Kratos.*/

#endif /* KRATOS_STRING_UTILS  defined */
