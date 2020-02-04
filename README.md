# Emojis for Modern C++ 😊

Welcome to **CppMoji**. CppMoji is a C++ library that replaces emoji shortcodes in a string with unicode emojis. Throughout the project, the creators attempted to explore modern C++ constructs - including _string_views_, parallel _for_each_ loops, and structured bindings.

The library obtains the emojis from the [Emojidex API](https://developer.emojidex.com/). 

## Dependencies

1. [The C++ Requests Library](https://github.com/whoshuu/cpr)
2. [JSON for Modern C++](https://github.com/nlohmann/json)
3. [Libcurl](https://curl.haxx.se/libcurl/)
## Usage

    #include "cppmoji.h"
    
    int main() {
    std::string plain_text = "Just :clap: :clap: because :eyes: the :clap: dude :man: has :clap: long :clap: hair :haircut: doesn't :angry: make :thumbsdown: it :100: edgy :microphone: :clap: :clap: :clap:";
    std::string emojised_text = emojiseText(plain_text);
	// Just 👏 👏 because 👀 the 👏 dude 👨 has 👏 long 👏 hair 💇 doesn't 😠 make 👎 it 💯 edgy 🎤 👏 👏 👏 
    return 0;
    }


## Future Plans
1. Parallelize calls to the API using a C++ 17 [parallel _for_each_ loop](https://stackoverflow.com/a/36246386/12215371), after it's implemented by _clang_. 
2. Clean up code and add comments.
3. Assemble the code into a single portable *.hpp file.
4. Switch from using narrow strings to using _std::wstrings_ to prevent inconsistent parsing and display for unicode emojis. 

## Contributors

1. [Pooja](https://github.com/pk0267)
2. [Arpan](https://github.com/RealArpanBhattacharya)

To become a contributor, send an email to [me](mailto:poorvajakolli99@gmail.com).

## Inspiration

emojicpp (https://github.com/99xt/emojicpp)
