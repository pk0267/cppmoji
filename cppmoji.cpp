#include <iostream>
#include "cppmoji.h"
#include <vector>
#include <cpr/cpr.h>
#include "json.hpp"
#include "sstream"


std::vector<std::string_view> split(std::string_view text, std::string_view delimiter = " ")
{
    std::vector<std::string_view> output;
    size_t first = 0;

    while (first < text.size())
    {
        const auto second = text.find_first_of(delimiter, first);

        if (first != second)
            output.emplace_back(text.substr(first, second-first));

        if (second == std::string_view::npos)
            break;

        first = second + 1;
    }
    return output;
}

std::string_view getEmojiFromCode(std::string_view emoji_code)
{
    try {
        std::string request_url = ("https://www.emojidex.com/api/v1/emoji/");
        request_url = request_url.append(emoji_code);
        auto r = cpr::Get(cpr::Url{request_url});
        auto json_response = nlohmann::json::parse(r.text);

        if(r.status_code != 200)
            return emoji_code;
        else {
            nlohmann::json json_data;
            std::stringstream json_stream(r.text);
            json_stream >> json_data;
            std::string emoji_in_quotes = to_string(json_data["moji"]);
            std::wstring emoji(emoji_in_quotes.begin()+1, emoji_in_quotes.end()-1);
            return emoji_in_quotes.substr(1, emoji_in_quotes.size()-2);
        }
    }
    catch(const std::exception& e)
    {
        return emoji_code;
    }

}

std::string emojiseText(std::string text)
{
    auto tokens = split(text, " ");

    std::string emojised_tokens[tokens.size()];

    std::vector<std::pair <int, std::string>> indexed_tokens;

    for(int i = 0; i < tokens.size(); i++) {
        const std::pair<int, std::basic_string_view<char>> &pair = std::make_pair(i, tokens[i]);
        indexed_tokens.emplace_back(pair);
    }

    for(auto indexed_token: indexed_tokens)
    {
        int i = indexed_token.first;
        auto token = indexed_token.second;
        if(token.at(0) == ':' && token.at(token.length()-1) == ':')
        {
            emojised_tokens[i] = (getEmojiFromCode(token.substr(1, token.length()-2)));
        }
        else
            emojised_tokens[i] = (token);
    }



    std::string emojised_text;

    for(const auto &emojised_token: emojised_tokens)
        emojised_text.append(emojised_token + " ");

    return emojised_text;
}