#include <iostream>
#include <codecvt>
#include "cppmoji.h"
#include "cpr/cpr.h"

int main() {

    //Just 👏 👏 because 👀 the 👏 dude 👨 has 👏 long 👏 hair 💇 doesn't 😠 make 👎 it 💯 edgy 🎤 👏 👏 👏
    std::string plain_text = "Just :clap: :clap: because :eyes: the :clap: dude :man: has :clap: long :clap: hair :haircut: doesn't :angry: make :thumbsdown: it :100: edgy :microphone:"
                 " :clap: :clap: :clap:";
    std::cout << "Input: " << plain_text << std::endl;
    std::string output = emojiseText(plain_text);
    std::cout << output;
    return 0;
}
