#include <iostream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "log/log.h"
#include "homenet/homenet.h"

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log(Log::F);
    FUN();
    {
        //Plot some info about the program
        {
            std::string out = "";
            for(int i = 0; i < argc; i++){
                out += "[" + std::string(argv[i]) + "]";
            }
            LOGI("Starting HomeNet with args \"" + out + "\"...");
        }

        HomeNet hn("/etc/homenet/hnconfig.conf");

        hn.sync();

        LOGI("Overview:\n" + hn.getOverview());

        LOGI("Quiting...");
    }

    LOGI("Bye!");
    sleep(1);
}
