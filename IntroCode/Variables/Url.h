//
// Created by hayley on 2024/07/02.
//

#ifndef URL_H
#define URL_H

#include<string>
#include<iomanip>

class Url {
    std::string protocol;
    std::string resource;
public:
    Url(std::string protocol, std::string resource) : protocol(protocol), resource(resource){};

    std::string display() {
        return (protocol + "://" + resource);
    }
};



#endif //URL_H
