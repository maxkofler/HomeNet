#ifndef PARSER_H
#define PARSER_H

#include "log/log.h"
#include "parseblock.h"

#include <string>
#include <fstream>

class Parser
{
public:
    Parser();

    /**
     * @brief Loads a file and parses it
     * @param path              The path to the file to load
     * @return                  The ammount of lines parsed
     *                          -1 when file not openable
     */
    int                         parseFile(std::string path);

    std::vector<ParseBlock>     getVector(){return this->_entries;}

    /**
     * @brief Returns the next entry in this list
     * @return
     */
    ParseBlock                  getNext();

private:
    std::string                 _curPath;
    std::ifstream               _curFile;

    std::vector<ParseBlock>     _entries;
    size_t                      _curPos;
};

#endif // PARSER_H
