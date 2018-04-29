//
// Created by lango on 4/29/18.
//

#ifndef PLUTO_FILESYSTEM_H
#define PLUTO_FILESYSTEM_H

#include <filesystem/File.h>

namespace pluto
{
    namespace filesystem
    {
        class FileSystem
        {
        protected:
            char* name;
            //uint32_t device;  maybe later
            File* directory(const char* dirName);
            void* mount();
            void* read(File file, unsigned char* buffer, unsigned int length);
            void* close(File);
            File* open(const char* filename);
        };
    }
}

#endif //PLUTO_FILESYSTEM_H
