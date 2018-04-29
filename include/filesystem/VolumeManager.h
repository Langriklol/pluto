//
// Created by lango on 4/28/18.
//

#ifndef PLUTO_VOLUMEMANAGER_H
#define PLUTO_VOLUMEMANAGER_H

#include <filesystem/File.h>
#include <filesystem/FileSystem.h>

namespace pluto
{
    namespace filesystem
    {
        class VolumeManager
        {
        public:
            VolumeManager(FileSystem* fs);
            ~VolumeManager();
            File* openFile(const char* filename);
            void readFile(File file, unsigned char* buffer, unsigned int length);
            bool saveFile(File file);
            bool registerFileSystem();
            bool unregisterFileSystem();
            bool unregisterFileSystemById();

        private:
            File* file;
            char* path;
            FileSystem fs;
        };
    }
}
#endif //PLUTO_FILEMANAGER_H
