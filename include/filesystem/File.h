//
// Created by lango on 4/27/18.
//

#ifndef PLUTO_FILE_H
#define PLUTO_FILE_H

//Define file flags
#define FS_FILE 0
#define FS_SYMBOLICLINK 2
#define FS_DIRECTORY 4
#define FS_DEVICE 8
#define FS_INVALID 16

namespace pluto
{
    namespace filesystem
    {
        class File
        {
            public:
                File();
                ~File();
                void setFlag(uint32_t flag);
            protected:
                char* filename;
                uint32_t flags;
                uint32_t fileLength;
                uint32_t id;
                uint32_t position;
                uint32_t eof;
                uint32_t currentCluster;
                uint32_t device;
        };
    }
}

#endif //PLUTO_FILE_H
