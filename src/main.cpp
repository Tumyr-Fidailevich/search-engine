#include <string>
#include "config.h"
#include "search_server.h"


int main(int argc, char* argv[])
{
    auto config = Config(DEFAULT_CONFIG_PATH);

    auto search_server = SearchServer(config);
    
    search_server.run();
    return 0;
}